# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mafiamole/projects/paulsFramework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mafiamole/projects/paulsFramework/build/Linux

# Include any dependencies generated for this target.
include CMakeFiles/MoleBox.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MoleBox.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MoleBox.dir/flags.make

CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o: ../../src/MoleBox/Actions/keyboard.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/Actions/keyboard.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/Actions/keyboard.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/Actions/keyboard.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o

CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o: ../../src/MoleBox/Actions/mouse.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/Actions/mouse.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/Actions/mouse.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/Actions/mouse.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o

CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o: ../../src/MoleBox/action.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/action.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/action.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/action.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o

CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o: ../../src/MoleBox/actions.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/actions.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/actions.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/actions.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o: ../../src/MoleBox/Lua/content.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/content.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/content.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/content.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o: ../../src/MoleBox/Lua/LuaScriptHelper.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/LuaScriptHelper.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/LuaScriptHelper.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/LuaScriptHelper.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o: ../../src/MoleBox/Lua/Component.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/Component.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/Component.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/Component.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o: ../../src/MoleBox/Lua/luascript.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/luascript.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/luascript.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/luascript.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o: ../../src/MoleBox/Lua/luascripts.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/luascripts.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/luascripts.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/luascripts.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o: ../../src/MoleBox/Lua/luaeditor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/luaeditor.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/luaeditor.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/Lua/luaeditor.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o

CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o: ../../src/MoleBox/GameComponent.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/GameComponent.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/GameComponent.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/GameComponent.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o

CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o: ../../src/MoleBox/Game.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/Game.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/Game.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/Game.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o

CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o: CMakeFiles/MoleBox.dir/flags.make
CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o: ../../src/MoleBox/Content.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o -c /home/mafiamole/projects/paulsFramework/src/MoleBox/Content.cpp

CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/src/MoleBox/Content.cpp > CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.i

CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/src/MoleBox/Content.cpp -o CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.s

CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o.requires:
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o.requires

CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o.provides: CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o.requires
	$(MAKE) -f CMakeFiles/MoleBox.dir/build.make CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o.provides.build
.PHONY : CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o.provides

CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o.provides.build: CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o

# Object files for target MoleBox
MoleBox_OBJECTS = \
"CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o" \
"CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o" \
"CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o" \
"CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o" \
"CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o" \
"CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o" \
"CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o" \
"CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o" \
"CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o" \
"CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o" \
"CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o" \
"CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o" \
"CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o"

# External object files for target MoleBox
MoleBox_EXTERNAL_OBJECTS =

libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o
libMoleBox.so: CMakeFiles/MoleBox.dir/build.make
libMoleBox.so: /usr/local/lib64/libsfml-system.so
libMoleBox.so: /usr/local/lib64/libsfml-window.so
libMoleBox.so: /usr/local/lib64/libsfml-graphics.so
libMoleBox.so: /usr/local/lib64/libsfml-audio.so
libMoleBox.so: /usr/lib64/libGL.so
libMoleBox.so: /usr/lib64/libGLU.so
libMoleBox.so: /usr/lib64/libGL.so
libMoleBox.so: /usr/lib64/libSM.so
libMoleBox.so: /usr/lib64/libICE.so
libMoleBox.so: /usr/lib64/libX11.so
libMoleBox.so: /usr/lib64/libXext.so
libMoleBox.so: /usr/lib64/liblua-5.1.so
libMoleBox.so: /usr/lib64/libGLU.so
libMoleBox.so: /usr/lib64/libSM.so
libMoleBox.so: /usr/lib64/libICE.so
libMoleBox.so: /usr/lib64/libX11.so
libMoleBox.so: /usr/lib64/libXext.so
libMoleBox.so: /usr/lib64/liblua-5.1.so
libMoleBox.so: CMakeFiles/MoleBox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libMoleBox.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MoleBox.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MoleBox.dir/build: libMoleBox.so
.PHONY : CMakeFiles/MoleBox.dir/build

CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/Actions/keyboard.cpp.o.requires
CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/Actions/mouse.cpp.o.requires
CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/action.cpp.o.requires
CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/actions.cpp.o.requires
CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/content.cpp.o.requires
CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/LuaScriptHelper.cpp.o.requires
CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/Component.cpp.o.requires
CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascript.cpp.o.requires
CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luascripts.cpp.o.requires
CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/Lua/luaeditor.cpp.o.requires
CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/GameComponent.cpp.o.requires
CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/Game.cpp.o.requires
CMakeFiles/MoleBox.dir/requires: CMakeFiles/MoleBox.dir/src/MoleBox/Content.cpp.o.requires
.PHONY : CMakeFiles/MoleBox.dir/requires

CMakeFiles/MoleBox.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MoleBox.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MoleBox.dir/clean

CMakeFiles/MoleBox.dir/depend:
	cd /home/mafiamole/projects/paulsFramework/build/Linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mafiamole/projects/paulsFramework /home/mafiamole/projects/paulsFramework /home/mafiamole/projects/paulsFramework/build/Linux /home/mafiamole/projects/paulsFramework/build/Linux /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles/MoleBox.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MoleBox.dir/depend

