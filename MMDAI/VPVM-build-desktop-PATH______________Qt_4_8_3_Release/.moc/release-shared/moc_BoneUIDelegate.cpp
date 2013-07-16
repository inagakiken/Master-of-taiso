/****************************************************************************
** Meta object code from reading C++ file 'BoneUIDelegate.h'
**
** Created: Tue Jul 16 13:05:15 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/BoneUIDelegate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BoneUIDelegate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__BoneUIDelegate[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x08,
      35,   21,   21,   21, 0x08,
      48,   21,   21,   21, 0x08,
      61,   21,   21,   21, 0x08,
      81,   21,   21,   21, 0x08,
      97,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__BoneUIDelegate[] = {
    "vpvm::BoneUIDelegate\0\0resetBoneX()\0"
    "resetBoneY()\0resetBoneZ()\0resetBoneRotation()\0"
    "resetAllBones()\0openBoneDialog()\0"
};

void vpvm::BoneUIDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BoneUIDelegate *_t = static_cast<BoneUIDelegate *>(_o);
        switch (_id) {
        case 0: _t->resetBoneX(); break;
        case 1: _t->resetBoneY(); break;
        case 2: _t->resetBoneZ(); break;
        case 3: _t->resetBoneRotation(); break;
        case 4: _t->resetAllBones(); break;
        case 5: _t->openBoneDialog(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData vpvm::BoneUIDelegate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::BoneUIDelegate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_vpvm__BoneUIDelegate,
      qt_meta_data_vpvm__BoneUIDelegate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::BoneUIDelegate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::BoneUIDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::BoneUIDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__BoneUIDelegate))
        return static_cast<void*>(const_cast< BoneUIDelegate*>(this));
    return QObject::qt_metacast(_clname);
}

int vpvm::BoneUIDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
