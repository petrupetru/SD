# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\fac\SEM II\SD\tema_stive_cozi_deque\vila2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\fac\SEM II\SD\tema_stive_cozi_deque\vila2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/vila2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vila2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vila2.dir/flags.make

CMakeFiles/vila2.dir/main.cpp.obj: CMakeFiles/vila2.dir/flags.make
CMakeFiles/vila2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\fac\SEM II\SD\tema_stive_cozi_deque\vila2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vila2.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\vila2.dir\main.cpp.obj -c "D:\fac\SEM II\SD\tema_stive_cozi_deque\vila2\main.cpp"

CMakeFiles/vila2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vila2.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\fac\SEM II\SD\tema_stive_cozi_deque\vila2\main.cpp" > CMakeFiles\vila2.dir\main.cpp.i

CMakeFiles/vila2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vila2.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\fac\SEM II\SD\tema_stive_cozi_deque\vila2\main.cpp" -o CMakeFiles\vila2.dir\main.cpp.s

# Object files for target vila2
vila2_OBJECTS = \
"CMakeFiles/vila2.dir/main.cpp.obj"

# External object files for target vila2
vila2_EXTERNAL_OBJECTS =

vila2.exe: CMakeFiles/vila2.dir/main.cpp.obj
vila2.exe: CMakeFiles/vila2.dir/build.make
vila2.exe: CMakeFiles/vila2.dir/linklibs.rsp
vila2.exe: CMakeFiles/vila2.dir/objects1.rsp
vila2.exe: CMakeFiles/vila2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\fac\SEM II\SD\tema_stive_cozi_deque\vila2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vila2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\vila2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vila2.dir/build: vila2.exe

.PHONY : CMakeFiles/vila2.dir/build

CMakeFiles/vila2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\vila2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/vila2.dir/clean

CMakeFiles/vila2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\fac\SEM II\SD\tema_stive_cozi_deque\vila2" "D:\fac\SEM II\SD\tema_stive_cozi_deque\vila2" "D:\fac\SEM II\SD\tema_stive_cozi_deque\vila2\cmake-build-debug" "D:\fac\SEM II\SD\tema_stive_cozi_deque\vila2\cmake-build-debug" "D:\fac\SEM II\SD\tema_stive_cozi_deque\vila2\cmake-build-debug\CMakeFiles\vila2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/vila2.dir/depend

