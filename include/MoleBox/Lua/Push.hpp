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


#ifndef MB_LUA_PUSH_H
#define MB_LUA_PUSH_H

#include <lua.hpp>
#include <string>
#include <iostream>
#include <map>
#include <MoleBox/Lua/Export.hpp>

namespace MB {

  namespace Lua {
    
    /**
     * @brief Push a item of a provided type
     *
     * @param L Lua state to push to
     * @param value Value to push
     * @throw std::string Always throws this error if no type specialisation for the type provided exists.
     * @return void
     **/
    template<typename T> MOLEBOX_LUA_API void Push(lua_State* L,T value)
	{
		throw "type not supporteded";
	}
    
    /**
     * @brief Push an integer to a provided lua state.
     *
     * @param L Lua state to push
     * @param value Integer value to push
     * @return void
     **/
     template<> MOLEBOX_LUA_API void Push<int>(lua_State* L,int value);

    /**
     * @brief Push a float value to a lua state
     *
     * @param L Lua state to push
     * @param value float value to push.
     * @return void
     **/
    template<> MOLEBOX_LUA_API void Push<float>(lua_State* L,float value);
    
    /**
     * @brief Push a double precision floating point value to a lua state.
     *
     * @param L State to push to
     * @param value Value to push
     * @return void
     **/
    template<> MOLEBOX_LUA_API void Push<double>(lua_State* L,double value);
    
    /**
     * @brief Push a std::string to a lua state
     *
     * @param L Lua state to push to
     * @param value String value to push
     * @return void
     **/
    template<> MOLEBOX_LUA_API void Push<std::string>(lua_State* L,std::string value);
    
  }

}

#endif // MB_LUA_PUSH_H
