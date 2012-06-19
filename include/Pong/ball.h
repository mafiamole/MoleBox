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


#ifndef BALL_H
#define BALL_H


#include <MoleBox/GameComponent.hpp>
#include <MoleBox/Content/Content.hpp>

#include "player.h"
#include "enemy.h"

class Player;
class Game;

class Ball : public MB::GameComponent
{
  sf::Sprite sprite;
  sf::Vector2f startPosition;
  sf::Vector2f direction;
  float lowerBoundry, upperBoundry;
  Player *player;
  Enemy *enemy;
  bool InterceptPlayer(sf::Vector2f calculatedPositon,sf::Vector2f moveVector);
  bool IntereptEnemy(sf::Vector2f calculatedPositon,sf::Vector2f moveVector);
  sf::Sound sound;
  int playerScore,computerScore;
  float acceleration;
public:
    Ball(MB::Game* game);
    void SetOpponents(Player* player,Enemy* enemy);
    sf::Vector2f getPosition();
    virtual void Update(sf::Time elapsed, MB::Types::EventList* events);
    virtual void Draw();
    int PlayerScore();
    int ComputerScore();
};

#endif // BALL_H
