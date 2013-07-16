/****************************************************************************
** Meta object code from reading C++ file 'RenderOrderDialog.h'
**
** Created: Tue Jul 16 13:04:57 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/RenderOrderDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RenderOrderDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__RenderOrderDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   25,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   24,   24,   24, 0x08,
      80,   24,   24,   24, 0x08,
      93,   24,   24,   24, 0x08,
     106,   24,   24,   24, 0x08,
     121,   24,   24,   24, 0x08,
     141,  134,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__RenderOrderDialog[] = {
    "vpvm::RenderOrderDialog\0\0uuid\0"
    "renderOrderListDidSet(QList<QUuid>)\0"
    "retranslate()\0emitSignal()\0setOrderUp()\0"
    "setOrderDown()\0resetOrder()\0button\0"
    "handleButton(QAbstractButton*)\0"
};

void vpvm::RenderOrderDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RenderOrderDialog *_t = static_cast<RenderOrderDialog *>(_o);
        switch (_id) {
        case 0: _t->renderOrderListDidSet((*reinterpret_cast< const QList<QUuid>(*)>(_a[1]))); break;
        case 1: _t->retranslate(); break;
        case 2: _t->emitSignal(); break;
        case 3: _t->setOrderUp(); break;
        case 4: _t->setOrderDown(); break;
        case 5: _t->resetOrder(); break;
        case 6: _t->handleButton((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::RenderOrderDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::RenderOrderDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vpvm__RenderOrderDialog,
      qt_meta_data_vpvm__RenderOrderDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::RenderOrderDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::RenderOrderDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::RenderOrderDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__RenderOrderDialog))
        return static_cast<void*>(const_cast< RenderOrderDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int vpvm::RenderOrderDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void vpvm::RenderOrderDialog::renderOrderListDidSet(const QList<QUuid> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
