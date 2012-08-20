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


#ifndef STRING_HPP
#define STRING_HPP
#include <MoleBox/Lua/Export.hpp>
#include <MoleBox/Lua/Arguments/Argument.hpp>
namespace MB {

  namespace Lua {
    
    /**
     * @brief Represents a string value to be passed to a lua function
     **/
    class MOLEBOX_LUA_API String : public Argument
    {
    protected:
      std::string 	data;
    public:
      /**
       * @brief Sets an inital value to the data field
       *
       * @param defaultVal Value to set the data field
       **/
      explicit		String(std::string defaultVal);
      /**
       * @brief Default destructor
       *
       **/
      virtual 		~String();
      /**
       * @brief Sets the value to the data field
       *
       * @param value The value to set the data field to.
       * @return void
       **/
      void		 Set(std::string value);
      /**
       * @brief Pushes the current value of the data field to a given lua state.
       *
       * @param L The lua state to push the value to.
       * @return void
       **/
      void 		Push(lua_State* L);
    };
    
  }
  
}
#endif // STRING_HPP
