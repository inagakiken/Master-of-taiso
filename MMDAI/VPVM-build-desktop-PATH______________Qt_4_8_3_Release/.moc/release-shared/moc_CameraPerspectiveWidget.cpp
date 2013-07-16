/****************************************************************************
** Meta object code from reading C++ file 'CameraPerspectiveWidget.h'
**
** Created: Tue Jul 16 13:05:00 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/CameraPerspectiveWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CameraPerspectiveWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__CameraPerspectiveWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      38,   31,   30,   30, 0x05,
      90,   30,   30,   30, 0x05,

 // slots: signature, parameters, type, tag, flags
     118,   31,   30,   30, 0x0a,
     155,   30,   30,   30, 0x08,
     169,   30,   30,   30, 0x08,
     197,   30,   30,   30, 0x08,
     224,   30,   30,   30, 0x08,
     250,   30,   30,   30, 0x08,
     279,   30,   30,   30, 0x08,
     306,   30,   30,   30, 0x08,
     340,  334,   30,   30, 0x08,
     364,  334,   30,   30, 0x08,
     388,  334,   30,   30, 0x08,
     412,  334,   30,   30, 0x08,
     436,  334,   30,   30, 0x08,
     460,  334,   30,   30, 0x08,
     484,  334,   30,   30, 0x08,
     503,  334,   30,   30, 0x08,
     526,   30,   30,   30, 0x08,
     545,  334,   30,   30, 0x08,
     575,  334,   30,   30, 0x08,
     610,  604,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__CameraPerspectiveWidget[] = {
    "vpvm::CameraPerspectiveWidget\0\0camera\0"
    "cameraPerspectiveDidChange(QSharedPointer<ICamera>)\0"
    "cameraPerspectiveDidReset()\0"
    "setCameraPerspective(const ICamera*)\0"
    "retranslate()\0setCameraPerspectiveFront()\0"
    "setCameraPerspectiveBack()\0"
    "setCameraPerspectiveTop()\0"
    "setCameraPerspectiveBottom()\0"
    "setCameraPerspectiveLeft()\0"
    "setCameraPerspectiveRight()\0value\0"
    "updatePositionX(double)\0updatePositionY(double)\0"
    "updatePositionZ(double)\0updateRotationX(double)\0"
    "updateRotationY(double)\0updateRotationZ(double)\0"
    "updateFovy(double)\0updateDistance(double)\0"
    "initializeCamera()\0setPositionFromModel(Vector3)\0"
    "setPositionFromBone(Vector3)\0bones\0"
    "setPositionFromBone(QList<IBone*>)\0"
};

void vpvm::CameraPerspectiveWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CameraPerspectiveWidget *_t = static_cast<CameraPerspectiveWidget *>(_o);
        switch (_id) {
        case 0: _t->cameraPerspectiveDidChange((*reinterpret_cast< const QSharedPointer<ICamera>(*)>(_a[1]))); break;
        case 1: _t->cameraPerspectiveDidReset(); break;
        case 2: _t->setCameraPerspective((*reinterpret_cast< const ICamera*(*)>(_a[1]))); break;
        case 3: _t->retranslate(); break;
        case 4: _t->setCameraPerspectiveFront(); break;
        case 5: _t->setCameraPerspectiveBack(); break;
        case 6: _t->setCameraPerspectiveTop(); break;
        case 7: _t->setCameraPerspectiveBottom(); break;
        case 8: _t->setCameraPerspectiveLeft(); break;
        case 9: _t->setCameraPerspectiveRight(); break;
        case 10: _t->updatePositionX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->updatePositionY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->updatePositionZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->updateRotationX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->updateRotationY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->updateRotationZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->updateFovy((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->updateDistance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->initializeCamera(); break;
        case 19: _t->setPositionFromModel((*reinterpret_cast< const Vector3(*)>(_a[1]))); break;
        case 20: _t->setPositionFromBone((*reinterpret_cast< const Vector3(*)>(_a[1]))); break;
        case 21: _t->setPositionFromBone((*reinterpret_cast< const QList<IBone*>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::CameraPerspectiveWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::CameraPerspectiveWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vpvm__CameraPerspectiveWidget,
      qt_meta_data_vpvm__CameraPerspectiveWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::CameraPerspectiveWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::CameraPerspectiveWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::CameraPerspectiveWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__CameraPerspectiveWidget))
        return static_cast<void*>(const_cast< CameraPerspectiveWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int vpvm::CameraPerspectiveWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void vpvm::CameraPerspectiveWidget::cameraPerspectiveDidChange(const QSharedPointer<ICamera> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::CameraPerspectiveWidget::cameraPerspectiveDidReset()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
