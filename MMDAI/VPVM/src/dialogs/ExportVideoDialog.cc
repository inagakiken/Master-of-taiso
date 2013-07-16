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

#include "SceneWidget.h"
#include "SceneLoader.h"
#include "ExportVideoDialog.h"
#include "IVideoEncoder.h"

#include <QtGui>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets>
#endif

#include <vpvl2/vpvl2.h>
#include <vpvl2/qt/Util.h>

namespace vpvm
{

using namespace vpvl2::qt;
/* lupdate cannot parse tr() syntax correctly */

ExportVideoDialog::ExportVideoDialog(const QSize &minSize,
                                     const QSize &maxSize,
                                     QSettings *settings)
    : QDialog(),
      m_settingsRef(settings),
      m_audioGroup(new QGroupBox()),
      m_pathEdit(new QLineEdit()),
      m_openFileButton(new QPushButton(vpvm::ExportVideoDialog::tr("Open"))),
      m_sceneSizeGroup(new QGroupBox()),
      m_widthLabel(new QLabel()),
      m_widthBox(createSpinBox(minSize.width(), maxSize.width())),
      m_heightLabel(new QLabel()),
      m_heightBox(createSpinBox(minSize.height(), maxSize.height())),
      m_timeIndexGroup(new QGroupBox()),
      m_fromIndexLabel(new QLabel()),
      m_fromIndexBox(createSpinBox(0, 0)),
      m_toIndexLabel(new QLabel()),
      m_toIndexBox(createSpinBox(0, 0)),
      m_encodingSettingGroup(new QGroupBox()),
      m_audioCodecsLabel(new QLabel()),
      m_audioCodecsBox(new QComboBox()),
      m_videoCodecsLabel(new QLabel()),
      m_videoCodecsBox(new QComboBox()),
      m_sceneFPSLabel(new QLabel()),
      m_sceneFPSBox(new QComboBox()),
      m_includeGridBox(new QCheckBox())
{
    QScopedPointer<QVBoxLayout> mainLayout(new QVBoxLayout());
    connect(m_openFileButton.data(), SIGNAL(clicked()), SLOT(openFileDialog()));
    QScopedPointer<QHBoxLayout> rowLayout(new QHBoxLayout());
    rowLayout->addWidget(m_pathEdit.data());
    rowLayout->addWidget(m_openFileButton.data());
    m_audioGroup->setLayout(rowLayout.take());
    mainLayout->addWidget(m_audioGroup.data());
    m_sceneFPSBox->addItem("30", 30);
    m_sceneFPSBox->addItem("60", 60);
    m_sceneFPSBox->addItem("120", 120);
    QScopedPointer<QVBoxLayout> columnLayout(new QVBoxLayout());
    rowLayout.reset(new QHBoxLayout());
    rowLayout->addWidget(m_widthLabel.data());
    rowLayout->addWidget(m_widthBox.data());
    columnLayout->addLayout(rowLayout.take());
    rowLayout.reset(new QHBoxLayout());
    rowLayout->addWidget(m_heightLabel.data());
    rowLayout->addWidget(m_heightBox.data());
    columnLayout->addLayout(rowLayout.take());
    m_sceneSizeGroup->setLayout(columnLayout.take());
    columnLayout.reset(new QVBoxLayout());
    mainLayout->addWidget(m_sceneSizeGroup.data());
    rowLayout.reset(new QHBoxLayout());
    rowLayout->addWidget(m_fromIndexLabel.data());
    rowLayout->addWidget(m_fromIndexBox.data());
    columnLayout->addLayout(rowLayout.take());
    rowLayout.reset(new QHBoxLayout());
    rowLayout->addWidget(m_toIndexLabel.data());
    rowLayout->addWidget(m_toIndexBox.data());
    columnLayout->addLayout(rowLayout.take());
    m_timeIndexGroup->setLayout(columnLayout.take());
    columnLayout.reset(new QVBoxLayout());
    mainLayout->addWidget(m_timeIndexGroup.data());
    rowLayout.reset(new QHBoxLayout());
    rowLayout->addWidget(m_audioCodecsLabel.data());
    rowLayout->addWidget(m_audioCodecsBox.data());
    columnLayout->addLayout(rowLayout.take());
    rowLayout.reset(new QHBoxLayout());
    rowLayout->addWidget(m_videoCodecsLabel.data());
    rowLayout->addWidget(m_videoCodecsBox.data());
    columnLayout->addLayout(rowLayout.take());
    rowLayout.reset(new QHBoxLayout());
    rowLayout->addWidget(m_sceneFPSLabel.data());
    rowLayout->addWidget(m_sceneFPSBox.data());
    columnLayout->addLayout(rowLayout.take());
    columnLayout->addWidget(m_includeGridBox.data(), 0, Qt::AlignCenter);
    m_encodingSettingGroup->setLayout(columnLayout.take());
    mainLayout->addWidget(m_encodingSettingGroup.data());
    QScopedPointer<QDialogButtonBox> buttons(new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel));
    connect(buttons.data(), SIGNAL(accepted()), SLOT(saveSettings()));
    connect(buttons.data(), SIGNAL(rejected()), SLOT(close()));
    mainLayout->addWidget(buttons.take());
    setLayout(mainLayout.take());
    retranslate();
}

ExportVideoDialog::~ExportVideoDialog()
{
}

void ExportVideoDialog::retranslate()
{
    m_audioGroup->setTitle(vpvm::ExportVideoDialog::tr("Audio File Setting"));
    m_sceneSizeGroup->setTitle(vpvm::ExportVideoDialog::tr("Scene Size Setting"));
    m_widthLabel->setText(vpvm::ExportVideoDialog::tr("Width (px): "));
    m_heightLabel->setText(vpvm::ExportVideoDialog::tr("Height (px): "));
    m_timeIndexGroup->setTitle(vpvm::ExportVideoDialog::tr("Frame Index Setting"));
    m_fromIndexLabel->setText(vpvm::ExportVideoDialog::tr("Keyframe from: "));
    m_toIndexLabel->setText(vpvm::ExportVideoDialog::tr("Keyframe to: "));
    m_encodingSettingGroup->setTitle(vpvm::ExportVideoDialog::tr("Encoding Setting"));
    m_audioCodecsLabel->setText(vpvm::ExportVideoDialog::tr("Audio Codec: "));
    m_videoCodecsLabel->setText(vpvm::ExportVideoDialog::tr("Video Codec: "));
    m_sceneFPSLabel->setText(vpvm::ExportVideoDialog::tr("Scene FPS: "));
    m_includeGridBox->setText(vpvm::ExportVideoDialog::tr("Include Grid Field"));
}

void ExportVideoDialog::openFileDialog()
{
    const QString &filename = Util::openFileDialog("exportVideoDialog/lastAudioDirectory",
                                                   vpvm::ExportVideoDialog::tr("Open Audio File"),
                                                   vpvm::ExportVideoDialog::tr("WAV file (*.wav)"),
                                                   m_settingsRef);
    if (!filename.isEmpty())
        m_pathEdit->setText(filename);
}

void ExportVideoDialog::saveSettings()
{
    emit backgroundAudioPathDidChange(backgroundAudio());
    emit sceneWidthDidChange(sceneWidth());
    emit sceneHeightDidChange(sceneHeight());
    emit timeIndexEncodeVideoFromDidChange(fromIndex());
    emit timeIndexEncodeVideoToDidChange(toIndex());
    emit sceneFPSForEncodeVideoDidChange(sceneFPS());
    emit gridIncludedDidChange(includesGrid());
    emit settingsDidSave();
}

void ExportVideoDialog::setBackgroundAudioPath(const QString &value)
{
    m_pathEdit->setText(value);
}

void ExportVideoDialog::setSceneWidth(int value)
{
    m_widthBox->setValue(value);
}

void ExportVideoDialog::setSceneHeight(int value)
{
    m_heightBox->setValue(value);
}

void ExportVideoDialog::setTimeIndexEncodeVideoFrom(int value)
{
    m_fromIndexBox->setValue(value);
}

void ExportVideoDialog::setTimeIndexEncodeVideoTo(int value)
{
    m_toIndexBox->setValue(value);
}

void ExportVideoDialog::setSceneFPSForEncodeVideo(int value)
{
    switch (value) {
    case 120:
        m_sceneFPSBox->setCurrentIndex(2);
        break;
    case 60:
    default:
        m_sceneFPSBox->setCurrentIndex(1);
        break;
    case 30:
        m_sceneFPSBox->setCurrentIndex(0);
        break;
    }
}

void ExportVideoDialog::setGridIncluded(bool value)
{
    m_includeGridBox->setChecked(value);
}

void ExportVideoDialog::setImageConfiguration(bool value)
{
    m_pathEdit->setEnabled(!value);
    m_fromIndexBox->setEnabled(!value);
    m_toIndexBox->setEnabled(!value);
    m_sceneFPSBox->setEnabled(!value);
    m_audioCodecsBox->setEnabled(!value);
    m_videoCodecsBox->setEnabled(!value);
    setWindowTitle(value ? vpvm::ExportVideoDialog::tr("Exporting Image Setting")
                         : vpvm::ExportVideoDialog::tr("Exporting Video Setting"));
}

void ExportVideoDialog::setMaxTimeIndex(const Scene *sceneRef)
{
    int maxTimeIndex = 0;
    if (sceneRef)
        maxTimeIndex = sceneRef->duration();
    m_fromIndexBox->setMaximum(maxTimeIndex);
    m_toIndexBox->setMaximum(maxTimeIndex);
    m_toIndexBox->setValue(maxTimeIndex);
}

void ExportVideoDialog::setAvaiableCodecs(const IVideoEncoder *value)
{
    if (value) {
        m_audioCodecsBox->clear();
        m_videoCodecsBox->clear();
        QStringList s;
        foreach (const IVideoEncoder::Setting &setting, value->availableAudioSettings()) {
            s.clear(); s << setting.format; s << setting.codec;
            m_audioCodecsBox->addItem(setting.description, s);
        }
        foreach (const IVideoEncoder::Setting &setting, value->availableVideoSettings()) {
            s.clear(); s << setting.format; s << setting.codec;
            m_videoCodecsBox->addItem(setting.description, s);
        }
    }
}

void ExportVideoDialog::selectCodec(IVideoEncoder *value)
{
    const QStringList &ac = m_audioCodecsBox->itemData(m_audioCodecsBox->currentIndex()).toStringList();
    value->selectAudioSetting(IVideoEncoder::Setting("", ac[0], ac[1], ""));
    const QStringList &vc = m_videoCodecsBox->itemData(m_videoCodecsBox->currentIndex()).toStringList();
    value->selectVideoSetting(IVideoEncoder::Setting("", vc[0], vc[1], ""));
}

const QString ExportVideoDialog::backgroundAudio() const
{
    return m_pathEdit->text();
}

int ExportVideoDialog::sceneWidth() const
{
    return m_widthBox->value();
}

int ExportVideoDialog::sceneHeight() const
{
    return m_heightBox->value();
}

int ExportVideoDialog::fromIndex() const
{
    return m_fromIndexBox->value();
}

int ExportVideoDialog::toIndex() const
{
    return m_toIndexBox->value();
}

Scalar ExportVideoDialog::sceneFPS() const
{
    return m_sceneFPSBox->itemData(m_sceneFPSBox->currentIndex()).toFloat();
}

bool ExportVideoDialog::includesGrid() const
{
    return m_includeGridBox->isChecked();
}

const QString ExportVideoDialog::videoFormat() const
{
    return m_videoCodecsBox->itemData(m_videoCodecsBox->currentIndex()).toStringList().at(0);
}

QSpinBox *ExportVideoDialog::createSpinBox(int min, int max)
{
    QScopedPointer<QSpinBox> spinBox(new QSpinBox());
    spinBox->setAlignment(Qt::AlignRight);
    spinBox->setRange(min, max);
    return spinBox.take();
}

} /* namespace vpvm */
