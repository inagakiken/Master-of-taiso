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
CMAKE_SOURCE_DIR = /home/tk/Downloads/gli-0.4.1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tk/Downloads/gli-0.4.1.0

# Include any dependencies generated for this target.
include test/core/CMakeFiles/test-core_texture_cube.dir/depend.make

# Include the progress variables for this target.
include test/core/CMakeFiles/test-core_texture_cube.dir/progress.make

# Include the compile flags for this target's objects.
include test/core/CMakeFiles/test-core_texture_cube.dir/flags.make

test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o: test/core/CMakeFiles/test-core_texture_cube.dir/flags.make
test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o: test/core/core_texture_cube.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tk/Downloads/gli-0.4.1.0/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o"
	cd /home/tk/Downloads/gli-0.4.1.0/test/core && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o -c /home/tk/Downloads/gli-0.4.1.0/test/core/core_texture_cube.cpp

test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.i"
	cd /home/tk/Downloads/gli-0.4.1.0/test/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tk/Downloads/gli-0.4.1.0/test/core/core_texture_cube.cpp > CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.i

test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.s"
	cd /home/tk/Downloads/gli-0.4.1.0/test/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tk/Downloads/gli-0.4.1.0/test/core/core_texture_cube.cpp -o CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.s

test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o.requires:
.PHONY : test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o.requires

test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o.provides: test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o.requires
	$(MAKE) -f test/core/CMakeFiles/test-core_texture_cube.dir/build.make test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o.provides.build
.PHONY : test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o.provides

test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o.provides.build: test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o

# Object files for target test-core_texture_cube
test__core_texture_cube_OBJECTS = \
"CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o"

# External object files for target test-core_texture_cube
test__core_texture_cube_EXTERNAL_OBJECTS =

test/core/test-core_texture_cube: test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o
test/core/test-core_texture_cube: test/core/CMakeFiles/test-core_texture_cube.dir/build.make
test/core/test-core_texture_cube: test/core/CMakeFiles/test-core_texture_cube.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test-core_texture_cube"
	cd /home/tk/Downloads/gli-0.4.1.0/test/core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-core_texture_cube.dir/link.txt --verbose=$(VERBOSE)
	cd /home/tk/Downloads/gli-0.4.1.0/test/core && /usr/bin/cmake -E copy_directory /home/tk/Downloads/gli-0.4.1.0/test/core/data /home/tk/Downloads/gli-0.4.1.0/test/core/data

# Rule to build all files generated by this target.
test/core/CMakeFiles/test-core_texture_cube.dir/build: test/core/test-core_texture_cube
.PHONY : test/core/CMakeFiles/test-core_texture_cube.dir/build

test/core/CMakeFiles/test-core_texture_cube.dir/requires: test/core/CMakeFiles/test-core_texture_cube.dir/core_texture_cube.cpp.o.requires
.PHONY : test/core/CMakeFiles/test-core_texture_cube.dir/requires

test/core/CMakeFiles/test-core_texture_cube.dir/clean:
	cd /home/tk/Downloads/gli-0.4.1.0/test/core && $(CMAKE_COMMAND) -P CMakeFiles/test-core_texture_cube.dir/cmake_clean.cmake
.PHONY : test/core/CMakeFiles/test-core_texture_cube.dir/clean

test/core/CMakeFiles/test-core_texture_cube.dir/depend:
	cd /home/tk/Downloads/gli-0.4.1.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tk/Downloads/gli-0.4.1.0 /home/tk/Downloads/gli-0.4.1.0/test/core /home/tk/Downloads/gli-0.4.1.0 /home/tk/Downloads/gli-0.4.1.0/test/core /home/tk/Downloads/gli-0.4.1.0/test/core/CMakeFiles/test-core_texture_cube.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/core/CMakeFiles/test-core_texture_cube.dir/depend

