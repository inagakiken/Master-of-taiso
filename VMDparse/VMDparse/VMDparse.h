

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PTree.h"
#include "btVector3.h"
#include "btQuaternion.h"


#define VMD_INTERPOLATIONTABLESIZE 64 /* motion interpolation table size */

/* convert from/to radian */
#define MMDFILES_RAD(a) (a * (3.1415926f / 180.0f))
#define MMDFILES_DEG(a) (a * (180.0f / 3.1415926f))

/* VMDFile_Header: header structure for VMD file reading */
typedef struct _VMDFile_Header {
   char header[30]; /* "Vocaloid Motion Data 0002" */
   char name[20];   /* model name (unused) */
} VMDFile_Header;

/* VMDFile_BoneFrame: bone motion element structure for VMD file reading */
typedef struct _VMDFile_BoneFrame {
   char name[15];          /* bone name */
   unsigned long keyFrame; /* key frame */
   float pos[3];           /* position (x, y, z) */
   float rot[4];           /* rotation (x, y, z, w) */
   char interpolation[64]; /* interpolation parameters */
} VMDFile_BoneFrame;

/* VMDFile_FaceFrame: face motion element structure for VMD file reading */
typedef struct _VMDFile_FaceFrame {
   char name[15];          /* face name */
   unsigned long keyFrame; /* key frame */
   float weight;           /* weight (0.0 - 1.0) */
} VMDFile_FaceFrame;

/* VMDFile_Camera: camera motion element structure for VMD file reading */
typedef struct _VMDFile_CameraFrame {
   unsigned long keyFrame; /* key frame */
   float distance;
   float pos[3];
   float angle[3];
   char interpolation[24]; /* interpolation parameters */
   unsigned long viewAngle;
   unsigned char noPerspective;
} VMDFile_CameraFrame;

/* BoneKeyFrame: bone key frame */
typedef struct _BoneKeyFrame {
   float keyFrame;               /* key frame */
   btVector3 pos;                /* translation position */
   btQuaternion rot;             /* rotation */
   bool linear[4];               /* this is liner interpolation, use simpler calculation */
   float *interpolationTable[4]; /* table for interpolation */
} BoneKeyFrame;

/* BoneMotion: bone motion unit (list of key frames for a bone defined in a VMD file) */
typedef struct _BoneMotion {
   char *name;                 /* bone name */
   unsigned long numKeyFrame;  /* number of defined key frames */
   BoneKeyFrame *keyFrameList; /* list of key frame data */
} BoneMotion;

/* BoneMotionLink: linked list of defined bone motions in a VMD data */
typedef struct _BoneMotionLink {
   BoneMotion boneMotion; /* bone motion unit */
   struct _BoneMotionLink *next;
} BoneMotionLink;

/* FaceKeyFrame: face key frame */
typedef struct _FaceKeyFrame {
   float keyFrame; /* key frame */
   float weight;   /* face weight */
} FaceKeyFrame;

/* FaceMotion: face motion unit (list of key frames for a face defined in a VMD file) */
typedef struct _FaceMotion {
   char *name;                 /* face name */
   unsigned long numKeyFrame;  /* number of defined key frames */
   FaceKeyFrame *keyFrameList; /* list of key frame data */
} FaceMotion;

/* FaceMotionLink: linked list of defined face motions in a VMD data */
typedef struct _FaceMotionLink {
   FaceMotion faceMotion; /* face motion unit */
   struct _FaceMotionLink *next;
} FaceMotionLink;

/* CameraKeyFrame: camera key frame */
typedef struct _CameraKeyFrame {
   float keyFrame;               /* key frame */
   float distance;               /* distance */
   btVector3 pos;                /* translation position */
   btVector3 angle;              /* angle */
   bool linear[6];               /* this is liner interpolation, use simpler calculation */
   float *interpolationTable[6]; /* table for interpolation */
   float fovy;                   /* view angle */
   unsigned char noPerspective;  /* true when perspective is off */
} CameraKeyFrame;

/* CameraMotion: camera motion unit */
typedef struct _CameraMotion {
   unsigned long numKeyFrame;    /* number of defined key frames */
   CameraKeyFrame *keyFrameList; /* list of key frame data */
} CameraMotion;

/* VMD: motion file class */
class VMD
{
private:
public:

   unsigned long m_numTotalBoneKeyFrame; /* total number of bone frames */
   unsigned long m_numTotalFaceKeyFrame; /* total number of face frames */
   unsigned long m_numTotalCameraKeyFrame; /* total number of camera frames */

   PTree m_name2bone;
   PTree m_name2face;

   BoneMotionLink *m_boneLink;   /* linked list of bones in the motion */
   FaceMotionLink *m_faceLink;   /* linked list of faces in the motion */
   CameraMotion *m_cameraMotion; /* list of camera key frame data */

   unsigned long m_numBoneKind; /* number of bones in m_boneLink */
   unsigned long m_numFaceKind; /* number of faces in m_faceLink */

   float m_maxFrame; /* max frame */

   /* addBoneMotion: add new bone motion to list */
   void addBoneMotion(const char *name);

   /* addFaceMotion: add new face motion to list */
   void addFaceMotion(const char *name);

   /* getBoneMotion: find bone motion by name */
   BoneMotion * getBoneMotion(const char *name);

   /* getFaceMotion: find face motion by name */
   FaceMotion * getFaceMotion(const char *name);

   /* setBoneInterpolationTable: set up bone motion interpolation parameter */
   void setBoneInterpolationTable(BoneKeyFrame *bf, const char *ip);

   /* setCameraInterpolationTable: set up camera motion interpolation parameter */
   void setCameraInterpolationTable(CameraKeyFrame *cf, const char *ip);

   /* initialize: initialize VMD */
   void initialize();

   /* clear: free VMD */
   void clear();
   
//public:

   /* VMD: constructor */
   VMD();

   /* ~VMD: destructor */
   ~VMD();

   /* load: initialize and load from file name */
   bool load(const char *file);

   /* parse: initialize and load from data memories */
   bool parse(const unsigned char *data, unsigned long size);

   /* getTotalKeyFrame: get total number of key frames */
   unsigned long getTotalKeyFrame();

   /* getBoneMotionLink: get list of bone motions */
   BoneMotionLink * getBoneMotionLink();

   /* getFaceMotionLink: get list of face motions */
   FaceMotionLink * getFaceMotionLink();

   /* getCameraMotion: get camera motion */
   CameraMotion *getCameraMotion();

   /* getNumBoneKind: get number of bone motions */
   unsigned long getNumBoneKind();

   /* getNumFaceKind: get number of face motions */
   unsigned long getNumFaceKind();

   /* getMaxFrame: get max frame */
   float getMaxFrame();
};
