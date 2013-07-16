/****************************************************************************
** Meta object code from reading C++ file 'InterpolationGraphWidget.h'
**
** Created: Tue Jul 16 12:41:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/InterpolationGraphWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InterpolationGraphWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__InterpolationGraphWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      38,   32,   31,   31, 0x05,
      60,   32,   31,   31, 0x05,
      82,   32,   31,   31, 0x05,
     104,   32,   31,   31, 0x05,

 // slots: signature, parameters, type, tag, flags
     126,   32,   31,   31, 0x0a,
     137,   32,   31,   31, 0x0a,
     148,   32,   31,   31, 0x0a,
     159,   32,   31,   31, 0x0a,
     170,   31,   31,   31, 0x08,
     181,   32,   31,   31, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__InterpolationGraphWidget[] = {
    "vpvm::InterpolationGraphWidget\0\0value\0"
    "x1ValueDidChange(int)\0x2ValueDidChange(int)\0"
    "y1ValueDidChange(int)\0y2ValueDidChange(int)\0"
    "setX1(int)\0setX2(int)\0setY1(int)\0"
    "setY2(int)\0applyAll()\0selectParameterType(int)\0"
};

void vpvm::InterpolationGraphWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InterpolationGraphWidget *_t = static_cast<InterpolationGraphWidget *>(_o);
        switch (_id) {
        case 0: _t->x1ValueDidChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->x2ValueDidChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->y1ValueDidChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->y2ValueDidChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setX1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setX2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setY1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setY2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->applyAll(); break;
        case 9: _t->selectParameterType((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::InterpolationGraphWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::InterpolationGraphWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vpvm__InterpolationGraphWidget,
      qt_meta_data_vpvm__InterpolationGraphWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::InterpolationGraphWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::InterpolationGraphWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::InterpolationGraphWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__InterpolationGraphWidget))
        return static_cast<void*>(const_cast< InterpolationGraphWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int vpvm::InterpolationGraphWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void vpvm::InterpolationGraphWidget::x1ValueDidChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::InterpolationGraphWidget::x2ValueDidChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void vpvm::InterpolationGraphWidget::y1ValueDidChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void vpvm::InterpolationGraphWidget::y2ValueDidChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
