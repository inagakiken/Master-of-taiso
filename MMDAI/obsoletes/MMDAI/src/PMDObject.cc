/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2009-2010  Nagoya Institute of Technology          */
/*                           Department of Computer Science          */
/*                2010-2011  hkrn (libMMDAI)                         */
/*                                                                   */
/* All rights reserved.                                              */
/*                                                                   */
/* Redistribution and use in source and binary forms, with or        */
/* without modification, are permitted provided that the following   */
/* conditions are met:                                               */
/*                                                                   */
/* - Redistributions of source code must retain the above copyright  */
/*   notice, this list of conditions and the following disclaimer.   */
/* - Redistributions in binary form must reproduce the above         */
/*   copyright notice, this list of conditions and the following     */
/*   disclaimer in the documentation and/or other materials provided */
/*   with the distribution.                                          */
/* - Neither the name of the MMDAI project team nor the names of     */
/*   its contributors may be used to endorse or promote products     */
/*   derived from this software without specific prior written       */
/*   permission.                                                     */
/*                                                                   */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND            */
/* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,       */
/* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF          */
/* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE          */
/* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS */
/* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          */
/* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED   */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     */
/* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON */
/* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,   */
/* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    */
/* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           */
/* POSSIBILITY OF SUCH DAMAGE.                                       */
/* ----------------------------------------------------------------- */

/* headers */

#include "MMDAI/MMDAI.h"

namespace MMDAI {

#define PMDOBJECT_ALPHAFRAME    15.0   /* number of frames for appear/disappear alpha blending */
#define PMDOBJECT_COMMENTFRAME  150.0
#define PMDOBJECT_ALIASNAMELEN  50
#define PMDOBJECT_MINMOVEDIFF   0.0001f
#define PMDOBJECT_MOVESPEEDRATE 0.90f /* current * 0.90 + target * 0.10 */
#define PMDOBJECT_MINSPINDIFF   0.000001f
#define PMDOBJECT_SPINSPEEDRATE 0.95f /* current * 0.95 + target * 0.05 */

PMDObject::PMDObject(SceneRenderEngine *engine)
    : m_engine(engine),
      m_alias(NULL),
      m_model(0),
      m_motionManager(0),
      m_globalLipSync(NULL),
      m_isEnable(false),
      m_lightDir(0.0f, 0.0f, 0.0f),
      m_assignTo(NULL),
      m_baseBone(NULL),
      m_origBasePos(0.0f, 0.0f, 0.0f),
      m_offsetPos(0.0f, 0.0f, 0.0f),
      m_offsetRot(0.0f, 0.0f, 0.0f, 1.0f),
      m_moveSpeed(-1.0f),
      m_spinSpeed(-1.0f),
      m_allowToonShading(false),
      m_allowMotionFileDrop(false),
      m_isMoving(false),
      m_isRotating(false),
      m_underTurn(false),
      m_alphaAppearFrame(0.0f),
      m_alphaDisappearFrame(0.0f),
      m_needResetKinematic(false)

{
    m_model = m_engine->allocateModel();
}

PMDObject::~PMDObject()
{
    release();
}

void PMDObject::release()
{
    m_engine->releaseModel(m_model);
    m_model = 0;
    MMDAIMemoryRelease(m_alias);
    m_alias = 0;
    delete m_motionManager;
    m_motionManager = 0;

    m_globalLipSync = NULL;
    m_isEnable = false;
    m_lightDir.setZero();
    m_assignTo = NULL;
    m_baseBone = NULL;
    m_origBasePos.setZero();
    m_offsetPos.setZero();
    m_moveSpeed = -1.0f;
    m_spinSpeed = -1.0f;
    m_allowToonShading = false;
    m_allowMotionFileDrop = false;
    m_isMoving = false;
    m_isRotating = false;
    m_underTurn = false;
    m_alphaAppearFrame = 0.0f;
    m_alphaDisappearFrame = 0.0f;
    m_needResetKinematic = false;
}

bool PMDObject::load(IModelLoader *modelLoader,
                     ILipSyncLoader *lipSyncLoader,
                     BulletPhysics *bullet,
                     PMDBone *assignBone,
                     PMDObject *assignObject,
                     const btVector3 &offsetPos,
                     const btQuaternion &offsetRot,
                     bool forcedPosition)
{
    if (!modelLoader || !lipSyncLoader)
        return false;

    if (!m_model)
        m_model = m_engine->allocateModel();

    /* apply given parameters */
    m_assignTo = assignObject;
    m_baseBone = assignBone;

    PMDBone *bone = m_model->getRootBone();
    if (forcedPosition) {
        /* set offset by given parameters */
        m_offsetPos = offsetPos;
        m_offsetRot = offsetRot;
        bone->setOffset(m_offsetPos);
        bone->update();
    } else {
        /* set offset by root bone */
        m_offsetPos = bone->getOffset();
    }

    /* copy absolute position flag */
    for (int i = 0; i < 3; i++)
        m_absPosFlag[i] = false;

    /* copy toon rendering flag */
    m_allowToonShading = true;

    /* copy flag for motion file drop or all motion */
    if(assignBone || assignObject)
        m_allowMotionFileDrop = false;
    else
        m_allowMotionFileDrop = true;

    /* save position when position is fixed */
    if (m_baseBone)
        m_origBasePos = m_baseBone->getTransform().getOrigin();

    /* set alpha frame */
    m_alphaAppearFrame = PMDOBJECT_ALPHAFRAME;
    m_alphaDisappearFrame = 0.0;

    /* load model */
    if (m_engine->loadModel(m_model, modelLoader, bullet) == false) {
        release();
        return false;
    }

    /* set up lip sync */
    m_localLipSync.load(lipSyncLoader);

    /* set initial alias name as the same as model name */
    setAlias(m_model->getName());

    /* reset */
    m_moveSpeed = -1.0f;
    m_spinSpeed = -1.0f;

    /* set temporarily all body to Kinematic */
    /* this is fixed at first simulation */
    m_needResetKinematic = true;
    m_model->setPhysicsControl(false);

    /* enable */
    m_isEnable = true;

    return true;
}

bool PMDObject::startMotion(VMD * vmd,
                            const char * name,
                            bool full,
                            bool once,
                            bool enableSmooth,
                            bool enableRepos,
                            float priority)
{
    if (m_motionManager == NULL || !m_motionManager->startMotion(vmd, name, full, once, enableSmooth, enableRepos, priority))
        return false;
    return true;
}

bool PMDObject::swapMotion(VMD * vmd, const char *targetName)
{
    if (m_motionManager == NULL || !m_motionManager->swapMotion(vmd, targetName))
        return false;
    return true;
}

void PMDObject::updateRootBone()
{
    if (!m_baseBone || !m_model)
        return;

    /* relative position */
    btVector3 pos = m_offsetPos;
    /* if absolute flag is true, fix relative position from root bone */
    const btVector3 posAbs = m_offsetPos + m_origBasePos - m_baseBone->getTransform().getOrigin();
    if (m_absPosFlag[0])
        pos.setX(posAbs.x());
    if (m_absPosFlag[1])
        pos.setY(posAbs.y());
    if (m_absPosFlag[2])
        pos.setZ(posAbs.z());

    /* set root bone */
    PMDBone *b = m_model->getRootBone();
    b->setCurrentPosition(pos);
    b->setCurrentRotation(m_offsetRot);
    b->update();
    /* update transform for base position */
    const btTransform tr = m_baseBone->getTransform() * b->getTransform();
    b->setTransform(tr);
}

bool PMDObject::updateMotion(double deltaFrame)
{
    bool ret = false;

    if (!m_isEnable || !m_motionManager || !m_model)
        return ret;

    /* set rotation and position to bone and face from motion */
    ret = m_motionManager->update(deltaFrame);
    m_model->updateBone(); /* update bone, IK, and rotation */
    m_model->updateFace(); /* update face */

    return ret;
}

void PMDObject::setPhysicsEnable(bool value)
{
    if (!m_isEnable || !m_model)
        return;
    /* if necessary, change state of Bullet Physics */
    if (m_needResetKinematic) {
        if (value)
            m_model->setPhysicsControl(true);
        m_needResetKinematic = false;
    }
}

void PMDObject::updateSkin()
{
    if (!m_isEnable || !m_model)
        return;
    /* apply calculation result to bone */
    m_model->updateBoneFromSimulation();
    /* update skin */
    m_model->updateSkin();
    /* update toon */
    m_model->updateToon(&m_lightDir);
}

bool PMDObject::updateAlpha(double deltaFrame)
{
    bool ended = false;
    if (!m_isEnable || !m_model)
        return ended;

    if (m_alphaAppearFrame > 0.0f) {
        m_alphaAppearFrame -= deltaFrame;
        if (m_alphaAppearFrame < 0.0f)
            m_alphaAppearFrame = 0.0f;
        m_model->setGlobalAlpha((float)(1.0 - m_alphaAppearFrame / PMDOBJECT_ALPHAFRAME));
    }
    if (m_alphaDisappearFrame > 0.0f) {
        m_alphaDisappearFrame -= deltaFrame;
        if (m_alphaDisappearFrame <= 0.0f) {
            m_alphaDisappearFrame = 0.0f;
            ended = true; /* model was deleted */
        }
        m_model->setGlobalAlpha((float) (m_alphaDisappearFrame / PMDOBJECT_ALPHAFRAME));
    }

    return ended;
}

void PMDObject::startDisappear()
{
    m_alphaDisappearFrame = PMDOBJECT_ALPHAFRAME;
}

void PMDObject::setLightForToon(const btVector3 &value)
{
    m_lightDir = value;
    m_lightDir.normalize();
}

bool PMDObject::move(float fps)
{
    btVector3 pos2;
    bool ret = false;

    if (!m_isEnable || !m_model)
        return ret;

    /* get root bone */
    PMDBone *b = m_model->getRootBone();

    /* target position is m_offsetPos */
    /* move offset of root bone closer to m_offsetPos */
    const btVector3 pos = b->getOffset();
    m_isMoving = false;
    if (m_offsetPos != pos) {
        /* if there is difference then update */
        const float diff = pos.distance(m_offsetPos);
        if (diff > PMDOBJECT_MINMOVEDIFF) {
            if (m_moveSpeed >= 0.0f && fps != 0.0f) {
                /* max speed */
                const float maxStep = m_moveSpeed / fps;
                if (diff > maxStep) {
                    pos2 = pos.lerp(m_offsetPos, maxStep / diff);
                    m_isMoving = true;
                } else {
                    pos2 = m_offsetPos;
                    ret = true;
                }
            } else {
                /* current * 0.9 + target * 0.1 */
                pos2 = pos.lerp(m_offsetPos, 1.0f - PMDOBJECT_MOVESPEEDRATE);
                m_isMoving = true;
            }
        } else {
            /* set target offset directory if small difference */
            pos2 = m_offsetPos;
            ret = true;
        }
        b->setOffset(pos2);
        b->update();
    }

    return ret;
}

bool PMDObject::rotate(float fps)
{
    bool ret = false;

    if (!m_isEnable || !m_model)
        return ret;

    m_isRotating = false;

    /* get root bone */
    PMDBone *b = m_model->getRootBone();
    /* target rotation is m_offsetRot */
    /* turn rotation of root bone closer to m_offsetRot */
    if (m_offsetRot != b->getCurrentRotation()) {
        /* difference calculation */
        btQuaternion r = b->getCurrentRotation();
        r = r - m_offsetRot;
        const float diff = r.length();
        if (diff > PMDOBJECT_MINSPINDIFF) {
            if (m_spinSpeed >= 0.0f && fps != 0.0f) {
                /* max turn speed */
                const float maxStep = MMDAIMathRadian(m_spinSpeed) / fps;
                if (diff > maxStep) {
                    btQuaternion tmpRot = b->getCurrentRotation();
                    tmpRot = tmpRot.slerp(m_offsetRot, maxStep / diff);
                    b->setCurrentRotation(tmpRot);
                    m_isRotating = true;
                } else {
                    b->setCurrentRotation(m_offsetRot);
                    ret = true;
                }
            } else {
                /* current * 0.95 + target * 0.05 */
                btQuaternion tmpRot = b->getCurrentRotation();
                tmpRot = tmpRot.slerp(m_offsetRot, 1.0f - PMDOBJECT_SPINSPEEDRATE);
                b->setCurrentRotation(tmpRot);
                m_isRotating = true;
            }
        } else {
            /* set target offset directory if small difference */
            b->setCurrentRotation(m_offsetRot);
            ret = true;
        }
        b->update();
    }

    return ret;
}

bool PMDObject::createLipSyncMotion(const char *str, unsigned char **data, size_t *size)
{
    bool ret = m_localLipSync.createMotion(str, data, size);
    if (!ret && m_globalLipSync != NULL)
        ret = m_globalLipSync->createMotion(str, data, size);
    return ret;
}

} /* namespace */

