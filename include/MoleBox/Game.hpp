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


#ifndef MB_GAME_H
#define MB_GAME_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <MoleBox/Export.hpp>
#include <MoleBox/Content/Resources.hpp>
#include <MoleBox/Types.hpp>
#include <MoleBox/Actions/Actions.hpp>
#include "GameObject.hpp"
#include "GameConfig.hpp"
#include <string>
#include <map>
namespace MB {

class Action;

/**
  * Forward delcarations
  */
class GameComponent;

/**
 * @brief MB::Game provides the root of your game stucture. It includes your game loop, a window initalisation and more to begin creating your game.
 *
 * @author Paul Brown
 **/

typedef std::list<GameComponent *> ComponentList;

class MB_API_EXPORT Game : public GameObject
{
protected:
    sf::Clock 				clock;  
    std::string 			windowName;
    sf::RenderWindow *			window;
    std::map<std::string,std::string>	config;
    bool 				preventArgOverwrite;
    Actions::Actions			actions;
    void 				SetupWindow ();
    GameConfig				Config;
    MB::Content::Resources		resourceManager;
    ComponentList			components;

    /**
     * @brief Appends a game component to the component list
     *
     * @param component ...
     * @return :GameComponent*
     **/
    MB::GameComponent *			AddComponent(MB::GameComponent *component);
    /**
     * @brief Deletes all components in the component list from memory.
     * @warning Removes the object from memory. It invalidates all pointers
     * @return void
     **/
    void				DeleteComponents();
    /**
     * @brief Returns the number of components in the component list
     *
     * @return int
     **/
    int					ComponentCount();
    /**
     * @brief Iterates over all components and calls the Update function.
     *
     * @param elapsed The time since the last update
     * @param events List of input events
     * @return void
     **/
    void 				UpdateComponents(sf::Time elapsed, EventList *events);
    /**
     * @brief Iterates over all compoents and calls the draw function.
     *
     * @return void
     **/
    void				DrawComponents();
    
public:

  /**
   * @brief Game constructor task is to initialise the window, the game components and load resources.
   *
   * @param windowName The name of the window.
   * @param argc Number of command line arguments.
   * @param argv Command line arguments
   * @param preventArgOverwrite This prevents command line arguments from setting a number of attributes to the game. For example, resolution, fullscreen.  Defaults to false.
   **/
				  Game		( std::string windowName, int argc, char** argv, bool preventArgOverwrite = false );
  /**
   * @brief The destructor needs to clean up all resources used by the game.
   *
   **/
    virtual 			~Game		( );
    
    /**
     * @brief AddtoConfig takes the provided values and logs them into the config list. This main task is parsing the command line arguments.
     *
     * @param argc The number of arguments passed
     * @param argv The arguments
     * @return void
     **/
    void			AddToConfig	( int argc, char** argv);

    /**
     * @brief Update is called once per game loop. The game loop needs to perform or call the update routines for your game.
     *
     * @param elapsed This is the time since the last loop.
     * @param events A list of events taken from the gameloop.
     * @return void
     **/
    virtual void 			Update		( sf::Time elapsed, EventList *events  );
    
    /**
     * @brief The draw function needs to call the draw methods for all your game objects.
     *
     * @return void
     **/
    virtual void 			Draw		( );
    /**
     * @brief This begins the game loop.
     *
     * @return int Returns 0 on success.
     **/
    virtual int 			Run		( );
    
    /**
     * @brief DrawAsset is a convenience function for rendering an asset to the screen.
     *
     * @param drawable The asset, which needs to be extended from sf::Drawable.
     * @param states Define the states used for drawing to a RenderTarget Defaults to sf::RenderStates::Default. Search sf::RenderStates for more information.
     * @return void
     **/
    void 			DrawAsset	(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);

    /**
     * @brief Returns the current window in use.
     *
     * @return :RenderWindow*
     **/
    sf::RenderWindow * 		Window		( );
    /**
     * @brief Convenience function that stops execution. This allows the game to clear up it's resources.
     *
     * @return void
     **/
    
    void			Close		();


    /**
     * @brief Returns a reference to the actions object.
     *
     * @return MB::Actions::Actions*
     **/
    MB::Actions::Actions*		GetActions	( );

    
};

}

#endif // MB_GAME_H
