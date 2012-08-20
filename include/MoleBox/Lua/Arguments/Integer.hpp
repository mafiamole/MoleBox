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


#ifndef MB_LUA_INTEGER_HPP
#define MB_LUA_INTEGER_HPP
#include <MoleBox/Lua/Export.hpp>
#include <MoleBox/Lua/Arguments/Argument.hpp>
namespace MB {

  namespace Lua {

    /**
     * @brief An integer field to pass to a lua function.
     **/
    class MOLEBOX_LUA_API Integer : public MB::Lua::Argument
    {
    protected:
      int 	data;
    public:
      /**
       * @brief Initalise the integer field
       *
       * @param defaultVal A value to start off with.
       **/
      explicit 	Integer(int defaultVal);
      /**
       * @brief Default destructors.
       *
       **/
      virtual 	~Integer();
      /**
       * @brief Set a value.
       *
       * @param value Value to set.
       * @return void
       **/
      void 	Set(int value);
      /**
       * @brief ...
       *
       * @param value ...
       * @return void
       **/
      void	Push(lua_State* L);
      
    };

  }

}

#endif // MB_LUA_INTEGER_HPP
