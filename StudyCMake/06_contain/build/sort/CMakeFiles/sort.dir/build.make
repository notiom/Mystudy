# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build

# Include any dependencies generated for this target.
include sort/CMakeFiles/sort.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include sort/CMakeFiles/sort.dir/compiler_depend.make

# Include the progress variables for this target.
include sort/CMakeFiles/sort.dir/progress.make

# Include the compile flags for this target's objects.
include sort/CMakeFiles/sort.dir/flags.make

sort/CMakeFiles/sort.dir/bubble.cpp.o: sort/CMakeFiles/sort.dir/flags.make
sort/CMakeFiles/sort.dir/bubble.cpp.o: /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/bubble.cpp
sort/CMakeFiles/sort.dir/bubble.cpp.o: sort/CMakeFiles/sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object sort/CMakeFiles/sort.dir/bubble.cpp.o"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sort/CMakeFiles/sort.dir/bubble.cpp.o -MF CMakeFiles/sort.dir/bubble.cpp.o.d -o CMakeFiles/sort.dir/bubble.cpp.o -c /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/bubble.cpp

sort/CMakeFiles/sort.dir/bubble.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sort.dir/bubble.cpp.i"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/bubble.cpp > CMakeFiles/sort.dir/bubble.cpp.i

sort/CMakeFiles/sort.dir/bubble.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sort.dir/bubble.cpp.s"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/bubble.cpp -o CMakeFiles/sort.dir/bubble.cpp.s

sort/CMakeFiles/sort.dir/insert.cpp.o: sort/CMakeFiles/sort.dir/flags.make
sort/CMakeFiles/sort.dir/insert.cpp.o: /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/insert.cpp
sort/CMakeFiles/sort.dir/insert.cpp.o: sort/CMakeFiles/sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object sort/CMakeFiles/sort.dir/insert.cpp.o"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sort/CMakeFiles/sort.dir/insert.cpp.o -MF CMakeFiles/sort.dir/insert.cpp.o.d -o CMakeFiles/sort.dir/insert.cpp.o -c /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/insert.cpp

sort/CMakeFiles/sort.dir/insert.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sort.dir/insert.cpp.i"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/insert.cpp > CMakeFiles/sort.dir/insert.cpp.i

sort/CMakeFiles/sort.dir/insert.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sort.dir/insert.cpp.s"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/insert.cpp -o CMakeFiles/sort.dir/insert.cpp.s

sort/CMakeFiles/sort.dir/quick.cpp.o: sort/CMakeFiles/sort.dir/flags.make
sort/CMakeFiles/sort.dir/quick.cpp.o: /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/quick.cpp
sort/CMakeFiles/sort.dir/quick.cpp.o: sort/CMakeFiles/sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object sort/CMakeFiles/sort.dir/quick.cpp.o"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sort/CMakeFiles/sort.dir/quick.cpp.o -MF CMakeFiles/sort.dir/quick.cpp.o.d -o CMakeFiles/sort.dir/quick.cpp.o -c /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/quick.cpp

sort/CMakeFiles/sort.dir/quick.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sort.dir/quick.cpp.i"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/quick.cpp > CMakeFiles/sort.dir/quick.cpp.i

sort/CMakeFiles/sort.dir/quick.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sort.dir/quick.cpp.s"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/quick.cpp -o CMakeFiles/sort.dir/quick.cpp.s

sort/CMakeFiles/sort.dir/select.cpp.o: sort/CMakeFiles/sort.dir/flags.make
sort/CMakeFiles/sort.dir/select.cpp.o: /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/select.cpp
sort/CMakeFiles/sort.dir/select.cpp.o: sort/CMakeFiles/sort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object sort/CMakeFiles/sort.dir/select.cpp.o"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT sort/CMakeFiles/sort.dir/select.cpp.o -MF CMakeFiles/sort.dir/select.cpp.o.d -o CMakeFiles/sort.dir/select.cpp.o -c /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/select.cpp

sort/CMakeFiles/sort.dir/select.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sort.dir/select.cpp.i"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/select.cpp > CMakeFiles/sort.dir/select.cpp.i

sort/CMakeFiles/sort.dir/select.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sort.dir/select.cpp.s"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort/select.cpp -o CMakeFiles/sort.dir/select.cpp.s

# Object files for target sort
sort_OBJECTS = \
"CMakeFiles/sort.dir/bubble.cpp.o" \
"CMakeFiles/sort.dir/insert.cpp.o" \
"CMakeFiles/sort.dir/quick.cpp.o" \
"CMakeFiles/sort.dir/select.cpp.o"

# External object files for target sort
sort_EXTERNAL_OBJECTS =

/Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/lib/libsort.a: sort/CMakeFiles/sort.dir/bubble.cpp.o
/Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/lib/libsort.a: sort/CMakeFiles/sort.dir/insert.cpp.o
/Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/lib/libsort.a: sort/CMakeFiles/sort.dir/quick.cpp.o
/Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/lib/libsort.a: sort/CMakeFiles/sort.dir/select.cpp.o
/Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/lib/libsort.a: sort/CMakeFiles/sort.dir/build.make
/Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/lib/libsort.a: sort/CMakeFiles/sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/lib/libsort.a"
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && $(CMAKE_COMMAND) -P CMakeFiles/sort.dir/cmake_clean_target.cmake
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sort/CMakeFiles/sort.dir/build: /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/lib/libsort.a
.PHONY : sort/CMakeFiles/sort.dir/build

sort/CMakeFiles/sort.dir/clean:
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort && $(CMAKE_COMMAND) -P CMakeFiles/sort.dir/cmake_clean.cmake
.PHONY : sort/CMakeFiles/sort.dir/clean

sort/CMakeFiles/sort.dir/depend:
	cd /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/sort /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort /Users/cds-dn-173/Desktop/xl/code/cpp/Mystudy/StudyCmake/06_contain/build/sort/CMakeFiles/sort.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : sort/CMakeFiles/sort.dir/depend

