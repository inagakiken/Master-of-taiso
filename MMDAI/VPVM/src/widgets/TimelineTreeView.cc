/**

 Copyright (c) 2010-2013  hkrn

 All rights reserved.

 Redistribution and use in source and binary forms, with or
 without modification, are permitted provided that the following
 conditions are met:

 - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
 - Redistributions in binary form must reproduce the above
   copyright notice, this list of conditions and the following
   disclaimer in the documentation and/or other materials provided
   with the distribution.
 - Neither the name of the MMDAI project team nor the names of
   its contributors may be used to endorse or promote products
   derived from this software without specific prior written
   permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.

*/

#include "BoneMotionModel.h"
#include "MorphMotionModel.h"
#include "PMDMotionModel.h"
#include "SceneMotionModel.h"
#include "TimelineTreeView.h"

#include <vpvl2/qt/Util.h>

#include <QtGui>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets>
#endif

namespace vpvm
{

using namespace vpvl2::qt;

TimelineTreeView::TimelineTreeView(MotionBaseModel *mbm, QItemDelegate *delegate, QWidget *parent)
    : QTreeView(parent),
      m_rubberBand(new QRubberBand(QRubberBand::Rectangle)),
      m_frozenTreeView(new QTreeView(this))
{
    setModel(mbm);
    setSelectionBehavior(QAbstractItemView::SelectItems);
    setSelectionMode(QAbstractItemView::ExtendedSelection);
    setItemDelegate(delegate);
    setExpandsOnDoubleClick(true);
    setUniformRowHeights(true);
    setSortingEnabled(false);
    setItemsExpandable(false);
    m_frozenTreeView->setItemDelegate(new QItemDelegate());
    connect(m_frozenTreeView.data(), SIGNAL(collapsed(QModelIndex)), SLOT(addCollapsed(QModelIndex)));
    connect(m_frozenTreeView.data(), SIGNAL(expanded(QModelIndex)), SLOT(addExpanded(QModelIndex)));
    connect(m_frozenTreeView->verticalScrollBar(), SIGNAL(valueChanged(int)),
            verticalScrollBar(), SLOT(setValue(int)));
    connect(verticalScrollBar(), SIGNAL(valueChanged(int)),
            m_frozenTreeView->verticalScrollBar(), SLOT(setValue(int)));
    connect(header(), SIGNAL(sectionResized(int,int,int)), SLOT(updateSectionWidth(int,int,int)));
    connect(selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            SLOT(selectModelIndices(QItemSelection,QItemSelection)));
}

TimelineTreeView::~TimelineTreeView()
{
}

void TimelineTreeView::initializeFrozenView()
{
    QAbstractItemModel *m = model();
    m_frozenTreeView->setModel(m);
    // TODO: alternative of setResizeMode
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    m_frozenTreeView->header()->setResizeMode(QHeaderView::Fixed);
#endif
    viewport()->stackUnder(m_frozenTreeView.data());
    updateFrozenTreeView();
    m_frozenTreeView->setColumnWidth(0, columnWidth(0));
    m_frozenTreeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_frozenTreeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_frozenTreeView->show();
    updateFrozenTreeViewGeometry();
}

void TimelineTreeView::resizeEvent(QResizeEvent *event)
{
    QTreeView::resizeEvent(event);
    resizeColumnToContents(0);
    updateFrozenTreeViewGeometry();
    m_frozenTreeView->setColumnWidth(0, columnWidth(0));
}

QModelIndex TimelineTreeView::moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers)
{
    const QModelIndex &ci = currentIndex();
    int column = ci.column();
    if (column == 0) {
        return QModelIndex();
    }
    else if (column == 1 && cursorAction == MoveLeft) {
        return ci;
    }
    else {
        const QModelIndex &current = QTreeView::moveCursor(cursorAction, modifiers);
        const int x = visualRect(current).topLeft().x();
        if(cursorAction == MoveLeft && current.column() > 0 && x < m_frozenTreeView->columnWidth(0)){
            const int newValue = horizontalScrollBar()->value() + x - m_frozenTreeView->columnWidth(0);
            horizontalScrollBar()->setValue(newValue);
        }
        return current;
    }
}

void TimelineTreeView::scrollTo(const QModelIndex &index, ScrollHint hint)
{
    if (index.column() > 0)
        QTreeView::scrollTo(index, hint);
}

void TimelineTreeView::updateFrozenTreeView()
{
    int ncolumns = model()->columnCount();
    for (int i = 1; i < ncolumns; i++)
        m_frozenTreeView->setColumnHidden(i, true);
    updateFrozenTreeViewGeometry();
}

void TimelineTreeView::updateSectionWidth(int logicalIndex, int newSize, int /* oldSize */)
{
    if (logicalIndex == 0) {
        m_frozenTreeView->setColumnWidth(0, newSize);
        updateFrozenTreeViewGeometry();
    }
}

void TimelineTreeView::updateFrozenTreeViewGeometry()
{
    const QRect rect(frameWidth(),
                     frameWidth(),
                     columnWidth(0),
                     viewport()->height() + header()->height());
    m_frozenTreeView->setGeometry(rect);
}

QItemSelectionModel *TimelineTreeView::frozenViewSelectionModel() const
{
    return m_frozenTreeView->selectionModel();
}

void TimelineTreeView::selectFrameIndices(const QList<int> &frameIndices, bool registeredOnly)
{
    QItemSelection selection;
    if (PMDMotionModel *pmm = qobject_cast<PMDMotionModel *>(model())) {
        /* 現在のキーフレームのインデックスから全てのボーンまたは頂点モーフを選択する処理 */
        QSet<QModelIndex> categories;
        foreach (PMDMotionModel::ITreeItem *item, pmm->keys().values()) {
            foreach (int timeIndex, frameIndices) {
                /* モデルインデックス(登録済みのキーフレームのみ取得するように指定されている場合はデータがあるかを確認してなかったらスキップする) */
                const QModelIndex &index = pmm->timeIndexToModelIndex(item, timeIndex);
                if (registeredOnly) {
                    const QVariant &variant = index.data(MotionBaseModel::kBinaryDataRole);
                    if (!variant.canConvert(QVariant::ByteArray))
                        continue;
                }
                selection.append(QItemSelectionRange(index));
                /* カテゴリを追加 */
                const QModelIndex &category = pmm->index(item->parent()->rowIndex(), MotionBaseModel::toModelIndex(timeIndex));
                categories.insert(category);
            }
        }
        /* すべてのカテゴリを選択状態にする */
        foreach (const QModelIndex &index, categories)
            selection.append(QItemSelectionRange(index));
        selectionModel()->select(selection, QItemSelectionModel::ClearAndSelect);
    }
    else if (SceneMotionModel *smm = qobject_cast<SceneMotionModel *>(model())) {
        /* 現在のキーフレームのインデックスから現時点ではカメラフレームのみを選択する処理 */
        foreach (int timeIndex, frameIndices) {
            const QModelIndex &index = smm->index(0, MotionBaseModel::toModelIndex(timeIndex));
            if (registeredOnly && !index.data(MotionBaseModel::kBinaryDataRole).canConvert(QVariant::ByteArray))
                continue;
            selection.append(QItemSelectionRange(index));
        }
        selectionModel()->select(selection, QItemSelectionModel::ClearAndSelect);
    }
}

void TimelineTreeView::addKeyframesBySelectedIndices()
{
    MotionBaseModel *m = static_cast<MotionBaseModel *>(model());
    const QModelIndexList &indices = selectionModel()->selectedIndexes();
    if (!indices.empty()) {
        m->addKeyframesByModelIndices(indices);
    }
    else {
        Util::warning(this,
                      vpvm::TimelineTreeView::tr("Tried registering empty (not selected) keyframes"),
                      vpvm::TimelineTreeView::tr("Select at least a keyframe or more (select a cell in timeline tab) to register before registering keyframes."));
    }
}

void TimelineTreeView::deleteKeyframesBySelectedIndices()
{
    MotionBaseModel *m = static_cast<MotionBaseModel *>(model());
    const QModelIndexList &indices = selectionModel()->selectedIndexes();
    if (!indices.empty()) {
        m->deleteKeyframesByModelIndices(indices);
    }
    else {
        Util::warning(this,
                      vpvm::TimelineTreeView::tr("Tried deleting empty (not selected) keyframes"),
                      vpvm::TimelineTreeView::tr("Select at least a keyframe or more (select a cell in timeline tab) to delete before deleting keyframes."));
    }
}

void TimelineTreeView::setBoneKeyframesWeightBySelectedIndices(const vpvl2::Vector3 &position,
                                                               const vpvl2::Vector3 &rotation)
{
    if (BoneMotionModel *m = qobject_cast<BoneMotionModel *>(model())) {
        const QModelIndexList &indices = selectionModel()->selectedIndexes();
        m->applyKeyframeWeightByModelIndices(indices, position, rotation);
    }
}

void TimelineTreeView::setMorphKeyframesWeightBySelectedIndices(float value)
{
    if (MorphMotionModel *m = qobject_cast<MorphMotionModel *>(model())) {
        const QModelIndexList &indices = selectionModel()->selectedIndexes();
        m->applyKeyframeWeightByModelIndices(indices, value);
    }
}

void TimelineTreeView::mousePressEvent(QMouseEvent *event)
{
    const QPoint &pos = event->globalPos();
    const QWidget *v = viewport();
    if (v->rect().contains(v->mapFromGlobal(pos))) {
        m_rubberBandRect.setTopLeft(pos);
        m_rubberBandRect.setBottomRight(pos);
        m_rubberBand->setGeometry(m_rubberBandRect);
        m_rubberBand->show();
    }
}

void TimelineTreeView::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint &pos = event->globalPos();
    const QWidget *v = viewport();
    if (m_rubberBand->isVisible() && v->rect().contains(v->mapFromGlobal(pos))) {
        m_rubberBandRect.setBottomRight(pos);
        const QRect &rect = m_rubberBandRect.normalized();
        const QModelIndex &topLeft = indexAt(mapFromGlobal(rect.topLeft())),
                &bottomRight = indexAt(mapFromGlobal(rect.bottomRight()));
        QItemSelection selection;
        selection.select(topLeft, bottomRight);
        MotionBaseModel *mbm = static_cast<MotionBaseModel *>(model());
        selection = mbm->selectKeyframesFromItemSelection(selection);
        selectionModel()->select(selection, QItemSelectionModel::ClearAndSelect);
        m_rubberBand->setGeometry(rect);
    }
}

void TimelineTreeView::mouseReleaseEvent(QMouseEvent *event)
{
    MotionBaseModel *m = static_cast<MotionBaseModel *>(model());
    if (m_rubberBandRect.topLeft() == m_rubberBandRect.bottomRight()) {
        const QModelIndex &index = indexAt(event->pos());
        if (index.isValid()) {
            selectionModel()->select(index, QItemSelectionModel::ClearAndSelect);
            m->setTimeIndex(MotionBaseModel::toTimeIndex(index));
        }
    }
    else {
        const QModelIndex &index = indexAt(mapFromGlobal(m_rubberBandRect.topLeft()));
        m->setTimeIndex(MotionBaseModel::toTimeIndex(index));
    }
    m_rubberBand->hide();
}

void TimelineTreeView::mouseDoubleClickEvent(QMouseEvent *event)
{
    const QModelIndex &index = indexAt(event->pos());
    if (index.isValid()) {
        QModelIndexList indices;
        indices.append(index);
        emit modelIndexDidSelect(indices);
    }
    QTreeView::mouseDoubleClickEvent(event);
}

void TimelineTreeView::addCollapsed(const QModelIndex &index)
{
    collapse(index);
    m_expanded.removeOne(index);
    updateFrozenTreeViewGeometry();
}

void TimelineTreeView::addExpanded(const QModelIndex &index)
{
    expand(index);
    if (!m_expanded.contains(index))
        m_expanded.append(index);
    updateFrozenTreeViewGeometry();
}

void TimelineTreeView::selectModelIndices(const QItemSelection &selected, const QItemSelection & /* deselected */)
{
    QAbstractItemModel *m = model();
    QModelIndexList names, indices, selectedIndices = selected.indexes();
    /* ボーンまた頂点モーフのモデルである PMDMotionModel のクラスである */
    if (selectedIndices.size() > 0) {
        PMDMotionModel *pmm = qobject_cast<PMDMotionModel *>(m);
        QItemSelectionModel *sm = selectionModel();
        foreach (const QModelIndex &index, selectedIndices) {
            PMDMotionModel::ITreeItem *item = static_cast<PMDMotionModel::ITreeItem *>(index.internalPointer());
            /* ボーンまたは頂点フレームのカテゴリ名またはキーフレームが選択されていることを確認する */
            int column = index.column();
            if (item && !item->isRoot()) {
                if (item->isCategory()) {
                    int nchildren = item->countChildren();
                    for (int i = 0; i < nchildren; i++) {
                        /* ボーン名またはモーフ名 */
                        if (column == 0) {
                            const QModelIndex &child = pmm->index(i, 0, index);
                            names.append(child);
                            sm->select(child, QItemSelectionModel::Select);
                        }
                        else {
                            int timeIndex = PMDMotionModel::toTimeIndex(column);
                            const QModelIndex &child = pmm->timeIndexToModelIndex(item->child(i), timeIndex);
                            indices.append(child);
                            sm->select(child, QItemSelectionModel::Select);
                        }
                    }
                }
                else {
                    column == 0 ? names.append(index) : indices.append(index);
                }
            }
        }
        /* テーブルモデルがボーンの場合は該当ボーンを選択状態にする処理を入れる */
        if (BoneMotionModel *bmm = qobject_cast<BoneMotionModel *>(pmm)) {
            bmm->selectBonesByModelIndices(names.isEmpty() ? indices : names);
        }
        /* テーブルモデルがモーフの場合は該当モーフを選択状態にする処理を入れる */
        else if (MorphMotionModel *mmm = qobject_cast<MorphMotionModel *>(pmm)) {
            mmm->selectMorphsByModelIndices(names.isEmpty() ? indices : names);
        }
    }
}

void TimelineTreeView::restoreExpandState()
{
    foreach (const QModelIndex &index, m_expanded)
        m_frozenTreeView->expand(index);
}

TimelineHeaderView::TimelineHeaderView(Qt::Orientation orientation,
                                       bool stretchLastSection,
                                       QWidget *parent)
    : QHeaderView(orientation, parent)
{
    setDefaultAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    // TODO: alternative of setResizeMode
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    setResizeMode(QHeaderView::Fixed);
    setClickable(true);
    setMovable(false);
#endif
    setStretchLastSection(stretchLastSection);
    setSortIndicatorShown(false);
    setDefaultSectionSize(16);
}

TimelineHeaderView::~TimelineHeaderView()
{
}

void TimelineHeaderView::mousePressEvent(QMouseEvent *e)
{
    /* setMovable(false) にすると何故か sectionPressed が効かなくなるので mousePressEvent でシグナルを発行する */
    int modelIndex = logicalIndexAt(e->pos());
    emit timeIndexDidSelect(MotionBaseModel::toTimeIndex(modelIndex));
    QHeaderView::mousePressEvent(e);
}

} /* namespace vpvm */
