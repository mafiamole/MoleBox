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
#include "../src/MoleBox/Content/Content.h"
#include "../src/MoleBox/Game.h"
#include <iostream>

Player::Player(MB::Game* game) : MB::GameComponent(game),
				  upperBoundry(0),
				  lowerBoundry( game->Window()->getSize().y )
{
    playerSprite = MB::Content::NewSprite("paddle.png");
    
    if ( this->actions->Exists("Player Move Up") )
      this->up = this->actions->Get("Player Move Up");
    
    if (this->actions->Exists("Player Move Up") )
      this->down = this->actions->Get("Player Move Down");
    
    this->playerSprite.setPosition(30,1);

  
}

void Player::Update(sf::Time elapsed, MB::Types::EventList* events)
{
    MB::GameComponent::Update(elapsed, events);

    short int direction;
    
    if ( this->up->IsActive() && !this->down->IsActive() )
    {
      direction = -1;
    }
    else if (!this->up->IsActive() && this->down->IsActive())
    {
      direction = 1;
    }
    else 
    {
      direction = 0;
    }
    
    float vector =  direction * (int)elapsed.asMilliseconds() * 0.5f;
    
    sf::Vector2f playerPos = this->playerSprite.getPosition();
    
    playerPos.y = playerPos.y + vector;
    
    if ( playerPos.y < upperBoundry)
    {
      vector = 0;
      playerSprite.setPosition(30,upperBoundry + 1 );
      
    }
    else if ( (playerPos.y + this->playerSprite.getTextureRect().height)
	      > lowerBoundry )
    {
      vector = 0;
      playerSprite.setPosition(30,lowerBoundry - (this->playerSprite.getTextureRect().height + 1) );
    }
    else
    {
      vector = vector;
    }

    this->playerSprite.move(0, vector );

}

sf::IntRect Player::getHitBox()
{
  sf::IntRect rect;
  
  rect = this->playerSprite.getTextureRect();
  
  rect.left = this->playerSprite.getPosition().x;
  rect.top = this->playerSprite.getPosition().y;
  
  return rect;
}

const sf::Vector2f& Player::getPosition()
{
  return this->playerSprite.getPosition();
}


void Player::Draw()
{
  
  this->game->DrawSprite(this->playerSprite);
  
  MB::GameComponent::Draw();
  
}

Player::~Player()
{

}

