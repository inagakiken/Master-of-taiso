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

#include "MMDME/MMDME.h"

namespace MMDAI {

/* PMDModel::parse: initialize and load from ptr memories */
bool PMDModel::parse(IModelLoader *loader, BulletPhysics *bullet)
{
    bool ret = true;
    btQuaternion defaultRot;

    PMDFile_Vertex *fileVertex = NULL;
    PMDFile_Material *fileMaterial = NULL;
    PMDFile_Bone *fileBone = NULL;
    const char *centerBoneName = MotionController::getCenterBoneName();

    size_t size = 0, rest = 0;
    uint8_t *data = NULL;
    if (!loader->loadModelData(&data, &size))
        return false;

    rest = size;
    uint8_t *ptr = data, *start = data;

    /* release internal variables */
    release();
    m_hasSingleSphereMap = false;
    m_hasMultipleSphereMap = false;
    m_baseFace = NULL;
    m_centerBone = NULL;

    /* reset root bone's rotation */
    defaultRot = btQuaternion(0.0f, 0.0f, 0.0f, 1.0f);
    m_rootBone.setCurrentRotation(defaultRot);
    m_rootBone.update();

    m_bulletPhysics = bullet;

    /* reset toon texture IDs by system default textures */
    for (uint32_t i = 0; i < kNSystemTextureFiles; i++) {
        PMDTexture *texture = &m_localToonTexture[i];
        texture->setRenderEngine(m_engine);
        loader->loadSystemTexture(i, texture);
    }

    /* header */
    PMDFile_Header *fileHeader = reinterpret_cast<PMDFile_Header *>(ptr);
    if (sizeof(PMDFile_Header) > rest || fileHeader->magic[0] != 'P' || fileHeader->magic[1] != 'm' || fileHeader->magic[2] != 'd') {
        MMDAILogWarnString("Invalid signature of PMD");
        goto error;
    }
    if (fileHeader->version != 1.0f) {
        MMDAILogWarnString("Not supported version of PMD");
        goto error;
    }

    /* name */
    m_name = static_cast<char *>(MMDAIMemoryAllocate(sizeof(char) * (20 + 1)));
    if (m_name == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }
    MMDAIStringCopySafe(m_name, fileHeader->name, sizeof(fileHeader->name));

    /* comment */
    m_comment = static_cast<char *>(MMDAIMemoryAllocate(sizeof(char) * (256 + 1)));
    if (m_comment == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    MMDAIStringCopySafe(m_comment, fileHeader->comment, sizeof(fileHeader->comment));
    ptr += sizeof(PMDFile_Header);
    rest -= sizeof(PMDFile_Header);

    MMDAILogDebugSJIS("name=\"%s\", comment=\"%s\"", m_name, m_comment);

    /* vertex ptr and bone weights */
    /* relocate as separated list for later OpenGL calls */
    m_numVertex = *reinterpret_cast<uint32_t *>(ptr);
    if (m_numVertex * sizeof(PMDFile_Vertex) > rest) {
        MMDAILogWarnString("Size of vertices exceeds size of PMD");
        goto error;
    }

    ptr += sizeof(uint32_t);
    rest -= sizeof(uint32_t);

    m_vertexList = new btVector3[m_numVertex];
    m_normalList = new btVector3[m_numVertex];
    m_texCoordList = static_cast<TexCoord *>(MMDAIMemoryAllocate(sizeof(TexCoord) * m_numVertex));
    if (m_texCoordList == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    m_bone1List = static_cast<int16_t *>(MMDAIMemoryAllocate(sizeof(int16_t) * m_numVertex));
    if (m_bone1List == NULL) {
        MMDAILogWarnString("Failed parsing PMD: Cannot allocate memory");
        goto error;
    }

    m_bone2List = static_cast<int16_t *>(MMDAIMemoryAllocate(sizeof(int16_t) * m_numVertex));
    if (m_bone2List == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    m_boneWeight1 = static_cast<float *>(MMDAIMemoryAllocate(sizeof(float) * m_numVertex));
    if (m_boneWeight1 == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    m_noEdgeFlag = static_cast<bool *>(MMDAIMemoryAllocate(sizeof(int8_t) * m_numVertex));
    if (m_noEdgeFlag == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    fileVertex  = reinterpret_cast<PMDFile_Vertex *>(ptr);
    for (uint32_t i = 0; i < m_numVertex; i++) {
        PMDFile_Vertex *fv = &fileVertex[i];
        m_vertexList[i].setValue(fv->pos[0], fv->pos[1], fv->pos[2]);
        m_normalList[i].setValue(fv->normal[0], fv->normal[1], fv->normal[2]);
        m_texCoordList[i].u = fv->uv[0];
        m_texCoordList[i].v = fv->uv[1];
        m_bone1List[i] = fv->boneID[0];
        m_bone2List[i] = fv->boneID[1];
        m_boneWeight1[i] = fv->boneWeight1 * 0.01f;
        m_noEdgeFlag[i] = fv->noEdgeFlag == 1;
    }
    ptr += sizeof(PMDFile_Vertex) * m_numVertex;
    rest -= sizeof(PMDFile_Vertex) * m_numVertex;

    /* surface ptr, 3 vertex indices for each */
    m_numSurface = *reinterpret_cast<uint32_t *>(ptr);
    if (m_numSurface * sizeof(uint16_t) > rest) {
        MMDAILogWarnString("Size of indices exceeds size of PMD");
        goto error;
    }
    ptr += sizeof(uint32_t);
    rest -= sizeof(uint32_t);

    m_surfaceList = static_cast<uint16_t *>(MMDAIMemoryAllocate(sizeof(uint16_t) * m_numSurface));
    if (m_surfaceList == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    memcpy(m_surfaceList, ptr, sizeof(uint16_t) * m_numSurface);
    ptr += sizeof(uint16_t) * m_numSurface;
    rest -= sizeof(uint16_t) * m_numSurface;

    /* material ptr (color, texture, toon parameter, edge flag) */
    m_numMaterial = *reinterpret_cast<uint32_t *>(ptr);
    if (m_numMaterial * sizeof(PMDFile_Material) > rest) {
        MMDAILogWarnString("Size of materials exceeds size of PMD");
        goto error;
    }

    ptr += sizeof(uint32_t);
    rest -= sizeof(uint32_t);

    m_material = m_engine->allocateMaterials(m_numMaterial);
    fileMaterial = (PMDFile_Material *) ptr;
    for (uint32_t i = 0; i < m_numMaterial; i++) {
        if (!m_material[i]->setup(&fileMaterial[i], loader)) {
            /* ret = false; */
        }
    }

    ptr += sizeof(PMDFile_Material) * m_numMaterial;
    rest -= sizeof(PMDFile_Material) * m_numMaterial;

    /* bone ptr */
    m_numBone = *reinterpret_cast<uint16_t *>(ptr);
    if (m_numBone * sizeof(PMDFile_Bone) > rest) {
        MMDAILogWarnString("Size of bones exceeds size of PMD");
        goto error;
    }

    ptr += sizeof(uint16_t);
    rest -= sizeof(uint16_t);

    m_boneList = new PMDBone[m_numBone];
    if (m_boneList == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    fileBone = reinterpret_cast<PMDFile_Bone *>(ptr);
    for (uint32_t i = 0; i < m_numBone; i++) {
        PMDBone *bone = &m_boneList[i];
        if (!bone->setup(&(fileBone[i]), m_boneList, m_numBone, &m_rootBone))
            ret = false;
        if (MMDAIStringEquals(bone->getName(), centerBoneName))
            m_centerBone = bone;
    }
    if (!m_centerBone && m_numBone >= 1) {
        /* if no bone is named "center," use the first bone as center */
        m_centerBone = &(m_boneList[0]);
    }

    ptr += sizeof(PMDFile_Bone) * m_numBone;
    rest -= sizeof(PMDFile_Bone) * m_numBone;

    /* make ordered bone list */
    if (m_numBone > 0) {
        m_orderedBoneList = static_cast<PMDBone **>(MMDAIMemoryAllocate(sizeof(PMDBone *) * m_numBone));
        uint16_t k = 0;
        for (uint16_t i = 0; i < m_numBone; i++) {
            if (fileBone[i].parentBoneID == -1)
                m_orderedBoneList[k++] = &(m_boneList[i]);
        }
        uint16_t l = k;
        for (uint16_t i = 0; i < m_numBone; i++) {
            if (fileBone[i].parentBoneID != -1)
                m_orderedBoneList[l++] = &(m_boneList[i]);
        }
        uint16_t i = 0;
        do {
            for (uint16_t j = k; j < m_numBone; j++) {
                for (l = 0; l < j; l++) {
                    if (m_orderedBoneList[l] == m_orderedBoneList[j]->getParentBone())
                        break;
                }
                if (l >= j) {
                    PMDBone *bone = m_orderedBoneList[j];
                    if (j < m_numBone - 1)
                        memmove(m_orderedBoneList[j], m_orderedBoneList[j+1], sizeof(PMDBone *) * (m_numBone - 1 - j));
                    m_orderedBoneList[m_numBone - 1] = bone;
                    i = 1;
                }
            }
        } while (i != 0);
    }

    /* calculate bone offset after all bone positions are loaded */
    for (uint32_t i = 0; i < m_numBone; i++)
        m_boneList[i].computeOffset();

    /* IK ptr */
    m_numIK = *reinterpret_cast<uint16_t *>(ptr);
    if (m_numIK * sizeof(PMDFile_IK) > rest) {
        MMDAILogWarnString("Size of IKs exceeds size of PMD");
        goto error;
    }

    ptr += sizeof(uint16_t);
    rest -= sizeof(uint16_t);

    if (m_numIK > 0) {
        m_IKList = new PMDIK[m_numIK];
        if (m_IKList == NULL) {
            MMDAILogWarnString("Cannot allocate memory");
            goto error;
        }
        for (uint32_t i = 0; i < m_numIK; i++) {
            PMDFile_IK *fileIK = (PMDFile_IK *) ptr;
            ptr += sizeof(PMDFile_IK);
            rest -= sizeof(PMDFile_IK);
            m_IKList[i].setup(fileIK, (int16_t *)ptr, m_boneList);
            ptr += sizeof(int16_t) * fileIK->numLink;
            rest -= sizeof(int16_t) * fileIK->numLink;
        }
    }

    /* face ptr */
    m_numFace = *reinterpret_cast<uint16_t *>(ptr);
    if (m_numFace * sizeof(PMDFile_Face) > rest) {
        MMDAILogWarnString("Size of IKs exceeds size of PMD");
        goto error;
    }

    ptr += sizeof(uint16_t);
    rest -= sizeof(uint16_t);

    if (m_numFace > 0) {
        m_faceList = new PMDFace[m_numFace];
        if (m_faceList == NULL) {
            MMDAILogWarnString("Cannot allocate memory");
            goto error;
        }
        for (uint32_t i = 0; i < m_numFace; i++) {
            PMDFace *face = &m_faceList[i];
            PMDFile_Face *fileFace = (PMDFile_Face *)ptr;
            ptr += sizeof(PMDFile_Face);
            rest -= sizeof(PMDFile_Face);
            face->setup(fileFace, (PMDFile_Face_Vertex *) ptr);
            if (fileFace->type == PMD_FACE_BASE)
                m_baseFace = face; /* store base face */
            ptr += sizeof(PMDFile_Face_Vertex) * fileFace->numVertex;
            rest -= sizeof(PMDFile_Face_Vertex) * fileFace->numVertex;
        }
        if (m_baseFace == NULL) {
            ret = false;
        } else {
            /* convert base-relative index to the index of original vertices */
            for (uint32_t i = 0; i < m_numFace; i++)
                m_faceList[i].convertIndex(m_baseFace);
        }
    }

    /* display names (skip) */
    /* indices for faces which should be displayed in "face" region */
    m_numFaceDisplayNames = *reinterpret_cast<uint8_t *>(ptr);
    if (m_numFaceDisplayNames * sizeof(uint16_t) > rest) {
        MMDAILogWarnString("Size of display face names exceeds size of PMD");
        goto error;
    }

    m_faceDisplayNames = static_cast<uint16_t *>(MMDAIMemoryAllocate(sizeof(uint16_t) * m_numFaceDisplayNames));
    if (m_faceDisplayNames == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    ptr += sizeof(uint8_t);
    rest -= sizeof(uint8_t);

    memcpy(m_faceDisplayNames, ptr, sizeof(uint16_t) * m_numFaceDisplayNames);

    ptr += sizeof(uint16_t) * m_numFaceDisplayNames;
    rest -= sizeof(uint16_t) * m_numFaceDisplayNames;

    /* bone frame names */
    m_numBoneFrameNames = *reinterpret_cast<uint8_t *>(ptr);
    if (static_cast<size_t>(m_numBoneFrameNames * 50) > rest) {
        MMDAILogWarnString("Size of display bone frame names exceeds size of PMD");
        goto error;
    }

    m_boneFrameNames = static_cast<char **>(MMDAIMemoryAllocate(sizeof(void *) * m_numBoneFrameNames));
    if (m_boneFrameNames == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    ptr += sizeof(uint8_t);
    rest -= sizeof(uint8_t);

    for (uint32_t i = 0; i < m_numBoneFrameNames; i++) {
        char buf[51];
        MMDAIStringCopySafe(buf, reinterpret_cast<const char *>(ptr), sizeof(buf));
        m_boneFrameNames[i] = MMDAIStringClone(buf);
        ptr += 50;
        rest -= 50;
        MMDAILogDebugSJIS("frame=\"%s\"", buf);
    }

    /* indices for bones which should be displayed in each bone region */
    m_numBoneDisplayNames = *reinterpret_cast<uint32_t *>(ptr);
    if (m_numBoneDisplayNames * (sizeof(int16_t) + sizeof(uint8_t)) > rest) {
        MMDAILogWarnString("Size of display bone names exceeds size of PMD");
        goto error;
    }

    m_boneDisplayIndices = static_cast<uint16_t *>(MMDAIMemoryAllocate(sizeof(uint16_t) * m_numBoneDisplayNames));
    m_boneDisplayNames = static_cast<uint8_t *>(MMDAIMemoryAllocate(sizeof(uint8_t) * m_numBoneDisplayNames));
    if (m_boneDisplayIndices == NULL || m_boneDisplayNames == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    ptr += sizeof(uint32_t);
    rest -= sizeof(uint32_t);

    for (uint32_t i = 0; i < m_numBoneDisplayNames; i++) {
        m_boneDisplayIndices[i] = *reinterpret_cast<uint16_t *>(ptr);
        ptr += sizeof(uint16_t);
        m_boneDisplayNames[i] = *reinterpret_cast<uint8_t *>(ptr);
        ptr += sizeof(uint8_t);
        rest -= sizeof(uint16_t) + sizeof(uint8_t);
    }

    /* end of base format */
    /* check for remaining ptr */
    if (rest == 0) {
        /* no extension ptr remains */
        m_numRigidBody = 0;
        m_numConstraint = 0;
        /* assign default toon textures for toon shading */
        for (uint32_t i = 0; i < kNSystemTextureFiles; i++) {
            PMDTexture *texture = &m_localToonTexture[i];
            texture->setRenderEngine(m_engine);
            loader->loadSystemTexture(i, texture);
        }
    } else {
        /* English display names (skip) */
        uint8_t englishNameExist = *((uint8_t *) ptr);
        ptr += sizeof(uint8_t);
        rest -= sizeof(uint8_t);
        if (englishNameExist != 0) {
            /* model name and comments in English */
            ptr += 20 + 256;
            rest -= 20 + 256;
            /* bone names in English */
            ptr += 20 * m_numBone;
            rest -= 20 * m_numBone;
            /* face names in English */
            if (m_numFace > 0) {
                /* "base" not included in English list */
                ptr += 20 * (m_numFace - 1);
                rest -= 20 * (m_numFace - 1);
            }
            /* bone frame names in English */
            ptr += 50 * m_numBoneFrameNames;
            rest -= 50 * m_numBoneFrameNames;
        }

        /* toon texture file list (replace toon01.bmp - toon10.bmp) */
        /* the "toon0.bmp" should be loaded separatedly */
        PMDTexture *texture = &m_localToonTexture[0];
        texture->setRenderEngine(m_engine);
        loader->loadSystemTexture(0, texture);
        for (uint32_t i = 1; i < kNSystemTextureFiles; i++) {
            char exToonBMPName[100];
            memcpy(exToonBMPName, ptr, sizeof(exToonBMPName));
            exToonBMPName[sizeof(exToonBMPName) - 1] = 0;
            texture = &m_localToonTexture[i];
            texture->setRenderEngine(m_engine);
            loader->loadModelTexture(exToonBMPName, texture);
            ptr += sizeof(exToonBMPName);
            rest -= sizeof(exToonBMPName);
        }

        /* check for remaining ptr */
        if (rest == 0) {
            /* no rigid body / constraint ptr exist */
            m_numRigidBody = 0;
            m_numConstraint = 0;
        } else {
            btVector3 modelOffset = m_rootBone.getOffset();
            /* update bone matrix to apply root bone offset to bone position */
            for (uint32_t i = 0; i < m_numBone; i++)
                m_orderedBoneList[i]->update();

            /* Bullet Physics rigidbody ptr */
            m_numRigidBody = *reinterpret_cast<uint32_t *>(ptr);
            if (m_numRigidBody * sizeof(PMDFile_RigidBody) > rest) {
                MMDAILogWarnString("Size of rigid bodies exceeds size of PMD");
                goto error;
            }
            ptr += sizeof(uint32_t);
            rest -= sizeof(uint32_t);
            if (m_numRigidBody > 0) {
                m_rigidBodyList = new PMDRigidBody[m_numRigidBody];
                if (m_rigidBodyList == NULL) {
                    MMDAILogWarnString("Cannot allocate memory");
                    goto error;
                }
                PMDFile_RigidBody *fileRigidBody = reinterpret_cast<PMDFile_RigidBody *>(ptr);
                for (uint32_t i = 0; i < m_numRigidBody; i++) {
                    PMDFile_RigidBody *rb = &fileRigidBody[i];
                    if (! m_rigidBodyList[i].setup(rb, (rb->boneID == 0xFFFF) ? m_centerBone : &(m_boneList[rb->boneID])))
                        ret = false;
                    m_rigidBodyList[i].joinWorld(m_bulletPhysics->getWorld());
                    /* flag the bones under simulation in order to skip IK solving for those bones */
                    if (rb->type != 0 && rb->boneID != 0xFFFF)
                        m_boneList[rb->boneID].setSimulated(true);
                }
                ptr += sizeof(PMDFile_RigidBody) * m_numRigidBody;
                rest -= sizeof(PMDFile_RigidBody) * m_numRigidBody;
            }

            /* BulletPhysics constraint ptr */
            m_numConstraint = *reinterpret_cast<uint32_t *>(ptr);
            if (m_numConstraint * sizeof(PMDFile_Constraint) > rest) {
                MMDAILogWarnString("Size of constraints exceeds size of PMD");
                goto error;
            }
            ptr += sizeof(uint32_t);
            rest -= sizeof(uint32_t);
            if (m_numConstraint > 0) {
                m_constraintList = new PMDConstraint[m_numConstraint];
                if (m_constraintList == NULL) {
                    MMDAILogWarnString("Cannot allocate memory");
                    goto error;
                }
                PMDFile_Constraint *fileConstraint = reinterpret_cast<PMDFile_Constraint *>(ptr);
                for (uint32_t i = 0; i < m_numConstraint; i++) {
                    if (!m_constraintList[i].setup(&fileConstraint[i], m_rigidBodyList, &modelOffset))
                        ret = false;
                    m_constraintList[i].joinWorld(m_bulletPhysics->getWorld());
                }
                ptr += sizeof(PMDFile_Constraint) * m_numConstraint;
                rest -= sizeof(PMDFile_Constraint) * m_numConstraint;
            }
            assert(rest == 0);
        }
    }

    if (ret == false)
        goto error;

#ifdef MMDFILES_CONVERTCOORDINATESYSTEM
    /* left-handed system: PMD, DirectX */
    /* right-handed system: OpenGL, bulletphysics */
    /* convert the left-handed vertices to right-handed system */
    /* 1. vectors should be (x, y, -z) */
    /* 2. rotation should be (-rx, -ry, z) */
    /* 3. surfaces should be reversed */
    /* reverse Z value on vertices */
    for (uint32_t i = 0; i < m_numVertex; i++) {
        m_vertexList[i].setZ(-m_vertexList[i].z());
        m_normalList[i].setZ(-m_normalList[i].z());
    }
    /* reverse surface, swapping vartex order [0] and [1] in a triangle surface */
    for (uint32_t i = 0; i < m_numSurface; i += 3) {
        uint32_t j = m_surfaceList[i];
        m_surfaceList[i] = m_surfaceList[i+1];
        m_surfaceList[i+1] = j;
    }
#endif

    /* prepare work area */
    /* transforms for skinning */
    m_boneSkinningTrans = new btTransform[m_numBone];
    if (m_boneSkinningTrans == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    /* calculated Vertex informations for skinning */
    m_skinnedVertexList = new btVector3[m_numVertex];
    if (m_skinnedVertexList == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    m_skinnedNormalList = new btVector3[m_numVertex];
    if (m_skinnedNormalList == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    /* calculated Texture coordinates for toon shading */
    m_toonTexCoordList = static_cast<TexCoord *>(MMDAIMemoryAllocate(sizeof(TexCoord) * m_numVertex));
    if (m_toonTexCoordList == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    /* calculated Vertex positions for toon edge drawing */
    m_edgeVertexList = new btVector3[m_numVertex];
    if (m_edgeVertexList == NULL) {
        MMDAILogWarnString("Cannot allocate memory");
        goto error;
    }

    /* surface list to be rendered at edge drawing (skip non-edge materials) */
    m_numSurfaceForEdge = 0;

    for (uint32_t i = 0; i < m_numMaterial; i++) {
        PMDMaterial *m = m_material[i];
        if (m->hasEdge())
            m_numSurfaceForEdge += m->countSurfaces();
    }
    if (m_numSurfaceForEdge > 0) {
        m_surfaceListForEdge = static_cast<uint16_t *>(MMDAIMemoryAllocate(sizeof(uint16_t) * m_numSurfaceForEdge));
        if (m_surfaceListForEdge == NULL) {
            MMDAILogWarnString("Cannot allocate memory");
            goto error;
        }
        uint16_t *surfaceFrom = m_surfaceList;
        uint16_t *surfaceTo = m_surfaceListForEdge;
        for (uint32_t i = 0; i < m_numMaterial; i++) {
            PMDMaterial *m = m_material[i];
            uint32_t n = m->countSurfaces();
            if (m->hasEdge()) {
                memcpy(surfaceTo, surfaceFrom, sizeof(uint16_t) * n);
                surfaceTo += n;
            }
            surfaceFrom += n;
        }
    }

    /* check if spheremap is used (single or multiple) */
    for (uint32_t i = 0; i < m_numMaterial; i++) {
        PMDMaterial *m = m_material[i];
        if (m->hasSingleSphereMap())
            m_hasSingleSphereMap = true;
        if (m->hasMultipleSphereMap())
            m_hasMultipleSphereMap = true;
    }

    /* make index of rotation-subjective bones (type == UNDER_ROTATE or FOLLOW_RORATE) */
    m_numRotateBone = 0;
    for (uint32_t i = 0; i < m_numBone; i++) {
        uint8_t type = m_boneList[i].getType();
        if (type == UNDER_ROTATE || type == FOLLOW_ROTATE)
            m_numRotateBone++;
    }
    if (m_numRotateBone > 0) {
        m_rotateBoneIDList = static_cast<uint16_t *>(MMDAIMemoryAllocate(sizeof(uint16_t) * m_numRotateBone));
        if (m_rotateBoneIDList == NULL) {
            MMDAILogWarnString("Cannot allocate memory");
            goto error;
        }
        for (uint32_t i = 0, j = 0; i < m_numBone; i++) {
            uint8_t type = m_boneList[i].getType();
            if (type == UNDER_ROTATE || type == FOLLOW_ROTATE)
                m_rotateBoneIDList[j++] = i;
        }
    }

    /* check if some IK solvers can be disabled since the bones are simulated by physics */
    if (m_numIK > 0) {
        m_IKSimulated = static_cast<bool *>(MMDAIMemoryAllocate(sizeof(bool) * m_numIK));
        if (m_IKSimulated == NULL) {
            MMDAILogWarnString("Cannot allocate memory");
            goto error;
        }
        for (uint32_t i = 0; i < m_numIK; i++) {
            /* this IK will be disabled when the leaf bone is controlled by physics simulation */
            m_IKSimulated[i] = m_IKList[i].isSimulated();
        }
    }

    /* mark motion independency for each bone */
    for (uint32_t i = 0; i < m_numBone; i++)
        m_boneList[i].setMotionIndependency();

    /* build name->entity index for fast lookup */
    for (uint32_t i = 0; i < m_numBone; i++) {
        PMDBone *bone = &m_boneList[i];
        const char *name = bone->getName();
        PMDBone *bMatch = static_cast<PMDBone *>(m_name2bone.findNearest(name));
        if (bMatch == NULL || !MMDAIStringEquals(bMatch->getName(), name))
            m_name2bone.add(name, bone, (bMatch) ? bMatch->getName() : NULL); /* add */
    }
    for (uint32_t i = 0; i < m_numFace; i++) {
        PMDFace *face = &m_faceList[i];
        const char *name = face->getName();
        PMDFace *fMatch = static_cast<PMDFace *>(m_name2face.findNearest(name));
        if (fMatch == NULL || !MMDAIStringEquals(fMatch->getName(), name))
            m_name2face.add(name, face, (fMatch) ? fMatch->getName() : NULL); /* add */
    }

    /* get maximum height */
    if (m_numVertex > 0) {
        m_maxHeight = m_vertexList[0].y();
        for (uint32_t i = 1; i < m_numVertex; i++) {
            float y = m_vertexList[i].y();
            if (m_maxHeight < y)
                m_maxHeight = y;
        }
    }

    m_boundingSphereStep = m_numVertex / kBoundingSpherePoints;
    if (m_boundingSphereStep > kBoundingSpherePointsMax)
        m_boundingSphereStep = kBoundingSpherePointsMax;
    if (m_boundingSphereStep < kBoundingSpherePointsMin)
        m_boundingSphereStep = kBoundingSpherePointsMin;

    /* simulation is currently off, so change bone status */
    if (!m_enableSimulation)
        setPhysicsControl(false);
    loader->unloadModelData(start);

    return true;

    error:
    loader->unloadModelData(start);
    release();
    return false;
}

} /* namespace */

