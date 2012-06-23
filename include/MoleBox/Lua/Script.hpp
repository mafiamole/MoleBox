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


#ifndef LUASCRIPT_H
#define LUASCRIPT_H

#include <MoleBox/Lua/Scripts.hpp>
#include <lua.hpp>
#include <sstream>
#include <map>

namespace MB {
  
  namespace Lua {
  
    typedef std::map< std::string, const luaL_reg * > LuaRegisterMap;

    class LuaScript
    {
    private:
      lua_State *L;
      bool debug;
      LuaRegisterMap FuncsToReg;
    public:
	LuaScript(bool debug = false);
	bool LoadFromFile(std::string file);
	bool LoadFromString(std::string contents, std::string remarks = "");
	bool HandleError(int State);

	void AddLibrary(std::string name,const luaL_reg * stuff);
	bool RunScript();
	bool RunFunction(std::string name);
	bool LookForFunction( std::string name );
	std::string ErrorTypeName(int state);
	lua_State* GetState();
	virtual ~LuaScript();

    };

  }

}

#endif // LUASCRIPT_H