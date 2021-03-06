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


#ifndef MB_FSMGAME_HPP
#define MB_FSMGAME_HPP

#include <MoleBox/Export.hpp>
#include <MoleBox/Game.hpp>
#include <MoleBox/Patterns.hpp>
#include <MoleBox/GameComponent.hpp>

namespace MB {
  
  class MOLEBOX_API SMGame;
  
  /**
   * @brief Represents a 'state' within the programs structure. E.G. If the game is in a menu or server selection, in game etc.
   **/
  class MOLEBOX_API GameState : public MB::GameObject, public MB::SM::State
  {
  protected:
    MB::ComponentList components;
    SMGame* game;
     /**
     * @brief inserts a component to the component list.
     *
     * @param component The component to add
     * @return  MB::GameComponent *
     **/
    MB::GameComponent * AddComponent(MB::GameComponent * component);
    /**
     * @brief Removes all component objects added to the components list from memmory.
     * @Warning It removes the actual object from memory, not just the pointers to it.
     *
     * @return void
     **/
    void 		DeleteComponents();
    /**
     * @brief Returns the size of the component list.
     *
     * @return int
     **/
    int 		ComponentCount();
    /**
     * @brief This function is called when Update is called. It calls the update method of each component objet
     *
     * @param elapsed Time since last called
     * @param events Contains a list of input events from the window;
     * @return void
     **/
    void		UpdateComponents(sf::Time elapsed, MB::EventList* events);	
    
    /**
     * @brief Calls the draw method of each object. Is called when Draw is called.
     *
     * @return void
     **/
    void 		DrawComponents();

  public:
    /**
     * @brief Initiate the game state by passing it's name and the state machine.
     *
     * @param name name of your new found state.
     * @param sfm The state machine.
     **/
			GameState(std::string name, SMGame* sfm);
			~GameState();

    virtual void 	Draw();
    /**
     * @brief Used to update the logic of this 'state' Should be called by the game object every loop
     *
     * @param elapsed Time since last called
     * @param events Contains a list of input events from the window;
     * @return void
     **/
    virtual void 	Update(sf::Time elapsed, MB::EventList* events);
    /**
     * @brief Used to initalise / reinitalise the game state on state change. Override to handle your own resources.
     *
     * @return void
     **/
    virtual void 	DoEntre();
    /**
     * @brief Used to clean up on state change.Override to handle your own resources.
     *
     * @return void
     **/
    virtual void 	DoExit();
  };

  /**
   * @brief A 'game' that uses a state machine logic flow.
   * 
   * General usage is in extending this class through inheritence.
   * 
   * 
   **/
  class MOLEBOX_API SMGame : public MB::Game, public MB::SM::Machine
  {
  protected:
    std::map<std::string,GameState*> states;  
    GameState* currentState;
  public:
    /**
     * @brief Creates a new game object that works like some form of state machine
     *
     * @param windowName The name of the game window.
     * @param argc Command line argument count
     * @param argv The command line argument array
     * @param preventArgOverwrite This tells the configuration tool to not allow configurations to be overridden by any command line arguments. Defaults to false.
     **/
    SMGame(std::string windowName, int argc, char** argv, bool preventArgOverwrite = false);
    /**
     * @brief Default destructor
     *
     **/
    virtual ~SMGame();
    /**
     * @brief Adds a game state to the game state machine
     *
     * @param state The game state to add
     * @return void
     **/
    void 	AddState(GameState* state);
    /**
     * @brief changes the current state. This will automatically call the DoExit of the current state,
     *        followed by setting the state by the given string reference. It then calls DoEntre on that state.
     *
     * @param name The name of the state to change to.
     * @return void
     **/
    void 	SetState(std::string name);
    /**
     * @brief Called once per game loop. Update should be called in the overridden 
     *        function so that it also updates the game state.
     *
     * @param elapsed The time elapsed since the last update
     * @param events List of input events on this loop
     * @return void
     **/
    virtual void Update(sf::Time elapsed, MB::EventList* events);
    /**
     * @brief Calls the current gamestate draw method. Use by overriding it and calling it to update the current game state.
     *
     * @return void
     **/
    virtual void Draw();
    /**
     * @brief Initiates the game loop. Override it if you want additional tasks (like extra threads) to run along side the main loop
     *
     * @return int
     **/
    virtual int Run();
    /**
     * @brief returns a reference to the games window.
     *
     * @return sf::RenderWindow*
     **/
    sf::RenderWindow* Window();
  };



}

#endif // MB_FSMGAME_HPP
