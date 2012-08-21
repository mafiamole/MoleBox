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


#ifndef MB_LUA_COMPONENT_H
#define MB_LUA_COMPONENT_H

#include <MoleBox/GameComponent.hpp>

#include <MoleBox/Lua/Container.hpp>
#include <MoleBox/Lua/Function.hpp>
#include <MoleBox/Lua/Script.hpp>
#include <MoleBox/Lua/Containers.hpp>
#include <MoleBox/Lua/SFML.hpp>
#include <MoleBox/Lua/Helpers.hpp>
namespace MB {

  namespace Lua {

    class MOLEBOX_LUA_API Component : public MB::GameComponent
    {
    protected:
      Containers::Text 		textContainer;
      Containers::Sprites 	spritesContainer;
      Containers::Sounds 	soundContainer;
      Containers::Music 	musicContainer;
      Script *			script;
      
      /**
       * @brief This pushes the arguments for the update script onto the lua stack.
       *        This is to allow inheriting classes to set these values easily before or after their own when overriding the update class
       *
       * @param elapsed The time since the last update
       * @param events Action Events list.
       * @return void
       **/
      void PushUpdateArgs(sf::Time elapsed,EventList*events);
      
    public:
      /**
       * @brief Initalises the lua game componenent by loading a file.
       *
       * @param filename File location of the script to load
       * @param game Game instance
       **/
				Component(std::string filename, MB::Game* game);

      /**
       * @brief Update the component 
       *
       * @param elapsed The time since the last update
       * @param events A list of events.
       * @return void
       **/
      virtual void 		Update( sf::Time elapsed,EventList*events );
      /**
       * @brief The draw calls go here!.
       *
       * @return void
       **/
      virtual void 		Draw();
      /**
       * @brief Default destructor
       *
       **/
      virtual 			~Component();
    };

  }

}

#endif // MB_LUA_COMPONENT_H
