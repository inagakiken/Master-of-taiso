/****************************************************************************
** Meta object code from reading C++ file 'BackgroundImageSettingDialog.h'
**
** Created: Tue Jul 16 12:41:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/BackgroundImageSettingDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BackgroundImageSettingDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__BackgroundImageSettingDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      42,   36,   35,   35, 0x05,
      68,   36,   35,   35, 0x05,

 // slots: signature, parameters, type, tag, flags
      91,   36,   35,   35, 0x08,
     109,   36,   35,   35, 0x08,
     127,   35,   35,   35, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__BackgroundImageSettingDialog[] = {
    "vpvm::BackgroundImageSettingDialog\0\0"
    "value\0positionDidChange(QPoint)\0"
    "uniformDidEnable(bool)\0setPositionX(int)\0"
    "setPositionY(int)\0restoreAndClose()\0"
};

void vpvm::BackgroundImageSettingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BackgroundImageSettingDialog *_t = static_cast<BackgroundImageSettingDialog *>(_o);
        switch (_id) {
        case 0: _t->positionDidChange((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->uniformDidEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setPositionX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setPositionY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->restoreAndClose(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::BackgroundImageSettingDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::BackgroundImageSettingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vpvm__BackgroundImageSettingDialog,
      qt_meta_data_vpvm__BackgroundImageSettingDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::BackgroundImageSettingDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::BackgroundImageSettingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::BackgroundImageSettingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__BackgroundImageSettingDialog))
        return static_cast<void*>(const_cast< BackgroundImageSettingDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vpvm::BackgroundImageSettingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void vpvm::BackgroundImageSettingDialog::positionDidChange(const QPoint & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::BackgroundImageSettingDialog::uniformDidEnable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
