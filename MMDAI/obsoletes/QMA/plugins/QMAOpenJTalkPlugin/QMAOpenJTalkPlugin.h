/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2009-2011  Nagoya Institute of Technology          */
/*                           Department of Computer Science          */
/*                2010-2011  hkrn                                    */
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

#ifndef QMAOPENJTALKPLUGIN_H
#define QMAOPENJTALKPLUGIN_H

#include <QtCore/QByteArray>
#include <QtCore/QFutureWatcher>
#include <QtCore/QIODevice>
#include <QtCore/QTimer>
#include "portaudio.h"

#include "QMAPlugin.h"

#include "QMAOpenJTalkModel.h"

class QMAOpenJTalkPlugin : public QMAPlugin
{
    Q_OBJECT
    Q_INTERFACES(QMAPlugin)

public:
    static const QString kSynthEventStart;
    static const QString kSynthEventStop;
    static const QString kLipSyncStart;
    static const QString kLipSyncStop;

    QMAOpenJTalkPlugin(QObject *parent = 0);
    ~QMAOpenJTalkPlugin();

public slots:
    void load(MMDAI::SceneController *controller, const QString &baseName);
    void unload();
    void receiveCommand(const QString &command, const QList<QVariant> &arguments);
    void receiveEvent(const QString &type, const QList<QVariant> &arguments);

signals:
    void commandPost(const QString &command, const QList<QVariant> &arguments);
    void eventPost(const QString &type, const QList<QVariant> &arguments);

private:
    void run(const QString &name,
             const QString &style,
             const QString &text);

    QHash<QString, QMAOpenJTalkModel*> m_models;
    QTimer m_timer;
    QString m_base;
    QString m_dir;
    QString m_config;

    Q_DISABLE_COPY(QMAOpenJTalkPlugin)
};

#endif // QMAOPENJTALKPLUGIN_H
