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


#include <MoleBox/SMGame.hpp>

namespace MB
{


	SMGame::SMGame(std::string windowName, int argc, char** argv, bool preventArgOverwrite) : 
	  Game(windowName,argc,argv,preventArgOverwrite)
	{
	}

	SMGame::~SMGame() {}

	void SMGame::Update(sf::Time elapsed, MB::EventList* events)
	{
		MB::Game::Update(elapsed, events);
    
		if (this->initalised)
		  this->currentState->Update(elapsed,events);
	}

	void SMGame::Draw()
	{
	  this->currentState->Draw();
		MB::Game::Draw();

	}
	sf::RenderWindow* SMGame::Window()
	{
		return this->window;
	}
	void SMGame::AddState(GameState* state)
	{
	  this->states.insert( std::pair<std::string,GameState*>(state->GetName(),state) );
	}

	void SMGame::SetState(std::string name)
	{
  
		if ( this->initalised)
		{
		  this->currentState->DoExit();
		}
		if (this->states.find(name) != this->states.end())
		{
		  this->currentState = this->states[name];
		  this->currentState->DoEntre();
		  this->initalised = true;
		}
		else
		{
		  throw "State was not found";
		}
	}

	int SMGame::Run()
	{
		EventList eventList;
    
		this->window->setFramerateLimit(60);

		sf::Time elapsed = clock.restart();

		while ( this->window->isOpen() )
		{

			sf::Event event;

			while ( window->pollEvent(event) )
			{
				if ( event.type == sf::Event::Closed )
					window->close();
	//       else if ( event.type = sf::Event::Resized )
	// 	this->windowResized = true;
			else
			  eventList.insert( std::pair< sf::Event::EventType,sf::Event >( event.type,event ) );

		}

			window->clear();

			this->Update( elapsed , &eventList );

			this->Draw();

			this->window->display();

			eventList.clear();

			elapsed = clock.restart();

		}

		return 0;
	}
}
