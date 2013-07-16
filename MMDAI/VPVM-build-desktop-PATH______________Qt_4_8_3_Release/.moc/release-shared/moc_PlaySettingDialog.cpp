/****************************************************************************
** Meta object code from reading C++ file 'PlaySettingDialog.h'
**
** Created: Tue Jul 16 13:04:54 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/PlaySettingDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlaySettingDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__PlaySettingDialog[] = {

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
      25,   24,   24,   24, 0x05,
      43,   24,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   24,   24,   24, 0x08,
      78,   24,   24,   24, 0x08,
      92,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__PlaySettingDialog[] = {
    "vpvm::PlaySettingDialog\0\0settingsDidSave()\0"
    "playingDidStart()\0openFileDialog()\0"
    "retranslate()\0saveSettings()\0"
};

void vpvm::PlaySettingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PlaySettingDialog *_t = static_cast<PlaySettingDialog *>(_o);
        switch (_id) {
        case 0: _t->settingsDidSave(); break;
        case 1: _t->playingDidStart(); break;
        case 2: _t->openFileDialog(); break;
        case 3: _t->retranslate(); break;
        case 4: _t->saveSettings(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData vpvm::PlaySettingDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::PlaySettingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vpvm__PlaySettingDialog,
      qt_meta_data_vpvm__PlaySettingDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::PlaySettingDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::PlaySettingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::PlaySettingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__PlaySettingDialog))
        return static_cast<void*>(const_cast< PlaySettingDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vpvm::PlaySettingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void vpvm::PlaySettingDialog::settingsDidSave()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void vpvm::PlaySettingDialog::playingDidStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
