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


#ifndef LUA_CONTENT_H
#define LUA_CONTENT_H

#include "LuaScriptHelper.h"

namespace MB_Lua {

class Sounds {
  
  public:
    static Sounds& 			Instance			(); 
    static int 				Load				( lua_State *L );
    static int 				Play				( lua_State *L );
    static int 				PauseUnPause			( lua_State *L );
    static int 				Stop				( lua_State* L );

  };
  
class Sprites {
public:
    static int 				Load				( lua_State *L );
    static int 				Draw				( lua_State *L );
    static int				Move				( lua_State *L );
    static int				SetPosition			( lua_State *L );
    static int				GetPosition			( lua_State *L );
  };
   


class Text {
public:
    static int 				Create				( lua_State *L );
    static int 				Draw				( lua_State *L );
    static int 				Modify				( lua_State *L );
    static int				Move				( lua_State *L );
    static int				SetPosition			( lua_State *L );
    static int				GetPosition			( lua_State *L );
  };
   
}
#endif // CONTENT_H
