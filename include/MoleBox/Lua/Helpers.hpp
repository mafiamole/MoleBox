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


/*******************************************
 * 
 * These are auxillery functions to help
 * with interacting with Lua scripts.
 * 
 * 
 * 
 *******************************************/
#ifndef LUA_HELPERS_HPP
#define LUA_HELPERS_HPP
#include <MoleBox/Lua/Export.hpp>
#include <lua.hpp>
#include <string>
#include <iostream>
/**
 * @brief Used to fetch a reference from the Lua state registry of type T, which is given the label of identifier
 *
 * @param L The lua state.
 * @param identifier A string name given to the reference to the lua data. This reference needs to be unique within the scope of the state.
 * @return T*
 **/
namespace MB {
  
  namespace Lua {
    
    /**
     * @brief Obtains a pointer from a provided lua state's registry of a certain type
     *
     * @param L The lua state to obtain the pointer from.
     * @param identifier A character array identifier.
     * @return T*
     **/
    MOLEBOX_LUA_API template <class T> T* GetUserDataFromRegistry(lua_State* L,const char* identifier)
    {
      lua_pushstring(L,identifier);
      lua_gettable(L,LUA_REGISTRYINDEX);

      T* _this =(T*)lua_touserdata(L,-1); 
      return (T*)lua_topointer(L,-1);
    }
    
    /**
     * @brief Push a pointer to a Lua state registry
     *
     * @param L Lua state to push to
     * @param identifier Identifier of the object to pus
     * @param data The object pointer to push.
     * @return void
     **/
    MOLEBOX_LUA_API template <class T> void SetUserDataToRegistry(lua_State* L,const char* identifier,T* data)
    {
      
      std::cout << identifier << std::endl;
      lua_pushstring(L,identifier);
      lua_pushlightuserdata(L,(void*)data);
      lua_settable(L,LUA_REGISTRYINDEX);   
    }
    
    /**
     * @brief Push an error string to a lua state
     *
     * @param L Lua state to push to
     * @param message The error message to push.
     * @return void
     **/
    MOLEBOX_LUA_API void PushError(lua_State* L, std::string message);
  }
}

#endif