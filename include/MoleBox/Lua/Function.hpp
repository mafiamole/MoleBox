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
#ifndef MB_LUA_FUNCTION_HPP
#define MB_LUA_FUNCTION_HPP
#include <string>
#include <map>
#include <lua.hpp>
#include <MoleBox/Lua/Export.hpp>
#include "Arguments/Argument.hpp"

namespace MB {

  namespace Lua {

    /**
     * @brief Provides an object interface to the stack style lua interface for calling lua functions.
     **/
    class MOLEBOX_LUA_API Function
  {
    lua_State *L;
    std::map<std::string, Argument*> args;
    bool ready;
    
    public:
    /**
      * @brief Default constructor
      *
      **/
    Function();

      /**
      * @brief Copy constructor.
      *
      * @param copyFrom Object to copy
      **/
    Function(const Function& copyFrom);
    /**
      * @brief Constructor that sets a number of arguments on creation
      *
      **/      
    Function(std::map<std::string,Argument*> args);
    

    
    /**
      * @brief Default descructor
      *
      **/
    virtual ~Function();      
    /**
      * @brief Used to begin the function call.
      *
      * @param L The lua state you wish to invoke the function from
      * @param name name of the function
      * @param pushargs If this is true. Init will iterate through all set arguments push them to the state L stack.
      * @return int Returns the lua error state value.
      **/
    void InitCall(lua_State* L, std::string name, bool pushargs = true);
    
    /**
      * @brief Pushed all args pushed into this objects args member
      *
      * @param L State to push the args on to.
      * @return void
      **/
    void PushArgs(lua_State* L);
    
    /**
      * @brief Pushes the argument referenced by a string onto the stack from the args member.
      *
      * @param L State to push args on to
      * @param argName argument reference name.
      * @return void
      **/
    void PushArg(lua_State* L, std::string name);
    
    
    /**
      * @brief Calls the lua function and returns the lua error value.
      *
      * @param returnValues The number of return values the lua function is expected to return. Defaults to 0.
      * @return int
      **/
    int FinishCall(int returnValues = 0);

    
    /**
      * @brief Adds an integer argument to the arg list
      *
      * @param arg Integer value.
      * @return void
      **/

    void AddArg(std::string ref, int arg);
    /**
      * @brief Adds a std::string argument to the arg list
      *
      * @param arg String value
      * @return void
      **/
    void AddArg(std::string ref, std::string arg);
    /**
      * @brief Adds a float argument to the arg list
      *
      * @param arg Float value.
      * @return void
      **/
    void AddArg(std::string ref, float arg);
    /**
      * @brief Adds a double argument to the arg list (information may be lost due to double -> float conversion I think)
      *
      * @param arg double value
      * @return void
      **/
    void AddArg(std::string ref, double arg);
    /**
      * @brief Adds a boolean argument to the arg list
      *
      * @param arg boolean value.
      * @return void
      **/
    void AddArg(std::string ref, bool arg);
    
    /**
     * @brief Adds a new argument object to the list of arguments
     *
     * @param ref Named reference
     * @param arg The argument object
     * @return void
     **/
    void AddArg(std::string ref, Argument* arg);
    
    
    Argument * GetArg(std::string ref);
    
    /**
     * @brief Changes the value of a integer argument too this function
     *
     * @param ref Named Reference of the argument to change.
     * @param arg Value to change the arg to
     * @return void
     **/
    void SetArg(std::string ref,int arg);

    /**
     * @brief Changes the value of a string argument too this function
     *
     * @param ref Named Reference of the argument to change.
     * @param arg Value to change the arg to
     * @return void
     **/
    void SetArg(std::string ref,std::string arg);
    
    /**
     * @brief Changes the value of a float argument too this function
     *
     * @param ref Named Reference of the argument to change.
     * @param arg Value to change the arg to
     * @return void
     **/
    void SetArg(std::string ref,float arg);
    
    /**
     * @brief Changes the value of a double argument too this function
     *
     * @param ref Named Reference of the argument to change.
     * @param arg Value to change the arg to
     * @return void
     **/
    void SetArg(std::string ref,double arg);
    
    /**
     * @brief Changes the value of a boolean argument too this function
     *
     * @param ref Named Reference of the argument to change.
     * @param arg Value to change the arg to
     * @return void
     **/
    void SetArg(std::string ref,bool arg);
    };

  }

}

#endif // MB_LUA_FUNCTION_HPP
