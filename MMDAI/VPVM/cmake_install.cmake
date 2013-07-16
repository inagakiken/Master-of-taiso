# Install script for directory: /home/tk/MMDAI/VPVM

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
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

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Runtime")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./MMDAI2" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./MMDAI2")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./MMDAI2"
         RPATH "/usr/local:$ORIGIN:/home/tk/MMDAI/libav-src/build-release/install-root/lib:/home/tk/MMDAI/tbb-src/lib:/home/tk/MMDAI/zlib-src/build-release/install-root/lib:/home/tk/MMDAI/openal-soft-src/build-release/install-root/lib")
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE FILES "/home/tk/MMDAI/VPVM/MMDAI2")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./MMDAI2" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./MMDAI2")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./MMDAI2"
         OLD_RPATH "/home/tk/MMDAI/libav-src/build-release/install-root/lib:/home/tk/MMDAI/tbb-src/lib:/home/tk/MMDAI/zlib-src/build-release/install-root/lib:/home/tk/MMDAI/openal-soft-src/build-release/install-root/lib:::::::::::::::::::"
         NEW_RPATH "/usr/local:$ORIGIN:/home/tk/MMDAI/libav-src/build-release/install-root/lib:/home/tk/MMDAI/tbb-src/lib:/home/tk/MMDAI/zlib-src/build-release/install-root/lib:/home/tk/MMDAI/openal-soft-src/build-release/install-root/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./MMDAI2")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Runtime")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/resources" TYPE FILE FILES
    "/usr/share/qt4/translations/qt_help_cs.qm"
    "/usr/share/qt4/translations/qt_zh_TW.qm"
    "/usr/share/qt4/translations/qt_help_uk.qm"
    "/usr/share/qt4/translations/qt_help_de.qm"
    "/usr/share/qt4/translations/qt_he.qm"
    "/usr/share/qt4/translations/qt_help_ru.qm"
    "/usr/share/qt4/translations/qt_pl.qm"
    "/usr/share/qt4/translations/qt_ar.qm"
    "/usr/share/qt4/translations/qt_help_sl.qm"
    "/usr/share/qt4/translations/qt_ja.qm"
    "/usr/share/qt4/translations/qt_es.qm"
    "/usr/share/qt4/translations/qt_help_ko.qm"
    "/usr/share/qt4/translations/qt_help_pl.qm"
    "/usr/share/qt4/translations/qt_lt.qm"
    "/usr/share/qt4/translations/qt_de.qm"
    "/usr/share/qt4/translations/qt_hu.qm"
    "/usr/share/qt4/translations/qt_ru.qm"
    "/usr/share/qt4/translations/qt_fa.qm"
    "/usr/share/qt4/translations/qt_help_hu.qm"
    "/usr/share/qt4/translations/qt_pt.qm"
    "/usr/share/qt4/translations/qt_sv.qm"
    "/usr/share/qt4/translations/qt_help_gl.qm"
    "/usr/share/qt4/translations/qt_uk.qm"
    "/usr/share/qt4/translations/qt_fr.qm"
    "/usr/share/qt4/translations/qt_help_fr.qm"
    "/usr/share/qt4/translations/qt_help_zh_TW.qm"
    "/usr/share/qt4/translations/qt_zh_CN.qm"
    "/usr/share/qt4/translations/qt_help_ja.qm"
    "/usr/share/qt4/translations/qt_sl.qm"
    "/usr/share/qt4/translations/qt_ko.qm"
    "/usr/share/qt4/translations/qt_cs.qm"
    "/usr/share/qt4/translations/qt_da.qm"
    "/usr/share/qt4/translations/qt_help_zh_CN.qm"
    "/usr/share/qt4/translations/qt_sk.qm"
    "/usr/share/qt4/translations/qt_help_da.qm"
    "/usr/share/qt4/translations/qt_gl.qm"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/resources" TYPE FILE FILES "/home/tk/MMDAI/VPVM/VPVM_ja.qm")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/plugins" TYPE DIRECTORY FILES "/usr/lib/i386-linux-gnu/qt4/plugins/imageformats")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Runtime")
  
  file(WRITE "${CMAKE_INSTALL_PREFIX}/resources/qt.conf" "")
  file(GLOB_RECURSE QTPLUGINS "${CMAKE_INSTALL_PREFIX}/plugins/*.so")
  #file(MAKE_DIRECTORY "${CMAKE_INSTALL_PREFIX}/lib")
  list(APPEND DIRS_TO_FIND_LIBRARY "/home/tk/MMDAI/VPVM/../libav-src/build-release/install-root/lib")
  list(APPEND DIRS_TO_FIND_LIBRARY "/lib")
  list(APPEND DIRS_TO_FIND_LIBRARY "/lib")
  include(BundleUtilities)
  fixup_bundle("/usr/local/MMDAI2" "${QTPLUGINS}" "${DIRS_TO_FIND_LIBRARY}")
  get_bundle_keys("/usr/local/MMDAI2" "" "${DIRS_TO_FIND_LIBRARY}" keys)
  foreach(key ${keys})
    list(APPEND CMAKE_INSTALL_MANIFEST_FILES "${${key}_RESOLVED_EMBEDDED_ITEM}")
  endforeach()
  
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Runtime")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/tk/MMDAI/VPVM/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/tk/MMDAI/VPVM/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
