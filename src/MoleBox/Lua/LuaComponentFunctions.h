#ifndef LUACOMPONENTFUNCTIONS_H
#define LUACOMPONENTFUNCTIONS_H

#include "content.h"

static const luaL_reg sfml_lua_window[] =
{
  { "Size", MB_Lua::Window::Dimensions}, 
  { NULL, NULL }
};

static const luaL_reg sfml_lua_sprite[] =
{
  { "Load", MB_Lua::Sprites::Load},
  { "Draw", MB_Lua::Sprites::Draw},
  { "Move", MB_Lua::Sprites::Move},
  { "Size", MB_Lua::Sprites::Size},
  { "SetPosition", MB_Lua::Sprites::SetPosition},
  { "GetPosition", MB_Lua::Sprites::GetPosition},
  { NULL, NULL }
};

static const luaL_reg sfml_lua_text[] =
{
  { "Create", MB_Lua::Text::Create},
  { "Draw", MB_Lua::Text::Draw},
  { "Modify", MB_Lua::Text::Modify},
  { "Move", MB_Lua::Text::Move},
  { "Size", MB_Lua::Text::Size},
  { "SetPosition", MB_Lua::Text::SetPosition},
  { "GetPosition", MB_Lua::Text::GetPosition},
  { NULL, NULL }
};

static const luaL_Reg sfml_lua_sound[] =
{
  { "Load", MB_Lua::Sounds::Load},
  { "Play", MB_Lua::Sounds::Play},
  
  { NULL, NULL }
};


#endif