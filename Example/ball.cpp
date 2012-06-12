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


#include "ball.h"
#include "../src/MoleBox/Game.h"
#include "../src/MoleBox/Content/Content.h"
#include <cstdlib>
#include <ctime>

Ball::Ball(MB::Game* game) : MB::GameComponent(game)
{
  this->sprite = MB::Content::NewSprite("ball.png");
  this->startPosition.x = (this->game->Window()->getSize().x / 2) - (this->sprite.getTextureRect().width / 2);
  this->startPosition.y = (this->game->Window()->getSize().y / 2) - (this->sprite.getTextureRect().height / 2);
  
  this->sprite.setPosition(startPosition);
  
  this->lowerBoundry = 0;
  this->upperBoundry = this->game->Window()->getSize().y - this->sprite.getTextureRect().height;
  
  srand( std::time(NULL) );
  this->direction.x = 1;
  this->direction.y = 1;
  std::cout << this->direction.x << "," << this->direction.y << std::endl;
}

void Ball::SetOpponents(Player* player, Enemy* enemy)
{
  this->player = player;
  this->enemy = enemy;
}


void Ball::Update(sf::Time elapsed, MB::Types::EventList* events)
{
    MB::GameComponent::Update(elapsed, events);
    
    sf::Vector2f moveVector;
    
    moveVector.x = this->direction.x * (elapsed.asMilliseconds() * 0.5f);
    moveVector.y = this->direction.y * (elapsed.asMilliseconds() * 0.5f);
    
    sf::Vector2f calculatedPositon;
    
    calculatedPositon.x = this->sprite.getPosition().x + moveVector.x;
    calculatedPositon.y = this->sprite.getPosition().y + moveVector.y;
    
    if ( calculatedPositon.y < this->lowerBoundry or calculatedPositon.y > this->upperBoundry) {
      moveVector.y = moveVector.y * -1.0f; // flip the direction
      this->direction.y = this->direction.y * -1.0f;
      calculatedPositon.y = this->sprite.getPosition().y + moveVector.y;
    }
      
    if (this->InterceptPlayer(calculatedPositon,moveVector) or this->IntereptEnemy(calculatedPositon,moveVector) )
    {
      moveVector.x = moveVector.x * -1.0f; // flip the direction
      this->direction.x = this->direction.x * -1.0f;
      calculatedPositon.x = this->sprite.getPosition().x + moveVector.x;
      std::cout << "Interception with players detected" << std::endl;
      this->sprite.setPosition(calculatedPositon);
    }
    
    if ( calculatedPositon.x < 0 or calculatedPositon.x > this->game->Window()->getSize().x)
    {
      this->sprite.setPosition(this->startPosition);
        srand( std::time(NULL) );
        this->direction.x = 1;
	this->direction.y = 2;
    }
    else
    {
      this->sprite.setPosition(calculatedPositon);
    }
    
    //this->sprite.move(this->direction.x * elapsed.asMilliseconds() * 0.01, this->direction.y * elapsed.asMilliseconds() );
}

void Ball::Draw()
{
    MB::GameComponent::Draw();
    this->game->DrawSprite(this->sprite);
}

bool Ball::InterceptPlayer(sf::Vector2f calculatedPositon, sf::Vector2f moveVector)
{
  sf::IntRect rect,player;
  rect = this->sprite.getTextureRect();
  rect.top = this->sprite.getPosition().y;
  rect.left = this->sprite.getPosition().x;
  
  player = this->player->getHitBox();

  bool interception = false;  
  
  if ( player.intersects(rect) )
    interception = true;

  return interception;
}

bool Ball::IntereptEnemy(sf::Vector2f calculatedPositon, sf::Vector2f moveVector)
{
  sf::IntRect rect,enemy;
  
  rect = this->sprite.getTextureRect();
  rect.top = this->sprite.getPosition().y;
  rect.left = this->sprite.getPosition().x;  
  enemy = this->enemy->getHitBox();

  bool interception = false;

  
  if ( enemy.intersects(rect) )
    interception = true;

  return interception;  
}


sf::Vector2f Ball::getPosition()
{
  return this->sprite.getPosition();
}


