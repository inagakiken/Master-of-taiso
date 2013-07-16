/****************************************************************************
** Meta object code from reading C++ file 'PhysicsSettingDialog.h'
**
** Created: Tue Jul 16 12:41:34 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/PhysicsSettingDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PhysicsSettingDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__PhysicsSettingDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   28,   27,   27, 0x05,
      62,   28,   27,   27, 0x05,
      90,   28,   27,   27, 0x05,
     113,   28,   27,   27, 0x05,

 // slots: signature, parameters, type, tag, flags
     140,   27,   27,   27, 0x08,
     154,   27,   27,   27, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__PhysicsSettingDialog[] = {
    "vpvm::PhysicsSettingDialog\0\0value\0"
    "worldGravityDidSet(Vector3)\0"
    "worldMaxSubStepsDidSet(int)\0"
    "worldFloorDidSet(bool)\0"
    "worldRandSeedDidSet(ulong)\0retranslate()\0"
    "emitSignal()\0"
};

void vpvm::PhysicsSettingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PhysicsSettingDialog *_t = static_cast<PhysicsSettingDialog *>(_o);
        switch (_id) {
        case 0: _t->worldGravityDidSet((*reinterpret_cast< const Vector3(*)>(_a[1]))); break;
        case 1: _t->worldMaxSubStepsDidSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->worldFloorDidSet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->worldRandSeedDidSet((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 4: _t->retranslate(); break;
        case 5: _t->emitSignal(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::PhysicsSettingDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::PhysicsSettingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vpvm__PhysicsSettingDialog,
      qt_meta_data_vpvm__PhysicsSettingDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::PhysicsSettingDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::PhysicsSettingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::PhysicsSettingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__PhysicsSettingDialog))
        return static_cast<void*>(const_cast< PhysicsSettingDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vpvm::PhysicsSettingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void vpvm::PhysicsSettingDialog::worldGravityDidSet(const Vector3 & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::PhysicsSettingDialog::worldMaxSubStepsDidSet(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void vpvm::PhysicsSettingDialog::worldFloorDidSet(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void vpvm::PhysicsSettingDialog::worldRandSeedDidSet(unsigned long _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
