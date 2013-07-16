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

#ifndef VPVM_BONEDIALOG_H
#define VPVM_BONEDIALOG_H

#include <vpvl2/Common.h>

#include <QDialog>

class QDoubleSpinBox;
class QGroupBox;
class QLabel;
class QSettings;

namespace vpvm
{

using namespace vpvl2;
class BoneMotionModel;

class BoneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BoneDialog(BoneMotionModel *bmm, QSettings *settings, QWidget *parent = 0);
    ~BoneDialog();

private slots:
    void retranslate();
    void setPosition(const Vector3 &position);
    void setRotation(const Quaternion &rotation);
    void setXPosition(double value);
    void setYPosition(double value);
    void setZPosition(double value);
    void setXAngle(double value);
    void setYAngle(double value);
    void setZAngle(double value);
    void setPositionStep(double value);
    void setRotationStep(double value);
    void dialogAccepted();
    void dialogRejected();

private:
    static QDoubleSpinBox *createSpinBox();

    QScopedPointer<QGroupBox> m_positionGroup;
    QScopedPointer<QGroupBox> m_rotationGroup;
    QScopedPointer<QLabel> m_xPositionLabel;
    QScopedPointer<QLabel> m_yPositionLabel;
    QScopedPointer<QLabel> m_zPositionLabel;
    QScopedPointer<QLabel> m_stepPositionLabel;
    QScopedPointer<QLabel> m_xAngleLabel;
    QScopedPointer<QLabel> m_yAngleLabel;
    QScopedPointer<QLabel> m_zAngleLabel;
    QScopedPointer<QLabel> m_stepRotationLabel;
    QScopedPointer<QDoubleSpinBox> m_xPosition;
    QScopedPointer<QDoubleSpinBox> m_yPosition;
    QScopedPointer<QDoubleSpinBox> m_zPosition;
    QScopedPointer<QDoubleSpinBox> m_stepPosition;
    QScopedPointer<QDoubleSpinBox> m_xAngle;
    QScopedPointer<QDoubleSpinBox> m_yAngle;
    QScopedPointer<QDoubleSpinBox> m_zAngle;
    QScopedPointer<QDoubleSpinBox> m_stepRotation;
    QSettings *m_settingsRef;
    BoneMotionModel *m_boneMotionModelRef;
    bool m_dirty;

    Q_DISABLE_COPY(BoneDialog)
};

} /* namespace vpvm */

#endif // BONEDIALOG_H
