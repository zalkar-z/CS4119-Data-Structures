# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Task_0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task_0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task_0.dir/flags.make

CMakeFiles/Task_0.dir/doublyLinkedList.cpp.o: CMakeFiles/Task_0.dir/flags.make
CMakeFiles/Task_0.dir/doublyLinkedList.cpp.o: ../doublyLinkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task_0.dir/doublyLinkedList.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task_0.dir/doublyLinkedList.cpp.o -c "/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0/doublyLinkedList.cpp"

CMakeFiles/Task_0.dir/doublyLinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task_0.dir/doublyLinkedList.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0/doublyLinkedList.cpp" > CMakeFiles/Task_0.dir/doublyLinkedList.cpp.i

CMakeFiles/Task_0.dir/doublyLinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task_0.dir/doublyLinkedList.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0/doublyLinkedList.cpp" -o CMakeFiles/Task_0.dir/doublyLinkedList.cpp.s

# Object files for target Task_0
Task_0_OBJECTS = \
"CMakeFiles/Task_0.dir/doublyLinkedList.cpp.o"

# External object files for target Task_0
Task_0_EXTERNAL_OBJECTS =

Task_0: CMakeFiles/Task_0.dir/doublyLinkedList.cpp.o
Task_0: CMakeFiles/Task_0.dir/build.make
Task_0: CMakeFiles/Task_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task_0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task_0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task_0.dir/build: Task_0

.PHONY : CMakeFiles/Task_0.dir/build

CMakeFiles/Task_0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Task_0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Task_0.dir/clean

CMakeFiles/Task_0.dir/depend:
	cd "/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0" "/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0" "/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0/cmake-build-debug" "/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0/cmake-build-debug" "/Users/zalkar/Desktop/DSC++/My_Git/Lab#4/Task#0/cmake-build-debug/CMakeFiles/Task_0.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Task_0.dir/depend

