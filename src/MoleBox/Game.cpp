/*
    Copyright (c) 2012 Paul Brown mafiamole@gmail.com

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


#include "Game.h"
#include "GameComponent.h"
#include "Lua/luaeditor.h"
#include "Lua/LuaScriptHelper.h"
#include <iostream>

#ifdef LUA_EDITOR
 #include <QtGui/QApplication>

 void MB::LuaGUIThread ( args argList )
 {
  
  QApplication app(argList.argc,argList.argv);
  LuaEditor luaEditor;
  luaEditor.SetScripts(argList.scriptList);
  luaEditor.SetScript(argList.startScript);
  luaEditor.show();
  
  int result = app.exec();
  
 }
 
#endif

MB::Game::Game(std::string windowName)
{
  window = new sf::RenderWindow( sf::VideoMode( 800, 600 ), windowName );

}

MB::Game::~Game()
{
  ComponentVector::iterator componentItr;
  // ensure all components are removed from memory.
  for ( componentItr = components.begin(); componentItr != components.end(); componentItr++ )
  {
    delete ( *componentItr );
  }
  // empty pointers from container.
  components.clear();

}

void MB::Game::Draw()
{

  ComponentVector::iterator componentItr;
  
  for (componentItr = components.begin(); componentItr != components.end(); componentItr++)
  {
    (*componentItr)->Draw();
  }
  
}

void MB::Game::Update(sf::Time elapsed, MB::EventList* events)
{
  ComponentVector::iterator componentItr;
  
  for ( componentItr = components.begin(); componentItr != components.end(); componentItr++ )
  {
    ( *componentItr )->Update( elapsed, events );
  }
  
  this->actionList.Update();
  
}

sf::RenderWindow* MB::Game::Window()
{
  return this->window;
}


void MB::Game::Run(int argc, char** argv)
{
  EventList eventList;
#ifdef LUA_EDITOR
  args argList;
  argList.argc = argc;
  argList.argv = argv;
  argList.scriptList = this->GetScripts();
  argList.startScript = this->GetScript(argList.scriptList[0]);
  sf::Thread qtThread( &MB::LuaGUIThread,argList);
  qtThread.launch();
#endif

  clock.restart();
 
  while ( this->window->isOpen() )
  {
    
    sf::Event event;
    sf::Time elapsed = clock.restart();
    while ( window->pollEvent(event) )
    {
      
      if ( event.type == sf::Event::Closed )
	window->close();
      else
	eventList.insert( std::pair< sf::Event::EventType,sf::Event >( event.type,event ) );

    }
    
    window->clear();
    
    this->Update( elapsed, &eventList );
    
    this->Draw();

    this->window->display();
    
    eventList.clear();
    
  }
  
#ifdef LUA_EDITOR
  qtThread.wait();
#endif
}

void MB::Game::AddComponent(GameComponent* component)
{
  this->components.push_back(component);
}

int MB::Game::ComponentCount()
{
  return this->components.size();
}

void MB::Game::DrawSprite(const sf::Drawable& drawable, const sf::RenderStates& states)
{
  this->window->draw(drawable,states);
}

MB::Actions* MB::Game::GetActions()
{
  return &this->actionList;
}

#ifdef LUA_EDITOR

std::vector< std::string > MB::Game::GetScripts()
{
  return LuaHelper::LuaScripts::Instance().ScriptList();
}

std::string MB::Game::GetScript(std::string name)
{
  return LuaHelper::LuaScripts::Instance().GrabScript( name );
}


#endif
