# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /Volumes/cmake-3.2.2-Darwin-x86_64/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Volumes/cmake-3.2.2-Darwin-x86_64/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kayla/Projects/Graphics/CPE476Lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kayla/Projects/Graphics/CPE476Lab1

# Include any dependencies generated for this target.
include CMakeFiles/lab5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab5.dir/flags.make

CMakeFiles/lab5.dir/main.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab5.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/main.cpp.o -c /Users/kayla/Projects/Graphics/CPE476Lab1/main.cpp

CMakeFiles/lab5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kayla/Projects/Graphics/CPE476Lab1/main.cpp > CMakeFiles/lab5.dir/main.cpp.i

CMakeFiles/lab5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kayla/Projects/Graphics/CPE476Lab1/main.cpp -o CMakeFiles/lab5.dir/main.cpp.s

CMakeFiles/lab5.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/lab5.dir/main.cpp.o.requires

CMakeFiles/lab5.dir/main.cpp.o.provides: CMakeFiles/lab5.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/main.cpp.o.provides

CMakeFiles/lab5.dir/main.cpp.o.provides.build: CMakeFiles/lab5.dir/main.cpp.o

CMakeFiles/lab5.dir/GLSL.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/GLSL.cpp.o: GLSL.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab5.dir/GLSL.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/GLSL.cpp.o -c /Users/kayla/Projects/Graphics/CPE476Lab1/GLSL.cpp

CMakeFiles/lab5.dir/GLSL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/GLSL.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kayla/Projects/Graphics/CPE476Lab1/GLSL.cpp > CMakeFiles/lab5.dir/GLSL.cpp.i

CMakeFiles/lab5.dir/GLSL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/GLSL.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kayla/Projects/Graphics/CPE476Lab1/GLSL.cpp -o CMakeFiles/lab5.dir/GLSL.cpp.s

CMakeFiles/lab5.dir/GLSL.cpp.o.requires:
.PHONY : CMakeFiles/lab5.dir/GLSL.cpp.o.requires

CMakeFiles/lab5.dir/GLSL.cpp.o.provides: CMakeFiles/lab5.dir/GLSL.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/GLSL.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/GLSL.cpp.o.provides

CMakeFiles/lab5.dir/GLSL.cpp.o.provides.build: CMakeFiles/lab5.dir/GLSL.cpp.o

CMakeFiles/lab5.dir/tiny_obj_loader.cc.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/tiny_obj_loader.cc.o: tiny_obj_loader.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab5.dir/tiny_obj_loader.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/tiny_obj_loader.cc.o -c /Users/kayla/Projects/Graphics/CPE476Lab1/tiny_obj_loader.cc

CMakeFiles/lab5.dir/tiny_obj_loader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/tiny_obj_loader.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kayla/Projects/Graphics/CPE476Lab1/tiny_obj_loader.cc > CMakeFiles/lab5.dir/tiny_obj_loader.cc.i

CMakeFiles/lab5.dir/tiny_obj_loader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/tiny_obj_loader.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kayla/Projects/Graphics/CPE476Lab1/tiny_obj_loader.cc -o CMakeFiles/lab5.dir/tiny_obj_loader.cc.s

CMakeFiles/lab5.dir/tiny_obj_loader.cc.o.requires:
.PHONY : CMakeFiles/lab5.dir/tiny_obj_loader.cc.o.requires

CMakeFiles/lab5.dir/tiny_obj_loader.cc.o.provides: CMakeFiles/lab5.dir/tiny_obj_loader.cc.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/tiny_obj_loader.cc.o.provides.build
.PHONY : CMakeFiles/lab5.dir/tiny_obj_loader.cc.o.provides

CMakeFiles/lab5.dir/tiny_obj_loader.cc.o.provides.build: CMakeFiles/lab5.dir/tiny_obj_loader.cc.o

CMakeFiles/lab5.dir/Booth.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/Booth.cpp.o: Booth.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab5.dir/Booth.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/Booth.cpp.o -c /Users/kayla/Projects/Graphics/CPE476Lab1/Booth.cpp

CMakeFiles/lab5.dir/Booth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/Booth.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kayla/Projects/Graphics/CPE476Lab1/Booth.cpp > CMakeFiles/lab5.dir/Booth.cpp.i

CMakeFiles/lab5.dir/Booth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/Booth.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kayla/Projects/Graphics/CPE476Lab1/Booth.cpp -o CMakeFiles/lab5.dir/Booth.cpp.s

CMakeFiles/lab5.dir/Booth.cpp.o.requires:
.PHONY : CMakeFiles/lab5.dir/Booth.cpp.o.requires

CMakeFiles/lab5.dir/Booth.cpp.o.provides: CMakeFiles/lab5.dir/Booth.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/Booth.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/Booth.cpp.o.provides

CMakeFiles/lab5.dir/Booth.cpp.o.provides.build: CMakeFiles/lab5.dir/Booth.cpp.o

CMakeFiles/lab5.dir/Camera.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/Camera.cpp.o: Camera.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab5.dir/Camera.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/Camera.cpp.o -c /Users/kayla/Projects/Graphics/CPE476Lab1/Camera.cpp

CMakeFiles/lab5.dir/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/Camera.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kayla/Projects/Graphics/CPE476Lab1/Camera.cpp > CMakeFiles/lab5.dir/Camera.cpp.i

CMakeFiles/lab5.dir/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/Camera.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kayla/Projects/Graphics/CPE476Lab1/Camera.cpp -o CMakeFiles/lab5.dir/Camera.cpp.s

CMakeFiles/lab5.dir/Camera.cpp.o.requires:
.PHONY : CMakeFiles/lab5.dir/Camera.cpp.o.requires

CMakeFiles/lab5.dir/Camera.cpp.o.provides: CMakeFiles/lab5.dir/Camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/Camera.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/Camera.cpp.o.provides

CMakeFiles/lab5.dir/Camera.cpp.o.provides.build: CMakeFiles/lab5.dir/Camera.cpp.o

CMakeFiles/lab5.dir/MatrixStack.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/MatrixStack.cpp.o: MatrixStack.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab5.dir/MatrixStack.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/MatrixStack.cpp.o -c /Users/kayla/Projects/Graphics/CPE476Lab1/MatrixStack.cpp

CMakeFiles/lab5.dir/MatrixStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/MatrixStack.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kayla/Projects/Graphics/CPE476Lab1/MatrixStack.cpp > CMakeFiles/lab5.dir/MatrixStack.cpp.i

CMakeFiles/lab5.dir/MatrixStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/MatrixStack.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kayla/Projects/Graphics/CPE476Lab1/MatrixStack.cpp -o CMakeFiles/lab5.dir/MatrixStack.cpp.s

CMakeFiles/lab5.dir/MatrixStack.cpp.o.requires:
.PHONY : CMakeFiles/lab5.dir/MatrixStack.cpp.o.requires

CMakeFiles/lab5.dir/MatrixStack.cpp.o.provides: CMakeFiles/lab5.dir/MatrixStack.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/MatrixStack.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/MatrixStack.cpp.o.provides

CMakeFiles/lab5.dir/MatrixStack.cpp.o.provides.build: CMakeFiles/lab5.dir/MatrixStack.cpp.o

CMakeFiles/lab5.dir/Object.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/Object.cpp.o: Object.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab5.dir/Object.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/Object.cpp.o -c /Users/kayla/Projects/Graphics/CPE476Lab1/Object.cpp

CMakeFiles/lab5.dir/Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/Object.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kayla/Projects/Graphics/CPE476Lab1/Object.cpp > CMakeFiles/lab5.dir/Object.cpp.i

CMakeFiles/lab5.dir/Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/Object.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kayla/Projects/Graphics/CPE476Lab1/Object.cpp -o CMakeFiles/lab5.dir/Object.cpp.s

CMakeFiles/lab5.dir/Object.cpp.o.requires:
.PHONY : CMakeFiles/lab5.dir/Object.cpp.o.requires

CMakeFiles/lab5.dir/Object.cpp.o.provides: CMakeFiles/lab5.dir/Object.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/Object.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/Object.cpp.o.provides

CMakeFiles/lab5.dir/Object.cpp.o.provides.build: CMakeFiles/lab5.dir/Object.cpp.o

CMakeFiles/lab5.dir/Player.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/Player.cpp.o: Player.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab5.dir/Player.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/Player.cpp.o -c /Users/kayla/Projects/Graphics/CPE476Lab1/Player.cpp

CMakeFiles/lab5.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/Player.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kayla/Projects/Graphics/CPE476Lab1/Player.cpp > CMakeFiles/lab5.dir/Player.cpp.i

CMakeFiles/lab5.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/Player.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kayla/Projects/Graphics/CPE476Lab1/Player.cpp -o CMakeFiles/lab5.dir/Player.cpp.s

CMakeFiles/lab5.dir/Player.cpp.o.requires:
.PHONY : CMakeFiles/lab5.dir/Player.cpp.o.requires

CMakeFiles/lab5.dir/Player.cpp.o.provides: CMakeFiles/lab5.dir/Player.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/Player.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/Player.cpp.o.provides

CMakeFiles/lab5.dir/Player.cpp.o.provides.build: CMakeFiles/lab5.dir/Player.cpp.o

CMakeFiles/lab5.dir/Session.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/Session.cpp.o: Session.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab5.dir/Session.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/Session.cpp.o -c /Users/kayla/Projects/Graphics/CPE476Lab1/Session.cpp

CMakeFiles/lab5.dir/Session.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/Session.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kayla/Projects/Graphics/CPE476Lab1/Session.cpp > CMakeFiles/lab5.dir/Session.cpp.i

CMakeFiles/lab5.dir/Session.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/Session.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kayla/Projects/Graphics/CPE476Lab1/Session.cpp -o CMakeFiles/lab5.dir/Session.cpp.s

CMakeFiles/lab5.dir/Session.cpp.o.requires:
.PHONY : CMakeFiles/lab5.dir/Session.cpp.o.requires

CMakeFiles/lab5.dir/Session.cpp.o.provides: CMakeFiles/lab5.dir/Session.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/Session.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/Session.cpp.o.provides

CMakeFiles/lab5.dir/Session.cpp.o.provides.build: CMakeFiles/lab5.dir/Session.cpp.o

CMakeFiles/lab5.dir/SkyBox.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/SkyBox.cpp.o: SkyBox.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab5.dir/SkyBox.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/SkyBox.cpp.o -c /Users/kayla/Projects/Graphics/CPE476Lab1/SkyBox.cpp

CMakeFiles/lab5.dir/SkyBox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/SkyBox.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kayla/Projects/Graphics/CPE476Lab1/SkyBox.cpp > CMakeFiles/lab5.dir/SkyBox.cpp.i

CMakeFiles/lab5.dir/SkyBox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/SkyBox.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kayla/Projects/Graphics/CPE476Lab1/SkyBox.cpp -o CMakeFiles/lab5.dir/SkyBox.cpp.s

CMakeFiles/lab5.dir/SkyBox.cpp.o.requires:
.PHONY : CMakeFiles/lab5.dir/SkyBox.cpp.o.requires

CMakeFiles/lab5.dir/SkyBox.cpp.o.provides: CMakeFiles/lab5.dir/SkyBox.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/SkyBox.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/SkyBox.cpp.o.provides

CMakeFiles/lab5.dir/SkyBox.cpp.o.provides.build: CMakeFiles/lab5.dir/SkyBox.cpp.o

CMakeFiles/lab5.dir/Window.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/Window.cpp.o: Window.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab5.dir/Window.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/Window.cpp.o -c /Users/kayla/Projects/Graphics/CPE476Lab1/Window.cpp

CMakeFiles/lab5.dir/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/Window.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kayla/Projects/Graphics/CPE476Lab1/Window.cpp > CMakeFiles/lab5.dir/Window.cpp.i

CMakeFiles/lab5.dir/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/Window.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kayla/Projects/Graphics/CPE476Lab1/Window.cpp -o CMakeFiles/lab5.dir/Window.cpp.s

CMakeFiles/lab5.dir/Window.cpp.o.requires:
.PHONY : CMakeFiles/lab5.dir/Window.cpp.o.requires

CMakeFiles/lab5.dir/Window.cpp.o.provides: CMakeFiles/lab5.dir/Window.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/Window.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/Window.cpp.o.provides

CMakeFiles/lab5.dir/Window.cpp.o.provides.build: CMakeFiles/lab5.dir/Window.cpp.o

CMakeFiles/lab5.dir/World.cpp.o: CMakeFiles/lab5.dir/flags.make
CMakeFiles/lab5.dir/World.cpp.o: World.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab5.dir/World.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab5.dir/World.cpp.o -c /Users/kayla/Projects/Graphics/CPE476Lab1/World.cpp

CMakeFiles/lab5.dir/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5.dir/World.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/kayla/Projects/Graphics/CPE476Lab1/World.cpp > CMakeFiles/lab5.dir/World.cpp.i

CMakeFiles/lab5.dir/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5.dir/World.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/kayla/Projects/Graphics/CPE476Lab1/World.cpp -o CMakeFiles/lab5.dir/World.cpp.s

CMakeFiles/lab5.dir/World.cpp.o.requires:
.PHONY : CMakeFiles/lab5.dir/World.cpp.o.requires

CMakeFiles/lab5.dir/World.cpp.o.provides: CMakeFiles/lab5.dir/World.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab5.dir/build.make CMakeFiles/lab5.dir/World.cpp.o.provides.build
.PHONY : CMakeFiles/lab5.dir/World.cpp.o.provides

CMakeFiles/lab5.dir/World.cpp.o.provides.build: CMakeFiles/lab5.dir/World.cpp.o

# Object files for target lab5
lab5_OBJECTS = \
"CMakeFiles/lab5.dir/main.cpp.o" \
"CMakeFiles/lab5.dir/GLSL.cpp.o" \
"CMakeFiles/lab5.dir/tiny_obj_loader.cc.o" \
"CMakeFiles/lab5.dir/Booth.cpp.o" \
"CMakeFiles/lab5.dir/Camera.cpp.o" \
"CMakeFiles/lab5.dir/MatrixStack.cpp.o" \
"CMakeFiles/lab5.dir/Object.cpp.o" \
"CMakeFiles/lab5.dir/Player.cpp.o" \
"CMakeFiles/lab5.dir/Session.cpp.o" \
"CMakeFiles/lab5.dir/SkyBox.cpp.o" \
"CMakeFiles/lab5.dir/Window.cpp.o" \
"CMakeFiles/lab5.dir/World.cpp.o"

# External object files for target lab5
lab5_EXTERNAL_OBJECTS =

lab5: CMakeFiles/lab5.dir/main.cpp.o
lab5: CMakeFiles/lab5.dir/GLSL.cpp.o
lab5: CMakeFiles/lab5.dir/tiny_obj_loader.cc.o
lab5: CMakeFiles/lab5.dir/Booth.cpp.o
lab5: CMakeFiles/lab5.dir/Camera.cpp.o
lab5: CMakeFiles/lab5.dir/MatrixStack.cpp.o
lab5: CMakeFiles/lab5.dir/Object.cpp.o
lab5: CMakeFiles/lab5.dir/Player.cpp.o
lab5: CMakeFiles/lab5.dir/Session.cpp.o
lab5: CMakeFiles/lab5.dir/SkyBox.cpp.o
lab5: CMakeFiles/lab5.dir/Window.cpp.o
lab5: CMakeFiles/lab5.dir/World.cpp.o
lab5: CMakeFiles/lab5.dir/build.make
lab5: /usr/local/lib/libglfw3.dylib
lab5: /usr/local/lib/libGLEW.dylib
lab5: CMakeFiles/lab5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable lab5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab5.dir/build: lab5
.PHONY : CMakeFiles/lab5.dir/build

CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/main.cpp.o.requires
CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/GLSL.cpp.o.requires
CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/tiny_obj_loader.cc.o.requires
CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/Booth.cpp.o.requires
CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/Camera.cpp.o.requires
CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/MatrixStack.cpp.o.requires
CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/Object.cpp.o.requires
CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/Player.cpp.o.requires
CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/Session.cpp.o.requires
CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/SkyBox.cpp.o.requires
CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/Window.cpp.o.requires
CMakeFiles/lab5.dir/requires: CMakeFiles/lab5.dir/World.cpp.o.requires
.PHONY : CMakeFiles/lab5.dir/requires

CMakeFiles/lab5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab5.dir/clean

CMakeFiles/lab5.dir/depend:
	cd /Users/kayla/Projects/Graphics/CPE476Lab1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kayla/Projects/Graphics/CPE476Lab1 /Users/kayla/Projects/Graphics/CPE476Lab1 /Users/kayla/Projects/Graphics/CPE476Lab1 /Users/kayla/Projects/Graphics/CPE476Lab1 /Users/kayla/Projects/Graphics/CPE476Lab1/CMakeFiles/lab5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab5.dir/depend

