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
#include "../Content/Content.h"
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


MB::LuaComponent::LuaComponent(Game* game,std::string file) : GameComponent(game), script() , soundKey(0), spriteKey(0), textKey(0), scriptFile(file),text(),textBatch()
{
  
  //this->LoadScript(file);
  int success;

  bool loadedScript = this->script.LoadFromFile(file);

  
  if (loadedScript) {
    
    lua_State* L = this->script.GetState();
    
    lua_pushstring(L,"MB_GAME_COMPONENT");
    lua_pushlightuserdata(L,(void*)this);
    lua_settable(L,LUA_REGISTRYINDEX);    
    
    bool runscript = this->script.RunScript();
    bool runinit = this->script.RunFunction("init");

    }

  else {
   
    throw "Script was unable to be loaded.";
    
  }


}


void MB::LuaComponent::UpdateScriptPreCall(lua_State* L)
{

}



void MB::LuaComponent::Update( sf::Time elapsed, MB::Types::EventList* events,int argCount )
{
#ifdef LUA_EDITOR

  if ( LuaHelper::LuaScripts::Instance().NeedToUpdate(scriptFile) )
  {
    std::string newscript = LuaHelper::LuaScripts::Instance().GrabUpdate(this->scriptFile);
    
    this->script.LoadFromString(newscript);
        lua_State* L = this->script.GetState();
    lua_pushstring(L,"MB_GAME_COMPONENT");
    lua_pushlightuserdata(L,(void*)this);
    lua_settable(L,LUA_REGISTRYINDEX);  
    this->script.RunScript();
    this->script.RunFunction("init");
    
  }
#endif
  lua_State* L = this->script.GetState();
  
  lua_getglobal(L,"update");
  
  ActionsToLua( L, this->game->GetActions() );

  lua_pushnumber(L, (int)elapsed.asMilliseconds() );
  
  this->UpdateScriptPreCall(L);
  
  int s = lua_pcall( L , argCount, 0 ,0);
  
  this->script.HandleError(s);
  
  GameComponent::Update( elapsed, events );

}

int MB::LuaComponent::AddSounds(std::string file)
{
  int key = this->soundKey;  
  this->sounds.insert(std::pair <int,sf::Sound>(key, sf::Sound( Content::Load< sf::SoundBuffer >(file)) ) );
  this->soundKey++;
  return key;
}


sf::Sound* MB::LuaComponent::GetSound(int ref)
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


int MB::LuaComponent::AddSprite(std::string file)
{
  
  int key = this->spriteKey;
  this->sprites.insert( std::pair <int,sf::Sprite>( key, sf::Sprite( Content::Load< sf::Texture > (file) ) ) );
  this->spriteKey++;
  return key;
}

void MB::LuaComponent::AddSpriteToDrawList(int ref)
{
  this->spriteBatch.push_back(ref);
}

sf::Sprite* MB::LuaComponent::GetSprite(int ref)
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

int MB::LuaComponent::AddText(std::string value)
{
  int key = this->textKey;
  this->text.insert( std::pair <int,sf::Text>( key,sf::Text(sf::String(value)) )  );
  this->textKey++;
  return key;
}

void MB::LuaComponent::AddTextToDrawList(int ref)
{
  if ( this->text.find(ref) != this->text.end() ) {
    this->textBatch.push_back(ref);
  }
  else
  {
    throw "Unable to find text.";
  }
}



sf::Text* MB::LuaComponent::GetText(int ref)
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



void MB::LuaComponent::Draw()
{
  
  bool success = this->script.RunFunction("draw");

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

const sf::Vector2u& MB::LuaComponent::GetWindowSize()
{
  return this->game->Window()->getSize();
}


MB::LuaComponent::~LuaComponent()
{

  
}
