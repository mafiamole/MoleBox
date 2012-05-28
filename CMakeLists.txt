cmake_minimum_required(VERSION 2.8)
project(paulsframework)
#set (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
option(LUA_EDITOR_TOOL "Enable the Lua live editor" OFF)

find_package(SFML 2.0 REQUIRED system window graphics audio)

find_package(OpenGL REQUIRED)
find_package(GLU REQUIRED)

if (LUA_EDITOR_TOOL)
  find_package(Qt4)
  add_definitions( "-DLUA_EDITOR" )
endif()

find_package(Lua51)

  set ( paulsframework_SOURCES 
	      Framework/Lua/content.cpp
	      Framework/Actions/keyboard.cpp 
	      Framework/Actions/mouse.cpp 
	      Framework/action.cpp 
	      Framework/actions.cpp
	      Framework/Lua/LuaScriptHelper.cpp
	      Framework/Lua/Component.cpp
	      Framework/Lua/luascript.cpp
	      Framework/Lua/luascripts.cpp
	      Framework/Lua/luaeditor.cpp 
	      Framework/GameComponent.cpp
	      Framework/Game.cpp
	      Framework/Content.cpp
	      Example/testcomponent.cpp 
	      Example/game.cpp
	      Example/main.cpp
      )

  set ( paulsframework_HEADERS
	      Framework/Lua/luaeditor.h
	      Framework/Lua/LuaScriptHelper.h
	      Framework/Lua/Component.h
	      Framework/Lua/luascript.h
	      Framework/Lua/luascripts.h
	      Framework/ContentTemplate.h
	      Framework/Content.h
	      Framework/action.h
	      Framework/actions.h
	      Framework/ContainerDefinitions.h
	      Framework/Content.h
	      Framework/Game.h
	      Framework/GameComponent.h
	      Framework/Actions/keyboard.h
	      Framework/Actions/mouse.h
      )

  set ( paulsframework_FORMS 
	      Framework/Lua/GameLuaEditor.ui
      )

if (LUA_EDITOR_TOOL)

#  SET ( paulsframework_RESOURCES )
 
  qt4_wrap_cpp( paulsframework_HEADERS_MOC ${paulsframework_HEADERS} )
  qt4_wrap_ui( paulsframework_FORMS_HEADERS ${paulsframework_FORMS} )
# qt_add_resources( paulsframework_RESOURCES_RCC ${paulsframework_RESOURCES} )

  add_executable(paulsframework ${paulsframework_SOURCES}
	      ${paulsframework_HEADERS_MOC}
	      ${paulsframework_FORMS_HEADERS}
	      #${paulsframework_RESOURCES_RCC}
	      )
  include_directories(${CMAKE_CURRENT_BINARY_DIR})
  include(${QT_USE_FILE})
  add_definitions(${QT_DEFINITIONS})
  target_link_libraries(paulsframework ${QT_LIBRARIES})
else ()

  add_executable(paulsframework 
	      ${paulsframework_SOURCES}
	      )

endif()


if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLU_INCLUDE_PATH})
  target_link_libraries(paulsframework ${SFML_LIBRARIES} ${OPENGL_gl_LIBRARY} ${GLU_LIBRARY} ${LUA_LIBRARY})
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -Wno-long-long -pedantic -Weffc++ -Wextra")

add_subdirectory(Example)
add_subdirectory(Framework)
# Copy content to output directiory
file(COPY Content/ DESTINATION ${CMAKE_BINARY_DIR})
