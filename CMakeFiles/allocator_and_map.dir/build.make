# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/volodechka/Cource/HW_1/otus-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/volodechka/Cource/HW_1/otus-cpp

# Include any dependencies generated for this target.
include CMakeFiles/allocator_and_map.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/allocator_and_map.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/allocator_and_map.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/allocator_and_map.dir/flags.make

CMakeFiles/allocator_and_map.dir/main.cpp.o: CMakeFiles/allocator_and_map.dir/flags.make
CMakeFiles/allocator_and_map.dir/main.cpp.o: main.cpp
CMakeFiles/allocator_and_map.dir/main.cpp.o: CMakeFiles/allocator_and_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/volodechka/Cource/HW_1/otus-cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/allocator_and_map.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/allocator_and_map.dir/main.cpp.o -MF CMakeFiles/allocator_and_map.dir/main.cpp.o.d -o CMakeFiles/allocator_and_map.dir/main.cpp.o -c /home/volodechka/Cource/HW_1/otus-cpp/main.cpp

CMakeFiles/allocator_and_map.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/allocator_and_map.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/volodechka/Cource/HW_1/otus-cpp/main.cpp > CMakeFiles/allocator_and_map.dir/main.cpp.i

CMakeFiles/allocator_and_map.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/allocator_and_map.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/volodechka/Cource/HW_1/otus-cpp/main.cpp -o CMakeFiles/allocator_and_map.dir/main.cpp.s

# Object files for target allocator_and_map
allocator_and_map_OBJECTS = \
"CMakeFiles/allocator_and_map.dir/main.cpp.o"

# External object files for target allocator_and_map
allocator_and_map_EXTERNAL_OBJECTS =

allocator_and_map: CMakeFiles/allocator_and_map.dir/main.cpp.o
allocator_and_map: CMakeFiles/allocator_and_map.dir/build.make
allocator_and_map: liballocator_and_map_library_main.a
allocator_and_map: CMakeFiles/allocator_and_map.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/volodechka/Cource/HW_1/otus-cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable allocator_and_map"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/allocator_and_map.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/allocator_and_map.dir/build: allocator_and_map
.PHONY : CMakeFiles/allocator_and_map.dir/build

CMakeFiles/allocator_and_map.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/allocator_and_map.dir/cmake_clean.cmake
.PHONY : CMakeFiles/allocator_and_map.dir/clean

CMakeFiles/allocator_and_map.dir/depend:
	cd /home/volodechka/Cource/HW_1/otus-cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/volodechka/Cource/HW_1/otus-cpp /home/volodechka/Cource/HW_1/otus-cpp /home/volodechka/Cource/HW_1/otus-cpp /home/volodechka/Cource/HW_1/otus-cpp /home/volodechka/Cource/HW_1/otus-cpp/CMakeFiles/allocator_and_map.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/allocator_and_map.dir/depend
