/****************************************************************************
** Meta object code from reading C++ file 'SceneLightWidget.h'
**
** Created: Tue Jul 16 12:41:34 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/SceneLightWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SceneLightWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__SceneLightWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   24,   23,   23, 0x05,
      56,   24,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      86,   24,   23,   23, 0x0a,
     104,   24,   23,   23, 0x0a,
     126,   23,   23,   23, 0x08,
     140,   23,   23,   23, 0x08,
     154,   23,   23,   23, 0x08,
     171,   23,   23,   23, 0x08,
     189,   24,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__SceneLightWidget[] = {
    "vpvm::SceneLightWidget\0\0value\0"
    "lightColorDidSet(Vector3)\0"
    "lightDirectionDidSet(Vector3)\0"
    "setColor(Vector3)\0setDirection(Vector3)\0"
    "retranslate()\0updateColor()\0"
    "updatePosition()\0openColorDialog()\0"
    "setQColor(QColor)\0"
};

void vpvm::SceneLightWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SceneLightWidget *_t = static_cast<SceneLightWidget *>(_o);
        switch (_id) {
        case 0: _t->lightColorDidSet((*reinterpret_cast< const Vector3(*)>(_a[1]))); break;
        case 1: _t->lightDirectionDidSet((*reinterpret_cast< const Vector3(*)>(_a[1]))); break;
        case 2: _t->setColor((*reinterpret_cast< const Vector3(*)>(_a[1]))); break;
        case 3: _t->setDirection((*reinterpret_cast< const Vector3(*)>(_a[1]))); break;
        case 4: _t->retranslate(); break;
        case 5: _t->updateColor(); break;
        case 6: _t->updatePosition(); break;
        case 7: _t->openColorDialog(); break;
        case 8: _t->setQColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::SceneLightWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::SceneLightWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vpvm__SceneLightWidget,
      qt_meta_data_vpvm__SceneLightWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::SceneLightWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::SceneLightWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::SceneLightWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__SceneLightWidget))
        return static_cast<void*>(const_cast< SceneLightWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int vpvm::SceneLightWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void vpvm::SceneLightWidget::lightColorDidSet(const Vector3 & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::SceneLightWidget::lightDirectionDidSet(const Vector3 & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
