# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tk/MMDAI/zlib-src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tk/MMDAI/zlib-src/build-release

# Include any dependencies generated for this target.
include CMakeFiles/example64.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example64.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example64.dir/flags.make

CMakeFiles/example64.dir/test/example.o: CMakeFiles/example64.dir/flags.make
CMakeFiles/example64.dir/test/example.o: ../test/example.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tk/MMDAI/zlib-src/build-release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/example64.dir/test/example.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -D_FILE_OFFSET_BITS=64 -o CMakeFiles/example64.dir/test/example.o   -c /home/tk/MMDAI/zlib-src/test/example.c

CMakeFiles/example64.dir/test/example.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/example64.dir/test/example.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -D_FILE_OFFSET_BITS=64 -E /home/tk/MMDAI/zlib-src/test/example.c > CMakeFiles/example64.dir/test/example.i

CMakeFiles/example64.dir/test/example.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/example64.dir/test/example.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -D_FILE_OFFSET_BITS=64 -S /home/tk/MMDAI/zlib-src/test/example.c -o CMakeFiles/example64.dir/test/example.s

CMakeFiles/example64.dir/test/example.o.requires:
.PHONY : CMakeFiles/example64.dir/test/example.o.requires

CMakeFiles/example64.dir/test/example.o.provides: CMakeFiles/example64.dir/test/example.o.requires
	$(MAKE) -f CMakeFiles/example64.dir/build.make CMakeFiles/example64.dir/test/example.o.provides.build
.PHONY : CMakeFiles/example64.dir/test/example.o.provides

CMakeFiles/example64.dir/test/example.o.provides.build: CMakeFiles/example64.dir/test/example.o

# Object files for target example64
example64_OBJECTS = \
"CMakeFiles/example64.dir/test/example.o"

# External object files for target example64
example64_EXTERNAL_OBJECTS =

example64: CMakeFiles/example64.dir/test/example.o
example64: CMakeFiles/example64.dir/build.make
example64: lib/libz.so.1.2.7
example64: CMakeFiles/example64.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable example64"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example64.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example64.dir/build: example64
.PHONY : CMakeFiles/example64.dir/build

CMakeFiles/example64.dir/requires: CMakeFiles/example64.dir/test/example.o.requires
.PHONY : CMakeFiles/example64.dir/requires

CMakeFiles/example64.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example64.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example64.dir/clean

CMakeFiles/example64.dir/depend:
	cd /home/tk/MMDAI/zlib-src/build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tk/MMDAI/zlib-src /home/tk/MMDAI/zlib-src /home/tk/MMDAI/zlib-src/build-release /home/tk/MMDAI/zlib-src/build-release /home/tk/MMDAI/zlib-src/build-release/CMakeFiles/example64.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example64.dir/depend

