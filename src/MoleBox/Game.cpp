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


#include <MoleBox/Game.hpp>
#include <MoleBox/GameComponent.hpp>
#include <iostream>

namespace MB
{

	Game:: Game(std::string windowName, int argc, char** argv, bool preventArgOverwrite) :
		windowName(windowName),
		clock(),
		config()
	{

		this->AddToConfig(argc,argv);
    
		this->SetupWindow();

	}

	Game::~Game()
	{

	}

	void Game::Update(sf::Time elapsed, EventList* events)
	{
  
	  this->actions.Update(elapsed,events);
	  this->UpdateComponents(elapsed,events);
	}

	void Game::Draw()
	{
	  this->DrawComponents();
	}

	int Game::Run()
	{
		EventList eventList;
		this->window->setFramerateLimit(60);
		//clock.restart();
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

	void Game::SetupWindow()
	{
		sf::VideoMode videoMode;
		if (this->config.find("resolution") != this->config.end() && !this->preventArgOverwrite)
		{
			std::string resolution = this->config["resolution"];

			//somehow convert the string to unsigned integers

			std::string x,y;
			std::allocator< char >::size_type dividerPos = resolution.find("x");
			x = resolution.substr(0,dividerPos -1);
			y = resolution.substr(dividerPos+1);

			videoMode = sf::VideoMode( atoi( x.c_str() ) ,atoi( y.c_str() ),32);
		}
		else
		{
			videoMode = sf::VideoMode(800,600,32);
		}

		int style;

		if (this->config.find("fullscreen") != this->config.end())
		{
			if ( this->config["fullscreen"] == "true")
				style = sf::Style::Fullscreen;
			else
				style = sf::Style::Default;
		}
		else
		{
			style = sf::Style::Default;
		}

		this->window = new sf::RenderWindow(videoMode,this->windowName);
	}

	void Game::AddToConfig ( int argc, char **argv)
	{

	  for (int argCounter = 0; argCounter < argc; argCounter++)
		{
			std::string arg = argv[argCounter];
			std::allocator< char >::size_type valuePos = arg.find("=");
			std::allocator< char >::size_type dashPos = arg.find("-");
			std::string name = arg.substr(dashPos + 1, valuePos - 1);
			std::string value = arg.substr( valuePos + 1 );
			this->config.insert( std::pair<std::string,std::string>(name,value) );
		}

	}

	sf::RenderWindow* Game::Window()
	{
		return this->window;
	}

	void Game::Close()
	{
		this->window->close();
	}


	MB::GameComponent * Game::AddComponent(MB::GameComponent *component)
	{
	  this->components.push_back(component);
	  return component;
	}

	int Game::ComponentCount()
	{
	  return this->components.size();
	}

	void Game::DeleteComponents()
	{
	  ComponentList::iterator itr;
  
	  for ( itr = this->components.begin(); itr != this->components.end(); itr++ )
	  {
		delete (*itr);
	  }
	  this->components.clear();
	}

	void Game::UpdateComponents(sf::Time elapsed, EventList *events)
	{
	  ComponentList::iterator itr;
  
	  for ( itr = this->components.begin(); itr != this->components.end(); itr++ )
	  {
		(*itr)->Update(elapsed,events);
	  }
    
	}

	void Game::DrawComponents()
	{
	  ComponentList::iterator itr;
  
	  for ( itr = this->components.begin(); itr != this->components.end(); itr++ )
	  {
		(*itr)->Draw();
	  }
  
	}

	Actions::Actions* Game::GetActions()
	{
	  return &this->actions;
	}

	void Game::DrawAsset(const sf::Drawable& drawable, const sf::RenderStates& states)
	{
  
	  this->window->draw(drawable,states);
  
	}
}