# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\tymka\Desktop\Studia\DecisionTreee

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tymka\Desktop\Studia\DecisionTreee\build

# Include any dependencies generated for this target.
include CMakeFiles/DecisionTree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DecisionTree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DecisionTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DecisionTree.dir/flags.make

CMakeFiles/DecisionTree.dir/main.cpp.obj: CMakeFiles/DecisionTree.dir/flags.make
CMakeFiles/DecisionTree.dir/main.cpp.obj: C:/Users/tymka/Desktop/Studia/DecisionTreee/main.cpp
CMakeFiles/DecisionTree.dir/main.cpp.obj: CMakeFiles/DecisionTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\tymka\Desktop\Studia\DecisionTreee\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DecisionTree.dir/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DecisionTree.dir/main.cpp.obj -MF CMakeFiles\DecisionTree.dir\main.cpp.obj.d -o CMakeFiles\DecisionTree.dir\main.cpp.obj -c C:\Users\tymka\Desktop\Studia\DecisionTreee\main.cpp

CMakeFiles/DecisionTree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DecisionTree.dir/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tymka\Desktop\Studia\DecisionTreee\main.cpp > CMakeFiles\DecisionTree.dir\main.cpp.i

CMakeFiles/DecisionTree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DecisionTree.dir/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tymka\Desktop\Studia\DecisionTreee\main.cpp -o CMakeFiles\DecisionTree.dir\main.cpp.s

CMakeFiles/DecisionTree.dir/utils.cpp.obj: CMakeFiles/DecisionTree.dir/flags.make
CMakeFiles/DecisionTree.dir/utils.cpp.obj: C:/Users/tymka/Desktop/Studia/DecisionTreee/utils.cpp
CMakeFiles/DecisionTree.dir/utils.cpp.obj: CMakeFiles/DecisionTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\tymka\Desktop\Studia\DecisionTreee\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DecisionTree.dir/utils.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DecisionTree.dir/utils.cpp.obj -MF CMakeFiles\DecisionTree.dir\utils.cpp.obj.d -o CMakeFiles\DecisionTree.dir\utils.cpp.obj -c C:\Users\tymka\Desktop\Studia\DecisionTreee\utils.cpp

CMakeFiles/DecisionTree.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DecisionTree.dir/utils.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tymka\Desktop\Studia\DecisionTreee\utils.cpp > CMakeFiles\DecisionTree.dir\utils.cpp.i

CMakeFiles/DecisionTree.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DecisionTree.dir/utils.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tymka\Desktop\Studia\DecisionTreee\utils.cpp -o CMakeFiles\DecisionTree.dir\utils.cpp.s

CMakeFiles/DecisionTree.dir/errorMessages.cpp.obj: CMakeFiles/DecisionTree.dir/flags.make
CMakeFiles/DecisionTree.dir/errorMessages.cpp.obj: C:/Users/tymka/Desktop/Studia/DecisionTreee/errorMessages.cpp
CMakeFiles/DecisionTree.dir/errorMessages.cpp.obj: CMakeFiles/DecisionTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\tymka\Desktop\Studia\DecisionTreee\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DecisionTree.dir/errorMessages.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DecisionTree.dir/errorMessages.cpp.obj -MF CMakeFiles\DecisionTree.dir\errorMessages.cpp.obj.d -o CMakeFiles\DecisionTree.dir\errorMessages.cpp.obj -c C:\Users\tymka\Desktop\Studia\DecisionTreee\errorMessages.cpp

CMakeFiles/DecisionTree.dir/errorMessages.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DecisionTree.dir/errorMessages.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\tymka\Desktop\Studia\DecisionTreee\errorMessages.cpp > CMakeFiles\DecisionTree.dir\errorMessages.cpp.i

CMakeFiles/DecisionTree.dir/errorMessages.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DecisionTree.dir/errorMessages.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\tymka\Desktop\Studia\DecisionTreee\errorMessages.cpp -o CMakeFiles\DecisionTree.dir\errorMessages.cpp.s

# Object files for target DecisionTree
DecisionTree_OBJECTS = \
"CMakeFiles/DecisionTree.dir/main.cpp.obj" \
"CMakeFiles/DecisionTree.dir/utils.cpp.obj" \
"CMakeFiles/DecisionTree.dir/errorMessages.cpp.obj"

# External object files for target DecisionTree
DecisionTree_EXTERNAL_OBJECTS =

DecisionTree.exe: CMakeFiles/DecisionTree.dir/main.cpp.obj
DecisionTree.exe: CMakeFiles/DecisionTree.dir/utils.cpp.obj
DecisionTree.exe: CMakeFiles/DecisionTree.dir/errorMessages.cpp.obj
DecisionTree.exe: CMakeFiles/DecisionTree.dir/build.make
DecisionTree.exe: CMakeFiles/DecisionTree.dir/linkLibs.rsp
DecisionTree.exe: CMakeFiles/DecisionTree.dir/objects1.rsp
DecisionTree.exe: CMakeFiles/DecisionTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\tymka\Desktop\Studia\DecisionTreee\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable DecisionTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DecisionTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DecisionTree.dir/build: DecisionTree.exe
.PHONY : CMakeFiles/DecisionTree.dir/build

CMakeFiles/DecisionTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DecisionTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DecisionTree.dir/clean

CMakeFiles/DecisionTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tymka\Desktop\Studia\DecisionTreee C:\Users\tymka\Desktop\Studia\DecisionTreee C:\Users\tymka\Desktop\Studia\DecisionTreee\build C:\Users\tymka\Desktop\Studia\DecisionTreee\build C:\Users\tymka\Desktop\Studia\DecisionTreee\build\CMakeFiles\DecisionTree.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/DecisionTree.dir/depend
