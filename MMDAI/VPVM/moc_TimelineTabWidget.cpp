/****************************************************************************
** Meta object code from reading C++ file 'TimelineTabWidget.h'
**
** Created: Tue Jul 16 12:41:34 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/TimelineTabWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimelineTabWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vpvm__TimelineTabWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      67,   25,   24,   24, 0x05,
     124,  113,   24,   24, 0x05,
     190,  185,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
     228,   24,   24,   24, 0x0a,
     273,  262,   24,   24, 0x0a,
     325,  307,   24,   24, 0x0a,
     353,   24,   24,   24, 0x08,
     373,  367,   24,   24, 0x08,
     424,  418,   24,   24, 0x08,
     449,   24,   24,   24, 0x08,
     475,   24,   24,   24, 0x08,
     510,   24,   24,   24, 0x08,
     545,   24,   24,   24, 0x08,
     561,   24,   24,   24, 0x08,
     576,   24,   24,   24, 0x08,
     593,   24,   24,   24, 0x08,
     621,   24,   24,   24, 0x08,
     633,   24,   24,   24, 0x08,
     655,  649,   24,   24, 0x08,
     679,   24,   24,   24, 0x08,
     709,  703,   24,   24, 0x08,
     743,  703,   24,   24, 0x08,
     784,  778,   24,   24, 0x08,
     831,  824,   24,   24, 0x08,
     866,   24,   24,   24, 0x08,
     897,   24,   24,   24, 0x08,
     924,   24,   24,   24, 0x08,
     956,  948,   24,   24, 0x08,
     997,   24,   24,   24, 0x08,
    1040,  778,   24,   24, 0x08,
    1067,  824,   24,   24, 0x08,
    1106, 1096,   24,   24, 0x08,
    1149, 1096,   24,   24, 0x08,
    1200, 1193,   24,   24, 0x08,
    1231,  703,   24,   24, 0x08,
    1269,   24,   24,   24, 0x08,
    1294,   24,   24,   24, 0x08,
    1313,  418,   24,   24, 0x08,
    1335,  418,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_vpvm__TimelineTabWidget[] = {
    "vpvm::TimelineTabWidget\0\0"
    "timeIndex,forceCameraUpdate,forceEvenSame\0"
    "motionDidSeek(IKeyframe::TimeIndex,bool,bool)\0"
    "model,mode\0"
    "currentModelDidChange(IModelSharedPtr,SceneWidget::EditMode)\0"
    "mode\0editModeDidSet(SceneWidget::EditMode)\0"
    "addKeyframesFromSelectedIndices()\0"
    "pose,model\0loadPose(PosePtr,IModelSharedPtr)\0"
    "fromIndex,toIndex\0selectFrameIndices(int,int)\0"
    "retranslate()\0morph\0"
    "addMorphKeyframesAtCurrentTimeIndex(IMorph*)\0"
    "value\0setCurrentTimeIndex(int)\0"
    "setCurrentTimeIndexZero()\0"
    "insertKeyframesBySelectedIndices()\0"
    "deleteKeyframesBySelectedIndices()\0"
    "copyKeyframes()\0cutKeyframes()\0"
    "pasteKeyframes()\0pasteKeyframesWithReverse()\0"
    "nextFrame()\0previousFrame()\0index\0"
    "setCurrentTabIndex(int)\0notifyCurrentTabIndex()\0"
    "model\0toggleBoneEnable(IModelSharedPtr)\0"
    "toggleMorphEnable(IModelSharedPtr)\0"
    "bones\0toggleBoneButtonsByBones(QList<IBone*>)\0"
    "morphs\0toggleMorphByMorph(QList<IMorph*>)\0"
    "selectAllRegisteredKeyframes()\0"
    "openFrameSelectionDialog()\0"
    "openFrameWeightDialog()\0indices\0"
    "openInterpolationDialog(QModelIndexList)\0"
    "openInterpolationDialogBySelectedIndices()\0"
    "selectBones(QList<IBone*>)\0"
    "selectMorphs(QList<IMorph*>)\0selection\0"
    "selectBonesByItemSelection(QItemSelection)\0"
    "selectMorphsByItemSelection(QItemSelection)\0"
    "button\0selectButton(QAbstractButton*)\0"
    "setLastSelectedModel(IModelSharedPtr)\0"
    "clearLastSelectedModel()\0updateMorphValue()\0"
    "updateMorphValue(int)\0updateMorphValue(double)\0"
};

void vpvm::TimelineTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TimelineTabWidget *_t = static_cast<TimelineTabWidget *>(_o);
        switch (_id) {
        case 0: _t->motionDidSeek((*reinterpret_cast< const IKeyframe::TimeIndex(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->currentModelDidChange((*reinterpret_cast< IModelSharedPtr(*)>(_a[1])),(*reinterpret_cast< SceneWidget::EditMode(*)>(_a[2]))); break;
        case 2: _t->editModeDidSet((*reinterpret_cast< SceneWidget::EditMode(*)>(_a[1]))); break;
        case 3: _t->addKeyframesFromSelectedIndices(); break;
        case 4: _t->loadPose((*reinterpret_cast< PosePtr(*)>(_a[1])),(*reinterpret_cast< IModelSharedPtr(*)>(_a[2]))); break;
        case 5: _t->selectFrameIndices((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->retranslate(); break;
        case 7: _t->addMorphKeyframesAtCurrentTimeIndex((*reinterpret_cast< IMorph*(*)>(_a[1]))); break;
        case 8: _t->setCurrentTimeIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setCurrentTimeIndexZero(); break;
        case 10: _t->insertKeyframesBySelectedIndices(); break;
        case 11: _t->deleteKeyframesBySelectedIndices(); break;
        case 12: _t->copyKeyframes(); break;
        case 13: _t->cutKeyframes(); break;
        case 14: _t->pasteKeyframes(); break;
        case 15: _t->pasteKeyframesWithReverse(); break;
        case 16: _t->nextFrame(); break;
        case 17: _t->previousFrame(); break;
        case 18: _t->setCurrentTabIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->notifyCurrentTabIndex(); break;
        case 20: _t->toggleBoneEnable((*reinterpret_cast< const IModelSharedPtr(*)>(_a[1]))); break;
        case 21: _t->toggleMorphEnable((*reinterpret_cast< const IModelSharedPtr(*)>(_a[1]))); break;
        case 22: _t->toggleBoneButtonsByBones((*reinterpret_cast< const QList<IBone*>(*)>(_a[1]))); break;
        case 23: _t->toggleMorphByMorph((*reinterpret_cast< const QList<IMorph*>(*)>(_a[1]))); break;
        case 24: _t->selectAllRegisteredKeyframes(); break;
        case 25: _t->openFrameSelectionDialog(); break;
        case 26: _t->openFrameWeightDialog(); break;
        case 27: _t->openInterpolationDialog((*reinterpret_cast< const QModelIndexList(*)>(_a[1]))); break;
        case 28: _t->openInterpolationDialogBySelectedIndices(); break;
        case 29: _t->selectBones((*reinterpret_cast< const QList<IBone*>(*)>(_a[1]))); break;
        case 30: _t->selectMorphs((*reinterpret_cast< const QList<IMorph*>(*)>(_a[1]))); break;
        case 31: _t->selectBonesByItemSelection((*reinterpret_cast< const QItemSelection(*)>(_a[1]))); break;
        case 32: _t->selectMorphsByItemSelection((*reinterpret_cast< const QItemSelection(*)>(_a[1]))); break;
        case 33: _t->selectButton((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 34: _t->setLastSelectedModel((*reinterpret_cast< IModelSharedPtr(*)>(_a[1]))); break;
        case 35: _t->clearLastSelectedModel(); break;
        case 36: _t->updateMorphValue(); break;
        case 37: _t->updateMorphValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->updateMorphValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vpvm::TimelineTabWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vpvm::TimelineTabWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_vpvm__TimelineTabWidget,
      qt_meta_data_vpvm__TimelineTabWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vpvm::TimelineTabWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vpvm::TimelineTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vpvm::TimelineTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vpvm__TimelineTabWidget))
        return static_cast<void*>(const_cast< TimelineTabWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int vpvm::TimelineTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void vpvm::TimelineTabWidget::motionDidSeek(const IKeyframe::TimeIndex & _t1, bool _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vpvm::TimelineTabWidget::currentModelDidChange(IModelSharedPtr _t1, SceneWidget::EditMode _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void vpvm::TimelineTabWidget::editModeDidSet(SceneWidget::EditMode _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
