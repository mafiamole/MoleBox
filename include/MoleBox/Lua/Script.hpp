#ifndef LUA_SCRIPT_HPP
#define LUA_SCRIPT_HPP

#include <MoleBox/Lua/Export.hpp>
#include <string>
#include <sstream>
#include <list>
#include <lua.hpp>

extern "C"
{
  #include "lauxlib.h"
  #include <SFML/System/Mutex.hpp>
}

#include <MoleBox/Lua/Push.hpp>
#include <MoleBox/Lua/Function.hpp>


namespace MB {

  namespace Lua {
    
    typedef MOLEBOX_LUA_API std::map< std::string, const luaL_reg * > LuaRegisterMap;
    
    struct MOLEBOX_LUA_API UpdateScript {
      bool update;
      std::string body;
    };
    
    class MOLEBOX_LUA_API Script
    {
      
    protected:
      lua_State 			*L;
      std::string 			scriptFile;
      bool 				debug;
      LuaRegisterMap 			FuncsToReg;
      
      std::map <std::string,Function *> luaFuncs;
      /**
       * @brief Used to handle the error. When Script.debug is true, it throws a std::string. Otherwise it outputs to standard error
       *
       * @param State This is the lua state value returned by a lua call.
       * @return bool
       **/
      bool 				HandleError(int State);
      
      /**
       * @brief Internal method for obtaining a human readable error name to the error type returned by a lua call function.
       *
       * @param state his is the lua state value returned by a lua call.
       * @return std::string
       **/
      std::string 			ErrorTypeName(int state);
      
      sf::Mutex* mutex;
      
      UpdateScript updateInfo;
      
      
      
    public:
      /**
       * @brief Initialise a script just passing if debug mode should be enabled.
       *
       * @param debug ... Defaults to false.
       **/
					Script(bool debug = false);
      /**
	* @brief Initalise by passing a set of functions to call.
	*
	* @param functions A list of functions that the script is expected to contain.
	* @param debug if the script should use 'debug' features only Defaults to false.
	**/
					Script(std::map <std::string,Function *> functions, bool debug = false);
       
      /**
       * @brief default destructor
       *
       **/
      ~Script();
      
      /**
       * @brief Obtain a clone of functions
       *
       * @return std::map< std::string, MB::Lua::Function*, std::less< std::string >, std::allocator< std::pair< const std::string, MB::Lua::Function* > > >
       **/
      std::map <std::string,Function *> CloneFunctions();
      
      /**
       * @brief Loads and initalises the state from a file.
       * @warning Will override the current state
       * 
       * @param file File to load the script from
       * @return bool
       **/
      bool 				LoadFromFile(std::string file);
      
      /**
       * @brief Initalise a state from a string
       * @warning Will override the current state
       * 
       * @param contents Script body.
       * @return bool
       **/
      bool 				LoadFromString(std::string contents);

      /**
       * @brief Reinitalises a state from a string
       * @warning Will override the current state
       * 
       * @param contents Script body.
       * @return void
       **/
      void 				UpdateFromString(std::string contents);
      
      /**
       * @brief Add a name of a function that should exist in the script
       *
       * @param name name of the function
       * @return void
       **/
      void				AddFunction(std::string name);
      
      /**
       * @brief Add a name of a function that should exist in the script.
       *
       * @param name Name of the function.
       * @param args The arguments the function should accept
       * @return void
       **/
      void 				AddFunction(std::string name,std::map<std::string,Argument*> args);
      
      /**
       * @brief Obtains a pointer to a function object
       *
       * @param name Name of the function
       * @return MB::Lua::Function*
       **/
      Function* 			GetFunc(std::string name);
      
      /**
       * @brief Call a lua function of a given name, followed by the expect number of return values.
       *
       * @param name Name of the function
       * @param returnc Number of return values Defaults to 0.
       * @return int
       **/
      int 				FuncCall(std::string name, int returnc = 0);
      
      /**
       * @brief Register an array of c functions as a 'library' in lua.
       *
       * @param name Name of the users 'library'
       * @param functionArray A luaL_reg array.
       * @return void
       **/
      void 				RegisterLibrary(std::string name, const luaL_reg* functionArray);
      
      
      /**
       * @brief Returns a pointer to the internally used state.
       *
       * @return lua_State*
       **/
      lua_State* 			GetState();
      
      
      /**
       * @brief "Clones the script object"
       *
       * @return MB::Lua::Script*
       **/
      Script* 				Clone();
      
    };
    
  }

}

#endif //LUA_SCRIPT_HPP