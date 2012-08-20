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


#include <MoleBox/Lua/Arguments/ActionsArg.hpp>

ActionsArg::ActionsArg(std::map< std::string, MB::Actions::Action* > list)
{

}

ActionsArg::~ActionsArg()
{

}

void ActionsArg::Set(std::map< std::string, MB::Actions::Action* > list)
{
  this->data = list;
}

void ActionsArg::Push(lua_State* L)
{
  lua_newtable(L);
  
  std::map< std::string, MB::Actions::Action* > actionList = this->data;
  std::map< std::string, MB::Actions::Action* >::iterator actionItr;
  
  for (actionItr = actionList.begin(); actionItr != actionList.end(); actionItr++) {
    lua_newtable	( L );
    lua_pushboolean	( L, (*actionItr).second->IsActive() );
    lua_setfield	( L, -2, "IsActive" );
    lua_pushboolean	( L, (*actionItr).second->HasChanged() );
    lua_setfield	( L, -2, "HasChanged" );
    lua_setfield	( L, -2, (*actionItr).first.c_str() );
  }
  
}
