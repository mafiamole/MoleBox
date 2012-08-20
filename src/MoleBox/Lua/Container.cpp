#include <MoleBox/Lua/Container.hpp>
#include <MoleBox/Content/Content.hpp>
namespace MB
{
	namespace Content
	{
		/**
		 * 
		 * 	Lua ID's
		 * 
		 * 
		 * 
		 */
		LuaScriptID::LuaScriptID(std::string type) : ID(type)
		{
  
		}

		LuaScriptID::~LuaScriptID()
		{
  
		}

		MB::StrVector LuaScriptID::List()
		{
		  return MB::Content::List<MB::Lua::Script*>();
		}

		bool LuaScriptID::CheckExtension(std::string ext)
		{
		  return ext == "lua";
		}

		void LuaScriptID::Load(std::string fileLocation)
		{
		  MB::Content::Load<MB::Lua::Script *>(fileLocation);
		}
	}
}