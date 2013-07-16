/****************************************************************************
** Meta object code from reading C++ file 'TimelineTreeView.h'
**
** Created: Tue Jul 16 13:05:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../VPVM/include/TimelineTreeView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimelineTreeView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__TimelineTreeView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   24,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   23,   23,   23, 0x0a,
     101,   23,   23,   23, 0x0a,
     122,   23,   23,   23, 0x0a,
     151,  145,   23,   23, 0x08,
     177,  145,   23,   23, 0x08,
     222,  202,   23,   23, 0x08,
     290,  272,   23,   23, 0x08,
     353,  347,   23,   23, 0x08,
     430,  401,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__TimelineTreeView[] = {
    "vpvm::TimelineTreeView\0\0indices\0"
    "modelIndexDidSelect(QModelIndexList)\0"
    "addKeyframesBySelectedIndices()\0"
    "restoreExpandState()\0updateFrozenTreeView()\0"
    "index\0addCollapsed(QModelIndex)\0"
    "addExpanded(QModelIndex)\0selected,deselected\0"
    "selectModelIndices(QItemSelection,QItemSelection)\0"
    "position,rotation\0"
    "setBoneKeyframesWeightBySelectedIndices(Vector3,Vector3)\0"
    "value\0setMorphKeyframesWeightBySelectedIndices(float)\0"
    "logicalIndex,newSize,oldSize\0"
    "updateSectionWidth(int,int,int)\0"
};

void vpvm::TimelineTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TimelineTreeView *_t = static_cast<TimelineTreeView *>(_o);
        switch (_id) {
        case 0: _t->modelIndexDidSelect((*reinterpret_cast< const QModelIndexList(*)>(_a[1]))); break;
        case 1: _t->addKeyframesBySelectedIndices(); break;
        case 2: _t->restoreExpandState(); break;
        case 3: _t->updateFrozenTreeView(); break;
        case 4: _t->addCollapsed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->addExpanded((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->selectModelIndices((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 7: _t->setBoneKeyframesWeightBySelectedIndices((*reinterpret_cast< const Vector3(*)>(_a[1])),(*reinterpret_cast< const Vector3(*)>(_a[2]))); break;
        case 8: _t->setMorphKeyframesWeightBySelectedIndices((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: _t->updateSectionWidth((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::TimelineTreeView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::TimelineTreeView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_vpvm__TimelineTreeView,
      qt_meta_data_vpvm__TimelineTreeView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::TimelineTreeView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::TimelineTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::TimelineTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__TimelineTreeView))
        return static_cast<void*>(const_cast< TimelineTreeView*>(this));
    return QTreeView::qt_metacast(_clname);
}

int vpvm::TimelineTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
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
void vpvm::TimelineTreeView::modelIndexDidSelect(const QModelIndexList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_vpvm__TimelineHeaderView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      36,   26,   25,   25, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__TimelineHeaderView[] = {
    "vpvm::TimelineHeaderView\0\0timeIndex\0"
    "timeIndexDidSelect(int)\0"
};

void vpvm::TimelineHeaderView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TimelineHeaderView *_t = static_cast<TimelineHeaderView *>(_o);
        switch (_id) {
        case 0: _t->timeIndexDidSelect((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::TimelineHeaderView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::TimelineHeaderView::staticMetaObject = {
    { &QHeaderView::staticMetaObject, qt_meta_stringdata_vpvm__TimelineHeaderView,
      qt_meta_data_vpvm__TimelineHeaderView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::TimelineHeaderView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::TimelineHeaderView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::TimelineHeaderView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__TimelineHeaderView))
        return static_cast<void*>(const_cast< TimelineHeaderView*>(this));
    return QHeaderView::qt_metacast(_clname);
}

int vpvm::TimelineHeaderView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHeaderView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void vpvm::TimelineHeaderView::timeIndexDidSelect(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
