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

#include "LoggerWidget.h"

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets/QtWidgets>
#else
#include <QtGui/QtGui>
#endif

namespace {
QScopedPointer<vpvm::LoggerWidget> g_instance;
}

namespace vpvm
{

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
static void LoggerWidgetHandleMessage(QtMsgType /* type */, const QMessageLogContext & /* context */, const QString &message)
#else
static void LoggerWidgetHandleMessage(QtMsgType /* type */, const char *message)
#endif
{
    QString datetime = QDateTime::currentDateTime().toString(Qt::ISODate);
    g_instance->addMessage(datetime + " " + message);
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    fprintf(stderr, "%s %s\n", qPrintable(datetime), qPrintable(message));
#else
    fprintf(stderr, "%s %s\n", qPrintable(datetime), message);
#endif
}

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
static void LoggerWidgetHandleMessageNULL(QtMsgType /* type */, const QMessageLogContext & /* context */, const QString & /* message */)
#else
static void LoggerWidgetHandleMessageNULL(QtMsgType /* type */, const char * /* message */)
#endif
{
}

LoggerWidget *LoggerWidget::sharedInstance(QSettings *settings)
{
    if (!g_instance)
        g_instance.reset(new LoggerWidget(settings));
    return g_instance.data();
}

void LoggerWidget::quietLogMessages(bool value)
{
    if (value) {
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
        qInstallMessageHandler(LoggerWidgetHandleMessageNULL);
#else
        qInstallMsgHandler(LoggerWidgetHandleMessageNULL);
#endif
    }
    else {
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
        qInstallMessageHandler(LoggerWidgetHandleMessage);
#else
        qInstallMsgHandler(LoggerWidgetHandleMessage);
#endif
    }
}

LoggerWidget::LoggerWidget(QSettings *settings, QWidget *parent)
    : QWidget(parent),
      m_settings(settings),
      m_textEdit(0)
{
    Q_ASSERT(g_instance == 0);
    m_textEdit = new QTextEdit();
    m_textEdit->setReadOnly(true);
    m_textEdit->setLineWrapMode(QTextEdit::NoWrap);
    QVBoxLayout *layout = new QVBoxLayout();
    QHBoxLayout *hlayout = new QHBoxLayout();
    QPushButton *clearButton = new QPushButton(tr("Clear"));
    connect(clearButton, SIGNAL(clicked()), this, SLOT(clear()));
    QPushButton *saveButton = new QPushButton(tr("Save"));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
    hlayout->addWidget(saveButton);
    hlayout->addWidget(clearButton);
    layout->addLayout(hlayout);
    layout->addWidget(m_textEdit);
    layout->setMargin(10);
    setLayout(layout);
    setWindowTitle(tr("Log Window"));
    resize(QSize(640, 480));
    connect(this, SIGNAL(messageDidAdd(QString)), m_textEdit, SLOT(append(QString)));
}

LoggerWidget::~LoggerWidget()
{
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    qInstallMessageHandler(0);
#else
    qInstallMsgHandler(0);
#endif
}

void LoggerWidget::addMessage(const QString &message)
{
    emit messageDidAdd(message);
}

void LoggerWidget::save()
{
    const QString &name = "loggerWidget/lastLogDirectory";
    const QString &path = m_settings->value(name).toString();
    const QString &content = m_textEdit->toPlainText();
    const QString &filename = QFileDialog::getSaveFileName(this,
                                                           tr("Save script log"),
                                                           path,
                                                           tr("Log file (*.log)"));
    if (!filename.isEmpty()) {
        QDir dir(filename);
        dir.cdUp();
        m_settings->setValue(name, dir.absolutePath());
        QFile file(filename);
        if (file.open(QFile::WriteOnly))
            file.write(content.toUtf8());
    }
}

void LoggerWidget::clear()
{
    m_textEdit->clear();
}

} /* namespace vpvm */
