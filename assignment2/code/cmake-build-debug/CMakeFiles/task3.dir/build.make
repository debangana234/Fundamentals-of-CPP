# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/259/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/259/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/debangana/s8dechak_2581774/assignment2/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/debangana/s8dechak_2581774/assignment2/code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/task3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/task3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task3.dir/flags.make

CMakeFiles/task3.dir/task3.cpp.o: CMakeFiles/task3.dir/flags.make
CMakeFiles/task3.dir/task3.cpp.o: /home/debangana/s8dechak_2581774/assignment2/code/task3.cpp
CMakeFiles/task3.dir/task3.cpp.o: CMakeFiles/task3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/debangana/s8dechak_2581774/assignment2/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task3.dir/task3.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task3.dir/task3.cpp.o -MF CMakeFiles/task3.dir/task3.cpp.o.d -o CMakeFiles/task3.dir/task3.cpp.o -c /home/debangana/s8dechak_2581774/assignment2/code/task3.cpp

CMakeFiles/task3.dir/task3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/task3.dir/task3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/debangana/s8dechak_2581774/assignment2/code/task3.cpp > CMakeFiles/task3.dir/task3.cpp.i

CMakeFiles/task3.dir/task3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/task3.dir/task3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/debangana/s8dechak_2581774/assignment2/code/task3.cpp -o CMakeFiles/task3.dir/task3.cpp.s

# Object files for target task3
task3_OBJECTS = \
"CMakeFiles/task3.dir/task3.cpp.o"

# External object files for target task3
task3_EXTERNAL_OBJECTS =

task3: CMakeFiles/task3.dir/task3.cpp.o
task3: CMakeFiles/task3.dir/build.make
task3: CMakeFiles/task3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/debangana/s8dechak_2581774/assignment2/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task3.dir/build: task3
.PHONY : CMakeFiles/task3.dir/build

CMakeFiles/task3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task3.dir/clean

CMakeFiles/task3.dir/depend:
	cd /home/debangana/s8dechak_2581774/assignment2/code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/debangana/s8dechak_2581774/assignment2/code /home/debangana/s8dechak_2581774/assignment2/code /home/debangana/s8dechak_2581774/assignment2/code/cmake-build-debug /home/debangana/s8dechak_2581774/assignment2/code/cmake-build-debug /home/debangana/s8dechak_2581774/assignment2/code/cmake-build-debug/CMakeFiles/task3.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/task3.dir/depend

