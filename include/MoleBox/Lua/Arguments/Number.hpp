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


#ifndef NUMBER_HPP_HPP
#define NUMBER_HPP_HPP

#include <MoleBox/Lua/Export.hpp>
#include <MoleBox/Lua/Arguments/Argument.hpp>

namespace MB
{
  namespace Lua
  {
    /**
     * @brief A Floating point value to pass to a lua function
     **/
    class MOLEBOX_LUA_API Number : public MB::Lua::Argument
    {
    protected:
      float 	data;
    public:
      /**
       * @brief Destructor that requires an inital value for the data field
       *
       * @param defaultVal The value to set the data field.
       **/
      explicit 	Number(float defaultVal);
      /**
       * @brief Default destructor
       *
       * @return void
       **/
      virtual 	~Number();
      /**
	* @brief Change the value of the data field
	*
	* @param value value to change the data field to
	* @return void
	**/
      void  	Set(float value);
      /**
       * @brief Push the value of the data field to a given lua state.
       *
       * @param L Lua state to push the data field to.
       * @return void
       **/
      void  	Push(lua_State* L);

    };
  }
}

#endif // NUMBER_HPP_HPP
