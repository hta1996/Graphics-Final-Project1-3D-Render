# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build

# Include any dependencies generated for this target.
include src/engine/CMakeFiles/engine.dir/depend.make

# Include the progress variables for this target.
include src/engine/CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include src/engine/CMakeFiles/engine.dir/flags.make

src/engine/CMakeFiles/engine.dir/engine.cpp.obj: src/engine/CMakeFiles/engine.dir/flags.make
src/engine/CMakeFiles/engine.dir/engine.cpp.obj: src/engine/CMakeFiles/engine.dir/includes_CXX.rsp
src/engine/CMakeFiles/engine.dir/engine.cpp.obj: ../src/engine/engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/engine/CMakeFiles/engine.dir/engine.cpp.obj"
	cd D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/src/engine && C:/cygwin64/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/engine.cpp.obj -c D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/src/engine/engine.cpp

src/engine/CMakeFiles/engine.dir/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/engine.cpp.i"
	cd D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/src/engine && C:/cygwin64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/src/engine/engine.cpp > CMakeFiles/engine.dir/engine.cpp.i

src/engine/CMakeFiles/engine.dir/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/engine.cpp.s"
	cd D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/src/engine && C:/cygwin64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/src/engine/engine.cpp -o CMakeFiles/engine.dir/engine.cpp.s

src/engine/CMakeFiles/engine.dir/engine.cpp.obj.requires:

.PHONY : src/engine/CMakeFiles/engine.dir/engine.cpp.obj.requires

src/engine/CMakeFiles/engine.dir/engine.cpp.obj.provides: src/engine/CMakeFiles/engine.dir/engine.cpp.obj.requires
	$(MAKE) -f src/engine/CMakeFiles/engine.dir/build.make src/engine/CMakeFiles/engine.dir/engine.cpp.obj.provides.build
.PHONY : src/engine/CMakeFiles/engine.dir/engine.cpp.obj.provides

src/engine/CMakeFiles/engine.dir/engine.cpp.obj.provides.build: src/engine/CMakeFiles/engine.dir/engine.cpp.obj


src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj: src/engine/CMakeFiles/engine.dir/flags.make
src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj: src/engine/CMakeFiles/engine.dir/includes_CXX.rsp
src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj: ../src/engine/raytracer/raytracer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj"
	cd D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/src/engine && C:/cygwin64/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj -c D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/src/engine/raytracer/raytracer.cpp

src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/raytracer/raytracer.cpp.i"
	cd D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/src/engine && C:/cygwin64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/src/engine/raytracer/raytracer.cpp > CMakeFiles/engine.dir/raytracer/raytracer.cpp.i

src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/raytracer/raytracer.cpp.s"
	cd D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/src/engine && C:/cygwin64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/src/engine/raytracer/raytracer.cpp -o CMakeFiles/engine.dir/raytracer/raytracer.cpp.s

src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj.requires:

.PHONY : src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj.requires

src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj.provides: src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj.requires
	$(MAKE) -f src/engine/CMakeFiles/engine.dir/build.make src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj.provides.build
.PHONY : src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj.provides

src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj.provides.build: src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj


# Object files for target engine
engine_OBJECTS = \
"CMakeFiles/engine.dir/engine.cpp.obj" \
"CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj"

# External object files for target engine
engine_EXTERNAL_OBJECTS =

src/engine/libengine.a: src/engine/CMakeFiles/engine.dir/engine.cpp.obj
src/engine/libengine.a: src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj
src/engine/libengine.a: src/engine/CMakeFiles/engine.dir/build.make
src/engine/libengine.a: src/engine/CMakeFiles/engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libengine.a"
	cd D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/src/engine && $(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean_target.cmake
	cd D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/src/engine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/engine/CMakeFiles/engine.dir/build: src/engine/libengine.a

.PHONY : src/engine/CMakeFiles/engine.dir/build

src/engine/CMakeFiles/engine.dir/requires: src/engine/CMakeFiles/engine.dir/engine.cpp.obj.requires
src/engine/CMakeFiles/engine.dir/requires: src/engine/CMakeFiles/engine.dir/raytracer/raytracer.cpp.obj.requires

.PHONY : src/engine/CMakeFiles/engine.dir/requires

src/engine/CMakeFiles/engine.dir/clean:
	cd D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/src/engine && $(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean.cmake
.PHONY : src/engine/CMakeFiles/engine.dir/clean

src/engine/CMakeFiles/engine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/src/engine D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/src/engine D:/大学内容/大三上学期/高等计算图形学/Graphics-Final-Project1-3D-Render/build/src/engine/CMakeFiles/engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/engine/CMakeFiles/engine.dir/depend
