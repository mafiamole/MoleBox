cmake_minimum_required(VERSION 2.8)

project(MoleBox)
include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/Macros.cmake)
# #option(MB_LUA "Enable the use of Lua components in your application" ON)
# option(LUA_EDITOR_TOOL "Enable the Lua live editor" OFF)

# #
# #	Find the relevent packages for both the framework and examples.
# #
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

#include the relevant files to compile both the framework and examples
include_directories(${SFML_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLU_INCLUDE_PATH} ${LUA_INCLUDE_DIR})

if (LUA_EDITOR_TOOL)


endif()

add_subdirectory(src/MoleBox)

add_subdirectory(Example)

add_subdirectory(Example2)
# Copy content to output directiory

