/****************************************************************************
** Meta object code from reading C++ file 'ModelSettingWidget.h'
**
** Created: Tue Jul 16 13:05:11 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/ModelSettingWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModelSettingWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__ModelSettingWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   26,   25,   25, 0x05,
      60,   26,   25,   25, 0x05,
      85,   26,   25,   25, 0x05,
     118,   26,   25,   25, 0x05,
     151,   26,   25,   25, 0x05,
     183,   26,   25,   25, 0x05,

 // slots: signature, parameters, type, tag, flags
     209,   25,   25,   25, 0x08,
     229,  223,   25,   25, 0x08,
     264,  255,   25,   25, 0x08,
     291,   25,   25,   25, 0x08,
     308,   25,   25,   25, 0x08,
     325,   26,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__ModelSettingWidget[] = {
    "vpvm::ModelSettingWidget\0\0value\0"
    "edgeOffsetDidChange(double)\0"
    "opacityDidChange(Scalar)\0"
    "positionOffsetDidChange(Vector3)\0"
    "rotationOffsetDidChange(Vector3)\0"
    "projectiveShadowDidEnable(bool)\0"
    "selfShadowDidEnable(bool)\0retranslate()\0"
    "model\0setModel(IModelSharedPtr)\0"
    "position\0setPositionOffset(Vector3)\0"
    "updatePosition()\0updateRotation()\0"
    "emitOpacitySignal(int)\0"
};

void vpvm::ModelSettingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ModelSettingWidget *_t = static_cast<ModelSettingWidget *>(_o);
        switch (_id) {
        case 0: _t->edgeOffsetDidChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->opacityDidChange((*reinterpret_cast< const Scalar(*)>(_a[1]))); break;
        case 2: _t->positionOffsetDidChange((*reinterpret_cast< const Vector3(*)>(_a[1]))); break;
        case 3: _t->rotationOffsetDidChange((*reinterpret_cast< const Vector3(*)>(_a[1]))); break;
        case 4: _t->projectiveShadowDidEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->selfShadowDidEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->retranslate(); break;
        case 7: _t->setModel((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        case 8: _t->setPositionOffset((*reinterpret_cast< const Vector3(*)>(_a[1]))); break;
        case 9: _t->updatePosition(); break;
        case 10: _t->updateRotation(); break;
        case 11: _t->emitOpacitySignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::ModelSettingWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::ModelSettingWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vpvm__ModelSettingWidget,
      qt_meta_data_vpvm__ModelSettingWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::ModelSettingWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::ModelSettingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::ModelSettingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__ModelSettingWidget))
        return static_cast<void*>(const_cast< ModelSettingWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int vpvm::ModelSettingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void vpvm::ModelSettingWidget::edgeOffsetDidChange(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::ModelSettingWidget::opacityDidChange(const Scalar & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void vpvm::ModelSettingWidget::positionOffsetDidChange(const Vector3 & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void vpvm::ModelSettingWidget::rotationOffsetDidChange(const Vector3 & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void vpvm::ModelSettingWidget::projectiveShadowDidEnable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void vpvm::ModelSettingWidget::selfShadowDidEnable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
