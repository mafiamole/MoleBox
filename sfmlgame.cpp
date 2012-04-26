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


#include "sfmlgame.h"
#include "sfmlgamecomponent.h"
#include <iostream>

SFMLGame::SFMLGame(std::string windowName)
{
  window = new sf::RenderWindow(sf::VideoMode(800,600),windowName);
}

SFMLGame::~SFMLGame()
{
  ComponentVector::iterator componentItr;
  // ensure all components are removed from memory.
  for (componentItr = components.begin(); componentItr != components.end(); componentItr++)
  {
    delete (*componentItr);
  }
  // empty pointers from container.
  components.clear();
}

void SFMLGame::Draw()
{

  ComponentVector::iterator componentItr;
  
  for (componentItr = components.begin(); componentItr != components.end(); componentItr++)
  {
    (*componentItr)->Draw();
  }
}

void SFMLGame::Update(EventList* events)
{
  ComponentVector::iterator componentItr;
  
  for (componentItr = components.begin(); componentItr != components.end(); componentItr++)
  {
    (*componentItr)->Update(events);
  }
  
}

sf::RenderWindow* SFMLGame::Window()
{
  return this->window;
}


void SFMLGame::Run()
{

  EventList eventList;
  while (this->window->isOpen())
  {
    sf::Event event;
    while ( window->pollEvent(event) )
    {
      if (event.type == sf::Event::Closed)
	window->close();
      else
	eventList.insert(std::pair<sf::Event::EventType,sf::Event>(event.type,event));
    }
    
    window->clear();
    this->Update(&eventList);
    
    this->Draw();
    
    this->window->display();
    
    eventList.clear();
    
  }
}

void SFMLGame::AddComponent(SFMLGameComponent* component)
{
  this->components.push_back(component);
}

int SFMLGame::ComponentCount()
{
  return this->components.size();
}

