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
#include <MoleBox/Lua/SFML.hpp>
#include <MoleBox/Lua/Containers.hpp>
#include <MoleBox/Lua/Push.hpp>
#include <MoleBox/Lua/Script.hpp>

namespace MB
{
  namespace Lua
  {
    namespace SFML
    {


      // lazy shortcuts

      namespace Containers = MB::Lua::Containers;

      int Sprites::Load(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1)
	      MB::Lua::PushError(L, "Sprites.Load requires the following signature. Sprites.Load( (string) file )");


	  try {

	      std::string filename = lua_tostring(L,1);

	      Containers::Sprites* sprites = MB::Lua::GetUserDataFromRegistry<Containers::Sprites>(L,Containers::Sprites::RegRef);


	      sf::Sprite* spriteRef =sprites->Add( lua_tostring( L , 1 ) );

	      lua_pushlightuserdata( L, (void*)spriteRef );
	  }
	  catch (std::string err)
	  {
	      MB::Lua::PushError(L,err);
	  }


	  return 1;
      }

      int Sprites::Draw(lua_State* L)
      {
	  int n = lua_gettop( L );
	  std::cout << "adding to draw list!" <<std::endl;

	  if ( n != 1)
	      MB::Lua::PushError( L,  "Sprite.Draw() requires one of the following signatures: Sprites.Draw( (pointer) reference )");

	  sf::Sprite* spriteRef = (sf::Sprite*)lua_topointer( L , 1 );

	  Containers::Sprites* sprites = MB::Lua::GetUserDataFromRegistry<Containers::Sprites>(L,Containers::Sprites::RegRef);

	  if ( n == 1)
	      sprites->AppendToDrawList(spriteRef);

	  //   if ( n == 5)
	  //   {
	  //     sf::IntRect subRect( lua_tointeger( L ,2 ), lua_tointeger( L , 3 ), lua_tointeger( L,4 ), lua_tointeger( L , 5 ) );
	  //     spriteRef->setTextureRect(subRect);
	  //     sprites->AppendToDrawList(spriteRef);
	  //   }
	  return 0;

      }

      int Sprites::Move(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 3 )
	      MB::Lua::PushError( L, "Sprites.Move requires the following signature: Sprites.Move( (pointer) reference , (int) dx, (int) dy )" );

	  sf::Sprite* spriteRef = (sf::Sprite*)lua_topointer( L , 1 );

	  float x = lua_tonumber( L , 2 );
	  float y = lua_tonumber( L , 3 );

	  //Containers::Sprites* sprites = MB::Lua::GetUserDataFromRegistry<Containers::Sprites>(L,Containers::Sprites::RegRef);

	  //sprites->Get(spriteRef)->move(x,y);

	  spriteRef->move(x,y);

	  return 0;
      }

      int Sprites::SetPosition(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 3 )
	      MB::Lua::PushError( L, "Sprites.SetPosition requires the following signature: Sprites.SetPosition( (pointer) reference, (int) x, (int) y )"  );


	  sf::Sprite* spriteRef = (sf::Sprite*)lua_topointer( L , 1 );

	  //Containers::Sprites* sprites = MB::Lua::GetUserDataFromRegistry<Containers::Sprites>(L,Containers::Sprites::RegRef);

	  //sprites->Get(spriteRef)->setPosition( lua_tonumber(L, 2), lua_tonumber(L,3) );

	  spriteRef->setPosition(lua_tonumber(L, 2), lua_tonumber(L,3));

	  return 0;
      }

      int Sprites::GetPosition(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 3 )
	      MB::Lua::PushError( L, "Sprites.GetPosition requires the following signature: Sprites.GetPosition( (pointer) reference )");

	  sf::Sprite* spriteRef = (sf::Sprite*)lua_topointer( L , 1 );

	  //Containers::Sprites* sprites = MB::Lua::GetUserDataFromRegistry<Containers::Sprites>(L,Containers::Sprites::RegRef);

	  //sf::Vector2f pos = sprites->Get(sprite)->getPosition();
	  sf::Vector2f pos = spriteRef->getPosition();
	  lua_pushnumber( L , pos.x);
	  lua_pushnumber( L , pos.y);

	  return 2;
      }

      int Sprites::Size(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1 )
	      MB::Lua::PushError( L, "Sprites.Size requires the following signature: Sprites.Size( (pointer) reference )");

	  //Containers::Sprites* sprites = MB::Lua::GetUserDataFromRegistry<Containers::Sprites>(L,Containers::Sprites::RegRef);

	  sf::Sprite* spriteRef = (sf::Sprite*)lua_topointer( L , 1 );
	  //test = sprites->Get()->getTextureRect();

	  //sf::IntRect rect = sprites->Get(sprite)->getTextureRect();
	  sf::IntRect rect  = spriteRef->getTextureRect();
	  lua_pushnumber( L , rect.width);
	  lua_pushnumber( L , rect.height);

	  return 2;
      }

      int Sounds::Load(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1 )
	      MB::Lua::PushError( L, "Sounds.Load requires the following signature: Sounds.Load( (string) sound file )");


	  Containers::Sounds* sounds = MB::Lua::GetUserDataFromRegistry<Containers::Sounds>(L,Containers::Sounds::RegRef);

	  sf::Sound* soundRef = sounds->Load( lua_tostring( L , 1 ) );

	  lua_pushlightuserdata( L, (void*)soundRef );

	  return 1;
      }

      int Sounds::Play(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1 )
	      MB::Lua::PushError( L, "Sounds.Play requires the following signature: Sounds.Play( (pointer) sounfRef" );

	  sf::Sound* soundRef = (sf::Sound*)lua_topointer( L , 1 );

	  soundRef->play();

	  return 0;
      }

      int Sounds::Stop(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1 )
	      MB::Lua::PushError( L, "Sounds.Play requires the following signature: Sounds.Play( (pointer) sounfRef" );

	  sf::Sound* soundRef = (sf::Sound*)lua_topointer( L , 1 );

	  soundRef->stop();

	  return 0;
      }

      int Sounds::PauseUnPause(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1 )
	      MB::Lua::PushError( L, "Sounds.Play requires the following signature: Sounds.Play( (pointer) sounfRef" );

	  sf::Sound* soundRef = (sf::Sound*)lua_topointer( L , 1 );

	  soundRef->pause();

	  return 0;
      }

      int Text::Create(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1 )
	      MB::Lua::PushError( L, "Text.Create requires the following signature: Text.Create( (string) text" );

	  sf::Text* text = MB::Lua::GetUserDataFromRegistry<Containers::Text>(L,Containers::Text::RegRef)->Create( lua_tostring(L,1) );

	  lua_pushlightuserdata (L,(void*)text);

	  return 1;
      }

      int Text::Draw(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1)
	      MB::Lua::PushError( L,  "Text.Draw() requires the following signature: Text.Draw( (pointer) reference ) ");

	  sf::Text* textRef = (sf::Text*)lua_topointer( L , 1 );

	  Containers::Text* text = MB::Lua::GetUserDataFromRegistry<Containers::Text>(L,Containers::Text::RegRef);

	  if ( n == 1)
	      text->AppendToDrawList(textRef);

	  return 0;
      }

      int Text::Modify(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 2 )
	      MB::Lua::PushError( L,  "Text.Modify() requires the following signature: Text.Draw( (pointer) reference, (string) new text ) ");

	  sf::Text* textRef = (sf::Text*)lua_topointer( L , 1 );

	  sf::String newText( lua_tostring( L , 2 ) );

	  textRef->setString(newText);

	  return 0;
      }

      int Text::Size(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1 )
	      MB::Lua::PushError( L,  "Text.Size() requires the following signature: Text.( (pointer) reference ) ");

	  Containers::Text* text = MB::Lua::GetUserDataFromRegistry<Containers::Text>(L,Containers::Text::RegRef);

	  sf::Text* textRef = (sf::Text*)lua_topointer( L , 1 );

	  sf::FloatRect size = textRef->getLocalBounds();

	  lua_pushinteger ( L , size.width );
	  lua_pushinteger ( L , size.height );

	  return 2;
      }

      int Text::Move(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 2 )
	      MB::Lua::PushError( L,  "Text.Move() requires the following signature: Text.( (pointer) reference , (int) x , (int) y ) ");

	  Containers::Text* text = MB::Lua::GetUserDataFromRegistry<Containers::Text>(L,Containers::Text::RegRef);

	  sf::Text* textRef = (sf::Text*)lua_topointer( L , 1 );

	  textRef->move( lua_tonumber( L , 2 ) , lua_tonumber( L ,3 ) );

	  return 0;
      }

      int Text::GetPosition(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1 )
	      MB::Lua::PushError( L,  "Text.() requires the following signature: Text.( (pointer) reference ) ");

	  Containers::Text* text = MB::Lua::GetUserDataFromRegistry<Containers::Text>(L,Containers::Text::RegRef);

	  sf::Text* textRef = (sf::Text*)lua_topointer( L , 1 );

	  sf::Vector2f pos = textRef->getPosition();

	  lua_pushnumber( L , pos.x );
	  lua_pushnumber( L , pos.y );

	  return 2;
      }

      int Text::SetPosition(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 3)
	      MB::Lua::PushError( L,  "Text.() requires the following signature: Text.( (pointer) reference ) ");

	  Containers::Text* text = MB::Lua::GetUserDataFromRegistry<Containers::Text>(L,Containers::Text::RegRef);

	  sf::Text* textRef = (sf::Text*)lua_topointer( L , 1 );

	  textRef->setPosition( lua_tonumber( L , 2 ), lua_tonumber ( L , 3 ) );

	  return 0;
      }


      int Music::Load(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1)
	      MB::Lua::PushError( L, "Music.Load requires one argument. Music.Load( (string) sound file)" );

	  Containers::Music* Music = MB::Lua::GetUserDataFromRegistry<Containers::Music>(L,Containers::Music::RegRef);

	  try {
	      sf::Music* musicRef = Music->Load( lua_tostring( L , 1 ) );
	      lua_pushlightuserdata( L , musicRef );

	      return 1;
	  }
	  catch (std::string err)
	  {
	      MB::Lua::PushError( L, " C++ Exception was caught: " + err);
	      return 0;
	  }
      }

      int Music::Playing(lua_State* L)
      {
	  return 0;
      }

      int Music::Play(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1)
	      MB::Lua::PushError( L, "Music.Play requires one argument. Music.Play( (pointer) musicRef )" );

	  Containers::Music* Music = MB::Lua::GetUserDataFromRegistry<Containers::Music>(L,Containers::Music::RegRef);

	  try {
	      sf::Music* musicOb =(sf::Music*)lua_topointer( L , 1 );
	      Music->Play( musicOb );
	      return 0;
	  }
	  catch (std::string err)
	  {
	      MB::Lua::PushError( L, " C++ Exception was caught: " + err);
	      return 0;
	  }
      }

      int Music::Stop(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1)
	      MB::Lua::PushError( L, "Music.Stop requires one argument. Music.Stop( (pointer) musicRef )" );

	  Containers::Music* Music = MB::Lua::GetUserDataFromRegistry<Containers::Music>(L,Containers::Music::RegRef);

	  sf::Music* musicRef = (sf::Music*)lua_topointer(L , 1);

	  musicRef->stop();

	  return 0;
      }

      int Music::Continue(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1)
	      MB::Lua::PushError( L, "Music.Stop requires one argument. Music.Stop( (pointer) musicRef )" );

	  sf::Music* musicRef = (sf::Music*)lua_topointer(L , 1);

	  musicRef->play();


	  return 0;
      }

      int Music::Pause(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 1)
	      MB::Lua::PushError( L, "Music.Stop requires one argument. Music.Stop( (pointer) musicRef )" );

	  sf::Music* musicRef = (sf::Music*)lua_topointer(L , 1);

	  musicRef->pause();

	  return 0;
      }

      int Music::SetLoop(lua_State* L)
      {
	  int n = lua_gettop( L );

	  if ( n != 2)
	      MB::Lua::PushError( L, "Music.Stop requires two arguments. Music.Stop( (pointer) musicRef, (bool) loop )" );

	  sf::Music* musicRef = (sf::Music*)lua_topointer(L , 1);
	  bool value = lua_toboolean(L,2);
	  musicRef->setLoop( value );


	  return 0;
      }



      int Window::Dimensions(lua_State *L)
      {
	  int n = lua_gettop( L );

	  if ( n != 0)
	      MB::Lua::PushError(L, "Window.Size requires no arguments.");

	  sf::RenderWindow* window = MB::Lua::GetUserDataFromRegistry<sf::RenderWindow>(L,"SFML_GAME_WINDOW");
	  lua_pushinteger(L, window->getSize().x);
	  lua_pushinteger(L, window->getSize().y);
	  return 2;
      }

      int Window::Resized(lua_State* L)
      {
	  int n = lua_gettop ( L );

	  if ( n != 0)
	      MB::Lua::PushError(L, "Window.Resized requires no arguments.");

	  lua_pushboolean(L, false);

	  return 1;
      }
      
      MOLEBOX_LUA_API void RegisterWindow(MB::Lua::Script* script)
      {
	script->RegisterLibrary("Window",window_reg);
      }
      
      MOLEBOX_LUA_API void RegisterSprites(MB::Lua::Script* script)
      {
	script->RegisterLibrary("Sprites",sprite_Reg);
      }
      
      MOLEBOX_LUA_API void RegisterText(MB::Lua::Script* script)
      {
	script->RegisterLibrary("Text",text_reg);
      }
      
      MOLEBOX_LUA_API void RegisterSound(MB::Lua::Script* script)
      {
	script->RegisterLibrary("Sound",sound_reg);
      }
      
      MOLEBOX_LUA_API void RegisterMusic(MB::Lua::Script* script)
      {
	script->RegisterLibrary("Music",music_reg);
      }
    
    }
  }
}
