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

#include "MMDAI/MMDAI.h"
#include "QMAWindow.h"

#include "QMAPreference.h"
#include "QMAScenePlayer.h"
#include "QMAScenePreview.h"
#include "QMALogViewWidget.h"
#include "QMALicenseWidget.h"

QMAWindow::QMAWindow(QWidget *parent) :
    QMainWindow(parent),
    m_settings(QSettings::IniFormat, QSettings::UserScope, "MMDAI", "QtMMDAI"),
    m_licenseWidget(0),
    m_isFullScreen(false)
{
    m_settings.setIniCodec("UTF-8");
#ifdef Q_OS_MAC
    m_menuBar = new QMenuBar(0);
#else
    m_menuBar = menuBar();
#endif
    m_logWidget = new QMALogViewWidget;
    m_preference = new QMAPreference(&m_settings);
    m_scene = new QMAScenePlayer(m_preference, parent);

    createActions();
    createMenu(m_menuBar);
    mergeMenu();

    setCentralWidget(m_scene);
    setWindowTitle(qAppName());
    setMinimumSize(640, 480);
    statusBar()->showMessage("");

    readSetting();
}

QMAWindow::~QMAWindow()
{
    delete m_preference;
    delete m_scene;
    delete m_logWidget;
    delete m_licenseWidget;
}

void QMAWindow::initialize()
{
    m_scene->initialize();
}

void QMAWindow::loadPlugins()
{
    m_scene->loadPlugins();
}

void QMAWindow::start()
{
    m_scene->start();
}

void QMAWindow::reload(const QString &filename)
{
    m_scene->reload(filename);
}

void QMAWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_D: /* Debug */
        break;
    case Qt::Key_S: /* info String */
        break;
    case Qt::Key_V: /* test command / Vsync */
        break;
    }
    QList<QVariant> arguments;
    arguments << event->text();
    m_scene->delegateEvent(QString(MMDAI::ISceneEventHandler::kKeyEvent), arguments);
}

void QMAWindow::closeEvent(QCloseEvent *event)
{
    writeSetting();
    event->accept();
}

void QMAWindow::showLogWindow()
{
    m_logWidget->show();
}

void QMAWindow::resizeScene()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action) {
        QSize size = action->data().toSize();
        m_scene->resize(size);
        resize(size);
    }
}

void QMAWindow::toggleFullScreen()
{
    if (m_isFullScreen) {
        showNormal();
        statusBar()->show();
        m_isFullScreen = false;
    }
    else {
        statusBar()->hide();
        showFullScreen();
        m_isFullScreen = true;
    }
}

void QMAWindow::about()
{
    if (!m_licenseWidget)
        m_licenseWidget = new QMALicenseWidget;
    m_licenseWidget->show();
}

void QMAWindow::receiveEvent(const QString &type, const QList<QVariant> &arguments)
{
    Q_UNUSED(arguments);
    if (type == QMAPlugin::getUpdateEvent()) {
        double fps = m_scene->getSceneFrameTimer().getFramePerSecond();
        setWindowTitle(QString("%1 - (FPS: %2)").arg(qAppName()).arg(fps, 0, 'f', 1));
    }
}

void QMAWindow::createActions()
{
    QAction *action = NULL;

    action = new QAction(tr("Show log"), this);
    action->setStatusTip(tr("Open log window"));
    action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_L));
    connect(action, SIGNAL(triggered()), this, SLOT(showLogWindow()));
    m_showLogAction = action;

    action = new QAction(tr("Toggle fullscreen"), this);
    action->setStatusTip(tr("Enable / Disable fullscreen."));
    action->setShortcut(Qt::Key_F);
    connect(action, SIGNAL(triggered()), this, SLOT(toggleFullScreen()));
    m_toggleFullScreenAction = action;

    const char *message = QT_TR_NOOP("Resize scene to %1x%2");
    const char *description = QT_TR_NOOP("Set the width of the scene to %1px and the height of the scene to %2px.");

    action = new QAction(tr(message).arg(640).arg(480), this);
    action->setStatusTip(tr(description).arg(640).arg(480));
    action->setData(QSize(640, 480));
    connect(action, SIGNAL(triggered()), this, SLOT(resizeScene()));
    m_resize640x480Action = action;

    action = new QAction(tr(message).arg(800).arg(480), this);
    action->setStatusTip(tr(description).arg(800).arg(480));
    action->setData(QSize(800, 480));
    connect(action, SIGNAL(triggered()), this, SLOT(resizeScene()));
    m_resize800x480Action = action;

    action = new QAction(tr(message).arg(1024).arg(768), this);
    action->setStatusTip(tr(description).arg(1024).arg(768));
    action->setData(QSize(1024, 768));
    connect(action, SIGNAL(triggered()), this, SLOT(resizeScene()));
    m_resize1024x768Action = action;

    action = new QAction(tr(message).arg(1280).arg(800), this);
    action->setStatusTip(tr(description).arg(1280).arg(800));
    action->setData(QSize(1280, 800));
    connect(action, SIGNAL(triggered()), this, SLOT(resizeScene()));
    m_resize1280x800Action = action;

    action = new QAction(tr("E&xit"), this);
    action->setMenuRole(QAction::QuitRole);
    action->setShortcuts(QKeySequence::Quit);
    action->setStatusTip(tr("Exit the application."));
    connect(action, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    m_exitAction = action;

    QList<QKeySequence> shortcuts;
    shortcuts.append(QKeySequence(Qt::ALT + Qt::Key_Question));
    shortcuts.append(QKeySequence(Qt::ALT + Qt::Key_Slash));
    action = new QAction(tr("&About"), this);
    action->setMenuRole(QAction::AboutRole);
    action->setStatusTip(tr("Show the application's About box."));
    action->setShortcuts(shortcuts);
    connect(action, SIGNAL(triggered()), this, SLOT(about()));
    m_aboutAction = action;

    action = new QAction(tr("About &Qt"), this);
    action->setMenuRole(QAction::AboutQtRole);
    action->setStatusTip(tr("Show the Qt library's About box."));
    connect(action, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    m_aboutQtAction = action;

    connect(m_scene, SIGNAL(pluginEventPost(QString,QList<QVariant>)),
            this, SLOT(receiveEvent(QString,QList<QVariant>)));
}

void QMAWindow::createMenu(QMenuBar *menubar)
{
    m_menu.insert("File", menubar->addMenu(tr("&File")));
    menubar->addSeparator();
    m_menu.insert("Scene", menubar->addMenu(tr("&Scene")));
    menubar->addSeparator();
    m_menu.insert("Window", menubar->addMenu(tr("&Window")));
    menubar->addSeparator();
    m_menu.insert("Model", menubar->addMenu(tr("&Model")));
    menubar->addSeparator();
    m_menu.insert("Help", menubar->addMenu(tr("&Help")));
}

void QMAWindow::mergeMenu()
{
    m_scene->createMenu(m_menu);
    QMenu *fileMenu = m_menu["File"];
    fileMenu->addSeparator();
    fileMenu->addAction(m_showLogAction);
    fileMenu->addSeparator();
    fileMenu->addAction(m_exitAction);
    QMenu *windowMenu = m_menu["Window"];
    windowMenu->addAction(m_toggleFullScreenAction);
    windowMenu->addSeparator();
    windowMenu->addAction(m_resize640x480Action);
    windowMenu->addAction(m_resize800x480Action);
    windowMenu->addAction(m_resize1024x768Action);
    windowMenu->addAction(m_resize1280x800Action);
    QMenu *helpMenu = m_menu["Help"];
    helpMenu->addAction(m_aboutAction);
    helpMenu->addAction(m_aboutQtAction);
}

void QMAWindow::readSetting()
{
    m_settings.beginGroup("window");
    restoreGeometry(m_settings.value("geometry").toByteArray());
    restoreState(m_settings.value("state").toByteArray());
    m_settings.endGroup();
}

void QMAWindow::writeSetting()
{
    m_settings.beginGroup("window");
    m_settings.setValue("geometry", saveGeometry());
    m_settings.setValue("state", saveState());
    m_settings.endGroup();
}
