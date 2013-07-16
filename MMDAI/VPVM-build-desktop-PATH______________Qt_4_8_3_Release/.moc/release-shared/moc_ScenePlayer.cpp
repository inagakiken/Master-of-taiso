/****************************************************************************
** Meta object code from reading C++ file 'ScenePlayer.h'
**
** Created: Tue Jul 16 13:05:16 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/ScenePlayer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScenePlayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__ScenePlayer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      47,   41,   18,   18, 0x05,
      76,   18,   18,   18, 0x05,
      97,   18,   18,   18, 0x05,
     143,  133,   18,   18, 0x05,
     180,  162,   18,   18, 0x05,
     223,  208,   18,   18, 0x05,
     262,  256,   18,   18, 0x05,
     292,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
     308,   18,   18,   18, 0x0a,
     315,   18,   18,   18, 0x0a,
     333,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__ScenePlayer[] = {
    "vpvm::ScenePlayer\0\0renderFrameDidStart()\0"
    "delta\0renderFrameDidUpdate(Scalar)\0"
    "renderFrameDidStop()\0"
    "renderFrameDidStopAndRestoreState()\0"
    "timeIndex\0motionDidSeek(int)\0"
    "title,cancellable\0playerDidPlay(QString,bool)\0"
    "value,max,text\0playerDidUpdate(int,int,QString)\0"
    "title\0playerDidUpdateTitle(QString)\0"
    "playerDidStop()\0stop()\0setRestoreState()\0"
    "cancel()\0"
};

void vpvm::ScenePlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ScenePlayer *_t = static_cast<ScenePlayer *>(_o);
        switch (_id) {
        case 0: _t->renderFrameDidStart(); break;
        case 1: _t->renderFrameDidUpdate((*reinterpret_cast< const Scalar(*)>(_a[1]))); break;
        case 2: _t->renderFrameDidStop(); break;
        case 3: _t->renderFrameDidStopAndRestoreState(); break;
        case 4: _t->motionDidSeek((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->playerDidPlay((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->playerDidUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 7: _t->playerDidUpdateTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->playerDidStop(); break;
        case 9: _t->stop(); break;
        case 10: _t->setRestoreState(); break;
        case 11: _t->cancel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::ScenePlayer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::ScenePlayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_vpvm__ScenePlayer,
      qt_meta_data_vpvm__ScenePlayer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::ScenePlayer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::ScenePlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::ScenePlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__ScenePlayer))
        return static_cast<void*>(const_cast< ScenePlayer*>(this));
    return QObject::qt_metacast(_clname);
}

int vpvm::ScenePlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void vpvm::ScenePlayer::renderFrameDidStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void vpvm::ScenePlayer::renderFrameDidUpdate(const Scalar & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void vpvm::ScenePlayer::renderFrameDidStop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void vpvm::ScenePlayer::renderFrameDidStopAndRestoreState()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void vpvm::ScenePlayer::motionDidSeek(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void vpvm::ScenePlayer::playerDidPlay(const QString & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void vpvm::ScenePlayer::playerDidUpdate(int _t1, int _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void vpvm::ScenePlayer::playerDidUpdateTitle(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void vpvm::ScenePlayer::playerDidStop()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
