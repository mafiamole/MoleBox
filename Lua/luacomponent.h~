/*
    Copyright (c) 2012 Paul Brown <email>

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/


#ifndef LUACOMPONENT_H
#define LUACOMPONENT_H

extern "C" {
  #include "lua.hpp"
  #include "lualib.h"
  #include "lauxlib.h"
}

#include "../sfmlgamecomponent.h"
#include "../sfmlgame.h"
#include "luaScriptHelper.h"
#include <map>
/**
 * Aimed to provide functionality to scripts.
 * Since the LUA C API requires c++ functions to be static to be callable in Lua code,
 * This class is mostly contains static methods and members.
 */
/**
 * 
 * These static const luaL_reg essentally define the frameworks component API for Lua
 * 
 */
static const luaL_reg sprite[] =
{
  { "Load", LuaSFML::Sprites::Load},
  { "Draw", LuaSFML::Sprites::Draw},
  { NULL, NULL }
};

static const luaL_Reg sound[] =
{
  { "Load", LuaSFML::Sounds::Load},
  { "Play", LuaSFML::Sounds::Play},
  
  { NULL, NULL }
};

class LuaComponent : public SFMLGameComponent
{
private:
 lua_State *L;
  std::string scriptFile;
  bool LoadScript(std::string file);
  static LuaComponent* CurrentWorkingInstance; // lazy
public:
  LuaComponent(SFMLGame* game, std::string file);
  static void SetInstance(LuaComponent* differentInstance);
  static LuaComponent* GetInstance();
  static int LoadTexture(lua_State *L);
  lua_CFunction Test(lua_State *L);
  void HandelError(lua_State* L, int status);
  virtual void Update(EventList* events);
  virtual void Draw();
  virtual ~LuaComponent();
  
};

#endif // LUACOMPONENT_H
