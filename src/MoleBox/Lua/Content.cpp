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


#include <MoleBox/Lua/Content.hpp>

/**
 * LuaSFML namespace
 * 
 */

#include <MoleBox/Lua/Component.hpp>

using namespace MB;

static Lua::LuaComponent* getComponentFromUserData(lua_State* L)
{
  lua_pushstring(L,"MB_GAME_COMPONENT");
  lua_gettable(L,LUA_REGISTRYINDEX);
  Lua::LuaComponent* _this = (Lua::LuaComponent*)lua_touserdata(L,-1);
  return _this;
}

int Lua::Sounds::Load(lua_State* L)
{

  int n = lua_gettop(L);
  
  if ( n != 1)
  {
    
    lua_pushstring(L,"Sounds.Plays Requires one argument, filename of sound.");
    
    lua_error(L);
    
  }
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  std::string file;
  
  file = lua_tostring(L,1);

  int soundRef = _this->AddSounds(file);
  
  lua_pushinteger(L,soundRef);
  
  return 1;

}

int Lua::Sounds::Play(lua_State* L)
{

  int n = lua_gettop(L);
  
  if ( n != 1)
    
    Lua::PushError( L, "Sounds.Play Requires one argument. (sound)" );
  
  int soundKey = lua_tointeger(L,1);
  
  try {
    
    Lua::LuaComponent* _this = getComponentFromUserData(L);  
    _this->GetSound(soundKey)->play();
  
  }
  catch (std::string e) 
  {
    Lua::PushError( L, e );
  }
  return 0;
}

int Lua::Sounds::Stop(lua_State* L)
{
  int n = lua_gettop(L);
  
  if ( n != 1)
    
    Lua::PushError( L, "Sounds.Stop Requires one argument. (sound)" );
  
  int soundKey = lua_tointeger(L,1);  
    
  try {
    
    Lua::LuaComponent* _this = getComponentFromUserData(L);  
    _this->GetSound(soundKey)->stop();
  
  }
  catch (std::string e) 
  {
    Lua::PushError( L, e );
  }
  return 0;
}    



int Lua::Sounds::PauseUnPause(lua_State* L)
{
  int n = lua_gettop(L);
  
  if ( n != 1)
    
    Lua::PushError( L, "Sounds.Stop Requires one argument. (sound)" );
  
  int soundKey = lua_tointeger(L,1);  
  
  try {
    
    Lua::LuaComponent* _this = getComponentFromUserData(L);  
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
    Lua::PushError( L, e );
  }


  return 0;

}


int Lua::Sprites::Load(lua_State* L)
{
  int n = lua_gettop(L);
  
  if ( n != 1)
    
    Lua::PushError( L, "Sprites.Load Requires one arguments, the (texture file).");

  Lua::LuaComponent* _this = getComponentFromUserData(L);
  if ( _this == 0x0 )
  {
    Lua::PushError( L, "Component object not set in Lua::Sprites::Load" );
    return 0;
  }
  else {
  std::string file = lua_tostring(L,1);

  int ref = _this->AddSprite(file);
  
  lua_pushinteger(L,ref);
  
  return 1;
  }
}

int Lua::Sprites::Draw(lua_State* L)
{

  int n = lua_gettop( L );
  
  if ( n != 1 )
    
  Lua::PushError( L, "Sprites.Draw Requires one argument, the name of the sprite." );
  
  int sprite = lua_tointeger(L,1);
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  _this->AddSpriteToDrawList(sprite);

  return 0;
}

int Lua::Sprites::Move(lua_State* L)
{
  
  int n = lua_gettop( L );
  
  if ( n != 3 )
    
    Lua::PushError(  L, "Move requires three arguments: (sprite, x change in pixels, y change in pixels )");
    
  int sprite 	= lua_tointeger( L, 1 );
  float x 	= lua_tonumber( L, 2 );
  float y 	= lua_tonumber( L, 3 );
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  _this->GetSprite(sprite)->move(x,y);

  return 0;
}

int Lua::Sprites::SetPosition(lua_State *L)
{
  int n = lua_gettop( L );
  
  if ( n != 3 )
    
    Lua::PushError(  L, "Move requires three arguments: (sprite name, x change in pixels, y change in pixels )");
    
  int sprite 		= lua_tointeger( L, 1 );
  float x 		= lua_tonumber( L, 2 );
  float y 		= lua_tonumber( L, 3 );  

  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  _this->GetSprite(sprite)->setPosition(x,y);

  return 0;
}

int Lua::Sprites::GetPosition(lua_State* L)
{
   
  int n = lua_gettop( L ); 
  
  if ( n != 1 )
    Lua::PushError(  L, "Move requires three arguments: (sprite name, x change in pixels, y change in pixels )");

  int sprite 		= lua_tointeger( L, 1 );
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  sf::Vector2f position =  _this->GetSprite(sprite)->getPosition();
  
  float x,y;
  
  x = position.x;
  y = position.y;
  
  lua_pushnumber( L, x );
  lua_pushnumber( L, y );  
  
  return 2;
}

int Lua::Sprites::Size(lua_State* L)
{
  int n = lua_gettop( L ); 
  
  if ( n != 1 )
    Lua::PushError(  L, "Sprites.Size requires one arguments: ( string to display )");
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);  
  int ref		= lua_tointeger(L,1);
    
  try {
    int width = _this->GetSprite(ref)->getTextureRect().width;
    int height = _this->GetSprite(ref)->getTextureRect().height;
    
    lua_pushinteger(L,width);
    lua_pushinteger(L,height);
  }
  catch (std::string err)
  {
    Lua::PushError(L, err);
    
  }
  
  return 2;
}


int Lua::Text::Create(lua_State* L)
{
  int n = lua_gettop( L ); 
  
  if ( n != 1 )
    Lua::PushError(  L, "Create requires one arguments: ( string to display )");
  
   Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  std::string text = lua_tostring(L,1);
  
  int key = _this->AddText(text);
  
  lua_pushnumber( L, key);

  return 1;
  
}

int Lua::Text::Draw(lua_State* L)
{
  int n = lua_gettop( L ); 
  
  if ( n != 1 )
    Lua::PushError(  L, "Draw requires one arguments: ( text reference )");
  
  int text = lua_tointeger(L,1);
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  _this->AddTextToDrawList(text);

  return 0;
}

int Lua::Text::Modify(lua_State* L)
{
  int n = lua_gettop( L ); 
  
  if ( n != 2 )
    Lua::PushError(  L, "Create requires one arguments: ( string to display )");
  
   Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  int ref		= lua_tointeger(L,1);
  std::string text 	= lua_tostring(L,2);
  
  try {
    _this->GetText(ref)->setString(text);
  }
  catch (std::string err)
  {
    Lua::PushError(L, err);
    
  } 
  return 0;
}

int Lua::Text::Size(lua_State* L)
{
  int n = lua_gettop( L );
  
  if ( n != 1 )
    Lua::PushError(L, "Text.Size requires 1 argument ( the text object key) ");

  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  int ref = lua_tointeger(L,1);
  
  try {
    sf::FloatRect bounds = _this->GetText(ref)->getLocalBounds();
    lua_pushnumber(L,bounds.width);
    lua_pushnumber(L,bounds.height);
  }
  catch (std::string err)
  {
    Lua::PushError(L, err);
    
  }  
  
  return 2;
}


int Lua::Text::Move(lua_State* L)
{
  int n = lua_gettop( L );
  
  if ( n != 3 )
    Lua::PushError(L, "Text.Move requires three arguments ( the text object key, difference in x, difference in y) ");

  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  int ref = lua_tointeger(L,1);
  float x = lua_tonumber(L,2);
  float y = lua_tonumber(L,3);
  try {
    _this->GetText(ref)->move(x,y);

  }
  catch (std::string err)
  {
    Lua::PushError(L, err);
    
  }
  return 0;
}

int Lua::Text::GetPosition(lua_State* L)
{
  int n = lua_gettop( L );
  
  if ( n != 1 )
    Lua::PushError(L, "Text.GetPosition requires 1 argument ( the text object key) ");

  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  int ref = lua_tointeger(L,1);

  try {
    sf::Vector2f textpos = _this->GetText(ref)->getPosition();
    lua_pushnumber(L,textpos.x);
    lua_pushnumber(L,textpos.y);
  }
  catch (std::string err)
  {
    Lua::PushError(L, err);
  }
  return 0;
}

int Lua::Text::SetPosition(lua_State* L)
{
    int n = lua_gettop( L );
  
  if ( n != 3 )
    Lua::PushError(L, "Text.SetPosition requires three arguments ( the text object key, difference in x, difference in y) ");

  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  int ref = lua_tointeger(L,1);
  float x = lua_tonumber(L,2);
  float y = lua_tonumber(L,3);
  try {
    _this->GetText(ref)->setPosition(x,y);
  }
  catch (std::string err)
  {
    Lua::PushError(L, err);
  }
  return 0;
}

int Lua::Window::Dimensions(lua_State* L)
{
  int n = lua_gettop( L );
  
  if ( n != 0)
    Lua::PushError(L, "Window.Size requires no arguments.");

  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  lua_pushinteger(L, _this->GetWindowSize().x);
  lua_pushinteger(L, _this->GetWindowSize().y);
  return 2;
}

int Lua::Window::Resized(lua_State* L)
{
  int n = lua_gettop ( L );
  
  if ( n != 0)
   Lua::PushError(L, "Window.Resized requires no arguments.");
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  bool windowResize = _this->GetGame()->WindowResized();  
  
  lua_pushboolean(L, windowResize);
  
  return 1;
  
}

int Lua::Music::Load(lua_State*L)
{
  int n = lua_gettop ( L );

  if ( n != 1)
    Lua::PushError(L, "Music.Load requires one argument ( File ).");
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);
    
  std::string file = lua_tostring(L,1);
  
  try {
    
    int value = _this->AddMusic(file);
    
    lua_pushinteger(L,value);
  }
  catch (std::string err)
  {
    Lua::PushError(L, err);
  }
      
  return 1;
}

int Lua::Music::Playing(lua_State*L)
{
  int n = lua_gettop ( L );
  
  if ( n != 0)
    Lua::PushError(L, "Music.Plating requires one argument ( 'music reference' ).");
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  int isThisCurrentPlaying  = lua_tointeger(L,1);
  
  try
  {
    int currentPlaying = _this->CurrentMusicPlaying();
    
    lua_pushboolean(L, currentPlaying && isThisCurrentPlaying );
    
  }
  catch (std::string err)
  {
    Lua::PushError(L, err);
  }
  
  return 1;
}


int Lua::Music::Play(lua_State*L)
{
  int n = lua_gettop ( L );
  
  if ( n != 1)
    Lua::PushError(L, "Music.Play requires one argument ( 'music reference' ).");
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  int musicToPlay  = lua_tointeger(L,1);
  try {
    _this->SetPlayingMusic(musicToPlay);
  }
  catch (std::string err)
  {
    Lua::PushError(L,err);

  }
  catch (const char* err)
  {
   Lua::PushError(L,err);
  }
  return 0;
}


int Lua::Music::Stop(lua_State*L)
{
  int n = lua_gettop ( L );
  
  if ( n != 0)
    Lua::PushError(L, "Music.Stop requires zero arguments.");
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);

  try {
   int current =  _this->CurrentMusicPlaying();
   _this->GetMusic(current)->stop();
  }
  catch (std::string err)
  {
    Lua::PushError(L,err);

  }
  
  return 0;
}


int Lua::Music::Continue(lua_State*L)
{
  int n = lua_gettop ( L );
  
  if ( n != 0)
    Lua::PushError(L, "Music.Load requires zero arguments.");
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  try {
   int current =  _this->CurrentMusicPlaying();
   _this->GetMusic(current)->play();
  }
  catch (std::string err)
  {
    Lua::PushError(L,err);
  }
  return 0;
}


int Lua::Music::Pause(lua_State*L)
{
  int n = lua_gettop ( L );
  
  if ( n != 0)
    Lua::PushError(L, "Music.Load requires zero arguments.");
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);
  try {
   int current =  _this->CurrentMusicPlaying();
   _this->GetMusic(current)->pause();
  }
  catch (std::string err)
  {
    Lua::PushError(L,err);
  }
  return 0;
}

int Lua::Music::SetLoop(lua_State*L)
{
  int n = lua_gettop ( L );
  
  if ( n != 1)
    Lua::PushError(L, "Music.Load requires one argument ( bool ).");
  
  Lua::LuaComponent* _this = getComponentFromUserData(L);
  
  bool loop = lua_toboolean(L,1);
  try {
   int current =  _this->CurrentMusicPlaying();
   _this->SetMusicLoop(current,loop);
  }
  catch (std::string err)
  {
    Lua::PushError(L,err);
  }  
  return 0;
}

