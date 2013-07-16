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

#include "MotionBaseModel.h"

#include <vpvl2/vpvl2.h>

#include <QtCore/QtCore>
#include <QtGui/QtGui>

namespace vpvm
{

int MotionBaseModel::toTimeIndex(const QModelIndex &index)
{
    return toTimeIndex(index.column());
}

int MotionBaseModel::toTimeIndex(int modelColumnIndex)
{
    // column index 0 is row header
    return qMax(modelColumnIndex - 1, 0);
}

int MotionBaseModel::toModelIndex(int timeIndex)
{
    // column index 0 is row header
    return qMax(timeIndex + 1, 0);
}

MotionBaseModel::MotionBaseModel(QUndoGroup *undoRef, QObject *parent)
    : QAbstractTableModel(parent),
      m_motionRef(0),
      m_undoRef(undoRef),
      m_timeIndex(0),
      m_timeIndexColumnMax(kTimeIndexColumnMinimum),
      m_timeIndexColumnOffset(kTimeIndexColumnMinimum),
      m_modified(false)
{
}

MotionBaseModel::~MotionBaseModel()
{
}

QVariant MotionBaseModel::headerData(int /* section */, Qt::Orientation /* orientation */, int /* role */) const
{
    return QVariant();
}

QModelIndex MotionBaseModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();
    ITreeItem *parentItem = 0;
    if (!parent.isValid())
        parentItem = rootRef();
    else
        parentItem = static_cast<ITreeItem *>(parent.internalPointer());
    ITreeItem *childItem = parentItem->child(row);
    return childItem ? createIndex(row, column, childItem) : QModelIndex();
}

QModelIndex MotionBaseModel::parent(const QModelIndex &child) const
{
    if (!child.isValid())
        return QModelIndex();
    ITreeItem *childItem = static_cast<ITreeItem *>(child.internalPointer());
    ITreeItem *parentItem = childItem->parent();
    return parentItem == rootRef() ? QModelIndex() : createIndex(parentItem->rowIndex(), 0, parentItem);
}

int MotionBaseModel::rowCount(const QModelIndex &parent) const
{
    ITreeItem *parentItem;
    if (parent.column() > 0)
        return 0;
    if (!parent.isValid()) {
        parentItem = rootRef();
        if (!parentItem)
            return 0;
    }
    else {
        parentItem = static_cast<ITreeItem *>(parent.internalPointer());
    }
    return parentItem->countChildren();
}

void MotionBaseModel::cutKeyframesByModelIndices(const QModelIndexList &indices, int timeIndex)
{
    copyKeyframesByModelIndices(indices, timeIndex);
    deleteKeyframesByModelIndices(indices);
}

QItemSelection MotionBaseModel::selectKeyframesFromItemSelection(const QItemSelection &selection)
{
    const QModelIndexList &indices = selection.indexes();
    QItemSelection newSelection;
    foreach (const QModelIndex &index, indices) {
        const QVariant &variant = index.data(kBinaryDataRole);
        if (variant.canConvert(QVariant::ByteArray))
            newSelection.select(index, index);
    }
    return newSelection;
}

void MotionBaseModel::setTimeIndex(const vpvl2::IKeyframe::TimeIndex &newIndex)
{
    int oldIndex = m_timeIndex;
    if (oldIndex != newIndex) {
        m_timeIndex = newIndex;
        emit timeIndexDidChange(newIndex, oldIndex);
    }
}

bool MotionBaseModel::canFetchMore(const QModelIndex & /* parent */) const
{
    return m_timeIndexColumnOffset < m_timeIndexColumnMax;
}

void MotionBaseModel::fetchMore(const QModelIndex &parent)
{
    int remain = m_timeIndexColumnMax - m_timeIndexColumnOffset;
    int step = kTimeIndexColumnStep;
    int itemsToFetch = qMin(step, remain);
    if (itemsToFetch > 0) {
        beginInsertColumns(parent, m_timeIndexColumnOffset, m_timeIndexColumnOffset + itemsToFetch - 1);
        m_timeIndexColumnOffset += itemsToFetch;
        endInsertColumns();
    }
}

int MotionBaseModel::timeIndexColumnMax() const
{
    return m_timeIndexColumnMax;
}

void MotionBaseModel::setTimeIndexColumnMax(int newValue)
{
    /*
     * 最小値はモーションの最大フレーム値を優先し(ない場合は0)、
     * さらに登録時意図しないスクロールを避けるため追加値 (現在は固定値の+10) を入れる
     */
    int newTimeIndex = maxTimeIndex() + 10;
    if (newValue < newTimeIndex)
        newValue = newTimeIndex;
    setTimeIndexColumnMax0(newValue);
}

void MotionBaseModel::setTimeIndexColumnMax(const IMotionSharedPtr motion)
{
    setTimeIndexColumnMax0(motion->duration());
}

void MotionBaseModel::addUndoCommand(QUndoCommand *command)
{
    if (QUndoStack *activeStack = m_undoRef->activeStack())
        activeStack->push(command);
}

void MotionBaseModel::resetModel()
{
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    beginResetModel();
    endResetModel();
#else
    reset();
#endif
}

void MotionBaseModel::setModified(bool value)
{
    m_modified = value;
    emit motionDidModify(value);
}

void MotionBaseModel::setTimeIndexColumnMax0(int newValue)
{
    int oldValue = m_timeIndexColumnMax;
    /* 下限は kTimeIndexColumnMinimum (=30) を採用する */
    if (newValue < kTimeIndexColumnMinimum)
        newValue = kTimeIndexColumnMinimum;
    /* 元の値より小さい場合は余剰分のカラムの削除を実行 */
    if (m_timeIndexColumnMax > newValue) {
        removeColumns(newValue, m_timeIndexColumnMax - newValue);
        m_timeIndexColumnOffset = newValue;
    }
    m_timeIndexColumnMax = newValue;
    m_timeIndexColumnOffset = newValue;
    resetModel();
    emit timeIndexColumnMaxDidChange(newValue, oldValue);
}

} /* namespace vpvm */
