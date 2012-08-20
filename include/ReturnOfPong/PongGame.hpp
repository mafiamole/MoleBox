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


#ifndef PONGGAME_HPP
#define PONGGAME_HPP

#include <MoleBox/SMGame.hpp>
#include <ReturnOfPong/Components/Player.hpp>
#include <ReturnOfPong/Components/Enemy.hpp>
#include <ReturnOfPong/Components/Ball.hpp>
#include <ReturnOfPong/Components/HUD.hpp>

class PongGame : public MB::GameState
{
  Player* player;
  Enemy* enemy;
  Ball* ball;
  bool finished;
  sf::Text wonMessage;
  HUD* gameHUD;
public:
    PongGame(std::string name, MB::SMGame* sfm);
    virtual void Draw();
    virtual void Update(sf::Time elapsed, MB::EventList* events);
    virtual void DoEntre();
    virtual void DoExit();
    virtual void Update(sf::Time elapsed);
};

#endif // PONGGAME_HPP