#include "QMALicenseWidget.h"

#include <QtGui>

QMALicenseWidget::QMALicenseWidget(QWidget *parent) :
    QWidget(parent),
    m_text(0)
{
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *copyrightLabel = new QLabel;
    copyrightLabel->setText(tr("<h3>%1 %2+beta (Aloe)</h3>"
                               "Copyright (C) 2010-2011 "
                               "Nagoya Institute of Technology Department of Computer Science (MMDAgent), "
                               "hkrn (MMDAI) All rights reserved."
                               "<br><br>"
                               "Below table is a list of libraries MMDAI uses. "
                               "Double click a row to show the license text or open the website")
                            .arg(qApp->applicationName())
                            .arg(qApp->applicationVersion()));
    copyrightLabel->setWordWrap(true);
    layout->addWidget(copyrightLabel);
    QTreeView *tree = new QTreeView;
    QAbstractItemModel *model = new QStandardItemModel(0, 3);
    model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("License"));
    model->setHeaderData(2, Qt::Horizontal, tr("Website"));
    connect(tree, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(handleDoubleClick(QModelIndex)));
    tree->setRootIsDecorated(false);
    tree->setAlternatingRowColors(true);
    tree->setModel(model);
    tree->setEditTriggers(QTreeView::NoEditTriggers);
    layout->addWidget(tree);
    QLabel *aboutIconLabel = new QLabel;
    aboutIconLabel->setText(
                tr("%1's icon was generated with <a href='http://innoce.nobody.jp/'>Lat's Miku model</a>"
                   " and <a href='http://www.nicovideo.jp/watch/sm14177985'>Miku's love song motion</a>").arg(qApp->applicationName()));
    aboutIconLabel->setWordWrap(true);
    aboutIconLabel->setOpenExternalLinks(true);
    aboutIconLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    layout->addWidget(aboutIconLabel);
    setWindowTitle(QString(tr("About %1")).arg(qApp->applicationName()));
    resize(600, 450);
    setLayout(layout);
    m_model = model;

#ifdef QMA_BUNDLE_AQUESTALK2_PLUGIN
    addLibrary("AqKanji2Koe", "(proprietary)", "http://www.a-quest.com", "AquesTalk");
    addLibrary("AquesTalk2", "(proprietary)", "http://www.a-quest.com", "AquesTalk");
#endif
    addLibrary("PortAudio", "MIT/X11", "http://portaudio.com", "PortAudio");
    addLibrary("MeCab", "GPL/LGPL/New BSD", "http://mecab.sf.net", "mecab");
    addLibrary("hts_engine API", "New BSD", "http://hts-engine.sf.net", "HTSEngine");
    addLibrary("Open JTalk", "New BSD", "http://open-jtalk.sf.net", "OpenJTalk");
    addLibrary("Julius", "New BSD", "http://julius.sourceforge.jp", "Julius");
    addLibrary("OpenGL Easy Extension", "New BSD", "http://elf-stone.com/glee.php", "GLEE");
    addLibrary("Bullet Physics Library", "Zlib", "http://bulletphysics.org", "Bullet");
    addLibrary("Qt", "GPL/LGPL", "http://qt.nokia.com", "Qt");
    addLibrary("MMDAgent", "New BSD", "http://mmdagent.jp", "MMDAgent");
    addLibrary("MMDAI", "New BSD", "https://github.com/hkrn/MMDAI/", "MMDAI");
}

QMALicenseWidget::~QMALicenseWidget()
{
}

void QMALicenseWidget::addLibrary(const QString &name,
                                  const QString &license,
                                  const QString &website,
                                  const QString &path)
{
    m_path.insert(name, path);
    m_model->insertRow(0);
    m_model->setData(m_model->index(0, 0), name);
    m_model->setData(m_model->index(0, 1), license);
    m_model->setData(m_model->index(0, 2), website);
}


void QMALicenseWidget::handleDoubleClick(const QModelIndex &index)
{
    QVariant value;
    switch (index.column()) {
    case 0: // name
    case 1: // license
    {
        QString license = m_model->data(index).toString();
        QString name = m_model->data(m_model->index(index.row(), 0)).toString();
        QFile file(QString(":/licenses/%1").arg(m_path[name]));
        if (file.exists() && file.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream stream(&file);
            if (!m_text)
                m_text = new QTextEdit;
            m_text->setWindowTitle(tr("%1's license").arg(name));
            m_text->setReadOnly(true);
            m_text->setHtml(QString("<pre>%1</pre>").arg(stream.readAll()));
            m_text->resize(600, 500);
            m_text->setLineWrapMode(QTextEdit::NoWrap);
            m_text->show();
        }
        break;
    }
    case 2: // website
        value = m_model->data(index);
        QDesktopServices::openUrl(value.toString());
        break;
    }
}
