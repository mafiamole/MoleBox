# - Try to find MoleBox
# 
#  MoleBox_FOUND 	- System has found the MoleBox
#  MoleBox_INCLUDE_DIR 	- MoleBox Include directories
#  MoleBox_LIBRARY   	- link this to use MoleBox
#
#  MoleBox_ROOT - Points to the root of your MoleBox installation.
#

set(MoleBox_FOUND TRUE)

find_path(MoleBox_INCLUDE_DIR MoleBox/Game.hpp
          PATH_SUFFIXES include
          PATHS
          ${MoleBox_ROOT}
          $ENV{MoleBox_ROOT}
          ~/Library/Frameworks
          /Library/Frameworks
          /usr/local/
          /usr/
          /sw          # Fink
          /opt/local/  # DarwinPorts
          /opt/csw/    # Blastwave
          /opt/)

set(FIND_MoleBox_LIB_PATHS
    ${MoleBox_ROOT}
    $ENV{MoleBox_ROOT}
    ~/Library/Frameworks
    /Library/Frameworks
    /usr/local
    /usr
    /sw
    /opt/local
    /opt/csw
    /opt)

find_library(MoleBox_LIBRARY NAMES MoleBox PATH_SUFFIXES lib64 lib PATHS FIND_MoleBox_LIB_PATHS)

if(MoleBox_LIBRARY AND MoleBox_INCLUDE_DIR)
    message("Found MoleBox: ${MoleBox_INCLUDE_DIR}")
else()
    message("MoleBox was not found!")
    set(MoleBox_FOUND FALSE)
endif()


find_package(SFML 2.0 COMPONENTS system window graphics audio network REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLU REQUIRED)
find_package(Lua51)
  find_package(Qt4)
  include(${QT_USE_FILE})
  	add_definitions(${QT_DEFINITIONS})
# convenience vars
set(MoleBox_LIBRARIES ${MoleBox_LIBRARY} ${SFML_LIBRARIES} ${QT_LIBRARIES} ${OPENGL_gl_LIBRARY} ${GLU_LIBRARY} ${LUA_LIBRARY})
set(MoleBox_INCLUDE_DIRECTORIES ${MoleBox_INCLUDE_DIR} ${SFML_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLU_INCLUDE_PATH} ${LUA_INCLUDE_DIR} )
