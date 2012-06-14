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


#ifndef SFMLGAMECOMPONENT_H
#define SFMLGAMECOMPONENT_H

#include <SFML/Graphics.hpp>
#include "ContainerDefinitions.h"
#include "actions.h"
namespace MB {
  /**
  * Forward declarations
  */
  class Game;

  /**
  * Class is used to represent a component in the game.
  * It is aimed at being inherited.
  */
  class GameComponent
  {
  protected:
    /**
    * Pointer to the game object.
    * This is to allow the component to access the window object for rendering purposes.
    */
    Actions		*actions;
    Game 		*game;
      
  public:
    /**
    * the Constructor sets the pointer to the SFMLGame member.
    */
			GameComponent   ();
			GameComponent	(Game *game);
			
			Game * GetGame();
    /**
    * Called every game loop.
    * This function is used for changing the components state.
    */
    virtual void 	Update			( sf::Time elapsed,Types::EventList* events);
    /**
    * Called every game loop.
    * This function is used to render to the screen. 
    */
    virtual void 	Draw			();
    
    /**
    * Does nothing.
    * 
    */
    virtual 		~GameComponent	();
  };

}

#endif // SFMLGAMECOMPONENT_H
