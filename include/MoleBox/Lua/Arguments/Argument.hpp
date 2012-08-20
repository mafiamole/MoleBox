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


#ifndef MB_LUA_ARGUMENTS_HPP
#define MB_LUA_ARGUMENTS_HPP

#include <MoleBox/Lua/Export.hpp>
#include <MoleBox/Lua/Push.hpp>

namespace MB {

  namespace Lua {

    /**
     * @brief This represents a value passed to a lua function.
     * @brief  In order for this to work correctly. The function needs to put at the top of the stack before hand.
     **/
    class MOLEBOX_LUA_API Argument
    {
    protected:
      void 		*data;
    
    public:
      /**
       * @brief Default destructor
       *
       **/
      Argument();
      /**
       * @brief Default destructor
       *
       **/
      virtual ~Argument();
      /**
       * @brief Sets the value
       *
       * @param value Value to set.
       * @return void
       **/
      virtual void 	Set(void *value);
      /**
       * @brief Push the value to a given lua state
       *
       * @param L Lua state to push the value to
       * @return void
       **/
      virtual void 	Push(lua_State* L);
    };

  }

}

#endif // MB_LUA_ARGUMENTS_HPP
