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


#include <MoleBox/Lua/Containers.hpp>
#include <MoleBox/Content/Content.hpp>
#include <iostream>

namespace MB
{
	namespace Lua
	{
		namespace Containers
		{


			const char* Sprites::RegRef 	= "SFML_SPRITES_CONTAINER";
			const char* Text::RegRef 	= "SFML_TEXT_CONTAINER";
			const char* Sounds::RegRef 	= "SFML_SOUNDS_CONTAINER";
			const char* Music::RegRef	= "SFML_MUSIC_CONTAINER";

			Sprites::Sprites(sf::RenderTarget* target) : target(target) , spriteList() , listCounter(1)
			{
				this->listCounter = 1;
			}

			Sprites::~Sprites()
			{
			}

			sf::Sprite* Sprites::Add(std::string filename)
			{

				this->spriteList.push_back( sf::Sprite( MB::Content::Load<sf::Texture>(filename) ) );

				std::list< sf::Sprite >::iterator key = this->spriteList.end();
				--key;
				return &(*key);

			}


			void Sprites::AppendToDrawList( sf::Sprite* ref)
			{
				this->renderList.push_back( ref );
			}

			void Sprites::Draw()
			{
				std::list<sf::Sprite*>::iterator spriteItr;

				for (spriteItr = renderList.begin(); spriteItr != renderList.end(); ++spriteItr++)
				{
					sf::Sprite sprite = *(*spriteItr);
					this->target->draw( sprite );

				}
				this->renderList.empty(); // remove all sprite references from list.
			}



			Text::Text(sf::RenderTarget* target, sf::Font font) : target(target), textList() , listCounter(0), defaultFont(font)
			{

			}

			Text::~Text()
			{

			}

			sf::Text* Text::Create(std::string value)
			{
			//   int key = listCounter;
			//   this->text.insert( std::pair<int,sf::Text>( key, sf::Text( sf::String( value.c_str() ) ) ) );
			//   listCounter++;
			
				this->textList.push_back(  sf::Text( sf::String( value.c_str() ), defaultFont ) );

				std::list< sf::Text >::iterator key = this->textList.end();
				--key;
				return &(*key);
			}

			void Text::Draw()
			{

				std::list<sf::Text*>::iterator textItr;

				for (textItr = renderList.begin(); textItr != renderList.end(); textItr++)
				{

					this->target->draw( *(*textItr) );

				}
				this->renderList.empty(); // remove all sprite references from list.
			}

			void Text::AppendToDrawList( sf::Text* ref )
			{
				this->renderList.push_back( ref );
			}
			
			void Text::SetFont( std::string file )
			{
			  this->defaultFont.loadFromFile(file);
			}

			// sf::Text* Text::Get(int ref)
			// {
			//   if ( this->text.find(ref) != this->text.end() )
			//   {
			//     return &this->text[ref];
			//   }
			//   return 0;
			// }

			Sounds::Sounds() : soundList() , listCounter(0)
			{

			}

			Sounds::~Sounds()
			{

			}

			sf::Sound* Sounds::Load(std::string filename)
			{

			   // int key =listCounter;

				//this->sounds.insert( std::pair<int, sf::Sound> ( std::pair<int,sf::Sound>( key ,  sf::Sound( MB::Content::Load<sf::SoundBuffer>(filename) ) ) ) );
				this->soundList.push_back( sf::Sound( MB::Content::Load<sf::SoundBuffer>(filename) ) );
				std::list< sf::Sound >::iterator itr = this->soundList.end();
				--itr;
				return &(*itr);

			}


			Music::Music() : musicList() , listCounter(0)
			{


			}

			Music::~Music()
			{

			}

			sf::Music* Music::Load(std::string name)
			{
				/*
				this->music.push_back(MB::Content::Load<sf::Music*>(name));
				return this->music.back(); */
			//     int key = listCounter;
			//     this->music.insert(std::pair<int,sf::Music*>(std::pair<int,sf::Music*>( key,MB::Content::Load<sf::Music*>(name) ) ));
			//     listCounter++;
			//     return key;
				sf::Music* file = MB::Content::Load<sf::Music*>(name);
				this->musicList.push_back(file);

				return file;
			}

			void Music::Play(sf::Music* ref)
			{

			  ref->play();

			}
		}
	}
}