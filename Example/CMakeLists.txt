
set (SOURCES game.cpp main.cpp testcomponent.cpp)

add_executable(ExampleA ${SOURCES})


target_link_libraries(ExampleA MoleBox)