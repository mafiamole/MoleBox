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


#include <ReturnOfPong/PongGame.hpp>
#include <ReturnOfPong/Game.hpp>




PongGame::PongGame(std::string name, MB::SMGame* sfm): GameState(name,sfm)
{
    this->player = (Player*)this->AddComponent(new Player(sfm));
    this->enemy = (Enemy*)this->AddComponent(new Enemy(sfm));
    this->ball = (Ball*)this->AddComponent(new Ball(sfm));
    this->gameHUD = (HUD*)this->AddComponent(new HUD("ui.lua",sfm));
    this->gameHUD->SetBall(ball);
    this->enemy->SetBall(ball);
    this->ball->SetOpponents(player,enemy);
    this->wonMessage.setString("No one");
    this->finished = false;
    
    
}

void PongGame::Update(sf::Time elapsed, MB::EventList* events)
{
 
   if (this->game->GetActions()->Get("Close")->IsActive())
     game->SetState("MainMenu");
   
    if (finished) {
      if (events->find(sf::Event::MouseButtonPressed) != events->end())
      {
	this->game->SetState("MainMenu");
      }
    }
    else 
    {
        int pScore = ball->PlayerScore();
        int cScore = ball->ComputerScore();

        if (pScore >= 10)
        {
            this->wonMessage.setString("Player has won!");
            this->wonMessage.setCharacterSize(50);
            sf::Vector2f newPos;
            newPos.x = (this->game->Window()->getSize().x / 2)  - ( this->wonMessage.getGlobalBounds().width / 2) ;
            newPos.y = (this->game->Window()->getSize().x / 2)  - ( this->wonMessage.getGlobalBounds().width / 2) ;

            this->wonMessage.setPosition( newPos );
            this->finished = true;
        }

        if (cScore >= 10)
        {
            this->wonMessage.setString("Computer has won!");
            sf::Vector2f newPos;
            this->wonMessage.setCharacterSize(50);
            newPos.x = (this->game->Window()->getSize().x / 2)  - ( this->wonMessage.getGlobalBounds().width / 2) ;
            newPos.y = (this->game->Window()->getSize().x / 2)  - ( this->wonMessage.getGlobalBounds().width / 2) ;
            this->wonMessage.setPosition( newPos );
            this->finished = true;
        }
        MB::GameState::Update(elapsed, events);
    }
    
}

void PongGame::Draw()
{
    MB::GameState::Draw();
    if (finished)
    {
        this->game->DrawAsset(wonMessage);
    }
}


void PongGame::DoEntre()
{
    MB::GameState::DoEntre();
    
    this->finished = false;
    ball->ResetScores();
}

void PongGame::DoExit()
{
    MB::GameState::DoExit();
}

void PongGame::Update(sf::Time elapsed)
{
}

