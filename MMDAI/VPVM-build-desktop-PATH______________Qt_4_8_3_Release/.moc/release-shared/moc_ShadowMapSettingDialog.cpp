/****************************************************************************
** Meta object code from reading C++ file 'ShadowMapSettingDialog.h'
**
** Created: Tue Jul 16 13:04:57 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/ShadowMapSettingDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ShadowMapSettingDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__ShadowMapSettingDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      36,   30,   29,   29, 0x05,
      57,   30,   29,   29, 0x05,
      82,   30,   29,   29, 0x05,

 // slots: signature, parameters, type, tag, flags
     108,   29,   29,   29, 0x08,
     122,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__ShadowMapSettingDialog[] = {
    "vpvm::ShadowMapSettingDialog\0\0value\0"
    "sizeDidChange(QSize)\0centerDidChange(Vector3)\0"
    "distanceDidChange(Scalar)\0retranslate()\0"
    "emitSignals()\0"
};

void vpvm::ShadowMapSettingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ShadowMapSettingDialog *_t = static_cast<ShadowMapSettingDialog *>(_o);
        switch (_id) {
        case 0: _t->sizeDidChange((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 1: _t->centerDidChange((*reinterpret_cast< const Vector3(*)>(_a[1]))); break;
        case 2: _t->distanceDidChange((*reinterpret_cast< const Scalar(*)>(_a[1]))); break;
        case 3: _t->retranslate(); break;
        case 4: _t->emitSignals(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::ShadowMapSettingDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::ShadowMapSettingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vpvm__ShadowMapSettingDialog,
      qt_meta_data_vpvm__ShadowMapSettingDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::ShadowMapSettingDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::ShadowMapSettingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::ShadowMapSettingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__ShadowMapSettingDialog))
        return static_cast<void*>(const_cast< ShadowMapSettingDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vpvm::ShadowMapSettingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void vpvm::ShadowMapSettingDialog::sizeDidChange(const QSize & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::ShadowMapSettingDialog::centerDidChange(const Vector3 & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void vpvm::ShadowMapSettingDialog::distanceDidChange(const Scalar & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
