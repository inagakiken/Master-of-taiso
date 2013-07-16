/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Tue Jul 16 13:05:14 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      51,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   18,   17,   17, 0x05,
      58,   49,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      81,   17,   17,   17, 0x08,
      99,   17,   17,   17, 0x08,
     115,   17,   17,   17, 0x08,
     132,   17,   17,   17, 0x08,
     146,   17,   17,   17, 0x08,
     159,   17,   17,   17, 0x08,
     174,   17,   17,   17, 0x08,
     195,   17,   17,   17, 0x08,
     209,   17,   17,   17, 0x08,
     225,   17,   17,   17, 0x08,
     245,  239,   17,   17, 0x08,
     278,   17,   17,   17, 0x08,
     300,   17,   17,   17, 0x08,
     334,  317,   17,   17, 0x08,
     362,   17,   17,   17, 0x08,
     382,   17,   17,   17, 0x08,
     412,  401,   17,   17, 0x08,
     444,  401,   17,   17, 0x08,
     490,  479,   17,   17, 0x08,
     522,  479,   17,   17, 0x08,
     557,   17,   17,   17, 0x08,
     583,   17,   17,   17, 0x08,
     613,   17,   17,   17, 0x08,
     635,   17,   17,   17, 0x08,
     651,   17,   17,   17, 0x08,
     671,   17,   17,   17, 0x08,
     685,   17,   17,   17, 0x08,
     699,   17,   17,   17, 0x08,
     721,   17,   17,   17, 0x08,
     761,  742,   17,   17, 0x08,
     794,   17,   17,   17, 0x08,
     809,   17,   17,   17, 0x08,
     824,   17,   17,   17, 0x08,
     848,   17,   17,   17, 0x08,
     866,   17,   17,   17, 0x08,
     888,   17,   17,   17, 0x08,
     908,   17,   17,   17, 0x08,
     935,   17,   17,   17, 0x08,
     959,   17,   17,   17, 0x08,
     983,   17,   17,   17, 0x08,
    1005,   17,   17,   17, 0x08,
    1033,   17,   17,   17, 0x08,
    1048,   17,   17,   17, 0x08,
    1080,   17,   17,   17, 0x08,
    1107,   17,   17,   17, 0x08,
    1152, 1134,   17,   17, 0x08,
    1194, 1179,   17,   17, 0x08,
    1232, 1226,   17,   17, 0x08,
    1261,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__MainWindow[] = {
    "vpvm::MainWindow\0\0image\0"
    "sceneDidRendered(QImage)\0timestep\0"
    "sceneDidUpdate(Scalar)\0bindSceneLoader()\0"
    "newMotionFile()\0newProjectFile()\0"
    "loadProject()\0saveMotion()\0saveMotionAs()\0"
    "saveCameraMotionAs()\0saveProject()\0"
    "saveProjectAs()\0selectModel()\0model\0"
    "setCurrentModel(IModelSharedPtr)\0"
    "revertSelectedModel()\0openRecentFile()\0"
    "filename,didLoad\0addRecentFile(QString,bool)\0"
    "updateRecentFiles()\0clearRecentFiles()\0"
    "model,uuid\0addModel(IModelSharedPtr,QUuid)\0"
    "deleteModel(IModelSharedPtr,QUuid)\0"
    "asset,uuid\0addAsset(IModelSharedPtr,QUuid)\0"
    "deleteAsset(IModelSharedPtr,QUuid)\0"
    "insertMotionToAllModels()\0"
    "insertMotionToSelectedModel()\0"
    "deleteSelectedModel()\0saveModelPose()\0"
    "saveAssetMetadata()\0exportImage()\0"
    "exportVideo()\0invokeImageExporter()\0"
    "invokeVideoEncoder()\0image,width,height\0"
    "renderVideoFrame(QImage,int,int)\0"
    "addNewMotion()\0invokePlayer()\0"
    "openPlaySettingDialog()\0selectNextModel()\0"
    "selectPreviousModel()\0showLicenseWidget()\0"
    "openPhysicsSettingDialog()\0"
    "openRenderOrderDialog()\0openScreenColorDialog()\0"
    "openShadowMapDialog()\0openBackgroundImageDialog()\0"
    "openUndoView()\0enableSelectingBonesAndMorphs()\0"
    "resetSceneToMotionModels()\0"
    "disconnectInitialSignals()\0title,cancellable\0"
    "openProgress(QString,bool)\0value,max,text\0"
    "updateProgress(int,int,QString)\0title\0"
    "updateProgressTitle(QString)\0"
    "closeProgress()\0"
};

void vpvm::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->sceneDidRendered((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->sceneDidUpdate((*reinterpret_cast< const Scalar(*)>(_a[1]))); break;
        case 2: _t->bindSceneLoader(); break;
        case 3: _t->newMotionFile(); break;
        case 4: _t->newProjectFile(); break;
        case 5: _t->loadProject(); break;
        case 6: _t->saveMotion(); break;
        case 7: _t->saveMotionAs(); break;
        case 8: _t->saveCameraMotionAs(); break;
        case 9: _t->saveProject(); break;
        case 10: _t->saveProjectAs(); break;
        case 11: _t->selectModel(); break;
        case 12: _t->setCurrentModel((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        case 13: _t->revertSelectedModel(); break;
        case 14: _t->openRecentFile(); break;
        case 15: _t->addRecentFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 16: _t->updateRecentFiles(); break;
        case 17: _t->clearRecentFiles(); break;
        case 18: _t->addModel((*reinterpret_cast< IModelSharedPtr(*)>(_a[1])),(*reinterpret_cast< const QUuid(*)>(_a[2]))); break;
        case 19: _t->deleteModel((*reinterpret_cast< IModelSharedPtr(*)>(_a[1])),(*reinterpret_cast< const QUuid(*)>(_a[2]))); break;
        case 20: _t->addAsset((*reinterpret_cast< IModelSharedPtr(*)>(_a[1])),(*reinterpret_cast< const QUuid(*)>(_a[2]))); break;
        case 21: _t->deleteAsset((*reinterpret_cast< IModelSharedPtr(*)>(_a[1])),(*reinterpret_cast< const QUuid(*)>(_a[2]))); break;
        case 22: _t->insertMotionToAllModels(); break;
        case 23: _t->insertMotionToSelectedModel(); break;
        case 24: _t->deleteSelectedModel(); break;
        case 25: _t->saveModelPose(); break;
        case 26: _t->saveAssetMetadata(); break;
        case 27: _t->exportImage(); break;
        case 28: _t->exportVideo(); break;
        case 29: _t->invokeImageExporter(); break;
        case 30: _t->invokeVideoEncoder(); break;
        case 31: _t->renderVideoFrame((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 32: _t->addNewMotion(); break;
        case 33: _t->invokePlayer(); break;
        case 34: _t->openPlaySettingDialog(); break;
        case 35: _t->selectNextModel(); break;
        case 36: _t->selectPreviousModel(); break;
        case 37: _t->showLicenseWidget(); break;
        case 38: _t->openPhysicsSettingDialog(); break;
        case 39: _t->openRenderOrderDialog(); break;
        case 40: _t->openScreenColorDialog(); break;
        case 41: _t->openShadowMapDialog(); break;
        case 42: _t->openBackgroundImageDialog(); break;
        case 43: _t->openUndoView(); break;
        case 44: _t->enableSelectingBonesAndMorphs(); break;
        case 45: _t->resetSceneToMotionModels(); break;
        case 46: _t->disconnectInitialSignals(); break;
        case 47: _t->openProgress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 48: _t->updateProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 49: _t->updateProgressTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 50: _t->closeProgress(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_vpvm__MainWindow,
      qt_meta_data_vpvm__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int vpvm::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 51)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 51;
    }
    return _id;
}

// SIGNAL 0
void vpvm::MainWindow::sceneDidRendered(const QImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::MainWindow::sceneDidUpdate(const Scalar & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
