#include <MoleBox/Lua/Script.hpp>
#include <MoleBox/Patterns.hpp>
  
namespace MB
{
	namespace Lua
	{

		Script::Script( bool debug) : debug(false)
		{
		  mutex = new sf::Mutex();
		}

		Script::Script(std::map< std::string, Function* > functions, bool debug) : debug(false)
		{
		  this->luaFuncs = functions;
			mutex = new sf::Mutex();
		}

		// Script::Script(const Script& copyFrom) : mutex()
		// {
		//   this->debug 		= 	copyFrom.debug;
		//   this->scriptFile 	=	copyFrom.scriptFile;
		// 
		//   std::map <std::string,Function *>::iterator itr;
		//   
		//   this->mutex = new sf::Mutex;
		// 
		// }

		Script::~Script()
		{
		  lua_close(L);
		}

		std::map <std::string,Function *> Script::CloneFunctions()
		{
		  sf::Lock(*mutex);
		   std::map <std::string,Function *> newFunList;
		   std::map <std::string,Function *>::iterator itr;
   
		   for ( itr = this->luaFuncs.begin(); itr != this->luaFuncs.end(); itr++)
		   {
				Function* tempFuncPtr = (*itr).second;
			Function tempFunc = *tempFuncPtr;
			std::string name =  (*itr).first;
			 //std::pair<std::string,Function*> pair( std::string, new Function( tempFunc )  );
			this->luaFuncs.insert( std::pair<std::string,Function*>( name, new Function(tempFunc)) );
		   }
   
		   return newFunList;
		}

		void Script::AddFunction(std::string name)
		{
		  this->luaFuncs.insert( std::pair<std::string,Function*>(name, new Function()) );
		}

		void Script::AddFunction(std::string name,std::map<std::string,Argument*> args)
		{
		  this->luaFuncs.insert( std::pair<std::string,Function*>(name, new Function(args)) ); 
		}


		Function* Script::GetFunc(std::string name)
		{
		  if ( this->luaFuncs.find(name) != this->luaFuncs.end() )
		  {
			return this->luaFuncs[name];
		  }
		  return 0;
		}
		int Script::FuncCall(std::string name, int returnc)
		{
		  Function* func = this->GetFunc(name);
		  func->InitCall(this->L,name,true);
		  return func->FinishCall(returnc);
  
		}

		void Script::UpdateFromString(std::string contents)
		{
		  sf::Lock lock(*mutex);
		  this->updateInfo.update = true;
  
		  this->updateInfo.body = contents;
		}

		bool Script::HandleError(int State)
		{
		  lua_gettop(L);

		  if ( State == LUA_ERRRUN || State == LUA_ERRMEM || State == LUA_ERRERR )
		  {
			std::stringstream error;
			error << "Script ERROR:" <<  this->ErrorTypeName(State) <<  " error (";
			error << State;
			error << ") Message: ";
			error << lua_tostring(L, -1);
    
			lua_pop(L, 1);
  
			if (this->debug)
			{
      
			  throw error.str();
			}
			else
			{
			  std::cerr << error.str() << std::endl;
			}
    
			return false;
		  }
		  else {
			return true;
		  }
  
		}

		std::string Script::ErrorTypeName(int state)
		{
		  switch(state)
		  {
			case 0:
			  return "Not an error";
			  break;
			case LUA_YIELD:
			  return "YIELD";
			  break;
			case LUA_ERRRUN:
			  return "Runtime";
			break;
			case LUA_ERRSYNTAX:
			  return "Syntax";
			  break;
			case LUA_ERRMEM:
			  return "Memory allocation";
			  break;
			case LUA_ERRERR:
			  return "Running error handler";
			  break;
		  }
		  return "";
		}

		void Script::RegisterLibrary(std::string name,const luaL_Reg* stuff)
		{
			sf::Lock lock(*mutex);
		  std::cout << "Adding reg to temp list" << std::endl;
  
		  this->FuncsToReg.insert ( std::pair<std::string,const luaL_Reg*>(name,stuff) );
  
		}

		lua_State* Script::GetState()
		{
			sf::Lock lock(*mutex);
		  return L;
		}

		bool Script::LoadFromFile(std::string file)
		{
  
		  sf::Lock lock(*mutex);
		  int success;
  
		  this->L = luaL_newstate();
  
		  luaL_openlibs(this->L);

		  LuaRegisterMap::iterator regItr;
  
		  for (regItr = this->FuncsToReg.begin(); regItr != this->FuncsToReg.end(); regItr++)
		  {
   
			const luaL_reg* reg =  (*regItr).second;
			std::cout << "Adding function reg" << std::endl;
			luaL_register( L , (*regItr).first.c_str() , reg);
    
		  }
		  
		  success = luaL_loadfile(this->L,file.c_str());
  
		  return this->HandleError( success );   
		}

		bool Script::LoadFromString(std::string contents)
		{
		  sf::Lock lock(*mutex);
		  int success;

		  L = luaL_newstate();
  
		  luaL_openlibs(L);
  
		  LuaRegisterMap::iterator regItr;
  
		  for (regItr = this->FuncsToReg.begin(); regItr != this->FuncsToReg.end(); regItr++)
		  {
   
			const luaL_reg* reg =  (*regItr).second;
			luaL_register( L , (*regItr).first.c_str() , reg);
    
		  }

		  success = luaL_loadstring(L,contents.c_str());

  
		  return this->HandleError( success ); 
		}
	}
}