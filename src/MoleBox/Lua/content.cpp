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


#include "content.h"

/**
 * LuaSFML namespace
 * 
 */

#include "Component.h"

static MB::LuaComponent* getComponentFromUserData(lua_State* L)
{
  lua_pushstring(L,"MB_GAME_COMPONENT");
  lua_gettable(L,LUA_REGISTRYINDEX);
  MB::LuaComponent* _this = (MB::LuaComponent*)lua_touserdata(L,-1);
  return _this;
}

int MB_Lua::Sounds::Load(lua_State* L)
{

  int n = lua_gettop(L);
  
  if ( n != 1)
  {
    
    lua_pushstring(L,"Sounds.Plays Requires one argument, filename of sound.");
    
    lua_error(L);
    
  }
  
  MB::LuaComponent* _this = getComponentFromUserData(L);
  
  std::string file;
  
  file = lua_tostring(L,1);

  int soundRef = _this->AddSounds(file);
  
  lua_pushinteger(L,soundRef);
  
  return 1;

}

int MB_Lua::Sounds::Play(lua_State* L)
{

  int n = lua_gettop(L);
  
  if ( n != 1)
    
    LuaHelper::PushError( L, "Sounds.Play Requires one argument. (sound)" );
  
  int soundKey = lua_tointeger(L,1);
  
  try {
    
    MB::LuaComponent* _this = getComponentFromUserData(L);  
    _this->GetSound(soundKey)->play();
  
  }
  catch (std::string e) 
  {
    LuaHelper::PushError( L, e );
  }
  return 0;
}

int MB_Lua::Sounds::Stop(lua_State* L)
{
  int n = lua_gettop(L);
  
  if ( n != 1)
    
    LuaHelper::PushError( L, "Sounds.Stop Requires one argument. (sound)" );
  
  int soundKey = lua_tointeger(L,1);  
    
  try {
    
    MB::LuaComponent* _this = getComponentFromUserData(L);  
    _this->GetSound(soundKey)->stop();
  
  }
  catch (std::string e) 
  {
    LuaHelper::PushError( L, e );
  }
  return 0;
}    



int MB_Lua::Sounds::PauseUnPause(lua_State* L)
{
  int n = lua_gettop(L);
  
  if ( n != 1)
    
    LuaHelper::PushError( L, "Sounds.Stop Requires one argument. (sound)" );
  
  int soundKey = lua_tointeger(L,1);  
  
  try {
    
    MB::LuaComponent* _this = getComponentFromUserData(L);  
    sf::Sound::Status status =  _this->GetSound(soundKey)->getStatus();
    
    switch (status)
    {
      
      case 2:
	_this->GetSound(soundKey)->play();
	break;
	
      case 1:
	_this->GetSound(soundKey)->pause();
	break;
	
    }
    
  }
  catch (std::string e) 
  {
    LuaHelper::PushError( L, e );
  }


  return 0;

}


int MB_Lua::Sprites::Load(lua_State* L)
{
  int n = lua_gettop(L);
  
  if ( n != 1)
    
    LuaHelper::PushError( L, "Sprites.Load Requires one arguments, the (texture file).");

  MB::LuaComponent* _this = getComponentFromUserData(L);
  if ( _this == 0x0 )
  {
    LuaHelper::PushError( L, "Component object not set in MB_Lua::Sprites::Load" );
    return 0;
  }
  else {
  std::string file = lua_tostring(L,1);

  int ref = _this->AddSprite(file);
  
  lua_pushinteger(L,ref);
  
  return 1;
  }
}

int MB_Lua::Sprites::Draw(lua_State* L)
{

  int n = lua_gettop( L );
  
  if ( n != 1 )
    
  LuaHelper::PushError( L, "Sprites.Draw Requires one argument, the name of the sprite." );
  
  int sprite = lua_tointeger(L,1);
  
  MB::LuaComponent* _this = getComponentFromUserData(L);
  
  _this->AddSpriteToDrawList(sprite);

  return 0;
}

int MB_Lua::Sprites::Move(lua_State* L)
{
  
  int n = lua_gettop( L );
  
  if ( n != 3 )
    
    LuaHelper::PushError(  L, "Move requires three arguments: (sprite, x change in pixels, y change in pixels )");
    
  int sprite 	= lua_tointeger( L, 1 );
  float x 	= lua_tonumber( L, 2 );
  float y 	= lua_tonumber( L, 3 );
  
  MB::LuaComponent* _this = getComponentFromUserData(L);
  
  _this->GetSprite(sprite)->move(x,y);

  return 0;
}

int MB_Lua::Sprites::SetPosition(lua_State *L)
{
  int n = lua_gettop( L );
  
  if ( n != 3 )
    
    LuaHelper::PushError(  L, "Move requires three arguments: (sprite name, x change in pixels, y change in pixels )");
    
  int sprite 		= lua_tointeger( L, 1 );
  float x 		= lua_tonumber( L, 2 );
  float y 		= lua_tonumber( L, 3 );  

  MB::LuaComponent* _this = getComponentFromUserData(L);
  
  _this->GetSprite(sprite)->setPosition(x,y);

  return 0;
}

int MB_Lua::Sprites::GetPosition(lua_State* L)
{
   
  int n = lua_gettop( L ); 
  
  if ( n != 1 )
    LuaHelper::PushError(  L, "Move requires three arguments: (sprite name, x change in pixels, y change in pixels )");

  int sprite 		= lua_tointeger( L, 1 );
  
  MB::LuaComponent* _this = getComponentFromUserData(L);
  
  sf::Vector2f position =  _this->GetSprite(sprite)->getPosition();
  
  float x,y;
  
  x = position.x;
  y = position.y;
  
  lua_pushnumber( L, x );
  lua_pushnumber( L, y );  
  
  return 2;
}


int MB_Lua::Text::Create(lua_State* L)
{
  int n = lua_gettop( L ); 
  
  if ( n != 1 )
    LuaHelper::PushError(  L, "Create requires one arguments: ( string to display )");
  
   MB::LuaComponent* _this = getComponentFromUserData(L);
  
  std::string text = lua_tostring(L,1);
  
  int key = _this->AddText(text);
  
  lua_pushnumber( L, key);

  return 1;
  
}

int MB_Lua::Text::Draw(lua_State* L)
{
  int n = lua_gettop( L ); 
  
  if ( n != 1 )
    LuaHelper::PushError(  L, "Draw requires one arguments: ( text reference )");
  
  int text = lua_tointeger(L,1);
  
  MB::LuaComponent* _this = getComponentFromUserData(L);
  
  _this->AddTextToDrawList(text);

  return 0;
}

int MB_Lua::Text::Modify(lua_State* L)
{
  int n = lua_gettop( L ); 
  
  if ( n != 2 )
    LuaHelper::PushError(  L, "Create requires one arguments: ( string to display )");
  
   MB::LuaComponent* _this = getComponentFromUserData(L);
  
  int ref		= lua_tointeger(L,1);
  std::string text 	= lua_tostring(L,2);
  
  _this->GetText(ref)->setString(text);
 
  return 0;
}


int MB_Lua::Text::Move(lua_State* L)
{

}

int MB_Lua::Text::GetPosition(lua_State* L)
{

}

int MB_Lua::Text::SetPosition(lua_State* L)
{

}
