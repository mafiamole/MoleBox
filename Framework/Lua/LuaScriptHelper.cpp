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

#include "LuaScriptHelper.h"
// extracts a table into a std::map with provided types
/**
 * LuaHelper namespace
 * 
 */


bool LuaHelper::TypeCheck(lua_State *L,int index,int type) {

  return (bool)(lua_type(L,index) == type);
  
}


void LuaHelper::HandelError(lua_State *L,int status) {
  
  if ( status != 0 ) {
    
    std::cerr << "Script error: " << lua_tostring(L, -1) << std::endl;

    lua_pop(L, 1); // remove error message
    
  }
  
}

void LuaHelper::PushError(lua_State* L, std::string errorString)
{
  lua_pushstring(L,errorString.c_str());
  
  lua_error(L);  
}
/**
 * Return type templates
 * 
 */
template<class T> T LuaHelper::LuaReturnType(lua_State* L, int index)
{

  throw std::string("Feature not supported.");

}

template <> std::string LuaHelper::LuaReturnType< std::string >(lua_State* L, int index)
{

  std::string outputString;
  
  outputString = lua_tostring(L,index);
  
  return outputString;

}

template <> bool LuaHelper::LuaReturnType< bool >(lua_State* L, int index)
{
  return lua_toboolean(L, index);
}


template <> double LuaHelper::LuaReturnType< double >(lua_State* L, int index)
{
  return lua_tonumber(L,index);
}

template <> int LuaHelper::LuaReturnType< int >(lua_State* L, int index)
{
  return lua_tointeger(L,index);
}
