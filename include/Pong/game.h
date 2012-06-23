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


#ifndef GAME_H
#define GAME_H
#include <stdlib.h>


#include <MoleBox/GameComponent.hpp>
#include <MoleBox/Content/Resources.hpp>
#include "lua.hpp"

#include "ball.h"
#include "enemy.h"
#include "player.h"
#include "ui.h"

#ifdef LUA_EDITOR
  #include <MoleBox/Lua/Scripts.hpp>
#endif

class Game : public MB::Game
{
protected:
  Player* player;
  Enemy* enemy;
  Ball* ball;
  UI  * ui;
  bool finished;
  sf::Text won;
public:
    Game();
    void Update( sf::Time elapsed, MB::Types::EventList* events);
    void Draw();
    int Run(int argc,char** argv);

    virtual ~Game();
   

};

#endif // GAME_H