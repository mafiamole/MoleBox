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


#include <ReturnOfPong/Components/HUD.hpp>

HUD::HUD(std::string filename, MB::Game* game): MB::Lua::Component(filename,game)
{
  this->textContainer.SetFont("DroidSans.ttf");
  this->script->GetFunc("update")->AddArg("playerScore",0);
  this->script->GetFunc("update")->AddArg("computerScore",0);
}

HUD::~HUD()
{
  
}

void HUD::Update(sf::Time elapsed, MB::EventList* events)
{
   this->PushUpdateArgs(elapsed,events);
  int playerScore = this->ball->PlayerScore();
  int computerScore = this->ball->ComputerScore();
  
  MB::Lua::Function* update = this->script->GetFunc("update");
  
  update->SetArg("playerScore",playerScore);
  update->SetArg("computerScore",computerScore);
 
  lua_State* L = this->script->GetState();
 // update = this->script.GetFunc("update");
  update->InitCall(L,"update",false);
  update->PushArg(L,"elapsed");
  update->PushArg(L,"events");
  update->PushArg(L,"playerScore");
  update->PushArg(L,"computerScore");
  update->FinishCall(0);
}

void HUD::Draw()
{
    MB::Lua::Component::Draw();
}

void HUD::SetBall(Ball*ball)
{
  this->ball = ball;
}
