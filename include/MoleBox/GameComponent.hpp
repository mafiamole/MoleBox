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


#ifndef MB_GAMECOMPONENT_HPP
#define MB_GAMECOMPONENT_HPP

#include <MoleBox/Export.hpp>

#include <MoleBox/GameObject.hpp>
#include "Actions/Actions.hpp"
#include <SFML/Graphics/Drawable.hpp>

namespace MB {
  
  class Game;

  /**
   * @brief GameComponent is a convienence class that provides an general abstract for a general objects in your game. It provides a update and draw methods that are called by MB::Game if registered in the MB::Game object. Its usage is in extending, rather than invocation.
   **/
  class MOLEBOX_API GameComponent : public GameObject
  {
  protected:
    
    /**
     * @brief A reference to the main game object.
     **/
    Game *game;
    Actions::Actions* actions;
  public:

    /**
     * @brief Used to initalise your game component.
     *
     * @param game A pointer to your game object
     **/
    GameComponent(Game *game);
    /**
     * @brief Put code here to clean up your components resources. Game assets are cleaned up by the Game class. So no need to concern your self with that.
     *
     **/
    virtual ~GameComponent();
      
      /**
       * @brief Obtain the pointer of the game object
       *
       * @return Game*
       **/
      Game * GetGame();
      
      /**
       * @brief Update is called on each game loop. Update needs to contain your components changes for that loop.
       *
       * @param elapsed The time since the last loop
       * @param events A list of events for this loop.
       * @return void
       **/
      virtual void Update( sf::Time elapsed,EventList*events );
      /**
       * @brief This needs to contain the code that draws the components objects to screen.
       *
       * @return void
       **/
      virtual void Draw ();
      
      /**
       * @brief Convenience function that draws an asset to the assigned window.
       *
       * @param drawable The asset in question
       * @param states The states that the drawable will be drawn with. Defaults to sf::RenderStates::Default.
       * @return void
       **/
      void DrawAsset(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);

  };

}

#endif // MB_GAMECOMPONENT_HPP
