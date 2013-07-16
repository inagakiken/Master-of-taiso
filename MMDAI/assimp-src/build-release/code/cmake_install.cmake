# Install script for directory: /home/tk/MMDAI/assimp-src/code

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/tk/MMDAI/assimp-src/build-release/install-root")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tk/MMDAI/assimp-src/build-release/install-root/lib/libassimp.a")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/tk/MMDAI/assimp-src/build-release/install-root/lib" TYPE STATIC_LIBRARY FILES "/home/tk/MMDAI/assimp-src/build-release/code/libassimp.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiAnim.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiAssert.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiCamera.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiColor4D.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiColor4D.inl;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiConfig.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiDefines.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiFileIO.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiLight.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiMaterial.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiMaterial.inl;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiMatrix3x3.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiMatrix3x3.inl;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiMatrix4x4.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiMatrix4x4.inl;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiMesh.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiPostProcess.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiQuaternion.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiScene.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiTexture.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiTypes.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiVector2D.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiVector3D.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiVector3D.inl;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/aiVersion.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/assimp.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/assimp.hpp;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/DefaultLogger.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/ProgressHandler.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/IOStream.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/IOSystem.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/Logger.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/LogStream.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/NullLogger.h")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp" TYPE FILE FILES
    "/home/tk/MMDAI/assimp-src/code/../include/aiAnim.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiAssert.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiCamera.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiColor4D.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiColor4D.inl"
    "/home/tk/MMDAI/assimp-src/code/../include/aiConfig.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiDefines.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiFileIO.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiLight.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiMaterial.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiMaterial.inl"
    "/home/tk/MMDAI/assimp-src/code/../include/aiMatrix3x3.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiMatrix3x3.inl"
    "/home/tk/MMDAI/assimp-src/code/../include/aiMatrix4x4.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiMatrix4x4.inl"
    "/home/tk/MMDAI/assimp-src/code/../include/aiMesh.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiPostProcess.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiQuaternion.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiScene.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiTexture.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiTypes.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiVector2D.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiVector3D.h"
    "/home/tk/MMDAI/assimp-src/code/../include/aiVector3D.inl"
    "/home/tk/MMDAI/assimp-src/code/../include/aiVersion.h"
    "/home/tk/MMDAI/assimp-src/code/../include/assimp.h"
    "/home/tk/MMDAI/assimp-src/code/../include/assimp.hpp"
    "/home/tk/MMDAI/assimp-src/code/../include/DefaultLogger.h"
    "/home/tk/MMDAI/assimp-src/code/../include/ProgressHandler.h"
    "/home/tk/MMDAI/assimp-src/code/../include/IOStream.h"
    "/home/tk/MMDAI/assimp-src/code/../include/IOSystem.h"
    "/home/tk/MMDAI/assimp-src/code/../include/Logger.h"
    "/home/tk/MMDAI/assimp-src/code/../include/LogStream.h"
    "/home/tk/MMDAI/assimp-src/code/../include/NullLogger.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/Compiler/pushpack1.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/Compiler/poppack1.h;/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/Compiler/pstdint.h")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/tk/MMDAI/assimp-src/build-release/install-root/include/assimp/Compiler" TYPE FILE FILES
    "/home/tk/MMDAI/assimp-src/code/../include/Compiler/pushpack1.h"
    "/home/tk/MMDAI/assimp-src/code/../include/Compiler/poppack1.h"
    "/home/tk/MMDAI/assimp-src/code/pstdint.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

