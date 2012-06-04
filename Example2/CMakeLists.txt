
set (SOURCES main.cpp)

add_executable(Example2 ${SOURCES})

target_link_libraries(Example2 MoleBox)

#file(COPY Content/ DESTINATION ${CMAKE_BINARY_DIR})