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
include test/gtx/CMakeFiles/test-gtx.dir/depend.make

# Include the progress variables for this target.
include test/gtx/CMakeFiles/test-gtx.dir/progress.make

# Include the compile flags for this target's objects.
include test/gtx/CMakeFiles/test-gtx.dir/flags.make

test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o: test/gtx/CMakeFiles/test-gtx.dir/flags.make
test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o: test/gtx/gtx.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tk/Downloads/gli-0.4.1.0/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o"
	cd /home/tk/Downloads/gli-0.4.1.0/test/gtx && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test-gtx.dir/gtx.cpp.o -c /home/tk/Downloads/gli-0.4.1.0/test/gtx/gtx.cpp

test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-gtx.dir/gtx.cpp.i"
	cd /home/tk/Downloads/gli-0.4.1.0/test/gtx && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tk/Downloads/gli-0.4.1.0/test/gtx/gtx.cpp > CMakeFiles/test-gtx.dir/gtx.cpp.i

test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-gtx.dir/gtx.cpp.s"
	cd /home/tk/Downloads/gli-0.4.1.0/test/gtx && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tk/Downloads/gli-0.4.1.0/test/gtx/gtx.cpp -o CMakeFiles/test-gtx.dir/gtx.cpp.s

test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o.requires:
.PHONY : test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o.requires

test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o.provides: test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o.requires
	$(MAKE) -f test/gtx/CMakeFiles/test-gtx.dir/build.make test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o.provides.build
.PHONY : test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o.provides

test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o.provides.build: test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o

# Object files for target test-gtx
test__gtx_OBJECTS = \
"CMakeFiles/test-gtx.dir/gtx.cpp.o"

# External object files for target test-gtx
test__gtx_EXTERNAL_OBJECTS =

test/gtx/test-gtx: test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o
test/gtx/test-gtx: test/gtx/CMakeFiles/test-gtx.dir/build.make
test/gtx/test-gtx: test/gtx/CMakeFiles/test-gtx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test-gtx"
	cd /home/tk/Downloads/gli-0.4.1.0/test/gtx && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-gtx.dir/link.txt --verbose=$(VERBOSE)
	cd /home/tk/Downloads/gli-0.4.1.0/test/gtx && /usr/bin/cmake -E copy_directory /home/tk/Downloads/gli-0.4.1.0/test/gtx/data /home/tk/Downloads/gli-0.4.1.0/test/gtx/data

# Rule to build all files generated by this target.
test/gtx/CMakeFiles/test-gtx.dir/build: test/gtx/test-gtx
.PHONY : test/gtx/CMakeFiles/test-gtx.dir/build

test/gtx/CMakeFiles/test-gtx.dir/requires: test/gtx/CMakeFiles/test-gtx.dir/gtx.cpp.o.requires
.PHONY : test/gtx/CMakeFiles/test-gtx.dir/requires

test/gtx/CMakeFiles/test-gtx.dir/clean:
	cd /home/tk/Downloads/gli-0.4.1.0/test/gtx && $(CMAKE_COMMAND) -P CMakeFiles/test-gtx.dir/cmake_clean.cmake
.PHONY : test/gtx/CMakeFiles/test-gtx.dir/clean

test/gtx/CMakeFiles/test-gtx.dir/depend:
	cd /home/tk/Downloads/gli-0.4.1.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tk/Downloads/gli-0.4.1.0 /home/tk/Downloads/gli-0.4.1.0/test/gtx /home/tk/Downloads/gli-0.4.1.0 /home/tk/Downloads/gli-0.4.1.0/test/gtx /home/tk/Downloads/gli-0.4.1.0/test/gtx/CMakeFiles/test-gtx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/gtx/CMakeFiles/test-gtx.dir/depend
