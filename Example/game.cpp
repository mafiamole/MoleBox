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

#include "../src/MoleBox/Actions/keyboard.h"
#include "../src/MoleBox/Actions/mouse.h"

#include "../src/MoleBox/Lua/Component.h"

#include "game.h"




Game::Game() : MB::Game("Game Title")
{

  this->actionList.Register("Player Move Up",new MB::Keyboard(sf::Keyboard::Up));
  this->actionList.Register("Player Move Down",new MB::Keyboard(sf::Keyboard::Down));
  try {  
// 	this->AddComponent(new TestComponent(this));
// 	this->AddComponent(new MB::LuaComponent(this,"../testComponent.lua"));
// 	this->AddComponent(new MB::LuaComponent(this,"testComponent2.lua"));

  this->player 		= (Player*)this->AddComponent( new Player(this) );
  this->enemy		= (Enemy*)this->AddComponent( new Enemy(this) );
  this->ball 		= (Ball*)this->AddComponent( new Ball(this) );
  this->ui		= (UI*)this->AddComponent( new UI(this,"ui.lua") );
  enemy->SetBall(ball);
  ball->SetOpponents(player,enemy);
  ui->SetBall(ball);
  
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
}

void Game::Update( sf::Time elapsed, MB::Types::EventList* events)
{
  MB::Game::Update(elapsed,events);
  int pScore = ball->PlayerScore();
  int cScore = ball->ComputerScore();
  std::cout << pScore << "," << cScore << std::endl;
  if (pScore >= 10)
  {
    std::cout << "Player has won!" << std::endl;
    this->Window()->close();
  }
  
  if (cScore >= 10)
  {
    std::cout << "Computer has won!" << std::endl;
    this->Window()->close();
  }
}

void Game::Run(int argc,char **argv)
{
  MB::Game::Run(argc,argv);
}



