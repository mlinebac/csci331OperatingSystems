# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/matt/.local/share/Trash/files/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/matt/.local/share/Trash/files/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/matt/csci331

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matt/csci331/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/csci331.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/csci331.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/csci331.dir/flags.make

CMakeFiles/csci331.dir/lab2.c.o: CMakeFiles/csci331.dir/flags.make
CMakeFiles/csci331.dir/lab2.c.o: ../lab2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matt/csci331/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/csci331.dir/lab2.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/csci331.dir/lab2.c.o   -c /home/matt/csci331/lab2.c

CMakeFiles/csci331.dir/lab2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/csci331.dir/lab2.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matt/csci331/lab2.c > CMakeFiles/csci331.dir/lab2.c.i

CMakeFiles/csci331.dir/lab2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/csci331.dir/lab2.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matt/csci331/lab2.c -o CMakeFiles/csci331.dir/lab2.c.s

CMakeFiles/csci331.dir/lab2.c.o.requires:

.PHONY : CMakeFiles/csci331.dir/lab2.c.o.requires

CMakeFiles/csci331.dir/lab2.c.o.provides: CMakeFiles/csci331.dir/lab2.c.o.requires
	$(MAKE) -f CMakeFiles/csci331.dir/build.make CMakeFiles/csci331.dir/lab2.c.o.provides.build
.PHONY : CMakeFiles/csci331.dir/lab2.c.o.provides

CMakeFiles/csci331.dir/lab2.c.o.provides.build: CMakeFiles/csci331.dir/lab2.c.o


# Object files for target csci331
csci331_OBJECTS = \
"CMakeFiles/csci331.dir/lab2.c.o"

# External object files for target csci331
csci331_EXTERNAL_OBJECTS =

csci331: CMakeFiles/csci331.dir/lab2.c.o
csci331: CMakeFiles/csci331.dir/build.make
csci331: CMakeFiles/csci331.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matt/csci331/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable csci331"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/csci331.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/csci331.dir/build: csci331

.PHONY : CMakeFiles/csci331.dir/build

CMakeFiles/csci331.dir/requires: CMakeFiles/csci331.dir/lab2.c.o.requires

.PHONY : CMakeFiles/csci331.dir/requires

CMakeFiles/csci331.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/csci331.dir/cmake_clean.cmake
.PHONY : CMakeFiles/csci331.dir/clean

CMakeFiles/csci331.dir/depend:
	cd /home/matt/csci331/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matt/csci331 /home/matt/csci331 /home/matt/csci331/cmake-build-debug /home/matt/csci331/cmake-build-debug /home/matt/csci331/cmake-build-debug/CMakeFiles/csci331.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/csci331.dir/depend
