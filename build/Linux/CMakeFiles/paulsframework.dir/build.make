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
include CMakeFiles/paulsframework.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/paulsframework.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/paulsframework.dir/flags.make

CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o: CMakeFiles/paulsframework.dir/flags.make
CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o: ../../Framework/Actions/keyboard.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o -c /home/mafiamole/projects/paulsFramework/Framework/Actions/keyboard.cpp

CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/Framework/Actions/keyboard.cpp > CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.i

CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/Framework/Actions/keyboard.cpp -o CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.s

CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o.requires:
.PHONY : CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o.requires

CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o.provides: CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o.requires
	$(MAKE) -f CMakeFiles/paulsframework.dir/build.make CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o.provides.build
.PHONY : CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o.provides

CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o.provides.build: CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o

CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o: CMakeFiles/paulsframework.dir/flags.make
CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o: ../../Framework/Actions/mouse.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o -c /home/mafiamole/projects/paulsFramework/Framework/Actions/mouse.cpp

CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/Framework/Actions/mouse.cpp > CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.i

CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/Framework/Actions/mouse.cpp -o CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.s

CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o.requires:
.PHONY : CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o.requires

CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o.provides: CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o.requires
	$(MAKE) -f CMakeFiles/paulsframework.dir/build.make CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o.provides.build
.PHONY : CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o.provides

CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o.provides.build: CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o

CMakeFiles/paulsframework.dir/Framework/action.cpp.o: CMakeFiles/paulsframework.dir/flags.make
CMakeFiles/paulsframework.dir/Framework/action.cpp.o: ../../Framework/action.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/paulsframework.dir/Framework/action.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/paulsframework.dir/Framework/action.cpp.o -c /home/mafiamole/projects/paulsFramework/Framework/action.cpp

CMakeFiles/paulsframework.dir/Framework/action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paulsframework.dir/Framework/action.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/Framework/action.cpp > CMakeFiles/paulsframework.dir/Framework/action.cpp.i

CMakeFiles/paulsframework.dir/Framework/action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paulsframework.dir/Framework/action.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/Framework/action.cpp -o CMakeFiles/paulsframework.dir/Framework/action.cpp.s

CMakeFiles/paulsframework.dir/Framework/action.cpp.o.requires:
.PHONY : CMakeFiles/paulsframework.dir/Framework/action.cpp.o.requires

CMakeFiles/paulsframework.dir/Framework/action.cpp.o.provides: CMakeFiles/paulsframework.dir/Framework/action.cpp.o.requires
	$(MAKE) -f CMakeFiles/paulsframework.dir/build.make CMakeFiles/paulsframework.dir/Framework/action.cpp.o.provides.build
.PHONY : CMakeFiles/paulsframework.dir/Framework/action.cpp.o.provides

CMakeFiles/paulsframework.dir/Framework/action.cpp.o.provides.build: CMakeFiles/paulsframework.dir/Framework/action.cpp.o

CMakeFiles/paulsframework.dir/Framework/actions.cpp.o: CMakeFiles/paulsframework.dir/flags.make
CMakeFiles/paulsframework.dir/Framework/actions.cpp.o: ../../Framework/actions.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/paulsframework.dir/Framework/actions.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/paulsframework.dir/Framework/actions.cpp.o -c /home/mafiamole/projects/paulsFramework/Framework/actions.cpp

CMakeFiles/paulsframework.dir/Framework/actions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paulsframework.dir/Framework/actions.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/Framework/actions.cpp > CMakeFiles/paulsframework.dir/Framework/actions.cpp.i

CMakeFiles/paulsframework.dir/Framework/actions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paulsframework.dir/Framework/actions.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/Framework/actions.cpp -o CMakeFiles/paulsframework.dir/Framework/actions.cpp.s

CMakeFiles/paulsframework.dir/Framework/actions.cpp.o.requires:
.PHONY : CMakeFiles/paulsframework.dir/Framework/actions.cpp.o.requires

CMakeFiles/paulsframework.dir/Framework/actions.cpp.o.provides: CMakeFiles/paulsframework.dir/Framework/actions.cpp.o.requires
	$(MAKE) -f CMakeFiles/paulsframework.dir/build.make CMakeFiles/paulsframework.dir/Framework/actions.cpp.o.provides.build
.PHONY : CMakeFiles/paulsframework.dir/Framework/actions.cpp.o.provides

CMakeFiles/paulsframework.dir/Framework/actions.cpp.o.provides.build: CMakeFiles/paulsframework.dir/Framework/actions.cpp.o

CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o: CMakeFiles/paulsframework.dir/flags.make
CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o: ../../Framework/Lua/luaScriptHelper.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o -c /home/mafiamole/projects/paulsFramework/Framework/Lua/luaScriptHelper.cpp

CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/Framework/Lua/luaScriptHelper.cpp > CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.i

CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/Framework/Lua/luaScriptHelper.cpp -o CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.s

CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o.requires:
.PHONY : CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o.requires

CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o.provides: CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o.requires
	$(MAKE) -f CMakeFiles/paulsframework.dir/build.make CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o.provides.build
.PHONY : CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o.provides

CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o.provides.build: CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o

CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o: CMakeFiles/paulsframework.dir/flags.make
CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o: ../../Framework/Lua/Component.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o -c /home/mafiamole/projects/paulsFramework/Framework/Lua/Component.cpp

CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/Framework/Lua/Component.cpp > CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.i

CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/Framework/Lua/Component.cpp -o CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.s

CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o.requires:
.PHONY : CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o.requires

CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o.provides: CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o.requires
	$(MAKE) -f CMakeFiles/paulsframework.dir/build.make CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o.provides.build
.PHONY : CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o.provides

CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o.provides.build: CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o

CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o: CMakeFiles/paulsframework.dir/flags.make
CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o: ../../Framework/GameComponent.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o -c /home/mafiamole/projects/paulsFramework/Framework/GameComponent.cpp

CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/Framework/GameComponent.cpp > CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.i

CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/Framework/GameComponent.cpp -o CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.s

CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o.requires:
.PHONY : CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o.requires

CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o.provides: CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o.requires
	$(MAKE) -f CMakeFiles/paulsframework.dir/build.make CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o.provides.build
.PHONY : CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o.provides

CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o.provides.build: CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o

CMakeFiles/paulsframework.dir/Framework/Game.cpp.o: CMakeFiles/paulsframework.dir/flags.make
CMakeFiles/paulsframework.dir/Framework/Game.cpp.o: ../../Framework/Game.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/paulsframework.dir/Framework/Game.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/paulsframework.dir/Framework/Game.cpp.o -c /home/mafiamole/projects/paulsFramework/Framework/Game.cpp

CMakeFiles/paulsframework.dir/Framework/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paulsframework.dir/Framework/Game.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/Framework/Game.cpp > CMakeFiles/paulsframework.dir/Framework/Game.cpp.i

CMakeFiles/paulsframework.dir/Framework/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paulsframework.dir/Framework/Game.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/Framework/Game.cpp -o CMakeFiles/paulsframework.dir/Framework/Game.cpp.s

CMakeFiles/paulsframework.dir/Framework/Game.cpp.o.requires:
.PHONY : CMakeFiles/paulsframework.dir/Framework/Game.cpp.o.requires

CMakeFiles/paulsframework.dir/Framework/Game.cpp.o.provides: CMakeFiles/paulsframework.dir/Framework/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/paulsframework.dir/build.make CMakeFiles/paulsframework.dir/Framework/Game.cpp.o.provides.build
.PHONY : CMakeFiles/paulsframework.dir/Framework/Game.cpp.o.provides

CMakeFiles/paulsframework.dir/Framework/Game.cpp.o.provides.build: CMakeFiles/paulsframework.dir/Framework/Game.cpp.o

CMakeFiles/paulsframework.dir/Framework/Content.cpp.o: CMakeFiles/paulsframework.dir/flags.make
CMakeFiles/paulsframework.dir/Framework/Content.cpp.o: ../../Framework/Content.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/paulsframework.dir/Framework/Content.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/paulsframework.dir/Framework/Content.cpp.o -c /home/mafiamole/projects/paulsFramework/Framework/Content.cpp

CMakeFiles/paulsframework.dir/Framework/Content.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paulsframework.dir/Framework/Content.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/Framework/Content.cpp > CMakeFiles/paulsframework.dir/Framework/Content.cpp.i

CMakeFiles/paulsframework.dir/Framework/Content.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paulsframework.dir/Framework/Content.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/Framework/Content.cpp -o CMakeFiles/paulsframework.dir/Framework/Content.cpp.s

CMakeFiles/paulsframework.dir/Framework/Content.cpp.o.requires:
.PHONY : CMakeFiles/paulsframework.dir/Framework/Content.cpp.o.requires

CMakeFiles/paulsframework.dir/Framework/Content.cpp.o.provides: CMakeFiles/paulsframework.dir/Framework/Content.cpp.o.requires
	$(MAKE) -f CMakeFiles/paulsframework.dir/build.make CMakeFiles/paulsframework.dir/Framework/Content.cpp.o.provides.build
.PHONY : CMakeFiles/paulsframework.dir/Framework/Content.cpp.o.provides

CMakeFiles/paulsframework.dir/Framework/Content.cpp.o.provides.build: CMakeFiles/paulsframework.dir/Framework/Content.cpp.o

CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o: CMakeFiles/paulsframework.dir/flags.make
CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o: ../../Example/testcomponent.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o -c /home/mafiamole/projects/paulsFramework/Example/testcomponent.cpp

CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/Example/testcomponent.cpp > CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.i

CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/Example/testcomponent.cpp -o CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.s

CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o.requires:
.PHONY : CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o.requires

CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o.provides: CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o.requires
	$(MAKE) -f CMakeFiles/paulsframework.dir/build.make CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o.provides.build
.PHONY : CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o.provides

CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o.provides.build: CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o

CMakeFiles/paulsframework.dir/Example/game.cpp.o: CMakeFiles/paulsframework.dir/flags.make
CMakeFiles/paulsframework.dir/Example/game.cpp.o: ../../Example/game.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/paulsframework.dir/Example/game.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/paulsframework.dir/Example/game.cpp.o -c /home/mafiamole/projects/paulsFramework/Example/game.cpp

CMakeFiles/paulsframework.dir/Example/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paulsframework.dir/Example/game.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/Example/game.cpp > CMakeFiles/paulsframework.dir/Example/game.cpp.i

CMakeFiles/paulsframework.dir/Example/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paulsframework.dir/Example/game.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/Example/game.cpp -o CMakeFiles/paulsframework.dir/Example/game.cpp.s

CMakeFiles/paulsframework.dir/Example/game.cpp.o.requires:
.PHONY : CMakeFiles/paulsframework.dir/Example/game.cpp.o.requires

CMakeFiles/paulsframework.dir/Example/game.cpp.o.provides: CMakeFiles/paulsframework.dir/Example/game.cpp.o.requires
	$(MAKE) -f CMakeFiles/paulsframework.dir/build.make CMakeFiles/paulsframework.dir/Example/game.cpp.o.provides.build
.PHONY : CMakeFiles/paulsframework.dir/Example/game.cpp.o.provides

CMakeFiles/paulsframework.dir/Example/game.cpp.o.provides.build: CMakeFiles/paulsframework.dir/Example/game.cpp.o

CMakeFiles/paulsframework.dir/Example/main.cpp.o: CMakeFiles/paulsframework.dir/flags.make
CMakeFiles/paulsframework.dir/Example/main.cpp.o: ../../Example/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/paulsframework.dir/Example/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/paulsframework.dir/Example/main.cpp.o -c /home/mafiamole/projects/paulsFramework/Example/main.cpp

CMakeFiles/paulsframework.dir/Example/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paulsframework.dir/Example/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mafiamole/projects/paulsFramework/Example/main.cpp > CMakeFiles/paulsframework.dir/Example/main.cpp.i

CMakeFiles/paulsframework.dir/Example/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paulsframework.dir/Example/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mafiamole/projects/paulsFramework/Example/main.cpp -o CMakeFiles/paulsframework.dir/Example/main.cpp.s

CMakeFiles/paulsframework.dir/Example/main.cpp.o.requires:
.PHONY : CMakeFiles/paulsframework.dir/Example/main.cpp.o.requires

CMakeFiles/paulsframework.dir/Example/main.cpp.o.provides: CMakeFiles/paulsframework.dir/Example/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/paulsframework.dir/build.make CMakeFiles/paulsframework.dir/Example/main.cpp.o.provides.build
.PHONY : CMakeFiles/paulsframework.dir/Example/main.cpp.o.provides

CMakeFiles/paulsframework.dir/Example/main.cpp.o.provides.build: CMakeFiles/paulsframework.dir/Example/main.cpp.o

# Object files for target paulsframework
paulsframework_OBJECTS = \
"CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o" \
"CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o" \
"CMakeFiles/paulsframework.dir/Framework/action.cpp.o" \
"CMakeFiles/paulsframework.dir/Framework/actions.cpp.o" \
"CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o" \
"CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o" \
"CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o" \
"CMakeFiles/paulsframework.dir/Framework/Game.cpp.o" \
"CMakeFiles/paulsframework.dir/Framework/Content.cpp.o" \
"CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o" \
"CMakeFiles/paulsframework.dir/Example/game.cpp.o" \
"CMakeFiles/paulsframework.dir/Example/main.cpp.o"

# External object files for target paulsframework
paulsframework_EXTERNAL_OBJECTS =

paulsframework: CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o
paulsframework: CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o
paulsframework: CMakeFiles/paulsframework.dir/Framework/action.cpp.o
paulsframework: CMakeFiles/paulsframework.dir/Framework/actions.cpp.o
paulsframework: CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o
paulsframework: CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o
paulsframework: CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o
paulsframework: CMakeFiles/paulsframework.dir/Framework/Game.cpp.o
paulsframework: CMakeFiles/paulsframework.dir/Framework/Content.cpp.o
paulsframework: CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o
paulsframework: CMakeFiles/paulsframework.dir/Example/game.cpp.o
paulsframework: CMakeFiles/paulsframework.dir/Example/main.cpp.o
paulsframework: CMakeFiles/paulsframework.dir/build.make
paulsframework: /usr/local/lib64/libsfml-system.so
paulsframework: /usr/local/lib64/libsfml-window.so
paulsframework: /usr/local/lib64/libsfml-graphics.so
paulsframework: /usr/local/lib64/libsfml-audio.so
paulsframework: /usr/lib64/libGL.so
paulsframework: /usr/lib64/libGLU.so
paulsframework: /usr/lib64/libGL.so
paulsframework: /usr/lib64/libSM.so
paulsframework: /usr/lib64/libICE.so
paulsframework: /usr/lib64/libX11.so
paulsframework: /usr/lib64/libXext.so
paulsframework: /usr/lib64/liblua-5.1.so
paulsframework: /usr/lib64/libGLU.so
paulsframework: /usr/lib64/libSM.so
paulsframework: /usr/lib64/libICE.so
paulsframework: /usr/lib64/libX11.so
paulsframework: /usr/lib64/libXext.so
paulsframework: /usr/lib64/liblua-5.1.so
paulsframework: CMakeFiles/paulsframework.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable paulsframework"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/paulsframework.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/paulsframework.dir/build: paulsframework
.PHONY : CMakeFiles/paulsframework.dir/build

CMakeFiles/paulsframework.dir/requires: CMakeFiles/paulsframework.dir/Framework/Actions/keyboard.cpp.o.requires
CMakeFiles/paulsframework.dir/requires: CMakeFiles/paulsframework.dir/Framework/Actions/mouse.cpp.o.requires
CMakeFiles/paulsframework.dir/requires: CMakeFiles/paulsframework.dir/Framework/action.cpp.o.requires
CMakeFiles/paulsframework.dir/requires: CMakeFiles/paulsframework.dir/Framework/actions.cpp.o.requires
CMakeFiles/paulsframework.dir/requires: CMakeFiles/paulsframework.dir/Framework/Lua/luaScriptHelper.cpp.o.requires
CMakeFiles/paulsframework.dir/requires: CMakeFiles/paulsframework.dir/Framework/Lua/Component.cpp.o.requires
CMakeFiles/paulsframework.dir/requires: CMakeFiles/paulsframework.dir/Framework/GameComponent.cpp.o.requires
CMakeFiles/paulsframework.dir/requires: CMakeFiles/paulsframework.dir/Framework/Game.cpp.o.requires
CMakeFiles/paulsframework.dir/requires: CMakeFiles/paulsframework.dir/Framework/Content.cpp.o.requires
CMakeFiles/paulsframework.dir/requires: CMakeFiles/paulsframework.dir/Example/testcomponent.cpp.o.requires
CMakeFiles/paulsframework.dir/requires: CMakeFiles/paulsframework.dir/Example/game.cpp.o.requires
CMakeFiles/paulsframework.dir/requires: CMakeFiles/paulsframework.dir/Example/main.cpp.o.requires
.PHONY : CMakeFiles/paulsframework.dir/requires

CMakeFiles/paulsframework.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/paulsframework.dir/cmake_clean.cmake
.PHONY : CMakeFiles/paulsframework.dir/clean

CMakeFiles/paulsframework.dir/depend:
	cd /home/mafiamole/projects/paulsFramework/build/Linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mafiamole/projects/paulsFramework /home/mafiamole/projects/paulsFramework /home/mafiamole/projects/paulsFramework/build/Linux /home/mafiamole/projects/paulsFramework/build/Linux /home/mafiamole/projects/paulsFramework/build/Linux/CMakeFiles/paulsframework.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/paulsframework.dir/depend

