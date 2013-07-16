/****************************************************************************
** Meta object code from reading C++ file 'InterpolationDialog.h'
**
** Created: Tue Jul 16 12:41:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/InterpolationDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InterpolationDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__InterpolationDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x08,
      41,   26,   26,   26, 0x08,
      58,   51,   26,   26, 0x08,
      94,   88,   26,   26, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__InterpolationDialog[] = {
    "vpvm::InterpolationDialog\0\0retranslate()\0"
    "disable()\0button\0clickButton(QAbstractButton*)\0"
    "value\0selectPreset(int)\0"
};

void vpvm::InterpolationDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InterpolationDialog *_t = static_cast<InterpolationDialog *>(_o);
        switch (_id) {
        case 0: _t->retranslate(); break;
        case 1: _t->disable(); break;
        case 2: _t->clickButton((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 3: _t->selectPreset((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::InterpolationDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::InterpolationDialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vpvm__InterpolationDialog,
      qt_meta_data_vpvm__InterpolationDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::InterpolationDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::InterpolationDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::InterpolationDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__InterpolationDialog))
        return static_cast<void*>(const_cast< InterpolationDialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int vpvm::InterpolationDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
