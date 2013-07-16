/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Copyright (c) 2010-2011  hkrn                                    */
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

#ifndef QMASCENEPLAYER_H
#define QMASCENEPLAYER_H

#include <MMDAI/CommandParser.h>
#include <MMDAI/ISceneEventHandler.h>

#include "QMADebugRenderEngine.h"
#include "QMAModelLoaderFactory.h"
#include "QMAPlugin.h"
#include "QMATextRenderEngine.h"
#include "QMATimer.h"

/* to load glee correctly, should include QtOpenGL after MMDAI/MMDME */
#include <QtOpenGL>

namespace MMDAI {
class PMDObject;
class SceneController;
}

class QMAPreference;

class QMAScenePlayer : public QGLWidget, public MMDAI::ISceneEventHandler
{
    Q_OBJECT

public:
    QMAScenePlayer(QMAPreference *preference, QWidget *parent = 0);
    ~QMAScenePlayer();

    virtual void initialize();
    virtual void loadPlugins();
    virtual void start();
    virtual void reload(const QString &filename);

    bool addModel(const QString &filename);
    bool changeModel(const QString &filename);
    bool changeModel(const QString &filename, MMDAI::PMDObject *object);
    bool deleteModel();
    bool deleteModel(MMDAI::PMDObject *object);
    bool setStage(const QString &filename);
    bool setFloor(const QString &filename);
    bool setBackground(const QString &filename);
    bool insertMotionToAllModels(const QString &filename);
    bool insertMotionToSelectedModel(const QString &filename);
    bool insertMotionToModel(const QString &filename, MMDAI::PMDObject *object);
    void rotate(float x, float y);
    void translate(float x, float y);
    void selectModel(const QString &name);
    void setEdgeThin(float value);
    void setEnablePhysicalEngine(bool value);
    void updateShadowMapping();
    void loadUserPreference(const QString &path);

    void handleEventMessage(const char *eventType, int argc, ...);
    void setBaseMotion(MMDAI::PMDObject *object, MMDAI::IMotionLoader *loader);
    void zoom(bool up, Qt::KeyboardModifiers modifiers);
    void createMenu(const QHash<QString, QMenu*> &menuBar);

    inline const QMATimer &getSceneFrameTimer() const {
        return m_sceneFrameTimer;
    }

public slots:
    void delegateCommand(const QString &command, const QList<QVariant> &arguments);
    void delegateEvent(const QString &type, const QList<QVariant> &arguments);
    inline void toggleDisplayBone() {
        m_debug->toggleRenderBones();
    }
    inline void toggleDisplayRigidBody() {
        m_debug->toggleRenderRigidBodies();
    }

signals:
    void pluginLoaded(MMDAI::SceneController *, const QString &);
    void pluginUnloaded();
    void pluginCommandPost(const QString&, const QList<QVariant>&);
    void pluginEventPost(const QString&, const QList<QVariant>&);

protected:
    virtual bool handleCommand(const QString &command, const QList<QVariant> &arguments);
    virtual bool handleEvent(const QString &command, const QList<QVariant> &arguments);

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void closeEvent(QCloseEvent *event);
    void setUserPreference(const QString &filename, QFile &file);
    void createActions();

    MMDAI::SceneController *m_controller;
    QMADebugRenderEngine *m_debug;
    QMAPreference *m_preference;
    int m_interval;

protected slots:
    void hideText();
    void updateScene();
    void insertMotionToAllModels();
    void insertMotionToSelectedModel();
    void addModel();
    void setStage();
    void setFloor();
    void setBackground();
    void rotateUp();
    void rotateDown();
    void rotateLeft();
    void rotateRight();
    void translateUp();
    void translateDown();
    void translateLeft();
    void translateRight();
    void increaseEdgeThin();
    void decreaseEdgeThin();
    void togglePhysicSimulation();
    void toggleShadowMapping();
    void toggleShadowMappingLightFirst();
    void speak();
    void zoomIn();
    void zoomOut();
    void selectObject();
    void changeSelectedObject();
    void deleteSelectedObject();
    void saveScene();

private:
    void loadModel();
    void addPlugin(QMAPlugin *plugin);
    const QString openFileDialog(const QString &name, const QString &description, const QString &extensions);

    void updateModelPositionAndRotation(double fps);
    void renderDebugModel();
    void renderLogger();

    QMAModelLoaderFactory m_factory;
    QMATextRenderEngine m_text;
    QMATimer m_sceneFrameTimer;
    QTimer m_sceneUpdateTimer;
    MMDAI::CommandParser *m_parser;

    QMenu *m_selectModelMenu;
    QAction *m_insertMotionToAllAction;
    QAction *m_insertMotionToSelectedAction;
    QAction *m_addModelAction;
    QAction *m_setStageAction;
    QAction *m_setFloorAction;
    QAction *m_setBackgroundAction;
    QAction *m_saveSceneAction;
    QAction *m_increaseEdgeThinAction;
    QAction *m_decreaseEdgeThinAction;
    QAction *m_toggleDisplayBoneAction;
    QAction *m_toggleDisplayRigidBodyAction;
    QAction *m_togglePhysicSimulationAction;
    QAction *m_toggleShadowMappingAction;
    QAction *m_toggleShadowMappingFirstAction;
    QAction *m_speakAction;
    QAction *m_zoomInAction;
    QAction *m_zoomOutAction;
    QAction *m_rotateUpAction;
    QAction *m_rotateDownAction;
    QAction *m_rotateLeftAction;
    QAction *m_rotateRightAction;
    QAction *m_translateUpAction;
    QAction *m_translateDownAction;
    QAction *m_translateLeftAction;
    QAction *m_translateRightAction;
    QAction *m_changeSelectedObjectAction;
    QAction *m_deleteSelectedObjectAction;

    int m_x;
    int m_y;
    bool m_doubleClicked;
    bool m_showLog;
    bool m_enablePhysicsSimulation;

    Q_DISABLE_COPY(QMAScenePlayer)
};

#endif // QMASCENEPLAYER_H
