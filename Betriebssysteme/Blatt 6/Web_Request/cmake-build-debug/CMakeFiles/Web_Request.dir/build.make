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
CMAKE_SOURCE_DIR = "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Web_Request.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Web_Request.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Web_Request.dir/flags.make

CMakeFiles/Web_Request.dir/lib/web_request.c.obj: CMakeFiles/Web_Request.dir/flags.make
CMakeFiles/Web_Request.dir/lib/web_request.c.obj: CMakeFiles/Web_Request.dir/includes_C.rsp
CMakeFiles/Web_Request.dir/lib/web_request.c.obj: ../lib/web_request.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Web_Request.dir/lib/web_request.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Web_Request.dir\lib\web_request.c.obj   -c "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\lib\web_request.c"

CMakeFiles/Web_Request.dir/lib/web_request.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Web_Request.dir/lib/web_request.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\lib\web_request.c" > CMakeFiles\Web_Request.dir\lib\web_request.c.i

CMakeFiles/Web_Request.dir/lib/web_request.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Web_Request.dir/lib/web_request.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\lib\web_request.c" -o CMakeFiles\Web_Request.dir\lib\web_request.c.s

CMakeFiles/Web_Request.dir/better_bot.cpp.obj: CMakeFiles/Web_Request.dir/flags.make
CMakeFiles/Web_Request.dir/better_bot.cpp.obj: CMakeFiles/Web_Request.dir/includes_CXX.rsp
CMakeFiles/Web_Request.dir/better_bot.cpp.obj: ../better_bot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Web_Request.dir/better_bot.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Web_Request.dir\better_bot.cpp.obj -c "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\better_bot.cpp"

CMakeFiles/Web_Request.dir/better_bot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Web_Request.dir/better_bot.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\better_bot.cpp" > CMakeFiles\Web_Request.dir\better_bot.cpp.i

CMakeFiles/Web_Request.dir/better_bot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Web_Request.dir/better_bot.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\better_bot.cpp" -o CMakeFiles\Web_Request.dir\better_bot.cpp.s

CMakeFiles/Web_Request.dir/simple_bot.c.obj: CMakeFiles/Web_Request.dir/flags.make
CMakeFiles/Web_Request.dir/simple_bot.c.obj: CMakeFiles/Web_Request.dir/includes_C.rsp
CMakeFiles/Web_Request.dir/simple_bot.c.obj: ../simple_bot.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Web_Request.dir/simple_bot.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Web_Request.dir\simple_bot.c.obj   -c "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\simple_bot.c"

CMakeFiles/Web_Request.dir/simple_bot.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Web_Request.dir/simple_bot.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\simple_bot.c" > CMakeFiles\Web_Request.dir\simple_bot.c.i

CMakeFiles/Web_Request.dir/simple_bot.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Web_Request.dir/simple_bot.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\simple_bot.c" -o CMakeFiles\Web_Request.dir\simple_bot.c.s

# Object files for target Web_Request
Web_Request_OBJECTS = \
"CMakeFiles/Web_Request.dir/lib/web_request.c.obj" \
"CMakeFiles/Web_Request.dir/better_bot.cpp.obj" \
"CMakeFiles/Web_Request.dir/simple_bot.c.obj"

# External object files for target Web_Request
Web_Request_EXTERNAL_OBJECTS =

Web_Request.exe: CMakeFiles/Web_Request.dir/lib/web_request.c.obj
Web_Request.exe: CMakeFiles/Web_Request.dir/better_bot.cpp.obj
Web_Request.exe: CMakeFiles/Web_Request.dir/simple_bot.c.obj
Web_Request.exe: CMakeFiles/Web_Request.dir/build.make
Web_Request.exe: CMakeFiles/Web_Request.dir/linklibs.rsp
Web_Request.exe: CMakeFiles/Web_Request.dir/objects1.rsp
Web_Request.exe: CMakeFiles/Web_Request.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Web_Request.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Web_Request.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Web_Request.dir/build: Web_Request.exe

.PHONY : CMakeFiles/Web_Request.dir/build

CMakeFiles/Web_Request.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Web_Request.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Web_Request.dir/clean

CMakeFiles/Web_Request.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request" "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request" "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\cmake-build-debug" "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\cmake-build-debug" "Z:\Studi\Betriebssysteme\Blatt 6\Web_Request\cmake-build-debug\CMakeFiles\Web_Request.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Web_Request.dir/depend
