# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ndreadno/ft_container

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ndreadno/ft_container/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/map.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/map.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/map.dir/flags.make

CMakeFiles/map.dir/Map/main.cpp.o: CMakeFiles/map.dir/flags.make
CMakeFiles/map.dir/Map/main.cpp.o: ../Map/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ndreadno/ft_container/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/map.dir/Map/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/map.dir/Map/main.cpp.o -c /Users/ndreadno/ft_container/Map/main.cpp

CMakeFiles/map.dir/Map/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/map.dir/Map/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ndreadno/ft_container/Map/main.cpp > CMakeFiles/map.dir/Map/main.cpp.i

CMakeFiles/map.dir/Map/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/map.dir/Map/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ndreadno/ft_container/Map/main.cpp -o CMakeFiles/map.dir/Map/main.cpp.s

# Object files for target map
map_OBJECTS = \
"CMakeFiles/map.dir/Map/main.cpp.o"

# External object files for target map
map_EXTERNAL_OBJECTS =

map: CMakeFiles/map.dir/Map/main.cpp.o
map: CMakeFiles/map.dir/build.make
map: CMakeFiles/map.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ndreadno/ft_container/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable map"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/map.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/map.dir/build: map

.PHONY : CMakeFiles/map.dir/build

CMakeFiles/map.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/map.dir/cmake_clean.cmake
.PHONY : CMakeFiles/map.dir/clean

CMakeFiles/map.dir/depend:
	cd /Users/ndreadno/ft_container/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ndreadno/ft_container /Users/ndreadno/ft_container /Users/ndreadno/ft_container/cmake-build-debug /Users/ndreadno/ft_container/cmake-build-debug /Users/ndreadno/ft_container/cmake-build-debug/CMakeFiles/map.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/map.dir/depend

