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



#include <MoleBox/Lua/Scripts.hpp>

#ifdef LUA_EDITOR
#include <fstream>
#include <streambuf>

#include <iostream>
#include <algorithm>
using namespace MB;
  Lua::LuaScripts::LuaScripts() : scripts() {}
  
  Lua::LuaScripts::~LuaScripts() {}
  
  Lua::LuaScripts& Lua::LuaScripts::Instance() 
  {
    static LuaScripts instance;
    
    return instance;
  }
  
  int Lua::LuaScripts::LoadFromFile(lua_State* L, std::string file)
  {
    std::ifstream t(file.c_str());
    std::string scriptbody(	(std::istreambuf_iterator<char>(t)),
				std::istreambuf_iterator<char>());
    
    std::pair<std::string,ScriptContainer> pair;
    
    pair.first = file;
    pair.second.needsUpdating = false;
    pair.second.scriptBody = scriptbody;
    this->scripts.insert(pair);
    
    return luaL_loadstring(L,scriptbody.c_str());
  }

  
  std::string Lua::LuaScripts::GrabScript(std::string file)
  {
    sf::Lock lock(updateMutex);
    if ( this->scripts.find( file ) != this->scripts.end() )
    {
      return this->scripts[file].scriptBody;
    }
    else
    {
      return std::string("print(\"String\")");
    }
  }
  
  std::string Lua::LuaScripts::GrabUpdate(std::string file)
  {
    sf::Lock lock(updateMutex);
    if ( this->scripts.find( file ) != this->scripts.end() )
    {
      this->scripts[file].needsUpdating = false;
      return this->scripts[file].scriptBody;
    }
    else
    {
      return std::string("print(\"String\")");
    }
  }

  
  std::vector<std::string> Lua::LuaScripts::ScriptList()
  {
    std::vector < std::string > scriptList;
    std::map < std::string, ScriptContainer >::iterator scriptItr;
    
    for ( scriptItr = this->scripts.begin();
	  scriptItr != this->scripts.end();
	  scriptItr++ )
    {
      scriptList.push_back( (*scriptItr).first );
    }
    return scriptList;
  }
  
  void Lua::LuaScripts::UpdateScript ( std::string file,std::string contents )
  {

    sf::Lock lock(updateMutex);
    
    if (this->scripts.find(file) != this->scripts.end())
    {
      this->scripts[file].scriptBody = contents;
      this->scripts[file].needsUpdating = true;
    }
    else
    {
      std::cerr << "Unable to find script" << std::endl;
    }

  }
  
  bool Lua::LuaScripts::NeedToUpdate( std::string file )
  {

    sf::Lock lock(updateMutex);
    
    if (this->scripts.find(file) != this->scripts.end())
    {
      return this->scripts[file].needsUpdating;
      }
    else {
      return false;

    }

      return false;
  }
  

#endif