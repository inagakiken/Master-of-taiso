#include <QtCore/QtCore>
#include <QtGui/QImage>
#include <vpvl/vpvl.h>

static const QString kTextureTool = "/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/texturetool";

static int showUsage()
{
    fprintf(stderr, "Usage: pvrtc [sourcedir] [destdir] [filename]\n");
    return -1;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Q_UNUSED(a);

    if (argc != 4)
        return showUsage();
    const QDir source(argv[1]), dest(argv[2]);
    if (!source.isReadable() || !dest.isReadable())
        return showUsage();
    const QString &filename = argv[3];
    QFile file(source.absoluteFilePath(filename));
    if (file.isReadable())
        return showUsage();

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    if (file.open(QFile::ReadOnly)) {
        const QByteArray &bytes = file.readAll();
        vpvl::PMDModel model;
        if (model.load(reinterpret_cast<const uint8_t *>(bytes.constData()), bytes.size())) {
            const vpvl::MaterialList &materials = model.materials();
            int nmaterials = materials.count();
            for (int i = 0; i < nmaterials; i++) {
                vpvl::Material *material = materials[i];
                const QString main(reinterpret_cast<const char *>(material->mainTextureName())),
                              sub(reinterpret_cast<const char *>(material->subTextureName()));
                if (main.isEmpty() && sub.isEmpty())
                    continue;
                if (sub.endsWith(".sph") || sub.endsWith(".spa"))
                    QFile::copy(source.absoluteFilePath(sub), dest.absoluteFilePath(sub));
                QImage mainTexture(source.absoluteFilePath(main));
                QString png = main;
                png.replace(".bmp", ".png");
                if (mainTexture.width() > 512 && mainTexture.height() > 512)
                    mainTexture = mainTexture.scaled(512, 512, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                mainTexture.save(dest.absoluteFilePath(png));
                QString pvr = main;
                pvr.replace(".bmp", ".pvr");
                pvr.replace(".png", ".pvr");
                QProcess process;
                QStringList args;
                if (!QFile::exists(dest.absoluteFilePath(pvr))) {
                    args << "--bits-per-pixel-2";
                    args << "--channel-weighting-perceptual";
                    args << "--alpha-is-opacity";
                    args << "-e";
                    args << "PVRTC";
                    args << "-o";
                    args << dest.absoluteFilePath(pvr);
                    args << "-f";
                    args << "PVR";
                    args << dest.absoluteFilePath(png);
                    int ret = process.execute(kTextureTool, args);
                    qDebug() << args << ret;
                    if (ret == 0) {
                        QByteArray bytes = codec->fromUnicode(pvr);
                        material->setMainTextureName(reinterpret_cast<const uint8_t *>(bytes.constData()));
                    }
                }
                else {
                    QByteArray bytes = codec->fromUnicode(pvr);
                    material->setMainTextureName(reinterpret_cast<const uint8_t *>(bytes.constData()));
                }
            }
            QByteArray newBytes;
            newBytes.resize(model.estimateSize());
            model.save(reinterpret_cast<uint8_t *>(newBytes.data()));
            QFile newFile(dest.absoluteFilePath(filename));
            newFile.open(QFile::WriteOnly);
            newFile.write(newBytes);
        }
        else {
            qWarning() << "Error at loading model:" << model.error();
        }
    }
    else {
        qWarning() << "Error at opening file:" << file.errorString();
    }

    return 0;
}
