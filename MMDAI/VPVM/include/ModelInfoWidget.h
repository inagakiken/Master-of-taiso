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

#ifndef VPVM_MODELINFOWIDGET_H
#define VPVM_MODELINFOWIDGET_H

#include <vpvl2/IModel.h>
#include <vpvl2/qt/ApplicationContext.h>

#include <QDialog>

class QLabel;
class QLineEdit;
class QTextEdit;

namespace vpvm
{

using namespace vpvl2;
using namespace vpvl2::qt;
class SceneLoader;

class ModelInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModelInfoWidget(QWidget *parent = 0);
    ~ModelInfoWidget();

private slots:
    void retranslate();
    void setModel(IModelSharedPtr model);

private:
    QScopedPointer<QLabel> m_nameLabel;
    QScopedPointer<QLineEdit> m_nameValueLabel;
    QScopedPointer<QLabel> m_commentLabel;
    QScopedPointer<QTextEdit> m_commentValueLabel;
    QScopedPointer<QLabel> m_verticesCountLabel;
    QScopedPointer<QLineEdit> m_verticesCountValueLabel;
    QScopedPointer<QLabel> m_indicesCountLabel;
    QScopedPointer<QLineEdit> m_indicesCountValueLabel;
    QScopedPointer<QLabel> m_materialsCountLabel;
    QScopedPointer<QLineEdit> m_materialsCountValueLabel;
    QScopedPointer<QLabel> m_bonesCountLabel;
    QScopedPointer<QLineEdit> m_bonesCountValueLabel;
    QScopedPointer<QLabel> m_IKsCountLabel;
    QScopedPointer<QLineEdit> m_IKsCountValueLabel;
    QScopedPointer<QLabel> m_morphsCountLabel;
    QScopedPointer<QLineEdit> m_morphsCountValueLabel;
    QScopedPointer<QLabel> m_rigidBodiesCountLabel;
    QScopedPointer<QLineEdit> m_rigidBodiesCountValueLabel;
    QScopedPointer<QLabel> m_constrantsCountLabel;
    QScopedPointer<QLineEdit> m_constrantsCountValueLabel;
};

} /* namespace vpvm */

#endif // MODELINFOWIDGET_H
