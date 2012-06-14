/*
    Copyright (c) 2012 Paul Brown mafiamole@gmail.com

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

#include "../GameComponent.h"
#include "../Game.h"
#include "content.h"
#include "luascript.h"
#ifdef LUA_EDITOR
  #include "luascripts.h"

#endif

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
namespace MB {

  void ActionsToLua(lua_State* L, MB::Actions* actions);
  
  
  
  class LuaComponent : public GameComponent
  {
  private:

    std::string 		scriptFile;
    LuaScript			script;
    std::map<int,sf::Sprite>	sprites;
    std::map<int,sf::Text>	text;
    std::map<int,sf::Sound>	sounds;
    int spriteKey;
    int soundKey;
    int textKey;
    std::vector<int>		spriteBatch;
    std::vector<int>		textBatch;
  protected:
    virtual void UpdateScriptPreCall(lua_State* L);
  public:
    LuaComponent(MB::Game* game, std::string file);
    
    int	AddSprite(std::string file);
    int	AddSounds(std::string file);
    
    void AddSpriteToDrawList(int ref);
    void AddTextToDrawList(int ref);
    
    int AddText(std::string value);
    
    const sf::Vector2u& GetWindowSize();
    
    sf::Sprite* GetSprite(int ref);
    sf::Sound*	GetSound(int ref);
    sf::Text* GetText(int ref);
    
    virtual void Update(sf::Time elapsed,Types::EventList* events,int argCount = 2);
    virtual void Draw();
    
    virtual ~LuaComponent();
  };
  
}


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

#endif // LUACOMPONENT_H
