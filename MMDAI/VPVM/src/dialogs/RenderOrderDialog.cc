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

#include "RenderOrderDialog.h"
#include "SceneLoader.h"

#include <vpvl2/vpvl2.h>
#include <vpvl2/extensions/XMLProject.h>
#include <vpvl2/qt/Util.h>

#include <QtGui>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets>
#endif

namespace vpvm
{

using namespace vpvl2;
using namespace vpvl2::extensions;
using namespace vpvl2::qt;

RenderOrderDialog::RenderOrderDialog(SceneLoader *loader, QWidget *parent)
    : QDialog(parent),
      m_listWidget(new QListWidget()),
      m_dialogButtonBox(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel | QDialogButtonBox::Apply)),
      m_upButton(new QPushButton()),
      m_downButton(new QPushButton()),
      m_resetButton(new QPushButton())
{
    /* アイテムのドラッグ・アンド・ドロップを有効にする */
    m_listWidget->setSelectionMode(QListWidget::SingleSelection);
    m_listWidget->setDragEnabled(true);
    m_listWidget->viewport()->setAcceptDrops(true);
    m_listWidget->setDropIndicatorShown(true);
    m_listWidget->setDragDropMode(QListWidget::InternalMove);
    QScopedPointer<QHBoxLayout> subLayout(new QHBoxLayout());
    subLayout->addWidget(m_listWidget.data());
    QScopedPointer<QVBoxLayout> buttonLayout(new QVBoxLayout());
    connect(m_upButton.data(), SIGNAL(clicked()), SLOT(setOrderUp()));
    connect(m_downButton.data(), SIGNAL(clicked()), SLOT(setOrderDown()));
    connect(m_resetButton.data(), SIGNAL(clicked()), SLOT(resetOrder()));
    buttonLayout->addWidget(m_upButton.data());
    buttonLayout->addWidget(m_downButton.data());
    buttonLayout->addWidget(m_resetButton.data());
    buttonLayout->addStretch();
    subLayout->addLayout(buttonLayout.take());
    QScopedPointer<QVBoxLayout> mainLayout(new QVBoxLayout());
    mainLayout->addLayout(subLayout.take());
    connect(m_dialogButtonBox.data(), SIGNAL(accepted()), SLOT(accept()));
    connect(m_dialogButtonBox.data(), SIGNAL(rejected()), SLOT(reject()));
    connect(m_dialogButtonBox.data(), SIGNAL(clicked(QAbstractButton*)), SLOT(handleButton(QAbstractButton*)));
    connect(this, SIGNAL(accepted()), SLOT(emitSignal()));
    connect(this, SIGNAL(renderOrderListDidSet(QList<QUuid>)), loader, SLOT(setRenderOrderList(QList<QUuid>)));
    mainLayout->addWidget(m_dialogButtonBox.data());
    retranslate();
    setLayout(mainLayout.take());
    buildOriginFromRenderOrder(loader);
    setRenderOrder(m_origin);
    setWindowTitle(tr("Render Order Setting"));
}

RenderOrderDialog::~RenderOrderDialog()
{
}

void RenderOrderDialog::retranslate()
{
    m_upButton->setText(tr("Up"));
    m_downButton->setText(tr("Down"));
    m_resetButton->setText(tr("Reset"));
}

void RenderOrderDialog::emitSignal()
{
    QList<QUuid> value;
    int nitems = m_listWidget->count();
    for (int i = 0; i < nitems; i++) {
        QListWidgetItem *item = m_listWidget->item(i);
        const QVariant &var = item->data(QListWidgetItem::UserType);
        value.append(QUuid(var.toString()));
    }
    emit renderOrderListDidSet(value);
}

void RenderOrderDialog::setOrderUp()
{
    int row = m_listWidget->currentRow();
    if (row > 0 && row <= m_listWidget->count()) {
        QListWidgetItem *item = m_listWidget->takeItem(row);
        m_listWidget->insertItem(row - 1, item);
        m_listWidget->setCurrentItem(item);
    }
}

void RenderOrderDialog::setOrderDown()
{
    int row = m_listWidget->currentRow();
    if (row >= 0 && row < m_listWidget->count()) {
        QListWidgetItem *item = m_listWidget->takeItem(row);
        m_listWidget->insertItem(row + 1, item);
        m_listWidget->setCurrentItem(item);
    }
}

void RenderOrderDialog::handleButton(QAbstractButton *button)
{
    if (m_dialogButtonBox->buttonRole(button) == QDialogButtonBox::ApplyRole)
        emitSignal();
}

void RenderOrderDialog::resetOrder()
{
    setRenderOrder(m_origin);
}

void RenderOrderDialog::buildOriginFromRenderOrder(const SceneLoader *loader)
{
    const QList<QUuid> &list = loader->renderOrderList();
    foreach (const QUuid &uuid, list) {
        if (IModelSharedPtr model = loader->findModel(uuid))
            m_origin.append(NameUUID(Util::toQStringFromModel(model.data()), uuid));
    }
}

void RenderOrderDialog::setRenderOrder(const QList<NameUUID> &pairs)
{
    m_listWidget->clear();
    foreach (const NameUUID &pair, pairs) {
        QListWidgetItem *item = new QListWidgetItem(m_listWidget.data());
        item->setText(pair.first);
        item->setData(QListWidgetItem::UserType, QVariant(pair.second));
    }
}

} /* namespace vpvm */
