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
CMAKE_SOURCE_DIR = "D:\fac\SEM II\SD\tema_stive_cozi_deque\paranteze2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\fac\SEM II\SD\tema_stive_cozi_deque\paranteze2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/paranteze2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/paranteze2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/paranteze2.dir/flags.make

CMakeFiles/paranteze2.dir/main.cpp.obj: CMakeFiles/paranteze2.dir/flags.make
CMakeFiles/paranteze2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\fac\SEM II\SD\tema_stive_cozi_deque\paranteze2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/paranteze2.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\paranteze2.dir\main.cpp.obj -c "D:\fac\SEM II\SD\tema_stive_cozi_deque\paranteze2\main.cpp"

CMakeFiles/paranteze2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paranteze2.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\fac\SEM II\SD\tema_stive_cozi_deque\paranteze2\main.cpp" > CMakeFiles\paranteze2.dir\main.cpp.i

CMakeFiles/paranteze2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paranteze2.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\fac\SEM II\SD\tema_stive_cozi_deque\paranteze2\main.cpp" -o CMakeFiles\paranteze2.dir\main.cpp.s

# Object files for target paranteze2
paranteze2_OBJECTS = \
"CMakeFiles/paranteze2.dir/main.cpp.obj"

# External object files for target paranteze2
paranteze2_EXTERNAL_OBJECTS =

paranteze2.exe: CMakeFiles/paranteze2.dir/main.cpp.obj
paranteze2.exe: CMakeFiles/paranteze2.dir/build.make
paranteze2.exe: CMakeFiles/paranteze2.dir/linklibs.rsp
paranteze2.exe: CMakeFiles/paranteze2.dir/objects1.rsp
paranteze2.exe: CMakeFiles/paranteze2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\fac\SEM II\SD\tema_stive_cozi_deque\paranteze2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable paranteze2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\paranteze2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/paranteze2.dir/build: paranteze2.exe

.PHONY : CMakeFiles/paranteze2.dir/build

CMakeFiles/paranteze2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\paranteze2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/paranteze2.dir/clean

CMakeFiles/paranteze2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\fac\SEM II\SD\tema_stive_cozi_deque\paranteze2" "D:\fac\SEM II\SD\tema_stive_cozi_deque\paranteze2" "D:\fac\SEM II\SD\tema_stive_cozi_deque\paranteze2\cmake-build-debug" "D:\fac\SEM II\SD\tema_stive_cozi_deque\paranteze2\cmake-build-debug" "D:\fac\SEM II\SD\tema_stive_cozi_deque\paranteze2\cmake-build-debug\CMakeFiles\paranteze2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/paranteze2.dir/depend

