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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/astrid/nao/projects/nao

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk

# Include any dependencies generated for this target.
include CMakeFiles/nao.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nao.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nao.dir/flags.make

CMakeFiles/nao.dir/core/vision/detector.cpp.o: CMakeFiles/nao.dir/flags.make
CMakeFiles/nao.dir/core/vision/detector.cpp.o: ../core/vision/detector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nao.dir/core/vision/detector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nao.dir/core/vision/detector.cpp.o -c /home/astrid/nao/projects/nao/core/vision/detector.cpp

CMakeFiles/nao.dir/core/vision/detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nao.dir/core/vision/detector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/astrid/nao/projects/nao/core/vision/detector.cpp > CMakeFiles/nao.dir/core/vision/detector.cpp.i

CMakeFiles/nao.dir/core/vision/detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nao.dir/core/vision/detector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/astrid/nao/projects/nao/core/vision/detector.cpp -o CMakeFiles/nao.dir/core/vision/detector.cpp.s

CMakeFiles/nao.dir/core/vision/detector.cpp.o.requires:
.PHONY : CMakeFiles/nao.dir/core/vision/detector.cpp.o.requires

CMakeFiles/nao.dir/core/vision/detector.cpp.o.provides: CMakeFiles/nao.dir/core/vision/detector.cpp.o.requires
	$(MAKE) -f CMakeFiles/nao.dir/build.make CMakeFiles/nao.dir/core/vision/detector.cpp.o.provides.build
.PHONY : CMakeFiles/nao.dir/core/vision/detector.cpp.o.provides

CMakeFiles/nao.dir/core/vision/detector.cpp.o.provides.build: CMakeFiles/nao.dir/core/vision/detector.cpp.o

CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o: CMakeFiles/nao.dir/flags.make
CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o: ../core/vision/debug/debugballdetector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o -c /home/astrid/nao/projects/nao/core/vision/debug/debugballdetector.cpp

CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/astrid/nao/projects/nao/core/vision/debug/debugballdetector.cpp > CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.i

CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/astrid/nao/projects/nao/core/vision/debug/debugballdetector.cpp -o CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.s

CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o.requires:
.PHONY : CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o.requires

CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o.provides: CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o.requires
	$(MAKE) -f CMakeFiles/nao.dir/build.make CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o.provides.build
.PHONY : CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o.provides

CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o.provides.build: CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o

CMakeFiles/nao.dir/core/vision/balldetector.cpp.o: CMakeFiles/nao.dir/flags.make
CMakeFiles/nao.dir/core/vision/balldetector.cpp.o: ../core/vision/balldetector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nao.dir/core/vision/balldetector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nao.dir/core/vision/balldetector.cpp.o -c /home/astrid/nao/projects/nao/core/vision/balldetector.cpp

CMakeFiles/nao.dir/core/vision/balldetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nao.dir/core/vision/balldetector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/astrid/nao/projects/nao/core/vision/balldetector.cpp > CMakeFiles/nao.dir/core/vision/balldetector.cpp.i

CMakeFiles/nao.dir/core/vision/balldetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nao.dir/core/vision/balldetector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/astrid/nao/projects/nao/core/vision/balldetector.cpp -o CMakeFiles/nao.dir/core/vision/balldetector.cpp.s

CMakeFiles/nao.dir/core/vision/balldetector.cpp.o.requires:
.PHONY : CMakeFiles/nao.dir/core/vision/balldetector.cpp.o.requires

CMakeFiles/nao.dir/core/vision/balldetector.cpp.o.provides: CMakeFiles/nao.dir/core/vision/balldetector.cpp.o.requires
	$(MAKE) -f CMakeFiles/nao.dir/build.make CMakeFiles/nao.dir/core/vision/balldetector.cpp.o.provides.build
.PHONY : CMakeFiles/nao.dir/core/vision/balldetector.cpp.o.provides

CMakeFiles/nao.dir/core/vision/balldetector.cpp.o.provides.build: CMakeFiles/nao.dir/core/vision/balldetector.cpp.o

CMakeFiles/nao.dir/naointerface.cpp.o: CMakeFiles/nao.dir/flags.make
CMakeFiles/nao.dir/naointerface.cpp.o: ../naointerface.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nao.dir/naointerface.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nao.dir/naointerface.cpp.o -c /home/astrid/nao/projects/nao/naointerface.cpp

CMakeFiles/nao.dir/naointerface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nao.dir/naointerface.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/astrid/nao/projects/nao/naointerface.cpp > CMakeFiles/nao.dir/naointerface.cpp.i

CMakeFiles/nao.dir/naointerface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nao.dir/naointerface.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/astrid/nao/projects/nao/naointerface.cpp -o CMakeFiles/nao.dir/naointerface.cpp.s

CMakeFiles/nao.dir/naointerface.cpp.o.requires:
.PHONY : CMakeFiles/nao.dir/naointerface.cpp.o.requires

CMakeFiles/nao.dir/naointerface.cpp.o.provides: CMakeFiles/nao.dir/naointerface.cpp.o.requires
	$(MAKE) -f CMakeFiles/nao.dir/build.make CMakeFiles/nao.dir/naointerface.cpp.o.provides.build
.PHONY : CMakeFiles/nao.dir/naointerface.cpp.o.provides

CMakeFiles/nao.dir/naointerface.cpp.o.provides.build: CMakeFiles/nao.dir/naointerface.cpp.o

CMakeFiles/nao.dir/main.cpp.o: CMakeFiles/nao.dir/flags.make
CMakeFiles/nao.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nao.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nao.dir/main.cpp.o -c /home/astrid/nao/projects/nao/main.cpp

CMakeFiles/nao.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nao.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/astrid/nao/projects/nao/main.cpp > CMakeFiles/nao.dir/main.cpp.i

CMakeFiles/nao.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nao.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/astrid/nao/projects/nao/main.cpp -o CMakeFiles/nao.dir/main.cpp.s

CMakeFiles/nao.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/nao.dir/main.cpp.o.requires

CMakeFiles/nao.dir/main.cpp.o.provides: CMakeFiles/nao.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/nao.dir/build.make CMakeFiles/nao.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/nao.dir/main.cpp.o.provides

CMakeFiles/nao.dir/main.cpp.o.provides.build: CMakeFiles/nao.dir/main.cpp.o

CMakeFiles/nao.dir/core/common/worldobject.cpp.o: CMakeFiles/nao.dir/flags.make
CMakeFiles/nao.dir/core/common/worldobject.cpp.o: ../core/common/worldobject.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nao.dir/core/common/worldobject.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nao.dir/core/common/worldobject.cpp.o -c /home/astrid/nao/projects/nao/core/common/worldobject.cpp

CMakeFiles/nao.dir/core/common/worldobject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nao.dir/core/common/worldobject.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/astrid/nao/projects/nao/core/common/worldobject.cpp > CMakeFiles/nao.dir/core/common/worldobject.cpp.i

CMakeFiles/nao.dir/core/common/worldobject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nao.dir/core/common/worldobject.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/astrid/nao/projects/nao/core/common/worldobject.cpp -o CMakeFiles/nao.dir/core/common/worldobject.cpp.s

CMakeFiles/nao.dir/core/common/worldobject.cpp.o.requires:
.PHONY : CMakeFiles/nao.dir/core/common/worldobject.cpp.o.requires

CMakeFiles/nao.dir/core/common/worldobject.cpp.o.provides: CMakeFiles/nao.dir/core/common/worldobject.cpp.o.requires
	$(MAKE) -f CMakeFiles/nao.dir/build.make CMakeFiles/nao.dir/core/common/worldobject.cpp.o.provides.build
.PHONY : CMakeFiles/nao.dir/core/common/worldobject.cpp.o.provides

CMakeFiles/nao.dir/core/common/worldobject.cpp.o.provides.build: CMakeFiles/nao.dir/core/common/worldobject.cpp.o

CMakeFiles/nao.dir/core/common/ball.cpp.o: CMakeFiles/nao.dir/flags.make
CMakeFiles/nao.dir/core/common/ball.cpp.o: ../core/common/ball.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nao.dir/core/common/ball.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nao.dir/core/common/ball.cpp.o -c /home/astrid/nao/projects/nao/core/common/ball.cpp

CMakeFiles/nao.dir/core/common/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nao.dir/core/common/ball.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/astrid/nao/projects/nao/core/common/ball.cpp > CMakeFiles/nao.dir/core/common/ball.cpp.i

CMakeFiles/nao.dir/core/common/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nao.dir/core/common/ball.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/astrid/nao/projects/nao/core/common/ball.cpp -o CMakeFiles/nao.dir/core/common/ball.cpp.s

CMakeFiles/nao.dir/core/common/ball.cpp.o.requires:
.PHONY : CMakeFiles/nao.dir/core/common/ball.cpp.o.requires

CMakeFiles/nao.dir/core/common/ball.cpp.o.provides: CMakeFiles/nao.dir/core/common/ball.cpp.o.requires
	$(MAKE) -f CMakeFiles/nao.dir/build.make CMakeFiles/nao.dir/core/common/ball.cpp.o.provides.build
.PHONY : CMakeFiles/nao.dir/core/common/ball.cpp.o.provides

CMakeFiles/nao.dir/core/common/ball.cpp.o.provides.build: CMakeFiles/nao.dir/core/common/ball.cpp.o

CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o: CMakeFiles/nao.dir/flags.make
CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o: ../core/common/worldobjectmanager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o -c /home/astrid/nao/projects/nao/core/common/worldobjectmanager.cpp

CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/astrid/nao/projects/nao/core/common/worldobjectmanager.cpp > CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.i

CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/astrid/nao/projects/nao/core/common/worldobjectmanager.cpp -o CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.s

CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o.requires:
.PHONY : CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o.requires

CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o.provides: CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o.requires
	$(MAKE) -f CMakeFiles/nao.dir/build.make CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o.provides.build
.PHONY : CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o.provides

CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o.provides.build: CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o

# Object files for target nao
nao_OBJECTS = \
"CMakeFiles/nao.dir/core/vision/detector.cpp.o" \
"CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o" \
"CMakeFiles/nao.dir/core/vision/balldetector.cpp.o" \
"CMakeFiles/nao.dir/naointerface.cpp.o" \
"CMakeFiles/nao.dir/main.cpp.o" \
"CMakeFiles/nao.dir/core/common/worldobject.cpp.o" \
"CMakeFiles/nao.dir/core/common/ball.cpp.o" \
"CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o"

# External object files for target nao
nao_EXTERNAL_OBJECTS =

sdk/bin/nao: CMakeFiles/nao.dir/core/vision/detector.cpp.o
sdk/bin/nao: CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o
sdk/bin/nao: CMakeFiles/nao.dir/core/vision/balldetector.cpp.o
sdk/bin/nao: CMakeFiles/nao.dir/naointerface.cpp.o
sdk/bin/nao: CMakeFiles/nao.dir/main.cpp.o
sdk/bin/nao: CMakeFiles/nao.dir/core/common/worldobject.cpp.o
sdk/bin/nao: CMakeFiles/nao.dir/core/common/ball.cpp.o
sdk/bin/nao: CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libalvision.so
sdk/bin/nao: /usr/local/lib/libopencv_imgproc.so
sdk/bin/nao: /usr/local/lib/libopencv_highgui.so
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libalextractor.so
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libalproxies.so
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libalproxies.so
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libalcommon.so
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libalsoap.so
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/librttools.so
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libalthread.so
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libboost_signals-mt.a
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libboost_program_options-mt.a
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libalvalue.so
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libtinyxml.so
sdk/bin/nao: /usr/lib/x86_64-linux-gnu/librt.so
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libqi.so
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libboost_filesystem-mt.a
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libboost_thread-mt.a
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libboost_system-mt.a
sdk/bin/nao: /usr/lib/x86_64-linux-gnu/libdl.so
sdk/bin/nao: /home/astrid/nao/naoqi-sdk-1.14.5-linux64/lib/libalerror.so
sdk/bin/nao: /usr/local/lib/libopencv_core.so
sdk/bin/nao: CMakeFiles/nao.dir/build.make
sdk/bin/nao: CMakeFiles/nao.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sdk/bin/nao"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nao.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nao.dir/build: sdk/bin/nao
.PHONY : CMakeFiles/nao.dir/build

CMakeFiles/nao.dir/requires: CMakeFiles/nao.dir/core/vision/detector.cpp.o.requires
CMakeFiles/nao.dir/requires: CMakeFiles/nao.dir/core/vision/debug/debugballdetector.cpp.o.requires
CMakeFiles/nao.dir/requires: CMakeFiles/nao.dir/core/vision/balldetector.cpp.o.requires
CMakeFiles/nao.dir/requires: CMakeFiles/nao.dir/naointerface.cpp.o.requires
CMakeFiles/nao.dir/requires: CMakeFiles/nao.dir/main.cpp.o.requires
CMakeFiles/nao.dir/requires: CMakeFiles/nao.dir/core/common/worldobject.cpp.o.requires
CMakeFiles/nao.dir/requires: CMakeFiles/nao.dir/core/common/ball.cpp.o.requires
CMakeFiles/nao.dir/requires: CMakeFiles/nao.dir/core/common/worldobjectmanager.cpp.o.requires
.PHONY : CMakeFiles/nao.dir/requires

CMakeFiles/nao.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nao.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nao.dir/clean

CMakeFiles/nao.dir/depend:
	cd /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/astrid/nao/projects/nao /home/astrid/nao/projects/nao /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk/CMakeFiles/nao.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nao.dir/depend
