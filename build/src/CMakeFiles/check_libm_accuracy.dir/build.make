# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/praveen/Work/openrave

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/praveen/Work/openrave/build

# Include any dependencies generated for this target.
include src/CMakeFiles/check_libm_accuracy.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/check_libm_accuracy.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/check_libm_accuracy.dir/flags.make

src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o: src/CMakeFiles/check_libm_accuracy.dir/flags.make
src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o: ../src/check_libm_accuracy_main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/praveen/Work/openrave/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o"
	cd /home/praveen/Work/openrave/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o -c /home/praveen/Work/openrave/src/check_libm_accuracy_main.cpp

src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.i"
	cd /home/praveen/Work/openrave/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/praveen/Work/openrave/src/check_libm_accuracy_main.cpp > CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.i

src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.s"
	cd /home/praveen/Work/openrave/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/praveen/Work/openrave/src/check_libm_accuracy_main.cpp -o CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.s

src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o.requires:
.PHONY : src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o.requires

src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o.provides: src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/check_libm_accuracy.dir/build.make src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o.provides.build
.PHONY : src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o.provides

src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o.provides.build: src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o
.PHONY : src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o.provides.build

# Object files for target check_libm_accuracy
check_libm_accuracy_OBJECTS = \
"CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o"

# External object files for target check_libm_accuracy
check_libm_accuracy_EXTERNAL_OBJECTS =

src/check_libm_accuracy: src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o
src/check_libm_accuracy: 3rdparty/crlibm-1.0beta4/libcrlibm.a
src/check_libm_accuracy: src/CMakeFiles/check_libm_accuracy.dir/build.make
src/check_libm_accuracy: src/CMakeFiles/check_libm_accuracy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable check_libm_accuracy"
	cd /home/praveen/Work/openrave/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/check_libm_accuracy.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Checking accuracy between libm and crlibm"
	cd /home/praveen/Work/openrave/build/src && ./check_libm_accuracy /home/praveen/Work/openrave/build/src/libm_accuracy_results.h

# Rule to build all files generated by this target.
src/CMakeFiles/check_libm_accuracy.dir/build: src/check_libm_accuracy
.PHONY : src/CMakeFiles/check_libm_accuracy.dir/build

src/CMakeFiles/check_libm_accuracy.dir/requires: src/CMakeFiles/check_libm_accuracy.dir/check_libm_accuracy_main.cpp.o.requires
.PHONY : src/CMakeFiles/check_libm_accuracy.dir/requires

src/CMakeFiles/check_libm_accuracy.dir/clean:
	cd /home/praveen/Work/openrave/build/src && $(CMAKE_COMMAND) -P CMakeFiles/check_libm_accuracy.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/check_libm_accuracy.dir/clean

src/CMakeFiles/check_libm_accuracy.dir/depend:
	cd /home/praveen/Work/openrave/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/praveen/Work/openrave /home/praveen/Work/openrave/src /home/praveen/Work/openrave/build /home/praveen/Work/openrave/build/src /home/praveen/Work/openrave/build/src/CMakeFiles/check_libm_accuracy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/check_libm_accuracy.dir/depend
