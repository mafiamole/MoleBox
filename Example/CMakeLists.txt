
set (SOURCES ui.cpp ball.cpp enemy.cpp player.cpp game.cpp main.cpp testcomponent.cpp)

add_executable(ExampleA ${SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ExampleA MoleBox)

set (CONTENT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Content)
set (CONTENT_LIST ${CONTENT_DIR}/paddle.png ${CONTENT_DIR}/ball.png ${CONTENT_DIR}/ui.lua ${CONTENT_DIR}/mouthpop.wav )
#add_custom_command( TARGET ExampleA POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CONTENT_DIR} ${CMAKE_CURRENT_SOURCE_DIR}  

foreach ( contentFile ${CONTENT_LIST})
	message( ${contentFile} )
	message( ${CMAKE_CURRENT_BINARY_DIR} )
	add_custom_command( TARGET ExampleA POST_BUILD COMMAND cmake -E copy_if_different ${contentFile}  ${CMAKE_CURRENT_BINARY_DIR} DEPENDS ${contentFile}  )

endforeach ( contentFile )