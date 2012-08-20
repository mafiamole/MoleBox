#include <MoleBox/Lua/Helpers.hpp>

void MB::Lua::PushError(lua_State* L,std::string message)
{
  lua_pushstring( L, message.c_str() );
  lua_error( L );
}
