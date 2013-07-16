/****************************************************************************
** Meta object code from reading C++ file 'ExportVideoDialog.h'
**
** Created: Tue Jul 16 13:08:05 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/ExportVideoDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ExportVideoDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__ExportVideoDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   25,   24,   24, 0x05,
      69,   25,   24,   24, 0x05,
      94,   25,   24,   24, 0x05,
     120,   25,   24,   24, 0x05,
     159,   25,   24,   24, 0x05,
     196,   25,   24,   24, 0x05,
     236,   25,   24,   24, 0x05,
     264,   24,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
     282,   24,   24,   24, 0x08,
     296,   24,   24,   24, 0x08,
     313,   24,   24,   24, 0x08,
     328,   25,   24,   24, 0x08,
     360,   25,   24,   24, 0x08,
     379,   25,   24,   24, 0x08,
     399,   25,   24,   24, 0x08,
     432,   25,   24,   24, 0x08,
     463,   25,   24,   24, 0x08,
     494,   25,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__ExportVideoDialog[] = {
    "vpvm::ExportVideoDialog\0\0value\0"
    "backgroundAudioPathDidChange(QString)\0"
    "sceneWidthDidChange(int)\0"
    "sceneHeightDidChange(int)\0"
    "timeIndexEncodeVideoFromDidChange(int)\0"
    "timeIndexEncodeVideoToDidChange(int)\0"
    "sceneFPSForEncodeVideoDidChange(Scalar)\0"
    "gridIncludedDidChange(bool)\0"
    "settingsDidSave()\0retranslate()\0"
    "openFileDialog()\0saveSettings()\0"
    "setBackgroundAudioPath(QString)\0"
    "setSceneWidth(int)\0setSceneHeight(int)\0"
    "setTimeIndexEncodeVideoFrom(int)\0"
    "setTimeIndexEncodeVideoTo(int)\0"
    "setSceneFPSForEncodeVideo(int)\0"
    "setGridIncluded(bool)\0"
};

void vpvm::ExportVideoDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ExportVideoDialog *_t = static_cast<ExportVideoDialog *>(_o);
        switch (_id) {
        case 0: _t->backgroundAudioPathDidChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sceneWidthDidChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sceneHeightDidChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->timeIndexEncodeVideoFromDidChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->timeIndexEncodeVideoToDidChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->sceneFPSForEncodeVideoDidChange((*reinterpret_cast< Scalar(*)>(_a[1]))); break;
        case 6: _t->gridIncludedDidChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->settingsDidSave(); break;
        case 8: _t->retranslate(); break;
        case 9: _t->openFileDialog(); break;
        case 10: _t->saveSettings(); break;
        case 11: _t->setBackgroundAudioPath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->setSceneWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setSceneHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setTimeIndexEncodeVideoFrom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setTimeIndexEncodeVideoTo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setSceneFPSForEncodeVideo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->setGridIncluded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::ExportVideoDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::ExportVideoDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vpvm__ExportVideoDialog,
      qt_meta_data_vpvm__ExportVideoDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::ExportVideoDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::ExportVideoDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::ExportVideoDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__ExportVideoDialog))
        return static_cast<void*>(const_cast< ExportVideoDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vpvm::ExportVideoDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void vpvm::ExportVideoDialog::backgroundAudioPathDidChange(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::ExportVideoDialog::sceneWidthDidChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void vpvm::ExportVideoDialog::sceneHeightDidChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void vpvm::ExportVideoDialog::timeIndexEncodeVideoFromDidChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void vpvm::ExportVideoDialog::timeIndexEncodeVideoToDidChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void vpvm::ExportVideoDialog::sceneFPSForEncodeVideoDidChange(Scalar _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void vpvm::ExportVideoDialog::gridIncludedDidChange(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void vpvm::ExportVideoDialog::settingsDidSave()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
