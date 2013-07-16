/****************************************************************************
** Meta object code from reading C++ file 'MorphMotionModel.h'
**
** Created: Tue Jul 16 13:03:45 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/MorphMotionModel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MorphMotionModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__MorphMotionModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   24,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   63,   23,   23, 0x0a,
     115,   63,   23,   23, 0x0a,
     162,   63,   23,   23, 0x0a,
     209,   23,   23,   23, 0x0a,
     223,   23,   23,   23, 0x0a,
     244,  238,   23,   23, 0x0a,
     286,  273,   23,   23, 0x0a,
     331,   24,   23,   23, 0x0a,
     360,   23,   23,   23, 0x0a,
     376,   23,   23,   23, 0x0a,
     394,   23,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__MorphMotionModel[] = {
    "vpvm::MorphMotionModel\0\0morphs\0"
    "morphsDidSelect(QList<IMorph*>)\0indices\0"
    "addKeyframesByModelIndices(QModelIndexList)\0"
    "selectKeyframesByModelIndices(QModelIndexList)\0"
    "deleteKeyframesByModelIndices(QModelIndexList)\0"
    "removeModel()\0removeMotion()\0model\0"
    "setPMDModel(IModelSharedPtr)\0motion,model\0"
    "loadMotion(IMotionSharedPtr,IModelSharedPtr)\0"
    "selectMorphs(QList<IMorph*>)\0"
    "saveTransform()\0commitTransform()\0"
    "resetAllMorphs()\0"
};

void vpvm::MorphMotionModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MorphMotionModel *_t = static_cast<MorphMotionModel *>(_o);
        switch (_id) {
        case 0: _t->morphsDidSelect((*reinterpret_cast< const QList<IMorph*>(*)>(_a[1]))); break;
        case 1: _t->addKeyframesByModelIndices((*reinterpret_cast< const QModelIndexList(*)>(_a[1]))); break;
        case 2: _t->selectKeyframesByModelIndices((*reinterpret_cast< const QModelIndexList(*)>(_a[1]))); break;
        case 3: _t->deleteKeyframesByModelIndices((*reinterpret_cast< const QModelIndexList(*)>(_a[1]))); break;
        case 4: _t->removeModel(); break;
        case 5: _t->removeMotion(); break;
        case 6: _t->setPMDModel((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        case 7: _t->loadMotion((*reinterpret_cast< IMotionSharedPtr(*)>(_a[1])),(*reinterpret_cast< const IModelSharedPtr(*)>(_a[2]))); break;
        case 8: _t->selectMorphs((*reinterpret_cast< const QList<IMorph*>(*)>(_a[1]))); break;
        case 9: _t->saveTransform(); break;
        case 10: _t->commitTransform(); break;
        case 11: _t->resetAllMorphs(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::MorphMotionModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::MorphMotionModel::staticMetaObject = {
    { &PMDMotionModel::staticMetaObject, qt_meta_stringdata_vpvm__MorphMotionModel,
      qt_meta_data_vpvm__MorphMotionModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::MorphMotionModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::MorphMotionModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::MorphMotionModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__MorphMotionModel))
        return static_cast<void*>(const_cast< MorphMotionModel*>(this));
    return PMDMotionModel::qt_metacast(_clname);
}

int vpvm::MorphMotionModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PMDMotionModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void vpvm::MorphMotionModel::morphsDidSelect(const QList<IMorph*> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
