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


#include "enemy.h"
#include "game.h"
#include "../src/MoleBox/Game.h"
#include "../src/MoleBox/Content/Content.h"

Enemy::Enemy(MB::Game* game) : MB::GameComponent(game),
				  upperBoundry(0),
				  lowerBoundry( game->Window()->getSize().y )
{
  this->enemySprite = MB::Content::NewSprite("paddle.png");
  
  horiziontalPos = this->game->Window()->getSize().x - 30 - this->enemySprite.getTextureRect().width;
  
  this->enemySprite.setPosition(horiziontalPos,1);
}

void Enemy::SetBall(Ball* ball)
{
  this->ball = ball;
}


void Enemy::Update(sf::Time elapsed, MB::Types::EventList* events)
{
    MB::GameComponent::Update(elapsed, events);
    
    if (this->enemySprite.getPosition().y != this->ball->getPosition().y)
      this->enemySprite.setPosition(horiziontalPos,this->ball->getPosition().y - (this->enemySprite.getTextureRect().height / 2));
}


sf::IntRect Enemy::getHitBox()
{
  sf::IntRect hitBox;
  
  hitBox = this->enemySprite.getTextureRect();
  hitBox.left = this->getPosition().x;
  hitBox.top = this->getPosition().y;
  
  return hitBox;
}

const sf::Vector2f& Enemy::getPosition()
{
  return this->enemySprite.getPosition();
}


void Enemy::Draw()
{
    MB::GameComponent::Draw();
    
    this->game->DrawSprite(this->enemySprite);
}

Enemy::~Enemy()
{

}

