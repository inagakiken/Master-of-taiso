/****************************************************************************
** Meta object code from reading C++ file 'ModelInfoWidget.h'
**
** Created: Tue Jul 16 13:05:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/ModelInfoWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModelInfoWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__ModelInfoWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x08,
      43,   37,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__ModelInfoWidget[] = {
    "vpvm::ModelInfoWidget\0\0retranslate()\0"
    "model\0setModel(IModelSharedPtr)\0"
};

void vpvm::ModelInfoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ModelInfoWidget *_t = static_cast<ModelInfoWidget *>(_o);
        switch (_id) {
        case 0: _t->retranslate(); break;
        case 1: _t->setModel((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::ModelInfoWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::ModelInfoWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vpvm__ModelInfoWidget,
      qt_meta_data_vpvm__ModelInfoWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::ModelInfoWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::ModelInfoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::ModelInfoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__ModelInfoWidget))
        return static_cast<void*>(const_cast< ModelInfoWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int vpvm::ModelInfoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE