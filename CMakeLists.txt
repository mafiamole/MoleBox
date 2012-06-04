cmake_minimum_required(VERSION 2.8)

project(MoleBox)
include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/Macros.cmake)
#option(MB_LUA "Enable the use of Lua components in your application" ON)
option(LUA_EDITOR_TOOL "Enable the Lua live editor" OFF)

#
#	Find the relevent packages
#
message("Finding packages")
find_package(SFML 2.0 COMPONENTS system window graphics audio REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLU REQUIRED)
#if (MB_LUA)
find_package(Lua51)
#endif()
if (LUA_EDITOR_TOOL)
  find_package(Qt4)
  include(${QT_USE_FILE})
  add_definitions( "-DLUA_EDITOR" )
endif()

#
#	Set the Sources and headers and forms
#
set ( MoleBox_SOURCES

  src/MoleBox/Actions/keyboard.cpp 
  src/MoleBox/Actions/mouse.cpp 
  src/MoleBox/action.cpp 
  src/MoleBox/actions.cpp
  src/MoleBox/Lua/content.cpp	  
  src/MoleBox/Lua/LuaScriptHelper.cpp
  src/MoleBox/Lua/Component.cpp
  src/MoleBox/Lua/luascript.cpp
  src/MoleBox/Lua/luascripts.cpp
  src/MoleBox/Lua/luaeditor.cpp 
  src/MoleBox/GameComponent.cpp
  src/MoleBox/Game.cpp
  src/MoleBox/Content.cpp

  )

set ( MoleBox_HEADERS

  src/MoleBox/Lua/luaeditor.h
  src/MoleBox/Lua/LuaScriptHelper.h
  src/MoleBox/Lua/Component.h
  src/MoleBox/Lua/luascript.h
  src/MoleBox/Lua/luascripts.h
  src/MoleBox/ContentTemplate.h
  src/MoleBox/Content.h
  src/MoleBox/action.h
  src/MoleBox/actions.h
  src/MoleBox/ContainerDefinitions.h
  src/MoleBox/Content.h
  src/MoleBox/Game.h
  src/MoleBox/GameComponent.h
  src/MoleBox/Actions/keyboard.h
  src/MoleBox/Actions/mouse.h

  )
 
#
#	Sets up everything related compiling with the Lua Editor enabled.
#
if (LUA_EDITOR_TOOL)

	set ( MoleBox_FORMS 
	      src/MoleBox//Lua/GameLuaEditor.ui
		)

	#set ( paulsframework_RESOURCES )
 
	qt4_wrap_cpp( MoleBox_HEADERS_MOC ${MoleBox_HEADERS} )
	qt4_wrap_ui( MoleBox_FORMS_HEADERS ${MoleBox_FORMS} )

	# qt_add_resources( paulsframework_RESOURCES_RCC ${paulsframework_RESOURCES} )

	add_library(MoleBox SHARED
		${MoleBox_SOURCES}
		${MoleBox_HEADERS_MOC}
		${MoleBox_FORMS_HEADERS}
		#${paulsframework_RESOURCES_RCC}
	    )

	include_directories(${CMAKE_CURRENT_BINARY_DIR})
	include(${QT_USE_FILE})
	add_definitions(${QT_DEFINITIONS})
	target_link_libraries(MoleBox ${QT_LIBRARIES})
#
#	Sets up everything related compiling with the Lua Editor disabled.
#  
else ()

	add_library(MoleBox SHARED
	    ${MoleBox_SOURCES}
	    )

endif()

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLU_INCLUDE_PATH} ${LUA_INCLUDE_DIR})
  target_link_libraries(MoleBox ${SFML_LIBRARIES} ${OPENGL_gl_LIBRARY} ${GLU_LIBRARY} ${LUA_LIBRARY})
endif()


add_subdirectory(src/MoleBox)
add_subdirectory(Example)

add_subdirectory(Example2)
# Copy content to output directiory
file(COPY Content/ DESTINATION ${CMAKE_BINARY_DIR})
