# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/rino/CLion/clion-2019.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/rino/CLion/clion-2019.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lab6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab6.dir/flags.make

CMakeFiles/lab6.dir/main.c.o: CMakeFiles/lab6.dir/flags.make
CMakeFiles/lab6.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab6.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab6.dir/main.c.o   -c "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/main.c"

CMakeFiles/lab6.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab6.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/main.c" > CMakeFiles/lab6.dir/main.c.i

CMakeFiles/lab6.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab6.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/main.c" -o CMakeFiles/lab6.dir/main.c.s

CMakeFiles/lab6.dir/BLAS.c.o: CMakeFiles/lab6.dir/flags.make
CMakeFiles/lab6.dir/BLAS.c.o: ../BLAS.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab6.dir/BLAS.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab6.dir/BLAS.c.o   -c "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/BLAS.c"

CMakeFiles/lab6.dir/BLAS.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab6.dir/BLAS.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/BLAS.c" > CMakeFiles/lab6.dir/BLAS.c.i

CMakeFiles/lab6.dir/BLAS.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab6.dir/BLAS.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/BLAS.c" -o CMakeFiles/lab6.dir/BLAS.c.s

# Object files for target lab6
lab6_OBJECTS = \
"CMakeFiles/lab6.dir/main.c.o" \
"CMakeFiles/lab6.dir/BLAS.c.o"

# External object files for target lab6
lab6_EXTERNAL_OBJECTS =

lab6: CMakeFiles/lab6.dir/main.c.o
lab6: CMakeFiles/lab6.dir/BLAS.c.o
lab6: CMakeFiles/lab6.dir/build.make
lab6: CMakeFiles/lab6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable lab6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab6.dir/build: lab6

.PHONY : CMakeFiles/lab6.dir/build

CMakeFiles/lab6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab6.dir/clean

CMakeFiles/lab6.dir/depend:
	cd "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6" "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6" "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/cmake-build-debug" "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/cmake-build-debug" "/home/rino/Рабочий стол/Institut/5_semestr/ABC/lab6/cmake-build-debug/CMakeFiles/lab6.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lab6.dir/depend

