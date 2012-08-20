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


#include <ReturnOfPong/Components/Enemy.hpp>
#include <ReturnOfPong/Components/Ball.hpp>

Enemy::Enemy(MB::Game* game) : GameComponent(game), upperBoundry(0),lowerBoundry(game->Window()->getSize().y)
{
  this->sprite = sf::Sprite( MB::Content::Load<sf::Texture>("paddle.png") );
  
  horiziontalPos = this->game->Window()->getSize().x - 30 - this->sprite.getTextureRect().width;

  this->sprite.setPosition(horiziontalPos,(this->game->Window()->getSize().y / 2) - (this->sprite.getTextureRect().height /2 ) );

}

void Enemy::Update(sf::Time elapsed, MB::EventList* events)
{
    MB::GameComponent::Update(elapsed, events);
    
    int halfWayX = this->game->Window()->getSize().x / 2;
    //std::cout << halfWayX << std::endl;

    int direction = 0;
    
    float centrePos = this->sprite.getPosition().y  + (this->sprite.getTextureRect().height / 2); 
    
    //determin the movement direction depending on if the ball is in the other half of the cort or not.
    
    if ( ball->GetPosition().x < halfWayX)
      direction = this->ApprochCentre(centrePos);
    else
      direction = this->InterceptBall(centrePos);
    

    // update position
    
    float dy =  (direction * (int)elapsed.asMilliseconds() * 0.5f );
    
    sf::Vector2f position = this->sprite.getPosition();
    
    position.y = position.y + dy;
  
    if ( position.y < upperBoundry)
    {
      sprite.setPosition(horiziontalPos,upperBoundry + 1 );
      
    }
    else if ( (position.y + this->sprite.getTextureRect().height)
	      > lowerBoundry )
    {
      sprite.setPosition(horiziontalPos,lowerBoundry - (this->sprite.getTextureRect().height + 1) );
    }
    else
    {
      this->sprite.setPosition(position);
    }
    
}

void Enemy::Draw()
{
    MB::GameComponent::Draw();
    
    this->game->DrawAsset(this->sprite);
}

Enemy::~Enemy()
{

}

void Enemy::SetBall(Ball* ball)
{

  this->ball = ball;
}

const sf::Vector2f& Enemy::getPosition()
{
  return this->sprite.getPosition();
}

sf::FloatRect Enemy::GetHitBox()
{
  return this->sprite.getGlobalBounds();
}

int Enemy::InterceptBall(float playerYCentre)
{
  float ballyPos = this->ball->GetPosition().y;
  if ( playerYCentre > ballyPos)
  {
    return -1;
  }
  else
  {
    return 1;
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