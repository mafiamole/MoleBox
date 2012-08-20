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


#include <ReturnOfPong/MainMenu.hpp>
#include <iostream>

MainMenu::MainMenu(std::string name, MB::SMGame* sfm) : GameState(name,sfm)
{

  bg = sf::Sprite( MB::Content::Load<sf::Texture>("mainmenu_bg.png"));
  MB::Content::Load<sf::Texture>("mainmenu_start1.png");
  MB::Content::Load<sf::Texture>("mainmenu_exit1.png");
  start = sf::Sprite( MB::Content::Load<sf::Texture>("mainmenu_start2.png") );
  exitSprite = sf::Sprite( MB::Content::Load<sf::Texture>("mainmenu_exit2.png") );
  start.setPosition(300,250);
  exitSprite.setPosition(350,300);
}

MainMenu::~MainMenu()
{

}

void MainMenu::Draw()
{
  this->game->Window()->draw(bg);
  this->game->Window()->draw(start);
  this->game->Window()->draw(exitSprite);
}

void MainMenu::Update(sf::Time elapsed, MB::EventList* events)
{
  sf::Vector2i mousePostion = sf::Mouse::getPosition(*(this->game->Window()));
  bool overExit = this->exitSprite.getGlobalBounds().contains(mousePostion.x,mousePostion.y);
  bool overStart = this->start.getGlobalBounds().contains(mousePostion.x,mousePostion.y);
  bool leftButtonPressed = false;
  if ( events->find(sf::Event::MouseButtonPressed) != events->end() )
  {
    leftButtonPressed = events->at(sf::Event::MouseButtonPressed).mouseButton.button == sf::Mouse::Left;
  }
  
 sf::FloatRect ebounds = this->exitSprite.getGlobalBounds();
  


  if (overExit)
  {
    exitSprite.setTexture(MB::Content::Load<sf::Texture>("mainmenu_exit1.png"));
    hoverExit = true;
  if ( leftButtonPressed )
    this->game->Close();
  }
  else
  {
   if (hoverExit)
   {
      hoverExit = false;
      exitSprite.setTexture(MB::Content::Load<sf::Texture>("mainmenu_exit2.png"));
   }
  }
  
  if (overStart)
  {
    hoverStart = true;
    start.setTexture(MB::Content::Load<sf::Texture>("mainmenu_start1.png"));
    if ( leftButtonPressed)
      this->game->SetState("PongGame");
   
  }
  else
  {
    if (hoverStart)
    {
      hoverStart = false;
      start.setTexture(MB::Content::Load<sf::Texture>("mainmenu_start2.png"));
    }
  }
  
}

void MainMenu::Update(sf::Time elapsed)
{
  
}

void MainMenu::DoEntre()
{
  std::cout << "Entering menu." << std::endl;

  
}

void MainMenu::DoExit()
{
  std::cout << "exiting menu" << std::endl;
}

