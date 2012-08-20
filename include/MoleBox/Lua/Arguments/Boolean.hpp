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


#ifndef MB_LUA_BOOLEAN_H
#define MB_LUA_BOOLEAN_H

#include <MoleBox/Lua/Arguments/Argument.hpp>


namespace MB {

  namespace Lua {

    /**
     * @brief Represents a boolean value to be passed to a lua function.
     **/
    class Boolean : public MB::Lua::Argument
    {
    protected:
      bool 	data;
    public:
      /**
       * @brief Defines a boolean value :D
       *
       * @param defaultVal An inital value to start with
       **/
      explicit 	Boolean(bool defaultVal);
      /**
       * @brief default destructor
       *
       **/
      virtual 	~Boolean();	
      /**
       * @brief Set this boolean value
       *
       * @param value value to set
       * @return void
       **/
      void 	Set(bool value);
      /**
       * @brief Push the boolean value to the lua state.
       *
       * @param L The lua state to push to.
       * @return void
       **/
      void 	Push(lua_State* L);

    };

  }

}

#endif // MB_LUA_BOOLEAN_H
