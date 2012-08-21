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

#include <MoleBox/Lua/Container.hpp>
#include <MoleBox/Lua/Component.hpp>
#include <MoleBox/Lua/Arguments/ActionsArg.hpp>
#include <MoleBox/Game.hpp>

namespace MB
{
	namespace Lua
	{

		Component::Component(std::string filename, MB::Game* game) 
		: MB::GameComponent(game) , spritesContainer( game->Window() ), textContainer( game->Window(), sf::Font() )
		{
		  this->script = MB::Content::Load<MB::Lua::Script*>(filename);
		  
		  this->script->AddFunction("");  
		  this->script->AddFunction("draw");
		  this->script->AddFunction("init");
		  this->script->AddFunction("update");
		  
		  this->script->GetFunc("update")->AddArg("elapsed",0.0f);
		  this->script->GetFunc("update")->AddArg("events",new ActionsArg(this->game->GetActions()->GetList()));
  		  
// 		  this->script.RegisterLibrary("Window",SFML::window_reg);
// 		  this->script.RegisterLibrary("Sprites",SFML::sprite_Reg);
// 		  this->script.RegisterLibrary("Text",SFML::text_reg);
// 		  this->script.RegisterLibrary("Sound",SFML::sound_reg);
// 		  this->script.RegisterLibrary("Music",SFML::music_reg);
//   
		  SFML::RegisterWindow(this->script);
		  SFML::RegisterMusic(this->script);
		  SFML::RegisterSound(this->script);
		  SFML::RegisterSprites(this->script);
		  SFML::RegisterText(this->script);
		  
		  this->script->LoadFromFile(filename);
   
		  lua_State* L = this->script->GetState();
  
		  SetUserDataToRegistry<Containers::Music>	(L ,Containers::Music::RegRef	,&this->musicContainer);
		  SetUserDataToRegistry<Containers::Sounds>	(L ,Containers::Sounds::RegRef	,&this->soundContainer);
		  SetUserDataToRegistry<Containers::Sprites>	(L ,Containers::Sprites::RegRef	,&this->spritesContainer);
		  SetUserDataToRegistry<Containers::Text>	(L ,Containers::Text::RegRef	,&this->textContainer);
		  SetUserDataToRegistry<sf::RenderWindow>	(L ,"SFML_GAME_WINDOW"		,this->game->Window());
  
		  this->script->FuncCall("");
		  this->script->FuncCall("init");
  
		}


		Component::~Component()
		{

		}

		void Component::Draw()
		{
		  this->script->FuncCall("draw");
		  this->spritesContainer.Draw();
		  this->textContainer.Draw();

		}

		void Component::PushUpdateArgs(sf::Time elapsed,MB::EventList*events)
		{
		  this->script->GetFunc("update")->SetArg("elapsed",elapsed.asMilliseconds());
		  this->script->GetFunc("update")->GetArg("events")->Set(events); 
		}

		void Component::Update( sf::Time elapsed,MB::EventList *events )
		{
		  this->PushUpdateArgs(elapsed,events);
		  this->script->FuncCall("update");
		}
	}
}