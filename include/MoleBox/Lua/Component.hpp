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

#include <MoleBox/GameComponent.hpp>
#include <MoleBox/Game.hpp>
#include <MoleBox/Content/Content.hpp>
#include <MoleBox/Lua/Script.hpp>

#ifdef LUA_EDITOR
#include <MoleBox/Lua/Scripts.hpp>
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
  
  namespace Lua {
    
    void ActionsToLua(lua_State* L, MB::Actions* actions);
    
    class LuaComponent : public GameComponent
    {
    protected:

      std::string 		scriptFile;
      LuaScript *		script;
      std::map<int,sf::Sprite>	sprites;
      std::map<int,sf::Text>	text;
      std::map<int,sf::Sound>	sounds;
      int spriteKey;
      int soundKey;
      int textKey;
      std::vector<int>		spriteBatch;
      std::vector<int>		textBatch;
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
}


#endif // LUACOMPONENT_H
