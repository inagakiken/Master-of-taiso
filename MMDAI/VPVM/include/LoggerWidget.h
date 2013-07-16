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


#ifndef VPVM_LOGGERWIDGET_H_
#define VPVM_LOGGERWIDGET_H_

#include <QStringList>
#include <QTextEdit>
#include <QWidget>

class QSettings;
class QTextEdit;

namespace vpvm
{

class LoggerWidget : public QWidget
{
    Q_OBJECT

public:
    static LoggerWidget *sharedInstance(QSettings *settings);
    static void quietLogMessages(bool value);

    ~LoggerWidget();

    void addMessage(const QString &message);

signals:
    void messageDidAdd(const QString &message);

private slots:
    void save();
    void clear();

private:
    explicit LoggerWidget(QSettings *settings, QWidget *parent = 0);

    QSettings *m_settings;
    QTextEdit *m_textEdit;

    Q_DISABLE_COPY(LoggerWidget)
};

} /* namespace vpvm */

#endif // VPVM_LOGGERWIDGET_H
