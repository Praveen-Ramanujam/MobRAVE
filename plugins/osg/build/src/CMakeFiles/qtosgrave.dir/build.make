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
CMAKE_SOURCE_DIR = /home/raman/openrave/plugins/osg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/raman/openrave/plugins/osg/build

# Include any dependencies generated for this target.
include src/CMakeFiles/qtosgrave.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/qtosgrave.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/qtosgrave.dir/flags.make

src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o: src/CMakeFiles/qtosgrave.dir/flags.make
src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o: ../src/objecttree.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -o CMakeFiles/qtosgrave.dir/objecttree.cpp.o -c /home/raman/openrave/plugins/osg/src/objecttree.cpp

src/CMakeFiles/qtosgrave.dir/objecttree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qtosgrave.dir/objecttree.cpp.i"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -E /home/raman/openrave/plugins/osg/src/objecttree.cpp > CMakeFiles/qtosgrave.dir/objecttree.cpp.i

src/CMakeFiles/qtosgrave.dir/objecttree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qtosgrave.dir/objecttree.cpp.s"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -S /home/raman/openrave/plugins/osg/src/objecttree.cpp -o CMakeFiles/qtosgrave.dir/objecttree.cpp.s

src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o.requires:
.PHONY : src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o.requires

src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o.provides: src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/qtosgrave.dir/build.make src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o.provides.build
.PHONY : src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o.provides

src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o.provides.build: src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o
.PHONY : src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o.provides.build

src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o: src/CMakeFiles/qtosgrave.dir/flags.make
src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o: ../src/treemodel.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -o CMakeFiles/qtosgrave.dir/treemodel.cpp.o -c /home/raman/openrave/plugins/osg/src/treemodel.cpp

src/CMakeFiles/qtosgrave.dir/treemodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qtosgrave.dir/treemodel.cpp.i"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -E /home/raman/openrave/plugins/osg/src/treemodel.cpp > CMakeFiles/qtosgrave.dir/treemodel.cpp.i

src/CMakeFiles/qtosgrave.dir/treemodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qtosgrave.dir/treemodel.cpp.s"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -S /home/raman/openrave/plugins/osg/src/treemodel.cpp -o CMakeFiles/qtosgrave.dir/treemodel.cpp.s

src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o.requires:
.PHONY : src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o.requires

src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o.provides: src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/qtosgrave.dir/build.make src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o.provides.build
.PHONY : src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o.provides

src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o.provides.build: src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o
.PHONY : src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o.provides.build

src/CMakeFiles/qtosgrave.dir/Item.cpp.o: src/CMakeFiles/qtosgrave.dir/flags.make
src/CMakeFiles/qtosgrave.dir/Item.cpp.o: ../src/Item.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/qtosgrave.dir/Item.cpp.o"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -o CMakeFiles/qtosgrave.dir/Item.cpp.o -c /home/raman/openrave/plugins/osg/src/Item.cpp

src/CMakeFiles/qtosgrave.dir/Item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qtosgrave.dir/Item.cpp.i"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -E /home/raman/openrave/plugins/osg/src/Item.cpp > CMakeFiles/qtosgrave.dir/Item.cpp.i

src/CMakeFiles/qtosgrave.dir/Item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qtosgrave.dir/Item.cpp.s"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -S /home/raman/openrave/plugins/osg/src/Item.cpp -o CMakeFiles/qtosgrave.dir/Item.cpp.s

src/CMakeFiles/qtosgrave.dir/Item.cpp.o.requires:
.PHONY : src/CMakeFiles/qtosgrave.dir/Item.cpp.o.requires

src/CMakeFiles/qtosgrave.dir/Item.cpp.o.provides: src/CMakeFiles/qtosgrave.dir/Item.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/qtosgrave.dir/build.make src/CMakeFiles/qtosgrave.dir/Item.cpp.o.provides.build
.PHONY : src/CMakeFiles/qtosgrave.dir/Item.cpp.o.provides

src/CMakeFiles/qtosgrave.dir/Item.cpp.o.provides.build: src/CMakeFiles/qtosgrave.dir/Item.cpp.o
.PHONY : src/CMakeFiles/qtosgrave.dir/Item.cpp.o.provides.build

src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o: src/CMakeFiles/qtosgrave.dir/flags.make
src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o: ../src/treeitem.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -o CMakeFiles/qtosgrave.dir/treeitem.cpp.o -c /home/raman/openrave/plugins/osg/src/treeitem.cpp

src/CMakeFiles/qtosgrave.dir/treeitem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qtosgrave.dir/treeitem.cpp.i"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -E /home/raman/openrave/plugins/osg/src/treeitem.cpp > CMakeFiles/qtosgrave.dir/treeitem.cpp.i

src/CMakeFiles/qtosgrave.dir/treeitem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qtosgrave.dir/treeitem.cpp.s"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -S /home/raman/openrave/plugins/osg/src/treeitem.cpp -o CMakeFiles/qtosgrave.dir/treeitem.cpp.s

src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o.requires:
.PHONY : src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o.requires

src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o.provides: src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/qtosgrave.dir/build.make src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o.provides.build
.PHONY : src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o.provides

src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o.provides.build: src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o
.PHONY : src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o.provides.build

src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o: src/CMakeFiles/qtosgrave.dir/flags.make
src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o: ../src/qtosgviewer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -o CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o -c /home/raman/openrave/plugins/osg/src/qtosgviewer.cpp

src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.i"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -E /home/raman/openrave/plugins/osg/src/qtosgviewer.cpp > CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.i

src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.s"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -S /home/raman/openrave/plugins/osg/src/qtosgviewer.cpp -o CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.s

src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o.requires:
.PHONY : src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o.requires

src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o.provides: src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/qtosgrave.dir/build.make src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o.provides.build
.PHONY : src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o.provides

src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o.provides.build: src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o
.PHONY : src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o.provides.build

src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o: src/CMakeFiles/qtosgrave.dir/flags.make
src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o: ../src/qtosgravemain.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -o CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o -c /home/raman/openrave/plugins/osg/src/qtosgravemain.cpp

src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.i"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -E /home/raman/openrave/plugins/osg/src/qtosgravemain.cpp > CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.i

src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.s"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -S /home/raman/openrave/plugins/osg/src/qtosgravemain.cpp -o CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.s

src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o.requires:
.PHONY : src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o.requires

src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o.provides: src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/qtosgrave.dir/build.make src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o.provides.build
.PHONY : src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o.provides

src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o.provides.build: src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o
.PHONY : src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o.provides.build

src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o: src/CMakeFiles/qtosgrave.dir/flags.make
src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o: ../src/osgpick.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -o CMakeFiles/qtosgrave.dir/osgpick.cpp.o -c /home/raman/openrave/plugins/osg/src/osgpick.cpp

src/CMakeFiles/qtosgrave.dir/osgpick.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qtosgrave.dir/osgpick.cpp.i"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -E /home/raman/openrave/plugins/osg/src/osgpick.cpp > CMakeFiles/qtosgrave.dir/osgpick.cpp.i

src/CMakeFiles/qtosgrave.dir/osgpick.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qtosgrave.dir/osgpick.cpp.s"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -S /home/raman/openrave/plugins/osg/src/osgpick.cpp -o CMakeFiles/qtosgrave.dir/osgpick.cpp.s

src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o.requires:
.PHONY : src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o.requires

src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o.provides: src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/qtosgrave.dir/build.make src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o.provides.build
.PHONY : src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o.provides

src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o.provides.build: src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o
.PHONY : src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o.provides.build

src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o: src/CMakeFiles/qtosgrave.dir/flags.make
src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o: src/moc_qtosgviewer.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -o CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o -c /home/raman/openrave/plugins/osg/build/src/moc_qtosgviewer.cxx

src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.i"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -E /home/raman/openrave/plugins/osg/build/src/moc_qtosgviewer.cxx > CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.i

src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.s"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -S /home/raman/openrave/plugins/osg/build/src/moc_qtosgviewer.cxx -o CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.s

src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o.requires:
.PHONY : src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o.requires

src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o.provides: src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o.requires
	$(MAKE) -f src/CMakeFiles/qtosgrave.dir/build.make src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o.provides.build
.PHONY : src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o.provides

src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o.provides.build: src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o
.PHONY : src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o.provides.build

src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o: src/CMakeFiles/qtosgrave.dir/flags.make
src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o: src/moc_treemodel.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -o CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o -c /home/raman/openrave/plugins/osg/build/src/moc_treemodel.cxx

src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.i"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -E /home/raman/openrave/plugins/osg/build/src/moc_treemodel.cxx > CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.i

src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.s"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -S /home/raman/openrave/plugins/osg/build/src/moc_treemodel.cxx -o CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.s

src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o.requires:
.PHONY : src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o.requires

src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o.provides: src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o.requires
	$(MAKE) -f src/CMakeFiles/qtosgrave.dir/build.make src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o.provides.build
.PHONY : src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o.provides

src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o.provides.build: src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o
.PHONY : src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o.provides.build

src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o: src/CMakeFiles/qtosgrave.dir/flags.make
src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o: src/qrc_qtosgviewer.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -o CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o -c /home/raman/openrave/plugins/osg/build/src/qrc_qtosgviewer.cxx

src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.i"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -E /home/raman/openrave/plugins/osg/build/src/qrc_qtosgviewer.cxx > CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.i

src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.s"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/local/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS)  -O0 -I/usr/local/include/openrave-0.5 -I/usr/include -DOPENRAVE_DLL -DOPENRAVE_CORE_DLL  -S /home/raman/openrave/plugins/osg/build/src/qrc_qtosgviewer.cxx -o CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.s

src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o.requires:
.PHONY : src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o.requires

src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o.provides: src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o.requires
	$(MAKE) -f src/CMakeFiles/qtosgrave.dir/build.make src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o.provides.build
.PHONY : src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o.provides

src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o.provides.build: src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o
.PHONY : src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o.provides.build

src/moc_qtosgviewer.cxx: ../src/qtosgviewer.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_qtosgviewer.cxx"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/bin/moc-qt4 -I/usr/local/include/openrave-0.5 -I/usr/include -I/home/raman/openrave/plugins/osg/src -I/home/raman/openrave/plugins/osg/src/. -I/home/raman/openrave/plugins/osg/src/../.. -I/home/raman/openrave/plugins/osg/src/../include -I/usr/include/qt4 -I/usr/include/qt4/QtOpenGL -I/usr/local/include -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -DQT_DLL -DQT_GUI_LIB -DQT_CORE_LIB -o /home/raman/openrave/plugins/osg/build/src/moc_qtosgviewer.cxx /home/raman/openrave/plugins/osg/src/qtosgviewer.h

src/moc_treemodel.cxx: ../src/treemodel.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_treemodel.cxx"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/bin/moc-qt4 -I/usr/local/include/openrave-0.5 -I/usr/include -I/home/raman/openrave/plugins/osg/src -I/home/raman/openrave/plugins/osg/src/. -I/home/raman/openrave/plugins/osg/src/../.. -I/home/raman/openrave/plugins/osg/src/../include -I/usr/include/qt4 -I/usr/include/qt4/QtOpenGL -I/usr/local/include -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -DQT_DLL -DQT_GUI_LIB -DQT_CORE_LIB -o /home/raman/openrave/plugins/osg/build/src/moc_treemodel.cxx /home/raman/openrave/plugins/osg/src/treemodel.h

src/qrc_qtosgviewer.cxx: ../src/images/Import.png
src/qrc_qtosgviewer.cxx: ../src/images/save.png
src/qrc_qtosgviewer.cxx: ../src/images/smooth.png
src/qrc_qtosgviewer.cxx: ../src/images/flat.png
src/qrc_qtosgviewer.cxx: ../src/images/hand.png
src/qrc_qtosgviewer.cxx: ../src/images/house.png
src/qrc_qtosgviewer.cxx: ../src/images/lighton.png
src/qrc_qtosgviewer.cxx: ../src/images/lightoff.png
src/qrc_qtosgviewer.cxx: ../src/images/open.png
src/qrc_qtosgviewer.cxx: ../src/images/pause.png
src/qrc_qtosgviewer.cxx: ../src/images/play.png
src/qrc_qtosgviewer.cxx: ../src/images/pointer.png
src/qrc_qtosgviewer.cxx: ../src/images/wire.png
src/qrc_qtosgviewer.cxx: ../src/images/stop.png
src/qrc_qtosgviewer.cxx: ../src/images/faces.png
src/qrc_qtosgviewer.cxx: ../src/images/bbox.png
src/qrc_qtosgviewer.cxx: ../src/images/axes.png
src/qrc_qtosgviewer.cxx: ../src/images/shadow.png
src/qrc_qtosgviewer.cxx: ../src/images/no_edit.png
src/qrc_qtosgviewer.cxx: ../src/qtosgviewer.qrc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/raman/openrave/plugins/osg/build/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating qrc_qtosgviewer.cxx"
	cd /home/raman/openrave/plugins/osg/build/src && /usr/bin/rcc -name qtosgviewer -o /home/raman/openrave/plugins/osg/build/src/qrc_qtosgviewer.cxx /home/raman/openrave/plugins/osg/src/qtosgviewer.qrc

# Object files for target qtosgrave
qtosgrave_OBJECTS = \
"CMakeFiles/qtosgrave.dir/objecttree.cpp.o" \
"CMakeFiles/qtosgrave.dir/treemodel.cpp.o" \
"CMakeFiles/qtosgrave.dir/Item.cpp.o" \
"CMakeFiles/qtosgrave.dir/treeitem.cpp.o" \
"CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o" \
"CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o" \
"CMakeFiles/qtosgrave.dir/osgpick.cpp.o" \
"CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o" \
"CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o" \
"CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o"

# External object files for target qtosgrave
qtosgrave_EXTERNAL_OBJECTS =

../lib/libqtosgrave.so: src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o
../lib/libqtosgrave.so: src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o
../lib/libqtosgrave.so: src/CMakeFiles/qtosgrave.dir/Item.cpp.o
../lib/libqtosgrave.so: src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o
../lib/libqtosgrave.so: src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o
../lib/libqtosgrave.so: src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o
../lib/libqtosgrave.so: src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o
../lib/libqtosgrave.so: src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o
../lib/libqtosgrave.so: src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o
../lib/libqtosgrave.so: src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o
../lib/libqtosgrave.so: /usr/lib/libQtGui.so
../lib/libqtosgrave.so: /usr/lib/libpng.so
../lib/libqtosgrave.so: /usr/lib/libSM.so
../lib/libqtosgrave.so: /usr/lib/libICE.so
../lib/libqtosgrave.so: /usr/lib/libXrender.so
../lib/libqtosgrave.so: /usr/lib/libfreetype.so
../lib/libqtosgrave.so: /usr/lib/libfontconfig.so
../lib/libqtosgrave.so: /usr/lib/libXext.so
../lib/libqtosgrave.so: /usr/lib/libX11.so
../lib/libqtosgrave.so: /usr/lib/libm.so
../lib/libqtosgrave.so: /usr/lib/libQtCore.so
../lib/libqtosgrave.so: /usr/lib/libz.so
../lib/libqtosgrave.so: /usr/lib/libgthread-2.0.so
../lib/libqtosgrave.so: /usr/lib/libglib-2.0.so
../lib/libqtosgrave.so: /usr/lib/libgobject-2.0.so
../lib/libqtosgrave.so: /usr/lib/librt.so
../lib/libqtosgrave.so: /usr/local/lib64/libosg.so
../lib/libqtosgrave.so: /usr/local/lib64/libosgDB.so
../lib/libqtosgrave.so: /usr/local/lib64/libosgGA.so
../lib/libqtosgrave.so: /usr/local/lib64/libosgText.so
../lib/libqtosgrave.so: /usr/local/lib64/libosgViewer.so
../lib/libqtosgrave.so: /usr/local/lib64/libosgManipulator.so
../lib/libqtosgrave.so: /usr/local/lib64/libosgQt.so
../lib/libqtosgrave.so: /usr/local/lib64/libosgShadow.so
../lib/libqtosgrave.so: /usr/lib/libGLEW.so
../lib/libqtosgrave.so: /usr/lib/libQtOpenGL.so
../lib/libqtosgrave.so: src/CMakeFiles/qtosgrave.dir/build.make
../lib/libqtosgrave.so: src/CMakeFiles/qtosgrave.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../lib/libqtosgrave.so"
	cd /home/raman/openrave/plugins/osg/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qtosgrave.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/qtosgrave.dir/build: ../lib/libqtosgrave.so
.PHONY : src/CMakeFiles/qtosgrave.dir/build

src/CMakeFiles/qtosgrave.dir/requires: src/CMakeFiles/qtosgrave.dir/objecttree.cpp.o.requires
src/CMakeFiles/qtosgrave.dir/requires: src/CMakeFiles/qtosgrave.dir/treemodel.cpp.o.requires
src/CMakeFiles/qtosgrave.dir/requires: src/CMakeFiles/qtosgrave.dir/Item.cpp.o.requires
src/CMakeFiles/qtosgrave.dir/requires: src/CMakeFiles/qtosgrave.dir/treeitem.cpp.o.requires
src/CMakeFiles/qtosgrave.dir/requires: src/CMakeFiles/qtosgrave.dir/qtosgviewer.cpp.o.requires
src/CMakeFiles/qtosgrave.dir/requires: src/CMakeFiles/qtosgrave.dir/qtosgravemain.cpp.o.requires
src/CMakeFiles/qtosgrave.dir/requires: src/CMakeFiles/qtosgrave.dir/osgpick.cpp.o.requires
src/CMakeFiles/qtosgrave.dir/requires: src/CMakeFiles/qtosgrave.dir/moc_qtosgviewer.cxx.o.requires
src/CMakeFiles/qtosgrave.dir/requires: src/CMakeFiles/qtosgrave.dir/moc_treemodel.cxx.o.requires
src/CMakeFiles/qtosgrave.dir/requires: src/CMakeFiles/qtosgrave.dir/qrc_qtosgviewer.cxx.o.requires
.PHONY : src/CMakeFiles/qtosgrave.dir/requires

src/CMakeFiles/qtosgrave.dir/clean:
	cd /home/raman/openrave/plugins/osg/build/src && $(CMAKE_COMMAND) -P CMakeFiles/qtosgrave.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/qtosgrave.dir/clean

src/CMakeFiles/qtosgrave.dir/depend: src/moc_qtosgviewer.cxx
src/CMakeFiles/qtosgrave.dir/depend: src/moc_treemodel.cxx
src/CMakeFiles/qtosgrave.dir/depend: src/qrc_qtosgviewer.cxx
	cd /home/raman/openrave/plugins/osg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raman/openrave/plugins/osg /home/raman/openrave/plugins/osg/src /home/raman/openrave/plugins/osg/build /home/raman/openrave/plugins/osg/build/src /home/raman/openrave/plugins/osg/build/src/CMakeFiles/qtosgrave.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/qtosgrave.dir/depend

