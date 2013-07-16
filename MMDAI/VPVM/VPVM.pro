QT += core gui opengl
greaterThan(QT_MAJOR_VERSION, 4):QT += widgets concurrent

TARGET = MMDAI2
TEMPLATE = app
DEFINES += IS_VPVM
macx:DEFINES += USE_FILE32API

# libvpvl2 and base libraries
ALSOFT_PATH = ../openal-soft-src
ALURE_PATH = ../alure-src
ASSIMP_PATH = ../assimp-src
BULLET_PATH = ../bullet-src
VPVL1_PATH = ../libvpvl
VPVL2_PATH = ../libvpvl2
LIBAV_PATH = ../libav-src
NVTT_PATH = ../nvtt-src
GLEW_PATH = ../glew-src
GLM_PATH = ../glm-src
PORTAUDIO_PATH = ../portaudio-src
LIBXML2_PATH = ../libxml2-src
#ICU_PATH = ../icu-src
ZLIB_PATH = ../zlib-src
INSTALL_ROOT_DIR = install-root
GLOG_PATH = ../glog-src
ICU_PATH = ../icu4c-src
TBB_PATH = ../tbb-src

# CMake prefix path (mainly for win32)
exists($$(CMAKE_PREFIX_PATH)/include):INCLUDEPATH += "$$(CMAKE_PREFIX_PATH)/include"
exists($$(CMAKE_PREFIX_PATH)/lib):LIBS += -L"$$(CMAKE_PREFIX_PATH)/lib"

# configuration by build type
CONFIG(debug, debug|release) {
  BUILD_TYPE = debug
  VPVL2_LIBRARY_SUFFIX = _debug
}
CONFIG(release, debug|release):BUILD_TYPE = release

# configuration by CPU architecure
CONFIG(x86, x86|x86_64):BUILD_TYPE_SUFFIX = -32
CONFIG(x86_64, x86|x86_64):BUILD_TYPE_SUFFIX = -64

greaterThan(QT_MAJOR_VERSION, 4):BUILD_DIRECTORY_VPVL2_SUFFIX  = -qt5
BUILD_DIRECTORY = build-$${BUILD_TYPE}
BASE_LIBRARY_PATH = $${BUILD_DIRECTORY}/lib
PRODUCT_DIRECTORY = $${BUILD_DIRECTORY}/$${INSTALL_ROOT_DIR}
VPVL2_BUILD_DIRECTORY = $${BUILD_DIRECTORY}$${BUILD_DIRECTORY_VPVL2_SUFFIX}
win32 {
  LIBRARY_PATH = $${BASE_LIBRARY_PATH}/$${BUILD_TYPE}
  ASSIMP_LIBRARY_PATH = $${ASSIMP_PATH}/$${BUILD_DIRECTORY}/code/$${BUILD_TYPE}
  ASSIMP_INCLUDE_PATH = $${ASSIMP_PATH}/include
  ALSOFT_LIBRARY_PATH = $${ALSOFT_PATH}/$${BUILD_DIRECTORY}/lib/$${BUILD_TYPE}
  ALSOFT_INCLUDE_PATH = $${ALSOFT_PATH}/include/AL
  ALURE_INCLUDE_PATH = $${ALURE_PATH}/include
  ALURE_LIBRARY_PATH = $${ALURE_PATH}/$${BUILD_DIRECTORY}/$${BUILD_TYPE}
  BULLET_LIBRARY_PATH = $${BULLET_PATH}/$${LIBRARY_PATH}
  BULLET_INCLUDE_PATH = $${BULLET_PATH}/src
  GLEW_LIBRARY_PATH = $${GLEW_PATH}/lib
  ICU_LIBRARY_PATH = $${ICU_PATH}/lib
  LIBXML2_LIBRARY_PATH = $${LIBXML2_PATH}/win32/bin.msvc
  LIBXML2_INCLUDE_PATH = $${LIBXML2_PATH}/include
  VPVL1_LIBRARY_PATH = $${VPVL1_PATH}/$${LIBRARY_PATH}
  VPVL2_LIBRARY_PATH = $${VPVL2_PATH}/$${VPVL2_BUILD_DIRECTORY}/lib/$${BUILD_TYPE}
  VPVL2_INCLUDE_DIRS = $${VPVL2_PATH}/include $${VPVL2_PATH}/$${BUILD_DIRECTORY}/include
  ZLIB_LIBRARY_PATH = $${ZLIB_PATH}/$${LIBRARY_PATH}
  LIBS += -L$${NVTT_PATH}/$${BUILD_DIRECTORY}/src/nvcore/$${BUILD_TYPE} \
          -L$${NVTT_PATH}/$${BUILD_DIRECTORY}/src/nvimage/$${BUILD_TYPE} \
          -L$${NVTT_PATH}/$${BUILD_DIRECTORY}/src/nvmath/$${BUILD_TYPE} \
          -L$$(TBB_INSTALL_DIR)/lib/$$(TBB_ARCH_PLATFORM)
}
!win32 {
  CONFIG(debug, debug|release) {
    VPVL2_LIBRARY_PATH = $${VPVL2_PATH}/$${BUILD_DIRECTORY}/lib
    VPVL2_INCLUDE_DIRS = $${VPVL2_PATH}/include $${VPVL2_PATH}/$${BUILD_DIRECTORY}/include
  }
  else {
    VPVL2_LIBRARY_PATH = $${VPVL2_PATH}/$${BUILD_DIRECTORY}/$${INSTALL_ROOT_DIR}/lib
    VPVL2_INCLUDE_DIRS = $${VPVL2_PATH}/$${PRODUCT_DIRECTORY}/include
  }
  ASSIMP_LIBRARY_PATH = $${ASSIMP_PATH}/$${PRODUCT_DIRECTORY}/lib
  ASSIMP_INCLUDE_PATH = $${ASSIMP_PATH}/$${PRODUCT_DIRECTORY}/include/
  ALSOFT_LIBRARY_PATH = $${ALSOFT_PATH}/$${PRODUCT_DIRECTORY}/lib
  ALSOFT_INCLUDE_PATH = $${ALSOFT_PATH}/$${PRODUCT_DIRECTORY}/include
  ALURE_LIBRARY_PATH = $${ALURE_PATH}/$${PRODUCT_DIRECTORY}/lib
  ALURE_INCLUDE_PATH = $${ALURE_PATH}/$${PRODUCT_DIRECTORY}/include
  BULLET_LIBRARY_PATH = $${BULLET_PATH}/$${PRODUCT_DIRECTORY}/lib
  BULLET_INCLUDE_PATH = $${BULLET_PATH}/$${PRODUCT_DIRECTORY}/include/bullet
  GLOG_INCLUDE_PATH = $${GLOG_PATH}/$${PRODUCT_DIRECTORY}/include
  GLOG_LIBRARY_PATH = $${GLOG_PATH}/$${PRODUCT_DIRECTORY}/lib
  GLEW_LIBRARY_PATH = $${GLEW_PATH}/$${PRODUCT_DIRECTORY}/lib
  ICU_LIBRARY_PATH = $${ICU_PATH}/$${PRODUCT_DIRECTORY}/lib
  LIBAV_INCLUDE_PATH = $${LIBAV_PATH}/$${PRODUCT_DIRECTORY}/include
  LIBXML2_LIBRARY_PATH = $${LIBXML2_PATH}/$${PRODUCT_DIRECTORY}/lib
  LIBXML2_INCLUDE_PATH = $${LIBXML2_PATH}/$${PRODUCT_DIRECTORY}/include/libxml2
  ZLIB_LIBRARY_PATH = $${ZLIB_PATH}/$${BASE_LIBRARY_PATH}
  VPVL1_LIBRARY_PATH = $${VPVL1_PATH}/lib
  TBB_INCLUDE_PATH = $${TBB_PATH}/include
  TBB_LIBRARY_PATH = $${TBB_PATH}/lib
  CONFIG(debug, debug|release):LIBS += -L$${NVTT_PATH}/$${PRODUCT_DIRECTORY}/lib
  CONFIG(release, debug|release):LIBS += -L$${NVTT_PATH}/$${PRODUCT_DIRECTORY}/lib/static
}

# VPVL and others configuration
LIBS        += -L$${VPVL1_LIBRARY_PATH} \
               -L$${VPVL2_LIBRARY_PATH} \
               -L$${ALSOFT_LIBRARY_PATH} \
               -L$${ALURE_LIBRARY_PATH} \
               -L$${ASSIMP_LIBRARY_PATH} \
               -L$${BULLET_LIBRARY_PATH} \
               -L$${ICU_LIBRARY_PATH} \
               -L$${GLEW_LIBRARY_PATH} \
               -L$${ZLIB_LIBRARY_PATH} \
               -L$${LIBXML2_LIBRARY_PATH} \
                -L$${GLOG_LIBRARY_PATH} \
                -L$${TBB_LIBRARY_PATH}
INCLUDEPATH += $${ALSOFT_INCLUDE_PATH} \
               $${ALURE_INCLUDE_PATH} \
               $${ASSIMP_INCLUDE_PATH} \
               $${BULLET_INCLUDE_PATH} \
               $${NVTT_PATH}/$${BUILD_DIRECTORY}/src \
               $${NVTT_PATH}/extern/poshlib \
               $${NVTT_PATH}/src \
               $${GLEW_PATH}/include \
               $${GLM_PATH} \
               $${LIBXML2_INCLUDE_PATH} \
               $${ZLIB_PATH} \
               $${ZLIB_PATH}/$${BUILD_DIRECTORY} \
               $${LIBAV_INCLUDE_PATH} \
               $${VPVL2_INCLUDE_DIRS} \
               include \
                $${GLOG_INCLUDE_PATH}\
                $${TBB_INCLUDE_PATH}

# Required libraries
LIBS += -lvpvl2qtcommon \
        -lvpvl2 \
        -lvpvl \
        -ltbb \
       -lopenal \
        -lassimp \
        -lBulletSoftBody \
        -lBulletDynamics \
        -lBulletCollision \
        -lLinearMath \
        -lnvimage \
       -lnvmath \
        -lnvcore\
        -lglog

CONFIG(debug, debug|release):LIBS += -ltbb_debug -ltbbmalloc_debug
CONFIG(release, debug|release):LIBS += -ltbb -ltbbmalloc

win32 {
  INCLUDEPATH += $${ICU_PATH}/include
  CONFIG(debug, debug|release):LIBS += -llibxml2_a -lglew32sd -lglew32mxsd -licuind -licuucd -lzlibstaticd
  CONFIG(release, debug|release):LIBS += -llibxml2_a -lglew32s -lglew32mxs -licuin -licuuc -lzlibstatic
  LIBS += -licudt \
          -lalure32-static
}
!win32 {
  INCLUDEPATH += $${ICU_PATH}/source/common \
                 $${ICU_PATH}/source/i18n
  LIBS +=  -lalure-static \
 #          -lxml2 \
           -lGLEW \
           -licui18n \
           -licuuc \
           -licudata \
           -lz
}

macx:LIBS += -framework OpenCL \
             -framework CoreServices \
             -framework Cg \
             -framework CoreAudio \
             -framework AudioToolbox \
             -framework AudioUnit
linux-*:LIBS += -lCg -lCgGL

# based on QtCreator's qmake spec
DEFINES += QT_NO_CAST_TO_ASCII
contains(QT_CONFIG, reduce_exports):CONFIG += hide_symbols
unix {
  CONFIG(debug, debug|release):OBJECTS_DIR = $${OUT_PWD}/.obj/debug-shared
  CONFIG(release, debug|release):OBJECTS_DIR = $${OUT_PWD}/.obj/release-shared
  CONFIG(debug, debug|release):MOC_DIR = $${OUT_PWD}/.moc/debug-shared
  CONFIG(release, debug|release):MOC_DIR = $${OUT_PWD}/.moc/release-shared
  RCC_DIR = $${OUT_PWD}/.rcc
  UI_DIR = $${OUT_PWD}/.uic
}

translations.files = resources/translations/VPVM_ja.qm \
                     $$[QT_INSTALL_TRANSLATIONS]/qt_ja.qm
win32 {
  NVIDIA_CG_PATH  = "C:/Program Files (x86)/NVIDIA Corporation/Cg"
  LIBS           += -L$${NVIDIA_CG_PATH}/lib -lcg -lcggl
  INCLUDEPATH    += $${NVIDIA_CG_PATH}/include
  QMAKE_CFLAGS   += /wd4068 /wd4819
  QMAKE_CXXFLAGS += /wd4068 /wd4819
  RC_FILE         = resources/icons/app.rc
}
macx {
  ICON = resources/icons/app.icns
  QMAKE_CXXFLAGS *= -mmacosx-version-min=10.6
  QMAKE_LFLAGS *= -mmacosx-version-min=10.6
  QMAKE_LFLAGS += -Wl,-rpath,@loader_path/../
  QMAKE_INFO_PLIST = resources/Info.plist
  translations.path = Contents/Resources
  QMAKE_BUNDLE_DATA += translations
  LIBS += -framework Cocoa
}
linux-* {
  QMAKE_RPATHDIR += \$\$ORIGIN
  QMAKE_RPATHDIR += \$\$ORIGIN/lib
  QMA_RPATH = $$join(QMAKE_RPATHDIR, ":")
  QMAKE_LFLAGS += $$QMAKE_LFLAGS_NOUNDEF -Wl,-z,origin \'-Wl,-rpath,$${QMA_RPATH}\'
  QMAKE_RPATHDIR =
  libraries.path = /lib
  libraries.files = $${LIBAV_PATH}/release_native/lib/libavcodec.so.* \
                    $${LIBAV_PATH}/release_native/lib/libavformat.so.* \
                    $${LIBAV_PATH}/release_native/lib/libavutil.so.* \
                    $${LIBAV_PATH}/release_native/lib/libswscale.so.* \
                    $${DEVIL_PATH}/release_native/lib/libIL.so.* \
                    $${DEVIL_PATH}/release_native/lib/libILU.so.* \
                    $${DEVIL_PATH}/release_native/lib/libILUT.so.* \
                    $$[QT_INSTALL_LIBS]/libQtCore.so.4 \
                    $$[QT_INSTALL_LIBS]/libQtGui.so.4 \
                    $$[QT_INSTALL_LIBS]/libQtOpenGL.so.4
  plugins.path = /plugins
  plugins.files = $$[QT_INSTALL_PLUGINS]/*
  INSTALLS += libraries plugins
}
!macx {
  translations.path = /locales
  INSTALLS += translations
}

SOURCES += src/core/main.cc \
    src/core/SceneWidget.cc \
    src/core/SceneLoader.cc \
    src/core/LoggerWidget.cc \
    src/core/StringHelper.cc \
    src/core/Handles.cc \
    src/models/PMDMotionModel.cc \
    src/models/BoneMotionModel.cc \
    src/models/MorphMotionModel.cc \
    src/models/MotionBaseModel.cc \
    src/models/SceneMotionModel.cc \
    src/dialogs/BoneDialog.cc \
    src/dialogs/ExportVideoDialog.cc \
    src/dialogs/FrameWeightDialog.cc \
    src/dialogs/InterpolationDialog.cc \
    src/dialogs/PlaySettingDialog.cc \
    src/dialogs/FrameSelectionDialog.cc \
    src/dialogs/PhysicsSettingDialog.cc \
    src/dialogs/RenderOrderDialog.cc \
    src/dialogs/ShadowMapSettingDialog.cc \
    src/dialogs/BackgroundImageSettingDialog.cc \
    src/widgets/TimelineWidget.cc \
    src/widgets/MorphWidget.cc \
    src/widgets/CameraPerspectiveWidget.cc \
    src/widgets/TabWidget.cc \
    src/widgets/TimelineTabWidget.cc \
    src/widgets/TimelineTreeView.cc \
    src/widgets/LicenseWidget.cc \
    src/widgets/AssetWidget.cc \
    src/widgets/ModelTabWidget.cc \
    src/widgets/InterpolationGraphWidget.cc \
    src/widgets/ModelInfoWidget.cc \
    src/widgets/SceneLightWidget.cc \
    src/widgets/ModelSettingWidget.cc \
    src/core/MainWindow.cc \
    src/core/BoneUIDelegate.cc \
    src/widgets/ScenePlayer.cc \
    src/video/AVFactory.cc \
    src/core/Grid.cc \
    src/core/BackgroundImage.cc

HEADERS  += \
    include/SceneWidget.h \
    include/Handles.h \
    include/SceneLoader.h \
    include/Grid.h \
    include/Application.h \
    include/InfoPanel.h \
    include/LoggerWidget.h \
    include/StringHelper.h \
    include/BackgroundImage.h \
    include/MotionBaseModel.h \
    include/BoneMotionModel.h \
    include/MorphMotionModel.h \
    include/SceneMotionModel.h \
    include/PMDMotionModel.h \
    include/BoneDialog.h \
    include/ExportVideoDialog.h \
    include/FrameWeightDialog.h \
    include/InterpolationDialog.h \
    include/PlaySettingDialog.h \
    include/FrameSelectionDialog.h \
    include/PhysicsSettingDialog.h \
    include/RenderOrderDialog.h \
    include/ShadowMapSettingDialog.h \
    include/BackgroundImageSettingDialog.h \
    include/MorphWidget.h \
    include/CameraPerspectiveWidget.h \
    include/TabWidget.h \
    include/TimelineTabWidget.h \
    include/TimelineTreeView.h \
    include/LicenseWidget.h \
    include/AssetWidget.h \
    include/ModelTabWidget.h \
    include/InterpolationGraphWidget.h \
    include/ModelInfoWidget.h \
    include/SceneLightWidget.h \
    include/ModelSettingWidget.h \
    include/TimelineWidget.h \
    include/IAudioDecoder.h \
    include/IVideoEncoder.h \
    include/MainWindow.h \
    include/BoneUIDelegate.h \
    include/ScenePlayer.h \
    include/AVFactory.h

!win32 {
    SOURCES += src/video/AudioDecoder.cc \
        src/video/AVCommon.cc \
        src/video/VideoEncoder.cc
    HEADERS += include/AudioDecoder.h \
        include/AVCommon.h \
        include/VideoEncoder.h
    DEFINES += VPVM_ENABLE_VIDEO
    LIBS += -L$${LIBAV_PATH}/$${PRODUCT_DIRECTORY}/lib \
            -lavcodec \
            -lavformat \
            -lavutil \
            -lswscale
}

CODECFORTR = UTF-8
RESOURCES += resources/VPVM.qrc
TRANSLATIONS += resources/translations/VPVM.ts
