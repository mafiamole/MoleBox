#include <iostream>


#include "content.h"
#include "SFMLContent.h"
#include "sfmlgame.h"
#include "Test/game.h"
#include "Lua/luaScriptHelper.h"
#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
  
  try {
  Game game;
  
  game.Run();
  }
  catch (std::string error) {
    std::cout << error << std::endl;
  }
 
  
  return EXIT_SUCCESS;
}
