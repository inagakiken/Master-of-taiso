/****************************************************************************
** Meta object code from reading C++ file 'BoneDialog.h'
**
** Created: Tue Jul 16 12:41:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/BoneDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BoneDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__BoneDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      41,   32,   17,   17, 0x08,
      71,   62,   17,   17, 0x08,
     101,   95,   17,   17, 0x08,
     122,   95,   17,   17, 0x08,
     143,   95,   17,   17, 0x08,
     164,   95,   17,   17, 0x08,
     182,   95,   17,   17, 0x08,
     200,   95,   17,   17, 0x08,
     218,   95,   17,   17, 0x08,
     242,   95,   17,   17, 0x08,
     266,   17,   17,   17, 0x08,
     283,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__BoneDialog[] = {
    "vpvm::BoneDialog\0\0retranslate()\0"
    "position\0setPosition(Vector3)\0rotation\0"
    "setRotation(Quaternion)\0value\0"
    "setXPosition(double)\0setYPosition(double)\0"
    "setZPosition(double)\0setXAngle(double)\0"
    "setYAngle(double)\0setZAngle(double)\0"
    "setPositionStep(double)\0setRotationStep(double)\0"
    "dialogAccepted()\0dialogRejected()\0"
};

void vpvm::BoneDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BoneDialog *_t = static_cast<BoneDialog *>(_o);
        switch (_id) {
        case 0: _t->retranslate(); break;
        case 1: _t->setPosition((*reinterpret_cast< const Vector3(*)>(_a[1]))); break;
        case 2: _t->setRotation((*reinterpret_cast< const Quaternion(*)>(_a[1]))); break;
        case 3: _t->setXPosition((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setYPosition((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setZPosition((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setXAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setYAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->setZAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setPositionStep((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->setRotationStep((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->dialogAccepted(); break;
        case 12: _t->dialogRejected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::BoneDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::BoneDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vpvm__BoneDialog,
      qt_meta_data_vpvm__BoneDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::BoneDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::BoneDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::BoneDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__BoneDialog))
        return static_cast<void*>(const_cast< BoneDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vpvm::BoneDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
