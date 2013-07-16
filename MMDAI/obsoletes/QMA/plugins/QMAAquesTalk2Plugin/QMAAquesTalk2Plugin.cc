/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2010-2011  hkrn                                    */
/*                                                                   */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/* - Redistributions of source code must retain the above copyright  */
/*   notice, this list of conditions and the following disclaimer.   */
/* - Redistributions in binary form must reproduce the above         */
/*   copyright notice, this list of conditions and the following     */
/*   disclaimer in the documentation and/or other materials provided */
/*   with the distribution.                                          */
/* - Neither the name of the MMDAI project team nor the names of     */
/*   its contributors may be used to endorse or promote products     */
/*   derived from this software without specific prior written       */
/*   permission.                                                     */
/*                                                                   */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND            */
/* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,       */
/* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF          */
/* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          */
/* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS */
/* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          */
/* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     */
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON */
/* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   */
/* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    */
/* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           */
/* POSSIBILITY OF SUCH DAMAGE.                                       */
/* ----------------------------------------------------------------- */

#include "QMAAquesTalk2Plugin.h"

#include <QtConcurrentRun>
#include <QDir>
#include <QFile>
#include <QTextCodec>

#include <MMDAI/MMDAI.h>

#if defined(Q_OS_WIN32)
#include "AquesTalk2Da.h"
#include "AqKanji2Koe.h"
#elif defined(Q_OS_DARWIN)
#include <AquesTalk2/AquesTalk2.h>
#include <AqKanji2Koe/AqKanji2Koe.h>
#include "portaudio.h"
#else
#include "AquesTalk2.h"
#include "AqKanji2Koe.h"
#include "portaudio.h"
#endif

const QString QMAAquesTalk2Plugin::kAquesTalk2Start = "MMDAI_AQTK2_START";
const QString QMAAquesTalk2Plugin::kAquesTalk2RawStart = "MMDAI_AQTK2_START_RAW";
const QString QMAAquesTalk2Plugin::kAquesTalk2EventStart = "MMDAI_AQTK2_EVENT_START";
const QString QMAAquesTalk2Plugin::kAquesTalk2EventStop = "MMDAI_AQTK2_EVENT_STOP";

QMAAquesTalk2Plugin::QMAAquesTalk2Plugin(QObject *parent)
: QMAPlugin(parent)
{
}

QMAAquesTalk2Plugin::~QMAAquesTalk2Plugin()
{
}

void QMAAquesTalk2Plugin::load(MMDAI::SceneController *controller, const QString &baseName)
{
    Q_UNUSED(controller);
    Q_UNUSED(baseName);
#if !defined(Q_OS_WIN32)
    PaError err = Pa_Initialize();
    if (err != paNoError)
        MMDAILogWarn("Pa_Initialized failed: %s", Pa_GetErrorText(err));
#endif
}

void QMAAquesTalk2Plugin::unload()
{
#if !defined(Q_OS_WIN32)
    PaError err = Pa_Terminate();
    if (err != paNoError)
        MMDAILogWarn("Pa_Terminate failed: %s", Pa_GetErrorText(err));
#endif
}

void QMAAquesTalk2Plugin::receiveCommand(const QString &command, const QList<QVariant> &arguments)
{
    int argc = arguments.count();
    if ((command == kAquesTalk2Start || command == kAquesTalk2RawStart) && argc >= 3) {
        QString text = arguments[2].toString();
        QString phontPath = arguments[1].toString();
        QString modelName = arguments[0].toString();
        bool convert = command == kAquesTalk2Start;
        phontPath = QDir::isAbsolutePath(phontPath) ? phontPath : ("MMDAIResources:/" + phontPath);
        QtConcurrent::run(this, &QMAAquesTalk2Plugin::run, modelName, phontPath, text, convert);
    }
}

void QMAAquesTalk2Plugin::receiveEvent(const QString &type, const QList<QVariant> &arguments)
{
    Q_UNUSED(type);
    Q_UNUSED(arguments);
    /* do nothing */
}

void QMAAquesTalk2Plugin::run(const QString &modelName, const QString &phontPath, const QString &text, bool convert)
{
    QFile phontFile(phontPath);
    QByteArray phont;
    char *ptr = 0;
    if (phontFile.exists() && phontFile.open(QIODevice::ReadOnly | QIODevice::Unbuffered)) {
        phont = phontFile.readAll();
        ptr = phont.data();
    }

    int rc = 0;
    char result[8192];
    QTextCodec *codec = QTextCodec::codecForName("Shift-JIS");
    if (convert) {
        const QString dicPath = QDir("MMDAIResources:/").absoluteFilePath("aq_dic");
        void *handle = AqKanji2Koe_Create(dicPath.toUtf8().constData(), &rc);
        if (handle == 0) {
            MMDAILogWarn("AqKanji2Koe_Create failed: %d", rc);
            return;
        }
        rc = AqKanji2Koe_Convert(handle, codec->fromUnicode(text).constData(), result, sizeof(result));
        AqKanji2Koe_Release(handle);
        if (rc != 0) {
            MMDAILogWarn("AqKanji2Koe_Convert failed: %d", rc);
            return;
        }
    }
    else {
        MMDAIStringCopySafe(result,  codec->fromUnicode(text).constData(), sizeof(result));
    }

    QList<QVariant> arguments;
    arguments << modelName;
    emit eventPost(kAquesTalk2EventStart, arguments);

#if defined(Q_OS_WIN32)
    rc = AquesTalk2Da_PlaySync(result, 100, ptr);
    if (rc != 0) {
        MMDAILogWarn("AquesTalk2Da_PlaySync failed: %d", rc);
        return;
    }
#else
    int size = 0;
    unsigned char *data = AquesTalk2_Synthe(result, 100, &size, ptr);
    if (data != NULL) {
        PaError err;
        PaStream *stream;
        PaStreamParameters output;
        output.device = Pa_GetDefaultOutputDevice();
        if (output.device == paNoDevice) {
            MMDAILogWarnString("No device to output found");
            goto final;
        }
        output.channelCount = 1;
        output.sampleFormat = paInt16;
        output.suggestedLatency = Pa_GetDeviceInfo(output.device)->defaultLowOutputLatency;
        output.hostApiSpecificStreamInfo = NULL;
        err = Pa_OpenStream(&stream, NULL, &output, 8000, 1024, paClipOff, NULL, NULL);
        if (err != paNoError) {
            MMDAILogWarn("Pa_OpenStream failed: %s", Pa_GetErrorText(err));
            goto final;
        }
        if (stream != NULL) {
            err = Pa_StartStream(stream);
            if (err != paNoError) {
                MMDAILogWarn("Pa_StartStream failed: %s", Pa_GetErrorText(err));
                goto final;
            }
            err = Pa_WriteStream(stream, data + 44, (size - 44) / sizeof(short));
            if (err != paNoError) {
                MMDAILogWarn("Pa_WriteStream failed: %s", Pa_GetErrorText(err));
                goto final;
            }
            err = Pa_CloseStream(stream);
            if (err != paNoError) {
                MMDAILogWarn("Pa_StartStream failed: %s", Pa_GetErrorText(err));
                goto final;
            }
        }
final:
        AquesTalk2_FreeWave(data);
    }
#endif

    arguments.clear();
    arguments << modelName;
    emit eventPost(kAquesTalk2EventStop, arguments);
}

Q_EXPORT_PLUGIN2(qma_aquestalk2_plugin, QMAAquesTalk2Plugin)
