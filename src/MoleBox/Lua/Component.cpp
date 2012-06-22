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

#include <MoleBox/Lua/Component.hpp>
#include <MoleBox/Content/Content.hpp>
#include <MoleBox/Lua/ScriptHelper.hpp>
#include <MoleBox/Lua/ComponentFunctions.hpp>
#include <MoleBox/Actions.hpp>

using namespace MB;

void Lua::ActionsToLua(lua_State* L,MB::Actions* actions)
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


Lua::LuaComponent::LuaComponent(Game* game,std::string file) : GameComponent(game), script() , soundKey(0), spriteKey(0), textKey(0), scriptFile(file),text(),textBatch()
{
  
  //this->LoadScript(file);
  int success;
  this->script = Content::Load<LuaScript*>(file);
  this->script->AddLibrary("Window",sfml_lua_window);
  this->script->AddLibrary("Sprite",sfml_lua_sprite);
  this->script->AddLibrary("Text",sfml_lua_text);
  this->script->AddLibrary("Sound",sfml_lua_sound);
  
  bool loadedScript = this->script->LoadFromFile(file);

  
  if (loadedScript) {
    
    lua_State* L = this->script->GetState();
    
    lua_pushstring(L,"MB_GAME_COMPONENT");
    lua_pushlightuserdata(L,(void*)this);
    lua_settable(L,LUA_REGISTRYINDEX);    
    
    bool runscript = this->script->RunScript();
    bool runinit = this->script->RunFunction("init");

    }

  else {
   
    throw "Script was unable to be loaded.";
    
  }


}


void Lua::LuaComponent::UpdateScriptPreCall(lua_State* L)
{

}



void Lua::LuaComponent::Update( sf::Time elapsed, MB::Types::EventList* events,int argCount )
{
#ifdef LUA_EDITOR

  if ( Lua::LuaScripts::Instance().NeedToUpdate(scriptFile) )
  {
    std::string newscript = Lua::LuaScripts::Instance().GrabUpdate(this->scriptFile);
    
    this->script->LoadFromString(newscript);
    lua_State* L = this->script->GetState();
    lua_pushstring(L,"MB_GAME_COMPONENT");
    lua_pushlightuserdata(L,(void*)this);
    lua_settable(L,LUA_REGISTRYINDEX);  
    this->script->RunScript();
    this->script->RunFunction("init");
    
  }
#endif
  lua_State* L = this->script->GetState();
  
  lua_getglobal(L,"update");
  
  Lua::ActionsToLua( L, this->game->GetActions() );

  lua_pushnumber(L, (int)elapsed.asMilliseconds() );
  
  this->UpdateScriptPreCall(L); // convenient virtual method.
  
  int s = lua_pcall( L , argCount, 0 ,0);
  
  this->script->HandleError(s);
  
  GameComponent::Update( elapsed, events );

}

int Lua::LuaComponent::AddSounds(std::string file)
{
  int key = this->soundKey;  
  this->sounds.insert(std::pair <int,sf::Sound>(key, sf::Sound( Content::Load< sf::SoundBuffer >(file)) ) );
  this->soundKey++;
  return key;
}


sf::Sound* Lua::LuaComponent::GetSound(int ref)
{
  if ( this->sounds.find(ref) != this->sounds.end() )
  {
    return &this->sounds[ref];
  }
  else
  {
    throw "Unable to find sound";
  }
}


int Lua::LuaComponent::AddSprite(std::string file)
{
  
  int key = this->spriteKey;
  this->sprites.insert( std::pair <int,sf::Sprite>( key, sf::Sprite( Content::Load< sf::Texture > (file) ) ) );
  this->spriteKey++;
  return key;
}

void Lua::LuaComponent::AddSpriteToDrawList(int ref)
{
  this->spriteBatch.push_back(ref);
}

sf::Sprite* Lua::LuaComponent::GetSprite(int ref)
{
  if ( this->sprites.find(ref) != this->sprites.end() )
  {
    return &this->sprites[ref];
  }
  else
  {
    throw "Unable to find sprite";
  }
}

int Lua::LuaComponent::AddText(std::string value)
{
  int key = this->textKey;
  this->text.insert( std::pair <int,sf::Text>( key,sf::Text(sf::String(value)) )  );
  this->textKey++;
  return key;
}

void Lua::LuaComponent::AddTextToDrawList(int ref)
{
  if ( this->text.find(ref) != this->text.end() ) {
    this->textBatch.push_back(ref);
  }
  else
  {
    throw "Unable to find text.";
  }
}



sf::Text* Lua::LuaComponent::GetText(int ref)
{
  if ( this->text.find(ref) != this->text.end() )
  {
    return &this->text[ref];
  }
  else
  {
    throw "Unable to find text";
  }  
}



void Lua::LuaComponent::Draw()
{
  
  bool success = this->script->RunFunction("draw");

  if ( success ) {

  std::vector<int>::iterator spriteItr;
  
  for (spriteItr = this->spriteBatch.begin(); spriteItr != this->spriteBatch.end(); spriteItr++)
  {
    if (this->sprites.find((*spriteItr)) != this->sprites.end())
    {
      this->game->Window()->draw (this->sprites[(*spriteItr)]);
    }
  }
  spriteBatch.clear();
   
  std::vector<int>::iterator textItr;
 
  for (textItr = this->textBatch.begin(); textItr != this->textBatch.end(); textItr++)
  {
    int key = (*textItr);
    if (this->text.find(key) != this->text.end())
    {
      
      this->game->Window()->draw (this->text[key]);
    }
  }
  textBatch.clear();  
  
  }
  else
  {
    std::cout << "Was unable to run draw function in script:" << this->scriptFile  << std::endl;
  }
  GameComponent::Draw();
}

const sf::Vector2u& Lua::LuaComponent::GetWindowSize()
{
  return this->game->Window()->getSize();
}


Lua::LuaComponent::~LuaComponent()
{

  
}
