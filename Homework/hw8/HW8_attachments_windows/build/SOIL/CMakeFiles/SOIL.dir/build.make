# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "D:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build

# Include any dependencies generated for this target.
include SOIL/CMakeFiles/SOIL.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include SOIL/CMakeFiles/SOIL.dir/compiler_depend.make

# Include the progress variables for this target.
include SOIL/CMakeFiles/SOIL.dir/progress.make

# Include the compile flags for this target's objects.
include SOIL/CMakeFiles/SOIL.dir/flags.make

SOIL/CMakeFiles/SOIL.dir/src/image_dxt.c.obj: SOIL/CMakeFiles/SOIL.dir/flags.make
SOIL/CMakeFiles/SOIL.dir/src/image_dxt.c.obj: SOIL/CMakeFiles/SOIL.dir/includes_C.rsp
SOIL/CMakeFiles/SOIL.dir/src/image_dxt.c.obj: E:/Courses/G1S2/CS100/Homework/hw8/HW8_attachments_windows/third_party/SOIL/src/image_dxt.c
SOIL/CMakeFiles/SOIL.dir/src/image_dxt.c.obj: SOIL/CMakeFiles/SOIL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object SOIL/CMakeFiles/SOIL.dir/src/image_dxt.c.obj"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT SOIL/CMakeFiles/SOIL.dir/src/image_dxt.c.obj -MF CMakeFiles\SOIL.dir\src\image_dxt.c.obj.d -o CMakeFiles\SOIL.dir\src\image_dxt.c.obj -c E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL\src\image_dxt.c

SOIL/CMakeFiles/SOIL.dir/src/image_dxt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SOIL.dir/src/image_dxt.c.i"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL\src\image_dxt.c > CMakeFiles\SOIL.dir\src\image_dxt.c.i

SOIL/CMakeFiles/SOIL.dir/src/image_dxt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SOIL.dir/src/image_dxt.c.s"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL\src\image_dxt.c -o CMakeFiles\SOIL.dir\src\image_dxt.c.s

SOIL/CMakeFiles/SOIL.dir/src/image_helper.c.obj: SOIL/CMakeFiles/SOIL.dir/flags.make
SOIL/CMakeFiles/SOIL.dir/src/image_helper.c.obj: SOIL/CMakeFiles/SOIL.dir/includes_C.rsp
SOIL/CMakeFiles/SOIL.dir/src/image_helper.c.obj: E:/Courses/G1S2/CS100/Homework/hw8/HW8_attachments_windows/third_party/SOIL/src/image_helper.c
SOIL/CMakeFiles/SOIL.dir/src/image_helper.c.obj: SOIL/CMakeFiles/SOIL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object SOIL/CMakeFiles/SOIL.dir/src/image_helper.c.obj"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT SOIL/CMakeFiles/SOIL.dir/src/image_helper.c.obj -MF CMakeFiles\SOIL.dir\src\image_helper.c.obj.d -o CMakeFiles\SOIL.dir\src\image_helper.c.obj -c E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL\src\image_helper.c

SOIL/CMakeFiles/SOIL.dir/src/image_helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SOIL.dir/src/image_helper.c.i"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL\src\image_helper.c > CMakeFiles\SOIL.dir\src\image_helper.c.i

SOIL/CMakeFiles/SOIL.dir/src/image_helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SOIL.dir/src/image_helper.c.s"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL\src\image_helper.c -o CMakeFiles\SOIL.dir\src\image_helper.c.s

SOIL/CMakeFiles/SOIL.dir/src/soil.c.obj: SOIL/CMakeFiles/SOIL.dir/flags.make
SOIL/CMakeFiles/SOIL.dir/src/soil.c.obj: SOIL/CMakeFiles/SOIL.dir/includes_C.rsp
SOIL/CMakeFiles/SOIL.dir/src/soil.c.obj: E:/Courses/G1S2/CS100/Homework/hw8/HW8_attachments_windows/third_party/SOIL/src/soil.c
SOIL/CMakeFiles/SOIL.dir/src/soil.c.obj: SOIL/CMakeFiles/SOIL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object SOIL/CMakeFiles/SOIL.dir/src/soil.c.obj"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT SOIL/CMakeFiles/SOIL.dir/src/soil.c.obj -MF CMakeFiles\SOIL.dir\src\soil.c.obj.d -o CMakeFiles\SOIL.dir\src\soil.c.obj -c E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL\src\soil.c

SOIL/CMakeFiles/SOIL.dir/src/soil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SOIL.dir/src/soil.c.i"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL\src\soil.c > CMakeFiles\SOIL.dir\src\soil.c.i

SOIL/CMakeFiles/SOIL.dir/src/soil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SOIL.dir/src/soil.c.s"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL\src\soil.c -o CMakeFiles\SOIL.dir\src\soil.c.s

SOIL/CMakeFiles/SOIL.dir/src/stb_image_aug.c.obj: SOIL/CMakeFiles/SOIL.dir/flags.make
SOIL/CMakeFiles/SOIL.dir/src/stb_image_aug.c.obj: SOIL/CMakeFiles/SOIL.dir/includes_C.rsp
SOIL/CMakeFiles/SOIL.dir/src/stb_image_aug.c.obj: E:/Courses/G1S2/CS100/Homework/hw8/HW8_attachments_windows/third_party/SOIL/src/stb_image_aug.c
SOIL/CMakeFiles/SOIL.dir/src/stb_image_aug.c.obj: SOIL/CMakeFiles/SOIL.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object SOIL/CMakeFiles/SOIL.dir/src/stb_image_aug.c.obj"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT SOIL/CMakeFiles/SOIL.dir/src/stb_image_aug.c.obj -MF CMakeFiles\SOIL.dir\src\stb_image_aug.c.obj.d -o CMakeFiles\SOIL.dir\src\stb_image_aug.c.obj -c E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL\src\stb_image_aug.c

SOIL/CMakeFiles/SOIL.dir/src/stb_image_aug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SOIL.dir/src/stb_image_aug.c.i"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL\src\stb_image_aug.c > CMakeFiles\SOIL.dir\src\stb_image_aug.c.i

SOIL/CMakeFiles/SOIL.dir/src/stb_image_aug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SOIL.dir/src/stb_image_aug.c.s"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL\src\stb_image_aug.c -o CMakeFiles\SOIL.dir\src\stb_image_aug.c.s

# Object files for target SOIL
SOIL_OBJECTS = \
"CMakeFiles/SOIL.dir/src/image_dxt.c.obj" \
"CMakeFiles/SOIL.dir/src/image_helper.c.obj" \
"CMakeFiles/SOIL.dir/src/soil.c.obj" \
"CMakeFiles/SOIL.dir/src/stb_image_aug.c.obj"

# External object files for target SOIL
SOIL_EXTERNAL_OBJECTS =

lib/libSOIL.a: SOIL/CMakeFiles/SOIL.dir/src/image_dxt.c.obj
lib/libSOIL.a: SOIL/CMakeFiles/SOIL.dir/src/image_helper.c.obj
lib/libSOIL.a: SOIL/CMakeFiles/SOIL.dir/src/soil.c.obj
lib/libSOIL.a: SOIL/CMakeFiles/SOIL.dir/src/stb_image_aug.c.obj
lib/libSOIL.a: SOIL/CMakeFiles/SOIL.dir/build.make
lib/libSOIL.a: SOIL/CMakeFiles/SOIL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library ..\lib\libSOIL.a"
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && $(CMAKE_COMMAND) -P CMakeFiles\SOIL.dir\cmake_clean_target.cmake
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SOIL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
SOIL/CMakeFiles/SOIL.dir/build: lib/libSOIL.a
.PHONY : SOIL/CMakeFiles/SOIL.dir/build

SOIL/CMakeFiles/SOIL.dir/clean:
	cd /d E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL && $(CMAKE_COMMAND) -P CMakeFiles\SOIL.dir\cmake_clean.cmake
.PHONY : SOIL/CMakeFiles/SOIL.dir/clean

SOIL/CMakeFiles/SOIL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\third_party\SOIL E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL E:\Courses\G1S2\CS100\Homework\hw8\HW8_attachments_windows\build\SOIL\CMakeFiles\SOIL.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : SOIL/CMakeFiles/SOIL.dir/depend

