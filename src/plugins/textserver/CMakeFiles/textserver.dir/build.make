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
include plugins/textserver/CMakeFiles/textserver.dir/depend.make

# Include the progress variables for this target.
include plugins/textserver/CMakeFiles/textserver.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/textserver/CMakeFiles/textserver.dir/flags.make

plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o: plugins/textserver/CMakeFiles/textserver.dir/flags.make
plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o: ../plugins/textserver/textserver.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o"
	cd /home/raman/openrave/src/plugins/textserver && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL  -fPIC -o CMakeFiles/textserver.dir/textserver.cpp.o -c /home/raman/openrave/plugins/textserver/textserver.cpp

plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/textserver.dir/textserver.cpp.i"
	cd /home/raman/openrave/src/plugins/textserver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL  -fPIC -E /home/raman/openrave/plugins/textserver/textserver.cpp > CMakeFiles/textserver.dir/textserver.cpp.i

plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/textserver.dir/textserver.cpp.s"
	cd /home/raman/openrave/src/plugins/textserver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL  -fPIC -S /home/raman/openrave/plugins/textserver/textserver.cpp -o CMakeFiles/textserver.dir/textserver.cpp.s

plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o.requires:
.PHONY : plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o.requires

plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o.provides: plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o.requires
	$(MAKE) -f plugins/textserver/CMakeFiles/textserver.dir/build.make plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o.provides.build
.PHONY : plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o.provides

plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o.provides.build: plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o
.PHONY : plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o.provides.build

# Object files for target textserver
textserver_OBJECTS = \
"CMakeFiles/textserver.dir/textserver.cpp.o"

# External object files for target textserver
textserver_EXTERNAL_OBJECTS =

plugins/textserver/libtextserver.so: plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o
plugins/textserver/libtextserver.so: src/libopenrave/libopenrave0.5.so.0.5.0
plugins/textserver/libtextserver.so: /usr/lib/libxml2.so
plugins/textserver/libtextserver.so: /usr/lib/libboost_date_time-mt.so
plugins/textserver/libtextserver.so: /usr/lib/libboost_thread-mt.so
plugins/textserver/libtextserver.so: cpp-gen-md5/libopenrave-md5.a
plugins/textserver/libtextserver.so: /usr/lib/libboost_filesystem-mt.so
plugins/textserver/libtextserver.so: /usr/lib/libboost_system-mt.so
plugins/textserver/libtextserver.so: 3rdparty/crlibm-1.0beta4/libcrlibm.a
plugins/textserver/libtextserver.so: 3rdparty/fparser-4.3/libfparser.a
plugins/textserver/libtextserver.so: plugins/textserver/CMakeFiles/textserver.dir/build.make
plugins/textserver/libtextserver.so: plugins/textserver/CMakeFiles/textserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libtextserver.so"
	cd /home/raman/openrave/src/plugins/textserver && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/textserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/textserver/CMakeFiles/textserver.dir/build: plugins/textserver/libtextserver.so
.PHONY : plugins/textserver/CMakeFiles/textserver.dir/build

plugins/textserver/CMakeFiles/textserver.dir/requires: plugins/textserver/CMakeFiles/textserver.dir/textserver.cpp.o.requires
.PHONY : plugins/textserver/CMakeFiles/textserver.dir/requires

plugins/textserver/CMakeFiles/textserver.dir/clean:
	cd /home/raman/openrave/src/plugins/textserver && $(CMAKE_COMMAND) -P CMakeFiles/textserver.dir/cmake_clean.cmake
.PHONY : plugins/textserver/CMakeFiles/textserver.dir/clean

plugins/textserver/CMakeFiles/textserver.dir/depend:
	cd /home/raman/openrave/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raman/openrave /home/raman/openrave/plugins/textserver /home/raman/openrave/src /home/raman/openrave/src/plugins/textserver /home/raman/openrave/src/plugins/textserver/CMakeFiles/textserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/textserver/CMakeFiles/textserver.dir/depend

