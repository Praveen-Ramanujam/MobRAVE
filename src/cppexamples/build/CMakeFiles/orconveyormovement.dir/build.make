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
include CMakeFiles/orconveyormovement.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/orconveyormovement.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/orconveyormovement.dir/flags.make

CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o: CMakeFiles/orconveyormovement.dir/flags.make
CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o: ../orconveyormovement.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/src/cppexamples/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -o CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o -c /home/raman/openrave/src/cppexamples/orconveyormovement.cpp

CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -E /home/raman/openrave/src/cppexamples/orconveyormovement.cpp > CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.i

CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -S /home/raman/openrave/src/cppexamples/orconveyormovement.cpp -o CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.s

CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o.requires:
.PHONY : CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o.requires

CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o.provides: CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o.requires
	$(MAKE) -f CMakeFiles/orconveyormovement.dir/build.make CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o.provides.build
.PHONY : CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o.provides

CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o.provides.build: CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o
.PHONY : CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o.provides.build

# Object files for target orconveyormovement
orconveyormovement_OBJECTS = \
"CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o"

# External object files for target orconveyormovement
orconveyormovement_EXTERNAL_OBJECTS =

orconveyormovement: CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o
orconveyormovement: CMakeFiles/orconveyormovement.dir/build.make
orconveyormovement: CMakeFiles/orconveyormovement.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable orconveyormovement"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/orconveyormovement.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/orconveyormovement.dir/build: orconveyormovement
.PHONY : CMakeFiles/orconveyormovement.dir/build

CMakeFiles/orconveyormovement.dir/requires: CMakeFiles/orconveyormovement.dir/orconveyormovement.cpp.o.requires
.PHONY : CMakeFiles/orconveyormovement.dir/requires

CMakeFiles/orconveyormovement.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/orconveyormovement.dir/cmake_clean.cmake
.PHONY : CMakeFiles/orconveyormovement.dir/clean

CMakeFiles/orconveyormovement.dir/depend:
	cd /home/raman/openrave/src/cppexamples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raman/openrave/src/cppexamples /home/raman/openrave/src/cppexamples /home/raman/openrave/src/cppexamples/build /home/raman/openrave/src/cppexamples/build /home/raman/openrave/src/cppexamples/build/CMakeFiles/orconveyormovement.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/orconveyormovement.dir/depend
