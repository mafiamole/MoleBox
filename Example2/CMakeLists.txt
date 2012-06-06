
set (SOURCES main.cpp game.cpp player.cpp Utility/spritesheet.cpp Utility/spritesheetanimator.cpp)

add_executable(Example2 ${SOURCES})

target_link_libraries(Example2 MoleBox)

add_subdirectory(Utility)

#file(COPY Content/ DESTINATION ${CMAKE_BINARY_DIR})