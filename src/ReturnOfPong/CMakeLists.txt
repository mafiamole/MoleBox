set (HEADERS 
  ${MB_INCLUDE_DIR}/ReturnOfPong/Game.hpp
  ${MB_INCLUDE_DIR}/ReturnOfPong/MainMenu.hpp
  ${MB_INCLUDE_DIR}/ReturnOfPong/PongGame.hpp
  ${MB_INCLUDE_DIR}/ReturnOfPong/Components/Player.hpp
  ${MB_INCLUDE_DIR}/ReturnOfPong/Components/Enemy.hpp
  ${MB_INCLUDE_DIR}/ReturnOfPong/Components/Ball.hpp
  ${MB_INCLUDE_DIR}/ReturnOfPong/Components/HUD.hpp
)
set (SOURCES
      main.cpp
      Game.cpp
      MainMenu.cpp
      PongGame.cpp
      Components/Player.cpp
      Components/Enemy.cpp
      Components/Ball.cpp
      Components/HUD.cpp
    )


add_executable(ReturnOfPong  ${HEADERS} ${SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ReturnOfPong MoleBox-Core MoleBox-Lua)

install (TARGETS ReturnOfPong DESTINATION bin)

add_subdirectory(Components)