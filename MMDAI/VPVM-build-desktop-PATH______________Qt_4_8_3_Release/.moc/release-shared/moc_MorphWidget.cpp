/****************************************************************************
** Meta object code from reading C++ file 'MorphWidget.h'
**
** Created: Tue Jul 16 13:04:59 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/MorphWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MorphWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__MorphWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      37,   18,   18,   18, 0x05,
      60,   54,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      86,   18,   18,   18, 0x08,
     106,  100,   18,   18, 0x08,
     141,  135,   18,   18, 0x08,
     159,  135,   18,   18, 0x08,
     177,  135,   18,   18, 0x08,
     199,  135,   18,   18, 0x08,
     219,   18,   18,   18, 0x08,
     233,   18,   18,   18, 0x08,
     247,   18,   18,   18, 0x08,
     265,   18,   18,   18, 0x08,
     281,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__MorphWidget[] = {
    "vpvm::MorphWidget\0\0morphWillChange()\0"
    "morphDidChange()\0morph\0morphDidRegister(IMorph*)\0"
    "retranslate()\0model\0setPMDModel(IModelSharedPtr)\0"
    "value\0setEyeWeight(int)\0setLipWeight(int)\0"
    "setEyeblowWeight(int)\0setOtherWeight(int)\0"
    "registerEye()\0registerLip()\0"
    "registerEyeblow()\0registerOther()\0"
    "updateMorphWeightValues()\0"
};

void vpvm::MorphWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MorphWidget *_t = static_cast<MorphWidget *>(_o);
        switch (_id) {
        case 0: _t->morphWillChange(); break;
        case 1: _t->morphDidChange(); break;
        case 2: _t->morphDidRegister((*reinterpret_cast< IMorph*(*)>(_a[1]))); break;
        case 3: _t->retranslate(); break;
        case 4: _t->setPMDModel((*reinterpret_cast< const IModelSharedPtr(*)>(_a[1]))); break;
        case 5: _t->setEyeWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setLipWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setEyeblowWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setOtherWeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->registerEye(); break;
        case 10: _t->registerLip(); break;
        case 11: _t->registerEyeblow(); break;
        case 12: _t->registerOther(); break;
        case 13: _t->updateMorphWeightValues(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::MorphWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::MorphWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vpvm__MorphWidget,
      qt_meta_data_vpvm__MorphWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::MorphWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::MorphWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::MorphWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__MorphWidget))
        return static_cast<void*>(const_cast< MorphWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int vpvm::MorphWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void vpvm::MorphWidget::morphWillChange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void vpvm::MorphWidget::morphDidChange()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void vpvm::MorphWidget::morphDidRegister(IMorph * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
