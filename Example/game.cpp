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

#include "game.h"

#include "../Framework/Lua/Component.h"
#include "../Framework/Actions/keyboard.h"
#include "../Framework/Actions/mouse.h"

#include <iostream>

Game::Game() : MB::Game("Game Title")
{
    
  this->AddComponent(new TestComponent(this));
  this->AddComponent(new MB::LuaComponent(this,"testComponent.lua"));
  //this->AddComponent(new MB::LuaComponent(this,"testComponent2.lua"));
  this->actionList.Register("Play Sound",new MB::Keyboard(sf::Keyboard::Space));
  this->actionList.Register("Play Music",new MB::Mouse(sf::Mouse::Left));
  this->actionList.Register("Player Move Left",new MB::Keyboard(sf::Keyboard::Left));
  this->actionList.Register("Player Move Right",new MB::Keyboard(sf::Keyboard::Left));
  
}

Game::~Game()
{
  
}

void Game::Draw()
{
  MB::Game::Draw();
}

void Game::Update(MB::EventList* events)
{
  MB::Game::Update(events);

}

void Game::Run(int argc,char **argv)
{
  MB::Game::Run(argc,argv);
}
