# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\User\Desktop\Bennington College\term2\Data_Structures_C++\Lab#4\Task#0"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Desktop\Bennington College\term2\Data_Structures_C++\Lab#4\Task#0\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Task_0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task_0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task_0.dir/flags.make

CMakeFiles/Task_0.dir/doublyLinkedList.cpp.obj: CMakeFiles/Task_0.dir/flags.make
CMakeFiles/Task_0.dir/doublyLinkedList.cpp.obj: ../doublyLinkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\Bennington College\term2\Data_Structures_C++\Lab#4\Task#0\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task_0.dir/doublyLinkedList.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Task_0.dir\doublyLinkedList.cpp.obj -c "C:\Users\User\Desktop\Bennington College\term2\Data_Structures_C++\Lab#4\Task#0\doublyLinkedList.cpp"

CMakeFiles/Task_0.dir/doublyLinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task_0.dir/doublyLinkedList.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\Bennington College\term2\Data_Structures_C++\Lab#4\Task#0\doublyLinkedList.cpp" > CMakeFiles\Task_0.dir\doublyLinkedList.cpp.i

CMakeFiles/Task_0.dir/doublyLinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task_0.dir/doublyLinkedList.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\Bennington College\term2\Data_Structures_C++\Lab#4\Task#0\doublyLinkedList.cpp" -o CMakeFiles\Task_0.dir\doublyLinkedList.cpp.s

# Object files for target Task_0
Task_0_OBJECTS = \
"CMakeFiles/Task_0.dir/doublyLinkedList.cpp.obj"

# External object files for target Task_0
Task_0_EXTERNAL_OBJECTS =

Task_0.exe: CMakeFiles/Task_0.dir/doublyLinkedList.cpp.obj
Task_0.exe: CMakeFiles/Task_0.dir/build.make
Task_0.exe: CMakeFiles/Task_0.dir/linklibs.rsp
Task_0.exe: CMakeFiles/Task_0.dir/objects1.rsp
Task_0.exe: CMakeFiles/Task_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\Desktop\Bennington College\term2\Data_Structures_C++\Lab#4\Task#0\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task_0.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Task_0.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task_0.dir/build: Task_0.exe

.PHONY : CMakeFiles/Task_0.dir/build

CMakeFiles/Task_0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Task_0.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Task_0.dir/clean

CMakeFiles/Task_0.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Desktop\Bennington College\term2\Data_Structures_C++\Lab#4\Task#0" "C:\Users\User\Desktop\Bennington College\term2\Data_Structures_C++\Lab#4\Task#0" "C:\Users\User\Desktop\Bennington College\term2\Data_Structures_C++\Lab#4\Task#0\cmake-build-debug" "C:\Users\User\Desktop\Bennington College\term2\Data_Structures_C++\Lab#4\Task#0\cmake-build-debug" "C:\Users\User\Desktop\Bennington College\term2\Data_Structures_C++\Lab#4\Task#0\cmake-build-debug\CMakeFiles\Task_0.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Task_0.dir/depend

