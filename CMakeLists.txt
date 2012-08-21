cmake_minimum_required(VERSION 2.8)

project(MoleBox)

########################################################
####		  	Version			    ####
########################################################
set(VERSION_MAJOR 0)
set(VERSION_MINOR 2)
set(VERSION_PATCH 0)


########################################################
####		  Build Options			    ####
########################################################

option ( MB_BUILD_SHARED_LIBS " TRUE to build molebox as shared libraries, FALSE to build as static libraries " TRUE )
option ( MB_BUILD_EXAMPLES "TRUE to build examples, FALSE to not build examples" FALSE )

if(NOT MB_BUILD_SHARED_LIBS)
    add_definitions(-DMB_STATIC)
    message("Building static build")
endif()

########################################################
####		  Feature Options		    ####
########################################################
option(INCLUDE_LUA "Include Lua in the project" OFF)
if ( INCLUDE_LUA )
  add_definitions(-DINCLUDE_LUA)
  option(LUA_EDITOR_TOOL "Enable the Lua live editor" OFF)
  add_definitions(-DMB_LUA_EXPORTS)
endif( )

########################################################
####		  Required Packages		    ####
########################################################

if ( INCLUDE_LUA )
  find_package(Lua51)
endif()
if (LUA_EDITOR_TOOL)
  find_package(Qt4)
  add_definitions("-DLUA_EDITOR" )
  include(${QT_USE_FILE})
endif()

find_package(SFML 2.0 COMPONENTS system window graphics audio network REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLU REQUIRED)

########################################################
####		  include directories		    ####
########################################################

set(MB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${SFML_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLU_INCLUDE_PATH} ${LUA_INCLUDE_DIR} ${MB_INCLUDE_DIR})


########################################################
####		add source directories		    ####
########################################################

add_subdirectory(src/MoleBox)

if ( MB_BUILD_EXAMPLES )
  add_subdirectory(src/ReturnOfPong)
endif()
