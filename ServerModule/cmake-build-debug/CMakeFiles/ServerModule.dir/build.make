# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /cygdrive/c/Users/giova/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/giova/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/giova/CLionProjects/ServerModule

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/giova/CLionProjects/ServerModule/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ServerModule.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ServerModule.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ServerModule.dir/flags.make

CMakeFiles/ServerModule.dir/main.cpp.o: CMakeFiles/ServerModule.dir/flags.make
CMakeFiles/ServerModule.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/giova/CLionProjects/ServerModule/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ServerModule.dir/main.cpp.o"
	C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerModule.dir/main.cpp.o -c /cygdrive/c/Users/giova/CLionProjects/ServerModule/main.cpp

CMakeFiles/ServerModule.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerModule.dir/main.cpp.i"
	C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/giova/CLionProjects/ServerModule/main.cpp > CMakeFiles/ServerModule.dir/main.cpp.i

CMakeFiles/ServerModule.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerModule.dir/main.cpp.s"
	C:/cygwin64/bin/x86_64-pc-cygwin-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/giova/CLionProjects/ServerModule/main.cpp -o CMakeFiles/ServerModule.dir/main.cpp.s

# Object files for target ServerModule
ServerModule_OBJECTS = \
"CMakeFiles/ServerModule.dir/main.cpp.o"

# External object files for target ServerModule
ServerModule_EXTERNAL_OBJECTS =

ServerModule.exe: CMakeFiles/ServerModule.dir/main.cpp.o
ServerModule.exe: CMakeFiles/ServerModule.dir/build.make
ServerModule.exe: C:/Boostbuild/lib/libboost_thread.a
ServerModule.exe: C:/Boostbuild/lib/libboost_system.a
ServerModule.exe: C:/Boostbuild/lib/libboost_filesystem.a
ServerModule.exe: C:/Boostbuild/lib/libboost_chrono.a
ServerModule.exe: C:/Boostbuild/lib/libboost_date_time.a
ServerModule.exe: C:/Boostbuild/lib/libboost_atomic.a
ServerModule.exe: CMakeFiles/ServerModule.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/giova/CLionProjects/ServerModule/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ServerModule.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ServerModule.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ServerModule.dir/build: ServerModule.exe

.PHONY : CMakeFiles/ServerModule.dir/build

CMakeFiles/ServerModule.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ServerModule.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ServerModule.dir/clean

CMakeFiles/ServerModule.dir/depend:
	cd /cygdrive/c/Users/giova/CLionProjects/ServerModule/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/giova/CLionProjects/ServerModule /cygdrive/c/Users/giova/CLionProjects/ServerModule /cygdrive/c/Users/giova/CLionProjects/ServerModule/cmake-build-debug /cygdrive/c/Users/giova/CLionProjects/ServerModule/cmake-build-debug /cygdrive/c/Users/giova/CLionProjects/ServerModule/cmake-build-debug/CMakeFiles/ServerModule.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ServerModule.dir/depend

