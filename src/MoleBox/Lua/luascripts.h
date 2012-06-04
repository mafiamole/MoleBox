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


#ifndef LUASCRIPTS_H
#define LUASCRIPTS_H

#ifdef LUA_EDITOR

extern "C" {
  #include "lua.hpp"
  #include "lualib.h"
  #include "lauxlib.h"
}

#include <string>
#include <map>
#include <vector>
#include <SFML/System.hpp>

namespace LuaHelper {  
    struct ScriptContainer {
      bool needsUpdating;
      std::string scriptBody;
    };
    class LuaScripts
    {
    private:
      std::map		<std::string,ScriptContainer> scripts;
      LuaScripts();
      ~LuaScripts();
      sf::Mutex updateMutex;
    public:
      static LuaScripts& 	Instance	();
      std::string		GrabUpdate	( std::string file );
      std::string 		GrabScript	( std::string file );
      std::vector<std::string> 	ScriptList	();
      void			UpdateScript	( std::string file, std::string contents );
      bool			NeedToUpdate	(std::string file);
      int			LoadFromFile    (lua_State*L, std::string file);

    };
    
  }
  #endif

#endif // LUASCRIPTS_H
