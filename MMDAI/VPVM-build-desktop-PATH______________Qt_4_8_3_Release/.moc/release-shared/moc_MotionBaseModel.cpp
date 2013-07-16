/****************************************************************************
** Meta object code from reading C++ file 'MotionBaseModel.h'
**
** Created: Tue Jul 16 13:03:42 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/MotionBaseModel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MotionBaseModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__MotionBaseModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   23,   22,   22, 0x05,
      77,   51,   22,   22, 0x05,
     157,  139,   22,   22, 0x05,
     206,  194,   22,   22, 0x05,
     257,  242,   22,   22, 0x05,
     298,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     314,   22,   22,   22, 0x0a,
     337,  329,   22,   22, 0x0a,
     381,  329,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__MotionBaseModel[] = {
    "vpvm::MotionBaseModel\0\0value\0"
    "motionDidModify(bool)\0newTimeIndex,oldTimeIndex\0"
    "timeIndexDidChange(IKeyframe::TimeIndex,IKeyframe::TimeIndex)\0"
    "newValue,oldValue\0"
    "timeIndexColumnMaxDidChange(int,int)\0"
    "title,value\0motionDidOpenProgress(QString,bool)\0"
    "value,max,text\0motionDidUpdateProgress(int,int,QString)\0"
    "motionDidLoad()\0removeMotion()\0indices\0"
    "addKeyframesByModelIndices(QModelIndexList)\0"
    "deleteKeyframesByModelIndices(QModelIndexList)\0"
};

void vpvm::MotionBaseModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MotionBaseModel *_t = static_cast<MotionBaseModel *>(_o);
        switch (_id) {
        case 0: _t->motionDidModify((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->timeIndexDidChange((*reinterpret_cast< const IKeyframe::TimeIndex(*)>(_a[1])),(*reinterpret_cast< const IKeyframe::TimeIndex(*)>(_a[2]))); break;
        case 2: _t->timeIndexColumnMaxDidChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->motionDidOpenProgress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->motionDidUpdateProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 5: _t->motionDidLoad(); break;
        case 6: _t->removeMotion(); break;
        case 7: _t->addKeyframesByModelIndices((*reinterpret_cast< const QModelIndexList(*)>(_a[1]))); break;
        case 8: _t->deleteKeyframesByModelIndices((*reinterpret_cast< const QModelIndexList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::MotionBaseModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::MotionBaseModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_vpvm__MotionBaseModel,
      qt_meta_data_vpvm__MotionBaseModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::MotionBaseModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::MotionBaseModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::MotionBaseModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__MotionBaseModel))
        return static_cast<void*>(const_cast< MotionBaseModel*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int vpvm::MotionBaseModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void vpvm::MotionBaseModel::motionDidModify(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::MotionBaseModel::timeIndexDidChange(const IKeyframe::TimeIndex & _t1, const IKeyframe::TimeIndex & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void vpvm::MotionBaseModel::timeIndexColumnMaxDidChange(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void vpvm::MotionBaseModel::motionDidOpenProgress(const QString & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void vpvm::MotionBaseModel::motionDidUpdateProgress(int _t1, int _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void vpvm::MotionBaseModel::motionDidLoad()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
