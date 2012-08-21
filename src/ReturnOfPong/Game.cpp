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


#include <ReturnOfPong/Game.hpp>
#include <MoleBox/Actions/Keyboard.hpp>
#include <MoleBox/Lua/Container.hpp>

Game::Game(std::string windowName, int argc, char** argv, bool preventArgOverwrite): SMGame(windowName, argc, argv, preventArgOverwrite)
{
  
  this->actions.Register("Player Move Up",new MB::Actions::Keyboard(sf::Keyboard::Up));
  this->actions.Register("Player Move Down",new MB::Actions::Keyboard(sf::Keyboard::Down));
  this->actions.Register("Close",new MB::Actions::Keyboard(sf::Keyboard::Escape));  
  this->AddState(new MainMenu("MainMenu",this));
  this->AddState(new PongGame("PongGame",this));
  this->SetState("MainMenu");
  args.argc = argc;
  args.argv = argv;
  this->resourceManager.AddIdentifier(MB::Content::GetID<MB::Lua::Script*>());
  args.map = this->resourceManager.ResourceLists(); // Must be done after content loading!.
}

Game::~Game()
{

}

void Game::Update(sf::Time elapsed, MB::EventList* events)
{
    MB::SMGame::Update(elapsed, events);

    if (events->find(sf::Event::LostFocus) != events->end())
    {
      std::cout << "Focus lost." << std::endl;
    }
  
}

void Game::Draw()
{
  MB::SMGame::Draw();

}

int Game::Run()
{  
    
    
    sf::Thread* thread = CreateRUIThreadOBJ(args);
    
    thread->launch();
    int returnVal = MB::SMGame::Run();
    thread->wait();
    return returnVal;
}


