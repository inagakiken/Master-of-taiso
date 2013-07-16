/**

 Copyright (c) 2010-2013  hkrn

 All rights reserved.

 Redistribution and use in source and binary forms, with or
 without modification, are permitted provided that the following
 conditions are met:

 - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
 - Redistributions in binary form must reproduce the above
   copyright notice, this list of conditions and the following
   disclaimer in the documentation and/or other materials provided
   with the distribution.
 - Neither the name of the MMDAI project team nor the names of
   its contributors may be used to endorse or promote products
   derived from this software without specific prior written
   permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef VPVM_BONEMOTIONMODEL_H
#define VPVM_BONEMOTIONMODEL_H

#include "PMDMotionModel.h"
#include "SceneLoader.h"

#include <vpvl2/IBoneKeyframe.h>
#include <vpvl2/Scene.h>

namespace vpvl2 {
class Factory;
class IBone;
class IModel;
class IMotion;
}

namespace vpvm
{

using namespace vpvl2;
using namespace vpvl2::qt;

class BoneMotionModel : public PMDMotionModel
{
    Q_OBJECT

public:
    enum ResetType {
        kX,
        kY,
        kZ,
        kRotation
    };

    typedef QSharedPointer<IBoneKeyframe> KeyFramePtr;
    typedef QPair<int, KeyFramePtr> KeyFramePair;
    typedef QList<KeyFramePair> KeyFramePairList;

    BoneMotionModel(Factory *factoryRef, QUndoGroup *undoRef, QObject *parent = 0);
    ~BoneMotionModel();

    void saveMotion(IMotion *motion);
    void copyKeyframesByModelIndices(const QModelIndexList &indices, int timeIndex);
    void pasteKeyframesByTimeIndex(int timeIndex);
    void pasteReversedFrame(int timeIndex);
    void applyKeyframeWeightByModelIndices(const QModelIndexList &indices, const Vector3 &translation, const Vector3 &rotation);
    bool isSelectionIdentical(const QList<IBone *> &bones) const;
    const QString nameFromModelIndex(const QModelIndex &index) const;
    const QModelIndexList modelIndicesFromBones(const QList<IBone *> &bones, int timeIndex) const;
    KeyFramePairList keyframesFromModelIndices(const QModelIndexList &indices) const;

    void loadPose(PosePtr pose, IModelSharedPtr model, int timeIndex);
    void setKeyframes(const KeyFramePairList &keyframes);
    void resetBone(ResetType type);
    void resetAllBones();
    void setSceneRef(const Scene *value);
    void setPosition(int coordinate, float value);
    void setRotation(int coordinate, float value);

    IBone *selectedBone() const { return m_selectedBones.isEmpty() ? 0 : m_selectedBones.first(); }
    Factory *factoryRef() const { return m_factoryRef; }
    PMDMotionModel::State *mutableState() { return &m_state; }
    bool isBoneSelected() const { return m_modelRef != 0 && selectedBone() != 0; }

public slots:
    void addKeyframesByModelIndices(const QModelIndexList &indices);
    void deleteKeyframesByModelIndices(const QModelIndexList &indices);
    void selectBonesByModelIndices(const QModelIndexList &indices);
    void removeModel();
    void removeMotion();
    void setPMDModel(IModelSharedPtr model);
    void loadMotion(IMotionSharedPtr motion, const IModelSharedPtr model);
    void rotateAngle(const Scalar &value, IBone *bone, int flags);
    void translateDelta(const Vector3 &delta, IBone *bone, int flags);
    void translateTo(const Vector3 &translation, IBone *bone, int flags);
    void selectBones(const QList<IBone *> &bones);
    void saveTransform();
    void commitTransform();

signals:
    void translationDidChange(IBone *bone, const Vector3 &lastPosition);
    void rotationDidChange(IBone *bone, const Quaternion &lastRotation);
    void bonesDidSelect(const QList<IBone *> &bones);

private slots:
    void setCamera(const ICamera *camera);

private:
    void translateInternal(const Vector3 &translation, const Vector3 &delta, IBone *bone, int flags);

    PMDMotionModel::State m_state;
    KeyFramePairList m_copiedKeyframes;
    QList<IBone *> m_selectedBones;
    Factory *m_factoryRef;
    IBoneKeyframe::InterpolationParameter m_interpolationParameter;
    Transform m_viewTransform;
    /* 操作時のボーンの位置と回転量を保存する。操作中は変化しない */
    QHash<IBone *, QPair<Vector3, Quaternion> > m_boneTransformStates;

    Q_DISABLE_COPY(BoneMotionModel)
};

} /* namespace vpvl2 */

#endif // BONEMOTIONMODEL_H
