/*
    Copyright (c) 2012 Paul Brown mafiamole@gmail.com

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

#include "Component.h"
#include "../Content.h"
#include "LuaScriptHelper.h"

void MB::ActionsToLua(lua_State* L,MB::Actions* actions)
{
  lua_newtable(L);
  
  std::map< std::string, Action* > actionList = actions->GetList();
  std::map< std::string, Action* >::iterator actionItr;
  
  for (actionItr = actionList.begin(); actionItr != actionList.end(); actionItr++) {
    lua_newtable	( L );
    lua_pushboolean	( L, (*actionItr).second->IsActive() );
    lua_setfield	( L, -2, "IsActive" );
    lua_pushboolean	( L, (*actionItr).second->HasChanged() );
    lua_setfield	( L, -2, "HasChanged" );
    lua_setfield	( L, -2, (*actionItr).first.c_str() );
  }
  
}



MB::LuaComponent::LuaComponent(Game* game,std::string file) : GameComponent(game)
{
  MB_Lua::Sprites::Instance().SetWindow(game->Window());
  this->LoadScript(file);
  
  scriptFile = file;

}

bool MB::LuaComponent::LoadScript(std::string file)
{
  int success;
  
  L = lua_open();

  luaL_openlibs(this->L);
  
  luaL_register(L,"Sprites",sprite);
  
  luaL_register(L,"Sounds",sound);
  
  success = luaL_loadfile(this->L,file.c_str());
  
  this->HandelError(this->L,success);
  
  success = lua_pcall(this->L,0,0,0); //execute script so we can grab functions;
  
  this->HandelError(this->L,success);
  
  std::map< int, std::string > textures;

  lua_getglobal(this->L,"init");
  
  if (!lua_isfunction(L,-1))
  {
    std::cout << "Init is not a function!" << std::endl;
  }
  success = lua_pcall(this->L,0,0,0);
  
  this->HandelError(this->L,success);
 
}

void MB::LuaComponent::HandelError(lua_State* L, int status)
{
  if ( status!=0 ) {
    
    std::cerr << "Script error: " << lua_tostring(L, -1) << std::endl;
    
    lua_pop(L, 1); // remove error message
    
  }
  
}


lua_CFunction MB::LuaComponent::Test(lua_State* L)
{
  
return 0;

}



void MB::LuaComponent::Update(EventList* events)
{
  
  lua_getglobal(this->L,"update");
  /*
  lua_newtable(L);
  EventList::iterator eventItr;
  for (eventItr = events->begin();eventItr != events->end();eventItr++)
  {
    sf::Event ev = (*eventItr).second;
    lua_pushinteger(L,(*eventItr).first); // key
    lua_pushstring(L,"blarg"); // value
    lua_settable(L,-3);    
  }
*/
  ActionsToLua(L,this->game->GetActions());
  int s = lua_pcall(this->L,1,0,0);
  HandelError(L,s);
  
  
  
  GameComponent::Update(events);

}

void MB::LuaComponent::Draw()
{
  
  lua_getglobal(this->L,"draw");
  
  int s = lua_pcall(this->L,0,1,0);
  
  std::map<int,std::string> spriteList;
  
  HandelError(L,s);

  GameComponent::Draw();
}

MB::LuaComponent::~LuaComponent()
{
  lua_close(L);
}


