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



MB::LuaComponent::LuaComponent(Game* game,std::string file) : GameComponent(game), script()
{
  MB_Lua::Sprites::Instance().SetWindow(game->Window());
  
  //this->LoadScript(file);
  int success;
  bool loadedScript = this->script.LoadFromFile(file);
  
  if (loadedScript) {
    this->scriptFile = file;
    this->script.RunFunction("init");
    
    }

}

void MB::LuaComponent::Update( EventList* events )
{
#ifdef LUA_EDITOR

  if ( LuaHelper::LuaScripts::Instance().NeedToUpdate(scriptFile) )
  {
    std::string newscript = LuaHelper::LuaScripts::Instance().GrabUpdate(this->scriptFile);
    
    this->script.LoadFromString(newscript);
    this->script.RunFunction("init");
    
  }
#endif
  lua_State* L = this->script.GetState();
  
  lua_getglobal(L,"update");

  ActionsToLua( L, this->game->GetActions() );
  
  int s = lua_pcall( L , 1, 0 ,0);
  
  this->script.HandleError(s);
  
  GameComponent::Update( events );

}

void MB::LuaComponent::Draw()
{
  
  this->script.RunFunction("draw");

  GameComponent::Draw();
}

MB::LuaComponent::~LuaComponent()
{

}
