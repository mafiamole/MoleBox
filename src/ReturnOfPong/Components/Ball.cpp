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


#include <ReturnOfPong/Components/Ball.hpp>


Ball::Ball(MB::Game* game) : MB::GameComponent(game), playerScore(0), computerScore(0), acceleration(1.0f)
{
    this->sprite = sf::Sprite ( MB::Content::Load<sf::Texture>("ball.png") );
    this->sound = sf::Sound( MB::Content::Load<sf::SoundBuffer>("mouthpop.wav") );
    this->startPosition.x = (this->game->Window()->getSize().x / 2) - (this->sprite.getTextureRect().width / 2);
    this->startPosition.y = (this->game->Window()->getSize().y / 2) - (this->sprite.getTextureRect().height / 2);

    this->sprite.setPosition(startPosition);

    this->lowerBoundry = 0;
    this->upperBoundry = this->game->Window()->getSize().y - this->sprite.getTextureRect().height;

    srand( std::time(NULL) );
    this->direction.x = 1;
    this->direction.y = 1;
}

void Ball::ResetScores()
{
 
  this->computerScore =0;
  this->playerScore = 0;
  
}

void Ball::Update(sf::Time elapsed, MB::EventList* events)
{
    MB::GameComponent::Update(elapsed, events);

    sf::Vector2f moveVector;

    moveVector.x = this->direction.x * (elapsed.asMilliseconds() * 0.5f * acceleration);
    moveVector.y = this->direction.y * (elapsed.asMilliseconds() * 0.5f * acceleration);

    sf::Vector2f calculatedPositon;

    calculatedPositon.x = this->sprite.getPosition().x + moveVector.x;
    calculatedPositon.y = this->sprite.getPosition().y + moveVector.y;

    if ( calculatedPositon.y < this->lowerBoundry || calculatedPositon.y > this->upperBoundry) {
        moveVector.y = moveVector.y * -1.0f; // flip the direction
        this->direction.y = this->direction.y * -1.0f;
        calculatedPositon.y = this->sprite.getPosition().y + moveVector.y;
    }


    bool playerIntercepted = this->InterceptPlayer(calculatedPositon,moveVector);
    bool enemyIntercepted = this->IntereptEnemy(calculatedPositon,moveVector);

    if ( playerIntercepted || enemyIntercepted )
    {
        moveVector.x = moveVector.x * -1.0f; // flip the direction
        this->direction.x = this->direction.x * -1.0f;
        calculatedPositon.x = this->sprite.getPosition().x + moveVector.x;
        this->sprite.setPosition(calculatedPositon);
        if (playerIntercepted)
            this->sound.setPosition(-15.0f,0,0);
        else
            this->sound.setPosition(15.0f,0,0);
        this->sound.play();
        this->acceleration += 0.05f;
    }

    if ( calculatedPositon.x < 0 || calculatedPositon.x > this->game->Window()->getSize().x)
    {
        this->sprite.setPosition(this->startPosition);
        this->direction.x = 1;
        this->direction.y = 1;
        if (calculatedPositon.x < 0)
            this->computerScore++;
        else
            this->playerScore++;
        acceleration = 1.0f;
    }
    else
    {
        this->sprite.setPosition(calculatedPositon);
    }

}

void Ball::Draw()
{
    MB::GameComponent::Draw();

    this->game->DrawAsset(this->sprite);

}

Ball::~Ball()
{

}

void Ball::SetOpponents(Player* player,Enemy* enemy)
{
    this->player = player;
    this->enemy = enemy;
}

sf::Vector2f Ball::GetPosition()
{
  return this->sprite.getPosition();
}
int Ball::PlayerScore()
{
  return this->playerScore;
}
int Ball::ComputerScore()
{
  return this->computerScore;
}

bool Ball::InterceptPlayer(sf::Vector2f calculatedPositon, sf::Vector2f moveVector)
{
  sf::FloatRect rect,player;
  rect = this->sprite.getGlobalBounds();
  
  player = this->player->GetHitBox();

  bool interception = false;  
  
  if ( player.intersects(rect) )
    interception = true;

  return interception;
}

bool Ball::IntereptEnemy(sf::Vector2f calculatedPositon, sf::Vector2f moveVector)
{
  sf::FloatRect rect,enemy;
  
  rect = this->sprite.getGlobalBounds();
  enemy = this->enemy->GetHitBox();

  bool interception = false;

  
  if ( enemy.intersects(rect) )
    interception = true;

  return interception;  
}
