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

	GameState::GameState(std::string name, SMGame* sfm) : MB::SM::State(name,sfm) , game(sfm)
	{
  
	}

	GameState::~GameState()
	{
  
	}

	void GameState::Draw()
	{
	  this->DrawComponents();
	}

	void GameState::Update(sf::Time elapsed, MB::EventList* events)
	{
	  this->UpdateComponents(elapsed,events);
	}

	void GameState::DoEntre()
	{
  
	}

	void GameState::DoExit()
	{
  
	}

	MB::GameComponent * GameState::AddComponent(MB::GameComponent * component)
	{
	  this->components.push_back(component);

	  return component;
	}

	void GameState::DeleteComponents()
	{
	  MB::ComponentList::iterator itr;
  
	  for (itr = components.begin(); itr != components.end(); itr++)
	  {
		delete (*itr);
	  }
  
	  this->components.clear();
	}

	int GameState::ComponentCount()
	{
	  return this->components.size();
	}

	void GameState::UpdateComponents(sf::Time elapsed, MB::EventList* events)
	{
	  MB::ComponentList::iterator itr;
  
	  for (itr = components.begin(); itr != components.end(); itr++)
	  {
		(*itr)->Update(elapsed,events);
	  }
	}

	void GameState::DrawComponents()
	{
	  MB::ComponentList::iterator itr;
  
	  for (itr = components.begin(); itr != components.end(); itr++)
	  {
    
		(*itr)->Draw();
	  } 
	}

}