/****************************************************************************
** Meta object code from reading C++ file 'LoggerWidget.h'
**
** Created: Tue Jul 16 13:03:41 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/LoggerWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoggerWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__LoggerWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   20,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   19,   19,   19, 0x08,
      58,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__LoggerWidget[] = {
    "vpvm::LoggerWidget\0\0message\0"
    "messageDidAdd(QString)\0save()\0clear()\0"
};

void vpvm::LoggerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LoggerWidget *_t = static_cast<LoggerWidget *>(_o);
        switch (_id) {
        case 0: _t->messageDidAdd((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->save(); break;
        case 2: _t->clear(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::LoggerWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::LoggerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vpvm__LoggerWidget,
      qt_meta_data_vpvm__LoggerWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::LoggerWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::LoggerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::LoggerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__LoggerWidget))
        return static_cast<void*>(const_cast< LoggerWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int vpvm::LoggerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void vpvm::LoggerWidget::messageDidAdd(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
