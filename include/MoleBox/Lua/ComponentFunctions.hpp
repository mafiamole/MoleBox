#ifndef LUACOMPONENTFUNCTIONS_H
#define LUACOMPONENTFUNCTIONS_H

#include <MoleBox/Lua/Content.hpp>
namespace MB {
  
  namespace Lua {
    static const luaL_reg sfml_lua_window[] =
    {
      { "Size", Window::Dimensions}, 
      { NULL, NULL }
    };

    static const luaL_reg sfml_lua_sprite[] =
    {
      { "Load", Sprites::Load},
      { "Draw", Sprites::Draw},
      { "Move", Sprites::Move},
      { "Size", Sprites::Size},
      { "SetPosition", Sprites::SetPosition},
      { "GetPosition", Sprites::GetPosition},
      { NULL, NULL }
    };

    static const luaL_reg sfml_lua_text[] =
    {
      { "Create", Text::Create},
      { "Draw", Text::Draw},
      { "Modify", Text::Modify},
      { "Move", Text::Move},
      { "Size", Text::Size},
      { "SetPosition", Text::SetPosition},
      { "GetPosition", Text::GetPosition},
      { NULL, NULL }
    };

    static const luaL_Reg sfml_lua_sound[] =
    {
      { "Load", Sounds::Load},
      { "Play", Sounds::Play},
      
      { NULL, NULL }
    };
  }
}
#endif