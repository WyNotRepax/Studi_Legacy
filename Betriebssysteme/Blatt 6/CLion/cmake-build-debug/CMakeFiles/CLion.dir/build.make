# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "Z:\Studi\Betriebssysteme\Blatt 6\CLion"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "Z:\Studi\Betriebssysteme\Blatt 6\CLion\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CLion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CLion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CLion.dir/flags.make

CMakeFiles/CLion.dir/main.cpp.obj: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/main.cpp.obj: CMakeFiles/CLion.dir/includes_CXX.rsp
CMakeFiles/CLion.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="Z:\Studi\Betriebssysteme\Blatt 6\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CLion.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CLion.dir\main.cpp.obj -c "Z:\Studi\Betriebssysteme\Blatt 6\CLion\main.cpp"

CMakeFiles/CLion.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "Z:\Studi\Betriebssysteme\Blatt 6\CLion\main.cpp" > CMakeFiles\CLion.dir\main.cpp.i

CMakeFiles/CLion.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "Z:\Studi\Betriebssysteme\Blatt 6\CLion\main.cpp" -o CMakeFiles\CLion.dir\main.cpp.s

CMakeFiles/CLion.dir/lib/web_request.c.obj: CMakeFiles/CLion.dir/flags.make
CMakeFiles/CLion.dir/lib/web_request.c.obj: CMakeFiles/CLion.dir/includes_C.rsp
CMakeFiles/CLion.dir/lib/web_request.c.obj: ../lib/web_request.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="Z:\Studi\Betriebssysteme\Blatt 6\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/CLion.dir/lib/web_request.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\CLion.dir\lib\web_request.c.obj   -c "Z:\Studi\Betriebssysteme\Blatt 6\CLion\lib\web_request.c"

CMakeFiles/CLion.dir/lib/web_request.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CLion.dir/lib/web_request.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "Z:\Studi\Betriebssysteme\Blatt 6\CLion\lib\web_request.c" > CMakeFiles\CLion.dir\lib\web_request.c.i

CMakeFiles/CLion.dir/lib/web_request.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CLion.dir/lib/web_request.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "Z:\Studi\Betriebssysteme\Blatt 6\CLion\lib\web_request.c" -o CMakeFiles\CLion.dir\lib\web_request.c.s

# Object files for target CLion
CLion_OBJECTS = \
"CMakeFiles/CLion.dir/main.cpp.obj" \
"CMakeFiles/CLion.dir/lib/web_request.c.obj"

# External object files for target CLion
CLion_EXTERNAL_OBJECTS =

CLion.exe: CMakeFiles/CLion.dir/main.cpp.obj
CLion.exe: CMakeFiles/CLion.dir/lib/web_request.c.obj
CLion.exe: CMakeFiles/CLion.dir/build.make
CLion.exe: CMakeFiles/CLion.dir/linklibs.rsp
CLion.exe: CMakeFiles/CLion.dir/objects1.rsp
CLion.exe: CMakeFiles/CLion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="Z:\Studi\Betriebssysteme\Blatt 6\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CLion.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CLion.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CLion.dir/build: CLion.exe

.PHONY : CMakeFiles/CLion.dir/build

CMakeFiles/CLion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CLion.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CLion.dir/clean

CMakeFiles/CLion.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "Z:\Studi\Betriebssysteme\Blatt 6\CLion" "Z:\Studi\Betriebssysteme\Blatt 6\CLion" "Z:\Studi\Betriebssysteme\Blatt 6\CLion\cmake-build-debug" "Z:\Studi\Betriebssysteme\Blatt 6\CLion\cmake-build-debug" "Z:\Studi\Betriebssysteme\Blatt 6\CLion\cmake-build-debug\CMakeFiles\CLion.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CLion.dir/depend

