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


#ifndef GAME_HPP
#define GAME_HPP

#include <MoleBox/SMGame.hpp>
#include <ReturnOfPong/MainMenu.hpp>
#include <ReturnOfPong/PongGame.hpp>
#include <MoleBox/ResourceUI/RUI_Thread.hpp>
class Game : public MB::SMGame
{

public:
    Game(std::string windowName, int argc, char** argv, bool preventArgOverwrite = false);
    virtual ~Game();
    virtual void Update(sf::Time elapsed, MB::EventList* events);
    virtual void Draw();
    int Run();
private:
    sf::Sprite bg;
    Args args;

};

#endif // GAME_HPP
