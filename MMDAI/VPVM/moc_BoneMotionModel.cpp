/****************************************************************************
** Meta object code from reading C++ file 'BoneMotionModel.h'
**
** Created: Tue Jul 16 12:41:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/BoneMotionModel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BoneMotionModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__BoneMotionModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      41,   23,   22,   22, 0x05,
      96,   78,   22,   22, 0x05,
     139,  133,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     177,  169,   22,   22, 0x0a,
     221,  169,   22,   22, 0x0a,
     268,  169,   22,   22, 0x0a,
     311,   22,   22,   22, 0x0a,
     325,   22,   22,   22, 0x0a,
     346,  340,   22,   22, 0x0a,
     388,  375,   22,   22, 0x0a,
     450,  433,   22,   22, 0x0a,
     498,  481,   22,   22, 0x0a,
     556,  533,   22,   22, 0x0a,
     588,  133,   22,   22, 0x0a,
     615,   22,   22,   22, 0x0a,
     631,   22,   22,   22, 0x0a,
     656,  649,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__BoneMotionModel[] = {
    "vpvm::BoneMotionModel\0\0bone,lastPosition\0"
    "translationDidChange(IBone*,Vector3)\0"
    "bone,lastRotation\0"
    "rotationDidChange(IBone*,Quaternion)\0"
    "bones\0bonesDidSelect(QList<IBone*>)\0"
    "indices\0addKeyframesByModelIndices(QModelIndexList)\0"
    "deleteKeyframesByModelIndices(QModelIndexList)\0"
    "selectBonesByModelIndices(QModelIndexList)\0"
    "removeModel()\0removeMotion()\0model\0"
    "setPMDModel(IModelSharedPtr)\0motion,model\0"
    "loadMotion(IMotionSharedPtr,IModelSharedPtr)\0"
    "value,bone,flags\0rotateAngle(Scalar,IBone*,int)\0"
    "delta,bone,flags\0translateDelta(Vector3,IBone*,int)\0"
    "translation,bone,flags\0"
    "translateTo(Vector3,IBone*,int)\0"
    "selectBones(QList<IBone*>)\0saveTransform()\0"
    "commitTransform()\0camera\0"
    "setCamera(const ICamera*)\0"
};

void vpvm::BoneMotionModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BoneMotionModel *_t = static_cast<BoneMotionModel *>(_o);
        switch (_id) {
        case 0: _t->translationDidChange((*reinterpret_cast< IBone*(*)>(_a[1])),(*reinterpret_cast< const Vector3(*)>(_a[2]))); break;
        case 1: _t->rotationDidChange((*reinterpret_cast< IBone*(*)>(_a[1])),(*reinterpret_cast< const Quaternion(*)>(_a[2]))); break;
        case 2: _t->bonesDidSelect((*reinterpret_cast< const QList<IBone*>(*)>(_a[1]))); break;
        case 3: _t->addKeyframesByModelIndices((*reinterpret_cast< const QModelIndexList(*)>(_a[1]))); break;
        case 4: _t->deleteKeyframesByModelIndices((*reinterpret_cast< const QModelIndexList(*)>(_a[1]))); break;
        case 5: _t->selectBonesByModelIndices((*reinterpret_cast< const QModelIndexList(*)>(_a[1]))); break;
        case 6: _t->removeModel(); break;
        case 7: _t->removeMotion(); break;
        case 8: _t->setPMDModel((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        case 9: _t->loadMotion((*reinterpret_cast< IMotionSharedPtr(*)>(_a[1])),(*reinterpret_cast< const IModelSharedPtr(*)>(_a[2]))); break;
        case 10: _t->rotateAngle((*reinterpret_cast< const Scalar(*)>(_a[1])),(*reinterpret_cast< IBone*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->translateDelta((*reinterpret_cast< const Vector3(*)>(_a[1])),(*reinterpret_cast< IBone*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->translateTo((*reinterpret_cast< const Vector3(*)>(_a[1])),(*reinterpret_cast< IBone*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->selectBones((*reinterpret_cast< const QList<IBone*>(*)>(_a[1]))); break;
        case 14: _t->saveTransform(); break;
        case 15: _t->commitTransform(); break;
        case 16: _t->setCamera((*reinterpret_cast< const ICamera*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::BoneMotionModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::BoneMotionModel::staticMetaObject = {
    { &PMDMotionModel::staticMetaObject, qt_meta_stringdata_vpvm__BoneMotionModel,
      qt_meta_data_vpvm__BoneMotionModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::BoneMotionModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::BoneMotionModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::BoneMotionModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__BoneMotionModel))
        return static_cast<void*>(const_cast< BoneMotionModel*>(this));
    return PMDMotionModel::qt_metacast(_clname);
}

int vpvm::BoneMotionModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PMDMotionModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void vpvm::BoneMotionModel::translationDidChange(IBone * _t1, const Vector3 & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::BoneMotionModel::rotationDidChange(IBone * _t1, const Quaternion & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void vpvm::BoneMotionModel::bonesDidSelect(const QList<IBone*> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
