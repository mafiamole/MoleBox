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


#include "player.h"
#include "../src/MoleBox/Game.h"

Player::Player(MB::Game* game) : MB::GameComponent(game), sprite(MB::Content<sf::Texture>::Load("player.png"),60,60), animator(&this->sprite)
{
  this->sprite.setPosition(0,200);
    this->animator.SetLoopSpeed(200);
    this->animator.AddAnimation("Left", 6,0,1,2,3,4,5);
    this->animator.AddAnimation("Right",6,5,4,3,2,1,0);
    std::cout << sf::Texture::getMaximumSize( ) << std::endl;
}

void Player::Update(sf::Time elapsed, MB::EventList* events)
{

  MB::GameComponent::Update(elapsed, events);
  
  MB::Action* moveLeft = this->game->GetActions()->Get("Player Move Left");
  MB::Action* moveRight = this->game->GetActions()->Get("Player Move Right");

  float newX = direction * 0.4 * elapsed.asMilliseconds();
  
  if (moveLeft->IsActive() && !moveRight->IsActive())
  {
    if (moveLeft->HasChanged()) {
      this->animator.Play("Left");
    }
    direction = -1;
  }
  else if (!moveLeft->IsActive() && moveRight->IsActive())
  {
    if (moveRight->HasChanged()) {
      this->animator.Play("Right");
    }
    direction = 1;
  }
  else
  {
    this->animator.Stop();
    direction = 0;
  }
  this->animator.Update();
 
  this->sprite.move(newX,0.0f);
 
}

void Player::Draw()
{
  
  MB::GameComponent::Draw();
  
  this->game->Window()->draw(this->sprite);
  
}


Player::~Player()
{

}

