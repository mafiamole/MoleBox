set( HEADERS
      ${MB_INCLUDE_DIR}/MoleBox/ResourceUI/Exports.hpp
      ${MB_INCLUDE_DIR}/MoleBox/ResourceUI/LuaEditor.hpp
      ${MB_INCLUDE_DIR}/MoleBox/ResourceUI/ResourceUI.hpp
      ${MB_INCLUDE_DIR}/MoleBox/ResourceUI/RUI_Thread.hpp
      ${MB_INCLUDE_DIR}/MoleBox/ResourceUI/ImageUI.hpp
      ${MB_INCLUDE_DIR}/MoleBox/ResourceUI/AudioUI.hpp

)

set ( SOURCES
    ResourceUI.cpp
    LuaEditor.cpp
    RUI_Thread.cpp
    ImageUI.cpp
    AudioUI.cpp
)

set ( FORMS 
	Main.ui
	LuaEditor.ui
	Audio.ui
	)

  find_package(Qt4)
  include(${QT_USE_FILE})

qt4_wrap_cpp( MoleBox_HEADERS_MOC ${HEADERS} )
qt4_wrap_ui( MoleBox_FORMS_HEADERS ${FORMS} )

add_definitions( "-DLUA_EDITOR" )
add_definitions(${QT_DEFINITIONS})


find_package(Lua51)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${LUA_INCLUDE_DIR} ${QT_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/src)
if(MB_BUILD_SHARED_LIBS)
add_library(MoleBox-Resources SHARED ${HEADERS} ${SOURCES} ${MoleBox_HEADERS_MOC} ${MoleBox_FORMS_HEADERS} )
else()
add_library(MoleBox-Resources STATIC ${HEADERS} ${SOURCES} ${MoleBox_HEADERS_MOC} ${MoleBox_FORMS_HEADERS} )

endif()

set_target_properties(MoleBox-Resources PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

target_link_libraries(MoleBox-Resources ${MB_LIBS} ${LUA_LIBRARIES} ${QT_LIBRARIES} )

	install( TARGETS MoleBox-Resources
            RUNTIME DESTINATION bin COMPONENT bin
            LIBRARY DESTINATION lib${LIB_SUFFIX} COMPONENT bin 
            ARCHIVE DESTINATION lib${LIB_SUFFIX} COMPONENT devel
            FRAMEWORK DESTINATION ${CMAKE_INSTALL_FRAMEWORK_PREFIX} COMPONENT bin)

	install (DIRECTORY "${MB_INCLUDE_DIR}/MoleBox" DESTINATION "include" )