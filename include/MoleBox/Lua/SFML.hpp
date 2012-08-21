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


/*******************************************
 *
 * These static functions provide an
 * interface with SFML
 *
 * These require the use of the container
 * which are to be used to link your code
 * to the lua states.
 *
 *******************************************/
#ifndef LUA_SFML_HPP
#define LUA_SFML_HPP

#include <lua.hpp>

#include <MoleBox/Export.hpp>
#include <MoleBox/Lua/Helpers.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


namespace MB
{

  namespace Lua
  {
    class Script;
    
    namespace SFML
    {

      /**
       * @brief C functions for lua to add and use sounds.
       **/
      class Sounds
      {

      public:
	  static Sounds& 			Instance			();
	  static int 				Load				( lua_State *L );
	  static int 				Play				( lua_State *L );
	  static int 				PauseUnPause			( lua_State *L );
	  static int 				Stop				( lua_State* L );

      };

      /**
       * @brief C functions for lua to add and use sprites.
       **/
      class Sprites
      {
      public:
	  static int 				Load				( lua_State *L );
	  static int 				Draw				( lua_State *L );
	  static int				Move				( lua_State *L );
	  static int				SetPosition			( lua_State *L );
	  static int				GetPosition			( lua_State *L );
	  static int				Size				( lua_State *L );

      };



      /**
       * @brief C functions for lua to add and use drawable text.
       **/
      class Text
      {
      public:
	  static int 				Create				( lua_State *L );
	  static int 				Draw				( lua_State *L );
	  static int 				Modify				( lua_State *L );
	  static int				Move				( lua_State *L );
	  static int				SetPosition			( lua_State *L );
	  static int				GetPosition			( lua_State *L );
	  static int				Size				( lua_State *L );


      };

      /**
       * @brief C functions for lua to add and use music.
       **/
      class Music
      {

      public:

	  static int 				Load				( lua_State *L );
	  static int 				Play				( lua_State *L );
	  static int 				Playing				( lua_State *L );
	  static int 				Pause				( lua_State *L );
	  static int 				Continue			( lua_State *L );
	  static int 				Stop				( lua_State *L );
	  static int 				SetLoop				( lua_State *L );

      };

      /**
       * @brief C functions for lua to obtain window information.
       **/
      class Window
      {
      public:
	  static int Dimensions ( lua_State *L );
	  static int Resized	  ( lua_State *L );
      };

      /**
       * @brief Lua function register array for the window C functions
       **/
      static const  luaL_reg window_reg[] =
      {
	  { "Size", Window::Dimensions},
	  { NULL, NULL }
      };

      /**
       * @brief Lua function register array for the Sprite C functions
       **/
      static const luaL_reg sprite_Reg[] =
      {
	  { "Load", Sprites::Load},
	  { "Draw", Sprites::Draw},
	  { "Move", Sprites::Move},
	  { "Size", Sprites::Size},
	  { "SetPosition", Sprites::SetPosition},
	  { "GetPosition", Sprites::GetPosition},
	  { NULL, NULL }
      };

      /**
       * @brief Lua function register array for the Text C functions
       **/
      static const luaL_reg text_reg[] =
      {
	  { "Create", Text::Create},
	  { "Draw", Text::Draw},
	  { "Modify", Text::Modify},
	  { "Move", Text::Move},
	  { "Size", Text::Size},
	  { "SetPosition", Text::SetPosition},
	  { "GetPosition", Text::GetPosition},
	  { NULL, NULL }
      };

      /**
       * @brief Lua function register array for the Sound C functions
       **/
      static const luaL_Reg sound_reg[] =
      {
	  { "Load", Sounds::Load},
	  { "Play", Sounds::Play},

	  { NULL, NULL }
      };

      /**
       * @brief Lua function register array for the Music C functions
       **/
      static const  luaL_Reg music_reg[] =
      {
	  { "Load", Music::Load },
	  { "Play", Music::Play},
	  { "Playing",Music::Playing},
	  { "Pause",Music::Pause},
	  { "Continue", Music::Continue},
	  { "Stop",Music::Stop},
	  { "SetLoop",Music::SetLoop},
	  { NULL, NULL }
      };

    void RegisterWindow(MB::Lua::Script* script);
    void RegisterSprites(MB::Lua::Script*);
    void RegisterText(MB::Lua::Script*);
    void RegisterSound(MB::Lua::Script*);
    void RegisterMusic(MB::Lua::Script*);

    }

  }
}

#endif
