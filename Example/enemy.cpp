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

Enemy::Enemy(Game* game) : MB::GameComponent(game),
				  upperBoundry(0),
				  lowerBoundry( game->Window()->getSize().y )
{
  this->enemySprite = MB::Content::NewSprite("paddle.png");
  
  horiziontalPos = this->game->Window()->getSize().x - 30 - this->enemySprite.getTextureRect().width;
  this->enemySprite.setPosition(horiziontalPos,(this->game->Window()->getSize().y / 2) - (this->enemySprite.getTextureRect().height /2 ) );
}

void Enemy::SetBall(Ball* ball)
{
  this->ball = ball;
}


void Enemy::Update(sf::Time elapsed, MB::Types::EventList* events)
{
    MB::GameComponent::Update(elapsed, events);
    
    int halfWayX = this->game->Window()->getSize().x / 2;
    //std::cout << halfWayX << std::endl;

    int direction = 0;
    
    float centrePos = this->enemySprite.getPosition().y  + (this->enemySprite.getTextureRect().height / 2); 
    
    //determin the movement direction depending on if the ball is in the other half of the cort or not.
    
    if ( ball->getPosition().x < halfWayX)
      direction = this->ApprochCentre(centrePos);
    else
      direction = this->InterceptBall(centrePos);
    

    // update position
    
    float dy =  (direction * (int)elapsed.asMilliseconds() * 0.5f );
    
    sf::Vector2f position = this->enemySprite.getPosition();
    
    position.y = position.y + dy;
  
    if ( position.y < upperBoundry)
    {
      enemySprite.setPosition(horiziontalPos,upperBoundry + 1 );
      
    }
    else if ( (position.y + this->enemySprite.getTextureRect().height)
	      > lowerBoundry )
    {
      enemySprite.setPosition(horiziontalPos,lowerBoundry - (this->enemySprite.getTextureRect().height + 1) );
    }
    else
    {
      this->enemySprite.setPosition(position);
    }
    

  
}

int Enemy::ApprochCentre(float playerYCentre)
{   
    if ( playerYCentre  < ( (this->game->Window()->getSize().y / 2) - 10) )
    {
      return 1;
    }
    else if (playerYCentre  > ( (this->game->Window()->getSize().y / 2) + 10))
    {
      return -1;
    }
    else 
    {
      return 0;
    }

}

int Enemy::InterceptBall(float playerYCentre)
{
  float ballyPos = this->ball->getPosition().y;
  if ( playerYCentre > ballyPos)
  {
    return -1;
  }
  else
  {
    return 1;
  }
    
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

void Enemy::PrintPositon()
{
  std::cout << "Enemy Pos`:" << this->enemySprite.getPosition().x << "," << this->enemySprite.getPosition().y << std::endl;
}
