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
include plugins/basesensors/CMakeFiles/nxtsensors.dir/depend.make

# Include the progress variables for this target.
include plugins/basesensors/CMakeFiles/nxtsensors.dir/progress.make

# Include the compile flags for this target's objects.
include plugins/basesensors/CMakeFiles/nxtsensors.dir/flags.make

plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o: plugins/basesensors/CMakeFiles/nxtsensors.dir/flags.make
plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o: ../plugins/basesensors/touchsensor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/praveen/Work/openrave/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o"
	cd /home/praveen/Work/openrave/build/plugins/basesensors && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL  -fPIC -o CMakeFiles/nxtsensors.dir/touchsensor.cpp.o -c /home/praveen/Work/openrave/plugins/basesensors/touchsensor.cpp

plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nxtsensors.dir/touchsensor.cpp.i"
	cd /home/praveen/Work/openrave/build/plugins/basesensors && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL  -fPIC -E /home/praveen/Work/openrave/plugins/basesensors/touchsensor.cpp > CMakeFiles/nxtsensors.dir/touchsensor.cpp.i

plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nxtsensors.dir/touchsensor.cpp.s"
	cd /home/praveen/Work/openrave/build/plugins/basesensors && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL  -fPIC -S /home/praveen/Work/openrave/plugins/basesensors/touchsensor.cpp -o CMakeFiles/nxtsensors.dir/touchsensor.cpp.s

plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o.requires:
.PHONY : plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o.requires

plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o.provides: plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o.requires
	$(MAKE) -f plugins/basesensors/CMakeFiles/nxtsensors.dir/build.make plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o.provides.build
.PHONY : plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o.provides

plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o.provides.build: plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o
.PHONY : plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o.provides.build

# Object files for target nxtsensors
nxtsensors_OBJECTS = \
"CMakeFiles/nxtsensors.dir/touchsensor.cpp.o"

# External object files for target nxtsensors
nxtsensors_EXTERNAL_OBJECTS =

plugins/basesensors/libnxtsensors.so: plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o
plugins/basesensors/libnxtsensors.so: src/libopenrave/libopenrave0.5.so.0.5.0
plugins/basesensors/libnxtsensors.so: /usr/lib/libxml2.so
plugins/basesensors/libnxtsensors.so: /usr/lib/libboost_date_time-mt.so
plugins/basesensors/libnxtsensors.so: /usr/lib/libboost_thread-mt.so
plugins/basesensors/libnxtsensors.so: cpp-gen-md5/libopenrave-md5.a
plugins/basesensors/libnxtsensors.so: /usr/lib/libboost_filesystem-mt.so
plugins/basesensors/libnxtsensors.so: /usr/lib/libboost_system-mt.so
plugins/basesensors/libnxtsensors.so: 3rdparty/crlibm-1.0beta4/libcrlibm.a
plugins/basesensors/libnxtsensors.so: 3rdparty/fparser-4.3/libfparser.a
plugins/basesensors/libnxtsensors.so: plugins/basesensors/CMakeFiles/nxtsensors.dir/build.make
plugins/basesensors/libnxtsensors.so: plugins/basesensors/CMakeFiles/nxtsensors.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libnxtsensors.so"
	cd /home/praveen/Work/openrave/build/plugins/basesensors && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nxtsensors.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plugins/basesensors/CMakeFiles/nxtsensors.dir/build: plugins/basesensors/libnxtsensors.so
.PHONY : plugins/basesensors/CMakeFiles/nxtsensors.dir/build

plugins/basesensors/CMakeFiles/nxtsensors.dir/requires: plugins/basesensors/CMakeFiles/nxtsensors.dir/touchsensor.cpp.o.requires
.PHONY : plugins/basesensors/CMakeFiles/nxtsensors.dir/requires

plugins/basesensors/CMakeFiles/nxtsensors.dir/clean:
	cd /home/praveen/Work/openrave/build/plugins/basesensors && $(CMAKE_COMMAND) -P CMakeFiles/nxtsensors.dir/cmake_clean.cmake
.PHONY : plugins/basesensors/CMakeFiles/nxtsensors.dir/clean

plugins/basesensors/CMakeFiles/nxtsensors.dir/depend:
	cd /home/praveen/Work/openrave/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/praveen/Work/openrave /home/praveen/Work/openrave/plugins/basesensors /home/praveen/Work/openrave/build /home/praveen/Work/openrave/build/plugins/basesensors /home/praveen/Work/openrave/build/plugins/basesensors/CMakeFiles/nxtsensors.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/basesensors/CMakeFiles/nxtsensors.dir/depend

