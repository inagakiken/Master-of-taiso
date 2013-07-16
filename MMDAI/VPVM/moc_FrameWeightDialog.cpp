/****************************************************************************
** Meta object code from reading C++ file 'FrameWeightDialog.h'
**
** Created: Tue Jul 16 12:41:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/FrameWeightDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrameWeightDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__FrameWeightDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      43,   25,   24,   24, 0x05,
      84,   77,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
     123,  117,   24,   24, 0x08,
     150,  117,   24,   24, 0x08,
     177,  117,   24,   24, 0x08,
     204,  117,   24,   24, 0x08,
     231,  117,   24,   24, 0x08,
     258,  117,   24,   24, 0x08,
     285,  117,   24,   24, 0x08,
     308,   24,   24,   24, 0x08,
     331,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__FrameWeightDialog[] = {
    "vpvm::FrameWeightDialog\0\0position,rotation\0"
    "boneWeightDidSet(Vector3,Vector3)\0"
    "weight\0morphKeyframeWeightDidSet(float)\0"
    "value\0setPositionXWeight(double)\0"
    "setPositionYWeight(double)\0"
    "setPositionZWeight(double)\0"
    "setRotationXWeight(double)\0"
    "setRotationYWeight(double)\0"
    "setRotationZWeight(double)\0"
    "setMorphWeight(double)\0emitBoneWeightSignal()\0"
    "emitMorphWeightSignal()\0"
};

void vpvm::FrameWeightDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FrameWeightDialog *_t = static_cast<FrameWeightDialog *>(_o);
        switch (_id) {
        case 0: _t->boneWeightDidSet((*reinterpret_cast< const Vector3(*)>(_a[1])),(*reinterpret_cast< const Vector3(*)>(_a[2]))); break;
        case 1: _t->morphKeyframeWeightDidSet((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->setPositionXWeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setPositionYWeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setPositionZWeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setRotationXWeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setRotationYWeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setRotationZWeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->setMorphWeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->emitBoneWeightSignal(); break;
        case 10: _t->emitMorphWeightSignal(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::FrameWeightDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::FrameWeightDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vpvm__FrameWeightDialog,
      qt_meta_data_vpvm__FrameWeightDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::FrameWeightDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::FrameWeightDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::FrameWeightDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__FrameWeightDialog))
        return static_cast<void*>(const_cast< FrameWeightDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vpvm::FrameWeightDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void vpvm::FrameWeightDialog::boneWeightDidSet(const Vector3 & _t1, const Vector3 & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::FrameWeightDialog::morphKeyframeWeightDidSet(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
