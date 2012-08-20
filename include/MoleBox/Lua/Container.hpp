#ifndef MB_LUASCRIPTCONTAINER
#define MB_LUASCRIPTCONTAINER

#include <fstream>
#include <SFML/System/Lock.hpp>

#include <MoleBox/Content/ContainerTemplate.hpp>
#include <MoleBox/Lua/Export.hpp>
#include <MoleBox/Lua/Script.hpp>

namespace MB {

  namespace Content {
    

    
    class MOLEBOX_LUA_API LuaScriptID : public ID
    {
    public:
      /**
       * @brief Constructor that sets the member type
       *
       * @param type string identifier Defaults to "luascript".
       **/
      LuaScriptID(std::string type = "luascript");
      /**
       * @brief default destructor
       *
       **/
      ~LuaScriptID();
      /**
       * @brief Obtain a list of lua scripts loaded
       *
       * @return MB:StrVector
       **/
      StrVector List();
      /**
       * @brief Checks to see if the lua script has the correct extension of .lua
       *
       * @param extension the extension in question.
       * @return bool
       **/
      bool CheckExtension(std::string extension);
      /**
       * @brief Load, but not return the lua script
       *
       * @param fileLocation Location of the script on the file system.
       * @return void
       **/
      void Load(std::string fileLocation);
    };   
    
    template<> class MOLEBOX_LUA_API Container<MB::Lua::Script *>
    {
      
      Container_Base<MB::Lua::Script *> base;
      LuaScriptID* id;
      
      public:
	
      Container()
      {
	id = new LuaScriptID();
      }
	
      ~Container()
      {
	std::map<std::string,MB::Lua::Script* >::iterator musicItr;
	for ( musicItr = base.contents.begin(); musicItr != base.contents.end(); musicItr++)
	{
	 MB::Lua::Script* file = (*musicItr).second;
	  delete file;
	}
	
	base.contents.clear();
      } 
	
      MB::Lua::Script * Load(std::string reference)
      {

	if ( this->base.contents.find(reference) == this->base.contents.end())
	{
	  
	  std::ifstream file(reference.c_str());

	  if ( file.good() )
	  {
	    file.close();
	    Lua::Script* script = new MB::Lua::Script();
	    
	  }
	  else
	  {
	    file.close();
	    throw Exception(COULD_NOT_LOAD,reference);
	  }
	  Lua::Script* script = new MB::Lua::Script();
	  if (!script->LoadFromFile(reference))
	    throw Exception(COULD_NOT_LOAD,reference);
	  
	  this->base.contents.insert(std::pair<std::string,MB::Lua::Script *>(reference,script));
	  
	}
	return this->base.contents[reference];
      }
      
      static Container<MB::Lua::Script *>& I()
      {
	static Container<MB::Lua::Script *> container;
	return container;	
      }
      
      StrVector List()
      {
	sf::Lock(this->base.mutex);
	return base.List();
      }
 
	      
      
      LuaScriptID* GetID()
      {
	return id;
      }
      
    }; 
  }
}
#endif