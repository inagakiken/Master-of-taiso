/****************************************************************************
** Meta object code from reading C++ file 'TimelineWidget.h'
**
** Created: Tue Jul 16 12:41:35 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/TimelineWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimelineWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__TimelineWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      61,   22,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     117,  107,   21,   21, 0x0a,
     179,  159,   21,   21, 0x0a,
     209,  107,   21,   21, 0x2a,
     234,   21,   21,   21, 0x08,
     248,   21,   21,   21, 0x08,
     279,   21,   21,   21, 0x08,
     319,  107,   21,   21, 0x08,
     369,  353,   21,   21, 0x08,
     413,  407,   21,   21, 0x28,
     452,  446,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__TimelineWidget[] = {
    "vpvm::TimelineWidget\0\0"
    "column,forceCameraUpdate,forceEvenSame\0"
    "motionDidSeek(IKeyframe::TimeIndex,bool,bool)\0"
    "timeIndex\0setCurrentTimeIndex(IKeyframe::TimeIndex)\0"
    "timeIndex,forceSeek\0setCurrentTimeIndex(int,bool)\0"
    "setCurrentTimeIndex(int)\0retranslate()\0"
    "setCurrentTimeIndexBySpinBox()\0"
    "setCurrentTimeIndexAndExpandBySpinBox()\0"
    "setCurrentTimeIndexAndSelect(int)\0"
    "index,forceSeek\0setCurrentTimeIndex(QModelIndex,bool)\0"
    "index\0setCurrentTimeIndex(QModelIndex)\0"
    "value\0adjustFrameColumnSize(int)\0"
};

void vpvm::TimelineWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TimelineWidget *_t = static_cast<TimelineWidget *>(_o);
        switch (_id) {
        case 0: _t->motionDidSeek((*reinterpret_cast< const IKeyframe::TimeIndex(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->setCurrentTimeIndex((*reinterpret_cast< const IKeyframe::TimeIndex(*)>(_a[1]))); break;
        case 2: _t->setCurrentTimeIndex((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->setCurrentTimeIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->retranslate(); break;
        case 5: _t->setCurrentTimeIndexBySpinBox(); break;
        case 6: _t->setCurrentTimeIndexAndExpandBySpinBox(); break;
        case 7: _t->setCurrentTimeIndexAndSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setCurrentTimeIndex((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->setCurrentTimeIndex((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->adjustFrameColumnSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::TimelineWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::TimelineWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vpvm__TimelineWidget,
      qt_meta_data_vpvm__TimelineWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::TimelineWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::TimelineWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::TimelineWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__TimelineWidget))
        return static_cast<void*>(const_cast< TimelineWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int vpvm::TimelineWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void vpvm::TimelineWidget::motionDidSeek(const IKeyframe::TimeIndex & _t1, bool _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
