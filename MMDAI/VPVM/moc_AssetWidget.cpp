/****************************************************************************
** Meta object code from reading C++ file 'AssetWidget.h'
**
** Created: Tue Jul 16 12:41:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/AssetWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AssetWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__AssetWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   19,   18,   18, 0x05,
      57,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      89,   19,   18,   18, 0x0a,
     115,   19,   18,   18, 0x0a,
     150,  144,   18,   18, 0x0a,
     176,  144,   18,   18, 0x0a,
     205,   18,   18,   18, 0x0a,
     219,   18,   18,   18, 0x08,
     246,  240,   18,   18, 0x08,
     270,   19,   18,   18, 0x08,
     306,  240,   18,   18, 0x08,
     330,  240,   18,   18, 0x08,
     358,  352,   18,   18, 0x08,
     382,  352,   18,   18, 0x08,
     406,  352,   18,   18, 0x08,
     430,   18,   18,   18, 0x08,
     447,  352,   18,   18, 0x08,
     473,  352,   18,   18, 0x08,
     495,   19,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__AssetWidget[] = {
    "vpvm::AssetWidget\0\0asset\0"
    "assetDidSelect(IModelSharedPtr)\0"
    "assetDidRemove(IModelSharedPtr)\0"
    "addAsset(IModelSharedPtr)\0"
    "removeAsset(IModelSharedPtr)\0model\0"
    "addModel(IModelSharedPtr)\0"
    "removeModel(IModelSharedPtr)\0retranslate()\0"
    "deleteCurrentAsset()\0index\0"
    "changeCurrentAsset(int)\0"
    "changeCurrentAsset(IModelSharedPtr)\0"
    "changeCurrentModel(int)\0changeParentBone(int)\0"
    "value\0updatePositionX(double)\0"
    "updatePositionY(double)\0updatePositionZ(double)\0"
    "updateRotation()\0updateScaleFactor(double)\0"
    "updateOpacity(double)\0"
    "setAssetProperties(IModelSharedPtr)\0"
};

void vpvm::AssetWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AssetWidget *_t = static_cast<AssetWidget *>(_o);
        switch (_id) {
        case 0: _t->assetDidSelect((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        case 1: _t->assetDidRemove((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        case 2: _t->addAsset((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        case 3: _t->removeAsset((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        case 4: _t->addModel((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        case 5: _t->removeModel((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        case 6: _t->retranslate(); break;
        case 7: _t->deleteCurrentAsset(); break;
        case 8: _t->changeCurrentAsset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->changeCurrentAsset((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        case 10: _t->changeCurrentModel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->changeParentBone((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->updatePositionX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->updatePositionY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->updatePositionZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->updateRotation(); break;
        case 16: _t->updateScaleFactor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->updateOpacity((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->setAssetProperties((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::AssetWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::AssetWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vpvm__AssetWidget,
      qt_meta_data_vpvm__AssetWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::AssetWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::AssetWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::AssetWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__AssetWidget))
        return static_cast<void*>(const_cast< AssetWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int vpvm::AssetWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void vpvm::AssetWidget::assetDidSelect(IModelSharedPtr _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::AssetWidget::assetDidRemove(IModelSharedPtr _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
