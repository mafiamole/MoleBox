#ifndef LUAEDITORFUNCTIONS_H
#define LUAEDITORFUNCTIONS_H

#include "lua.hpp"
#include <string>

template <int T> static int voidLuaEmptyFunction(lua_State *L) {
  
  int n = lua_gettop(L);
  
  int numberOfArgs = T;
  
  if ( numberOfArgs != T)
  {
    
    std::string error;
    error = "Incorrect number of arguments, this function takes ";
    error += numberOfArgs;
    error += ".";
    lua_pushstring(L,error.c_str());
    lua_error(L);
  }
 
  return 0;
  
}

static const luaL_reg lua_reg_sprite_DUMMY[] =
{
  { "Load", voidLuaEmptyFunction<1> },
  { "Draw", voidLuaEmptyFunction<1> },
  { "Move", voidLuaEmptyFunction<3> },
  { "Size", voidLuaEmptyFunction<0>},
  { "SetPosition", voidLuaEmptyFunction<3> },
  { "GetPosition", voidLuaEmptyFunction<0>},
  { NULL, NULL }
};

static const luaL_reg lua_reg_sound_DUMMY[] =
{
  { "Load", voidLuaEmptyFunction<1>},
  { "Play", voidLuaEmptyFunction<1>},
  { NULL, NULL }
};


static const luaL_reg lua_reg_window_DUMMY[] =
{
  { "Size", voidLuaEmptyFunction<0>},
  { NULL, NULL }
};

static const luaL_reg lua_reg_text_DUMMY[] =
{
  { "Create", voidLuaEmptyFunction<1>},
  { "Draw", voidLuaEmptyFunction<1>},
  { "Modify", voidLuaEmptyFunction<2>},
  { "Move",voidLuaEmptyFunction<3>},
  { "Size", voidLuaEmptyFunction<0>},  
  { "SetPosition", voidLuaEmptyFunction<3>},
  { "GetPosition", voidLuaEmptyFunction<0>},
  { NULL, NULL }
};

#endif
