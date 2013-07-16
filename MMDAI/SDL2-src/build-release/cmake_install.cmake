# Install script for directory: /home/tk/MMDAI/SDL2-src

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/tk/MMDAI/SDL2-src/build-release/install-root")
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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/tk/MMDAI/SDL2-src/build-release/lib/libSDL2.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/tk/MMDAI/SDL2-src/build-release/lib/libSDL2.so.2.0.0"
    "/home/tk/MMDAI/SDL2-src/build-release/lib/libSDL2.so.0"
    "/home/tk/MMDAI/SDL2-src/build-release/lib/libSDL2.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.so.2.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/tk/MMDAI/SDL2-src/build-release/lib/libSDL2main.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "/home/tk/MMDAI/SDL2-src/include/SDL_config_psp.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_gesture.h"
    "/home/tk/MMDAI/SDL2-src/include/begin_code.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_mouse.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_keyboard.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_name.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_revision.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_main.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_hints.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_test_fuzzer.h"
    "/home/tk/MMDAI/SDL2-src/include/close_code.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_thread.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_config_windows.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_opengl.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_atomic.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_test_common.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_touch.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_joystick.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_quit.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_video.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_scancode.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_test_font.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_test_compare.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_power.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_events.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_types.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_pixels.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_config_macosx.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_syswm.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_config_wiz.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_config_minimal.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_bits.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_test_images.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_test.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_log.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_test_crc32.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_messagebox.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_test_md5.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_version.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_config_pandora.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_opengles2.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_surface.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_system.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_test_log.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_error.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_endian.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_gamecontroller.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_test_assert.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_rwops.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_mutex.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_test_random.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_shape.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_cpuinfo.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_opengles.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_test_harness.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_audio.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_blendmode.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_timer.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_clipboard.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_config_android.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_assert.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_stdinc.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_config_iphoneos.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_rect.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_loadso.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_platform.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_keycode.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_haptic.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_render.h"
    "/home/tk/MMDAI/SDL2-src/include/SDL_copying.h"
    "/home/tk/MMDAI/SDL2-src/build-release/include/SDL_config.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/tk/MMDAI/SDL2-src/build-release/sdl2.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/home/tk/MMDAI/SDL2-src/build-release/sdl2-config")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/aclocal" TYPE FILE FILES "/home/tk/MMDAI/SDL2-src/sdl2.m4")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/tk/MMDAI/SDL2-src/build-release/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/tk/MMDAI/SDL2-src/build-release/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
