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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/raman/openrave/src/cppexamples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/raman/openrave/src/cppexamples/build

# Include any dependencies generated for this target.
include CMakeFiles/ikfastloader.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ikfastloader.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ikfastloader.dir/flags.make

CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o: CMakeFiles/ikfastloader.dir/flags.make
CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o: ../ikfastloader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/src/cppexamples/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -o CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o -c /home/raman/openrave/src/cppexamples/ikfastloader.cpp

CMakeFiles/ikfastloader.dir/ikfastloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ikfastloader.dir/ikfastloader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -E /home/raman/openrave/src/cppexamples/ikfastloader.cpp > CMakeFiles/ikfastloader.dir/ikfastloader.cpp.i

CMakeFiles/ikfastloader.dir/ikfastloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ikfastloader.dir/ikfastloader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -S /home/raman/openrave/src/cppexamples/ikfastloader.cpp -o CMakeFiles/ikfastloader.dir/ikfastloader.cpp.s

CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o.requires:
.PHONY : CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o.requires

CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o.provides: CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o.requires
	$(MAKE) -f CMakeFiles/ikfastloader.dir/build.make CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o.provides.build
.PHONY : CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o.provides

CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o.provides.build: CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o
.PHONY : CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o.provides.build

# Object files for target ikfastloader
ikfastloader_OBJECTS = \
"CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o"

# External object files for target ikfastloader
ikfastloader_EXTERNAL_OBJECTS =

ikfastloader: CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o
ikfastloader: CMakeFiles/ikfastloader.dir/build.make
ikfastloader: CMakeFiles/ikfastloader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ikfastloader"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ikfastloader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ikfastloader.dir/build: ikfastloader
.PHONY : CMakeFiles/ikfastloader.dir/build

CMakeFiles/ikfastloader.dir/requires: CMakeFiles/ikfastloader.dir/ikfastloader.cpp.o.requires
.PHONY : CMakeFiles/ikfastloader.dir/requires

CMakeFiles/ikfastloader.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ikfastloader.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ikfastloader.dir/clean

CMakeFiles/ikfastloader.dir/depend:
	cd /home/raman/openrave/src/cppexamples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raman/openrave/src/cppexamples /home/raman/openrave/src/cppexamples /home/raman/openrave/src/cppexamples/build /home/raman/openrave/src/cppexamples/build /home/raman/openrave/src/cppexamples/build/CMakeFiles/ikfastloader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ikfastloader.dir/depend

