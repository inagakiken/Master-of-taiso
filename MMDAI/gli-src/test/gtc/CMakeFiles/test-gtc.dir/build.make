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
include test/gtc/CMakeFiles/test-gtc.dir/depend.make

# Include the progress variables for this target.
include test/gtc/CMakeFiles/test-gtc.dir/progress.make

# Include the compile flags for this target's objects.
include test/gtc/CMakeFiles/test-gtc.dir/flags.make

test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o: test/gtc/CMakeFiles/test-gtc.dir/flags.make
test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o: test/gtc/gtc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tk/Downloads/gli-0.4.1.0/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o"
	cd /home/tk/Downloads/gli-0.4.1.0/test/gtc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test-gtc.dir/gtc.cpp.o -c /home/tk/Downloads/gli-0.4.1.0/test/gtc/gtc.cpp

test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-gtc.dir/gtc.cpp.i"
	cd /home/tk/Downloads/gli-0.4.1.0/test/gtc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tk/Downloads/gli-0.4.1.0/test/gtc/gtc.cpp > CMakeFiles/test-gtc.dir/gtc.cpp.i

test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-gtc.dir/gtc.cpp.s"
	cd /home/tk/Downloads/gli-0.4.1.0/test/gtc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tk/Downloads/gli-0.4.1.0/test/gtc/gtc.cpp -o CMakeFiles/test-gtc.dir/gtc.cpp.s

test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o.requires:
.PHONY : test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o.requires

test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o.provides: test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o.requires
	$(MAKE) -f test/gtc/CMakeFiles/test-gtc.dir/build.make test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o.provides.build
.PHONY : test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o.provides

test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o.provides.build: test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o

# Object files for target test-gtc
test__gtc_OBJECTS = \
"CMakeFiles/test-gtc.dir/gtc.cpp.o"

# External object files for target test-gtc
test__gtc_EXTERNAL_OBJECTS =

test/gtc/test-gtc: test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o
test/gtc/test-gtc: test/gtc/CMakeFiles/test-gtc.dir/build.make
test/gtc/test-gtc: test/gtc/CMakeFiles/test-gtc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test-gtc"
	cd /home/tk/Downloads/gli-0.4.1.0/test/gtc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-gtc.dir/link.txt --verbose=$(VERBOSE)
	cd /home/tk/Downloads/gli-0.4.1.0/test/gtc && /usr/bin/cmake -E copy_directory /home/tk/Downloads/gli-0.4.1.0/test/gtc/data /home/tk/Downloads/gli-0.4.1.0/test/gtc/data

# Rule to build all files generated by this target.
test/gtc/CMakeFiles/test-gtc.dir/build: test/gtc/test-gtc
.PHONY : test/gtc/CMakeFiles/test-gtc.dir/build

test/gtc/CMakeFiles/test-gtc.dir/requires: test/gtc/CMakeFiles/test-gtc.dir/gtc.cpp.o.requires
.PHONY : test/gtc/CMakeFiles/test-gtc.dir/requires

test/gtc/CMakeFiles/test-gtc.dir/clean:
	cd /home/tk/Downloads/gli-0.4.1.0/test/gtc && $(CMAKE_COMMAND) -P CMakeFiles/test-gtc.dir/cmake_clean.cmake
.PHONY : test/gtc/CMakeFiles/test-gtc.dir/clean

test/gtc/CMakeFiles/test-gtc.dir/depend:
	cd /home/tk/Downloads/gli-0.4.1.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tk/Downloads/gli-0.4.1.0 /home/tk/Downloads/gli-0.4.1.0/test/gtc /home/tk/Downloads/gli-0.4.1.0 /home/tk/Downloads/gli-0.4.1.0/test/gtc /home/tk/Downloads/gli-0.4.1.0/test/gtc/CMakeFiles/test-gtc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/gtc/CMakeFiles/test-gtc.dir/depend

