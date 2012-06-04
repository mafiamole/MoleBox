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
#include "testcomponent.h"
#include "../src/MoleBox/Actions/keyboard.h"
#include <iostream>

TestComponent::TestComponent(MB::Game* game): MB::GameComponent(game)
{
  
  texture 	= MB::Content< sf::Texture >::Load( "test.png" );
  
  sprite 	= sf::Sprite(texture);
  sprite2	= sf::Sprite(texture);
  sprite2.move(sprite.getTextureRect().width,0);
  
  music		= MB::Content< sf::Music >::Open( "menu.ogg" );
  musicPaused  	= true;
  
  spriteBatch	= new MB::SpriteBatch(this->game->Window());
  sound		= sf::Sound(MB::Content< sf::SoundBuffer >::Load( "mouthpop.wav" ));
  
  spriteBatch->push_back(&sprite);
  spriteBatch->push_back(&sprite2);
}

TestComponent::~TestComponent()
{
  
  delete spriteBatch;
  
  music->stop();

}

void TestComponent::Update(sf::Time elapsed, MB::EventList* events)
{
  
  MB::GameComponent::Update(elapsed,events);

  MB::Action* tempAction = this->actions->Get("Play Music");
/*  
  if ( !tempAction->IsActive() && tempAction->HasChanged() )
  {
    musicPaused = !musicPaused;
    if (musicPaused) {
      music->pause();
    }
    else {
      music->play();
    }      
  }
*/
/*
  if ( !this->actions->Get("Play Sound")->IsActive() && this->actions->Get("Play Sound")->HasChanged() )
    sound.play();
*/
}

void TestComponent::Draw()
{
  
  this->spriteBatch->Draw();

  MB::GameComponent::Draw();

}


