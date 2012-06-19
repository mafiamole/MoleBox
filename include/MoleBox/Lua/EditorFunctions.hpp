#ifndef LUAEDITORFUNCTIONS_H
#define LUAEDITORFUNCTIONS_H

#include "lua.hpp"
#include <string>

namespace MB {
  
  namespace Lua {

    template <int T> static int LuaEmptyFunction(lua_State *L) {
      
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

    template <typename K> void LuaPushK(lua_State *L)
    {
      throw "Unknown type";
    }

    template <> void LuaPushK<int>(lua_State *L)
    {
      lua_pushinteger(L,1);
    }

    template <> void LuaPushK<float>(lua_State *L)
    {
      lua_pushnumber(L,4.0);

    }
    template <> void LuaPushK<double>(lua_State *L)
    {
      lua_pushnumber(L,4.0);

    }
    template <> void LuaPushK<bool>(lua_State *L)
    {
      lua_pushboolean(L,true);
    }

    template <> void LuaPushK<std::string>(lua_State *L)
    {
      lua_pushstring(L,"DEBUG VALUE");
    }


    template <int T,int N,typename K> static int LuaEmptyFunctionWithReturn(lua_State *L) {
      
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
      try {
	
	for ( int itr =0; itr <= N; itr++ )
	{
	  
	  LuaPushK<K>(L);
	  
	}
	
      }
      catch (std::string error)
      {
	lua_pushstring(L,error.c_str());
	lua_error(L);
      }
      return 0;  
      
      
    }

    static const luaL_reg lua_reg_sprite_DUMMY[] =
    {
      { "Load", LuaEmptyFunctionWithReturn< 1 , 1 , int > },
      { "Draw", LuaEmptyFunction<1> },
      { "Move", LuaEmptyFunction<3> },
      { "Size", LuaEmptyFunctionWithReturn< 0 , 2 , int>},
      { "SetPosition", LuaEmptyFunction<3> },
      { "GetPosition", LuaEmptyFunctionWithReturn<0 , 2 , float>},
      { NULL, NULL }
    };

    static const luaL_reg lua_reg_sound_DUMMY[] =
    {
      { "Load", LuaEmptyFunctionWithReturn<1,1,int>},
      { "Play", LuaEmptyFunction<1>},
      { NULL, NULL }
    };


    static const luaL_reg lua_reg_window_DUMMY[] =
    {
      { "Size", LuaEmptyFunctionWithReturn<0,2,int>},
      { "Resize", LuaEmptyFunctionWithReturn<0,1,bool>},
      { NULL, NULL }
    };

    static const luaL_reg lua_reg_text_DUMMY[] =
    {
      { "Create", LuaEmptyFunctionWithReturn<1,1,int>},
      { "Draw", LuaEmptyFunction<1>},
      { "Modify", LuaEmptyFunction<2>},
      { "Move",LuaEmptyFunction<3>},
      { "Size", LuaEmptyFunctionWithReturn<0,2,int>},  
      { "SetPosition", LuaEmptyFunction<3>},
      { "GetPosition", LuaEmptyFunctionWithReturn<0,2,float>},
      { NULL, NULL }
    };

  }

}
#endif
