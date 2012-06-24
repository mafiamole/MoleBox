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
#include <iostream>

#include <MoleBox/Actions/Keyboard.hpp>
#include <MoleBox/Actions/Mouse.hpp>
#include <MoleBox/Lua/Component.hpp>

#include <Pong/game.h>


Game::Game() : MB::Game("Ultra Pong 3000")
{

  
  window = new sf::RenderWindow( sf::VideoMode( 800, 600 ), "Window name" );
   
  this->actionList.Register("Player Move Up",new MB::Keyboard(sf::Keyboard::Up));
  this->actionList.Register("Player Move Down",new MB::Keyboard(sf::Keyboard::Down));
  

  try {

  this->player 		= (Player*)this->AddComponent( new Player(this) );
  this->enemy		= (Enemy*)this->AddComponent( new Enemy(this) );
  this->ball 		= (Ball*)this->AddComponent( new Ball(this) );
  this->ui			= (UI*)this->AddComponent( new UI(this,"ui.lua") );
  enemy->SetBall(ball);
  ball->SetOpponents(player,enemy);
  ui->SetBall(ball);
  //, won("No one"),finished(false)
 
  this->won.setString("No one");
  this->finished = false;
  }
  catch (char const* e)
  {
    std::cout << e << std::endl;    
  }
  catch (std::string e)
  {
    std::cout << e << std::endl;
  }
  
}

Game::~Game()
{
  
}

void Game::Draw()
{
  MB::Game::Draw();  
  if (finished)
  {
    this->Window()->draw(won);
  }

}

void Game::Update( sf::Time elapsed, MB::Types::EventList* events)
{
  
  if (!finished)
  {
    int pScore = ball->PlayerScore();
    int cScore = ball->ComputerScore();

    if (pScore >= 10)
    {
      this->won.setString("Player has won!");
      this->won.setCharacterSize(50);
      sf::Vector2f newPos;
      newPos.x = (this->Window()->getSize().x / 2)  - ( this->won.getGlobalBounds().width / 2) ;
      newPos.y = (this->Window()->getSize().x / 2)  - ( this->won.getGlobalBounds().width / 2) ;
      
      this->won.setPosition( newPos );
      this->finished = true;
    }
    
    if (cScore >= 10)
    {
      this->won.setString("Computer has won!");
      sf::Vector2f newPos;
      this->won.setCharacterSize(50);
      newPos.x = (this->Window()->getSize().x / 2)  - ( this->won.getGlobalBounds().width / 2) ;
      newPos.y = (this->Window()->getSize().x / 2)  - ( this->won.getGlobalBounds().width / 2) ;
      this->won.setPosition( newPos );
      this->finished = true;
    }
    MB::Game::Update(elapsed,events);
    }

}

int Game::Run(int argc,char **argv)
{

  try
  {
    std::list< std::string > list = resourceManger.LoadList("resources.txt");
    if (list.size() == 0)
    {
      MB::Game::Run(argc,argv);
    }
    else
    {
      for (std::list< std::string >::iterator itr = list.begin();itr != list.end();itr++)
      {
	std::cerr << (*itr) << std::endl;
      }
      return 1;
    }
  }
  catch (MB::Content::Exception error)
  {
    Window()->close();
    std::cerr << error.toString() << std::endl;
    return 1;
  }
  
  return 0;
}



