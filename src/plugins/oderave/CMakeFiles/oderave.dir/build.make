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
include plugins/oderave/CMakeFiles/oderave.dir/depend.make

# Include the progress variables for this target.
include plugins/oderave/CMakeFiles/oderave.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/oderave/CMakeFiles/oderave.dir/flags.make

plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o: plugins/oderave/CMakeFiles/oderave.dir/flags.make
plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o: ../plugins/oderave/oderave.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o"
	cd /home/raman/openrave/src/plugins/oderave && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL  -fPIC -I/usr/include -DdDOUBLE      -o CMakeFiles/oderave.dir/oderave.cpp.o -c /home/raman/openrave/plugins/oderave/oderave.cpp

plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oderave.dir/oderave.cpp.i"
	cd /home/raman/openrave/src/plugins/oderave && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL  -fPIC -I/usr/include -DdDOUBLE      -E /home/raman/openrave/plugins/oderave/oderave.cpp > CMakeFiles/oderave.dir/oderave.cpp.i

plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oderave.dir/oderave.cpp.s"
	cd /home/raman/openrave/src/plugins/oderave && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL  -fPIC -I/usr/include -DdDOUBLE      -S /home/raman/openrave/plugins/oderave/oderave.cpp -o CMakeFiles/oderave.dir/oderave.cpp.s

plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o.requires:
.PHONY : plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o.requires

plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o.provides: plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o.requires
	$(MAKE) -f plugins/oderave/CMakeFiles/oderave.dir/build.make plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o.provides.build
.PHONY : plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o.provides

plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o.provides.build: plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o
.PHONY : plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o.provides.build

# Object files for target oderave
oderave_OBJECTS = \
"CMakeFiles/oderave.dir/oderave.cpp.o"

# External object files for target oderave
oderave_EXTERNAL_OBJECTS =

plugins/oderave/liboderave.so: plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o
plugins/oderave/liboderave.so: src/libopenrave/libopenrave0.5.so.0.5.0
plugins/oderave/liboderave.so: /usr/lib/libxml2.so
plugins/oderave/liboderave.so: /usr/lib/libboost_date_time-mt.so
plugins/oderave/liboderave.so: /usr/lib/libboost_thread-mt.so
plugins/oderave/liboderave.so: cpp-gen-md5/libopenrave-md5.a
plugins/oderave/liboderave.so: /usr/lib/libboost_filesystem-mt.so
plugins/oderave/liboderave.so: /usr/lib/libboost_system-mt.so
plugins/oderave/liboderave.so: 3rdparty/crlibm-1.0beta4/libcrlibm.a
plugins/oderave/liboderave.so: 3rdparty/fparser-4.3/libfparser.a
plugins/oderave/liboderave.so: plugins/oderave/CMakeFiles/oderave.dir/build.make
plugins/oderave/liboderave.so: plugins/oderave/CMakeFiles/oderave.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library liboderave.so"
	cd /home/raman/openrave/src/plugins/oderave && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/oderave.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/oderave/CMakeFiles/oderave.dir/build: plugins/oderave/liboderave.so
.PHONY : plugins/oderave/CMakeFiles/oderave.dir/build

plugins/oderave/CMakeFiles/oderave.dir/requires: plugins/oderave/CMakeFiles/oderave.dir/oderave.cpp.o.requires
.PHONY : plugins/oderave/CMakeFiles/oderave.dir/requires

plugins/oderave/CMakeFiles/oderave.dir/clean:
	cd /home/raman/openrave/src/plugins/oderave && $(CMAKE_COMMAND) -P CMakeFiles/oderave.dir/cmake_clean.cmake
.PHONY : plugins/oderave/CMakeFiles/oderave.dir/clean

plugins/oderave/CMakeFiles/oderave.dir/depend:
	cd /home/raman/openrave/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raman/openrave /home/raman/openrave/plugins/oderave /home/raman/openrave/src /home/raman/openrave/src/plugins/oderave /home/raman/openrave/src/plugins/oderave/CMakeFiles/oderave.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/oderave/CMakeFiles/oderave.dir/depend
