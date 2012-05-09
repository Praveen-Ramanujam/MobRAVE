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
CMAKE_SOURCE_DIR = /home/raman/openrave

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/raman/openrave/src

# Include any dependencies generated for this target.
include plugins/baserobots/CMakeFiles/baserobots.dir/depend.make

# Include the progress variables for this target.
include plugins/baserobots/CMakeFiles/baserobots.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/baserobots/CMakeFiles/baserobots.dir/flags.make

plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o: plugins/baserobots/CMakeFiles/baserobots.dir/flags.make
plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o: ../plugins/baserobots/baserobots.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o"
	cd /home/raman/openrave/src/plugins/baserobots && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL  -fPIC -o CMakeFiles/baserobots.dir/baserobots.cpp.o -c /home/raman/openrave/plugins/baserobots/baserobots.cpp

plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baserobots.dir/baserobots.cpp.i"
	cd /home/raman/openrave/src/plugins/baserobots && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL  -fPIC -E /home/raman/openrave/plugins/baserobots/baserobots.cpp > CMakeFiles/baserobots.dir/baserobots.cpp.i

plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baserobots.dir/baserobots.cpp.s"
	cd /home/raman/openrave/src/plugins/baserobots && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL  -fPIC -S /home/raman/openrave/plugins/baserobots/baserobots.cpp -o CMakeFiles/baserobots.dir/baserobots.cpp.s

plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o.requires:
.PHONY : plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o.requires

plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o.provides: plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o.requires
	$(MAKE) -f plugins/baserobots/CMakeFiles/baserobots.dir/build.make plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o.provides.build
.PHONY : plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o.provides

plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o.provides.build: plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o
.PHONY : plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o.provides.build

# Object files for target baserobots
baserobots_OBJECTS = \
"CMakeFiles/baserobots.dir/baserobots.cpp.o"

# External object files for target baserobots
baserobots_EXTERNAL_OBJECTS =

plugins/baserobots/libbaserobots.so: plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o
plugins/baserobots/libbaserobots.so: src/libopenrave/libopenrave0.5.so.0.5.0
plugins/baserobots/libbaserobots.so: /usr/lib/libxml2.so
plugins/baserobots/libbaserobots.so: /usr/lib/libboost_date_time-mt.so
plugins/baserobots/libbaserobots.so: /usr/lib/libboost_thread-mt.so
plugins/baserobots/libbaserobots.so: cpp-gen-md5/libopenrave-md5.a
plugins/baserobots/libbaserobots.so: /usr/lib/libboost_filesystem-mt.so
plugins/baserobots/libbaserobots.so: /usr/lib/libboost_system-mt.so
plugins/baserobots/libbaserobots.so: 3rdparty/crlibm-1.0beta4/libcrlibm.a
plugins/baserobots/libbaserobots.so: 3rdparty/fparser-4.3/libfparser.a
plugins/baserobots/libbaserobots.so: plugins/baserobots/CMakeFiles/baserobots.dir/build.make
plugins/baserobots/libbaserobots.so: plugins/baserobots/CMakeFiles/baserobots.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libbaserobots.so"
	cd /home/raman/openrave/src/plugins/baserobots && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/baserobots.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/baserobots/CMakeFiles/baserobots.dir/build: plugins/baserobots/libbaserobots.so
.PHONY : plugins/baserobots/CMakeFiles/baserobots.dir/build

plugins/baserobots/CMakeFiles/baserobots.dir/requires: plugins/baserobots/CMakeFiles/baserobots.dir/baserobots.cpp.o.requires
.PHONY : plugins/baserobots/CMakeFiles/baserobots.dir/requires

plugins/baserobots/CMakeFiles/baserobots.dir/clean:
	cd /home/raman/openrave/src/plugins/baserobots && $(CMAKE_COMMAND) -P CMakeFiles/baserobots.dir/cmake_clean.cmake
.PHONY : plugins/baserobots/CMakeFiles/baserobots.dir/clean

plugins/baserobots/CMakeFiles/baserobots.dir/depend:
	cd /home/raman/openrave/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raman/openrave /home/raman/openrave/plugins/baserobots /home/raman/openrave/src /home/raman/openrave/src/plugins/baserobots /home/raman/openrave/src/plugins/baserobots/CMakeFiles/baserobots.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/baserobots/CMakeFiles/baserobots.dir/depend
