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
include CMakeFiles/ip_print_tests_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ip_print_tests_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ip_print_tests_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ip_print_tests_lib.dir/flags.make

CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.o: CMakeFiles/ip_print_tests_lib.dir/flags.make
CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.o: ip_print_lib_folder/tests/tests_main.cpp
CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.o: CMakeFiles/ip_print_tests_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/volodechka/Cource/HW_1/otus-cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.o -MF CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.o.d -o CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.o -c /home/volodechka/Cource/HW_1/otus-cpp/ip_print_lib_folder/tests/tests_main.cpp

CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/volodechka/Cource/HW_1/otus-cpp/ip_print_lib_folder/tests/tests_main.cpp > CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.i

CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/volodechka/Cource/HW_1/otus-cpp/ip_print_lib_folder/tests/tests_main.cpp -o CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.s

# Object files for target ip_print_tests_lib
ip_print_tests_lib_OBJECTS = \
"CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.o"

# External object files for target ip_print_tests_lib
ip_print_tests_lib_EXTERNAL_OBJECTS =

libip_print_tests_lib.a: CMakeFiles/ip_print_tests_lib.dir/ip_print_lib_folder/tests/tests_main.cpp.o
libip_print_tests_lib.a: CMakeFiles/ip_print_tests_lib.dir/build.make
libip_print_tests_lib.a: CMakeFiles/ip_print_tests_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/volodechka/Cource/HW_1/otus-cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libip_print_tests_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ip_print_tests_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ip_print_tests_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ip_print_tests_lib.dir/build: libip_print_tests_lib.a
.PHONY : CMakeFiles/ip_print_tests_lib.dir/build

CMakeFiles/ip_print_tests_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ip_print_tests_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ip_print_tests_lib.dir/clean

CMakeFiles/ip_print_tests_lib.dir/depend:
	cd /home/volodechka/Cource/HW_1/otus-cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/volodechka/Cource/HW_1/otus-cpp /home/volodechka/Cource/HW_1/otus-cpp /home/volodechka/Cource/HW_1/otus-cpp /home/volodechka/Cource/HW_1/otus-cpp /home/volodechka/Cource/HW_1/otus-cpp/CMakeFiles/ip_print_tests_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ip_print_tests_lib.dir/depend

