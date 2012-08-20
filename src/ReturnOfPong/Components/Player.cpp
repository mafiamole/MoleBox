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


#include <ReturnOfPong/Components/Player.hpp>




Player::Player(MB::Game* game) : MB::GameComponent(game), lowerBoundry(game->Window()->getSize().y),upperBoundry(0)
{
  sprite = sf::Sprite( MB::Content::Load<sf::Texture>("paddle.png") );
  
  sprite.setPosition(30,1);
  
    if ( this->game->GetActions()->Exists("Player Move Up") )
      this->up =this->game->GetActions()->Get("Player Move Up");
    else
      throw "no action exists";
    
    if ( this->game->GetActions()->Exists("Player Move Down") ) 
      this->down = this->game->GetActions()->Get("Player Move Down");
    else
      throw "No action exists";
}

Player::~Player()
{

}

void Player::Update(sf::Time elapsed, MB::EventList* events)
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
    
    float vector =  direction * 0.5f * (float)elapsed.asMilliseconds() * 0.5f;
    
    //std::cout << "Player vector" << vector << std::endl;
    
    sf::Vector2f playerPos = this->sprite.getPosition();
    
    playerPos.y = playerPos.y + vector;
    
    if ( playerPos.y < upperBoundry)
    {
      vector = 0;
      sprite.setPosition(30,upperBoundry + 1 );
      
    }
    else if ( (playerPos.y + this->sprite.getTextureRect().height)
	      > lowerBoundry )
    {
      vector = 0;
      sprite.setPosition(30,lowerBoundry - (this->sprite.getTextureRect().height + 1) );
    }
    else
    {
      vector = vector;
    }

    this->sprite.move(0, vector );
    
}

void Player::Draw()
{
    MB::GameComponent::Draw();
    this->game->DrawAsset(this->sprite);
}

sf::FloatRect Player::GetHitBox()
{
  return this->sprite.getGlobalBounds();
}

