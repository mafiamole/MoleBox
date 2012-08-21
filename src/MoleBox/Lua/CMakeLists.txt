set( HEADERS
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Export.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Helpers.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Script.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Push.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Function.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Component.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/SFML.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Container.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Containers.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Arguments/Argument.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Arguments/Integer.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Arguments/String.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Arguments/Number.hpp
      ${MB_INCLUDE_DIR}/MoleBox/Lua/Arguments/Boolean.hpp
)

set ( SOURCES
      Helpers.cpp
      Script.cpp
      Push.cpp
      Function.cpp
      Component.cpp
      SFML.cpp
      Container.cpp
      Containers.cpp
      Arguments/Argument.cpp
      Arguments/Integer.cpp
      Arguments/String.cpp
      Arguments/Number.cpp
      Arguments/Boolean.cpp
      Arguments/ActionsArg.cpp
)
find_package(Lua51)

include_directories(${LUA_INCLUDE_DIR})
if (LUA_EDITOR_TOOL)
add_definitions( "-DLUA_EDITOR" )
endif()
if(MB_BUILD_SHARED_LIBS)
  add_library(MoleBox-Lua SHARED ${HEADERS} ${SOURCES})
else()
  add_library(MoleBox-Lua STATIC ${HEADERS} ${SOURCES})
endif()
set_target_properties(MoleBox-Lua PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
message ( "lua lib includes:" )
message ( ${MB_LIBS} )
target_link_libraries(MoleBox-Lua ${MB_LIBS}  MoleBox-Core )

add_subdirectory(Arguments)

	install( TARGETS MoleBox-Lua
            RUNTIME DESTINATION bin COMPONENT bin
            LIBRARY DESTINATION lib${LIB_SUFFIX} COMPONENT bin 
            ARCHIVE DESTINATION lib${LIB_SUFFIX} COMPONENT devel
            FRAMEWORK DESTINATION ${CMAKE_INSTALL_FRAMEWORK_PREFIX} COMPONENT bin)

	install (DIRECTORY "${MB_INCLUDE_DIR}/MoleBox" DESTINATION "include" )