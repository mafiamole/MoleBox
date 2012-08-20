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


#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP
#include <map>
#include <list>
#include <algorithm>
#include <MoleBox/Lua/Export.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace MB {

  namespace Lua
  {
    namespace Containers {
      
      class MOLEBOX_LUA_API Sprites
      {
      private:
	sf::RenderTarget* 		target;
	std::list<sf::Sprite>		spriteList;
	std::list<sf::Sprite*>		renderList;
	int				listCounter;
      public:
	Sprites							(sf::RenderTarget* target);
	~Sprites						();
	static const char*		RegRef;
	sf::Sprite* 			Add		(std::string filename);
	void 				AppendToDrawList	(sf::Sprite* ref);
	void 				Draw			();
	//sf::Sprite*			Get(int ref);
      };
      
      class MOLEBOX_LUA_API Text
      {
      private:
	sf::RenderTarget*		target;
	std::list<sf::Text>		textList;
	std::list<sf::Text*>		renderList;
	int				listCounter;
      public:
					Text			(sf::RenderTarget* target);
					~Text			();
	sf::Text*	Create			(std::string value);
	void				AppendToDrawList	( sf::Text* ref );
	void 				Draw			();
	//sf::Text*			Get(int ref);
	static const char*		RegRef;
      };
      
      class MOLEBOX_LUA_API Sounds
      {
      private:
	std::list<sf::Sound>		soundList;
	int				listCounter;
      public:
					Sounds			();
					~Sounds			();
	sf::Sound*  	 		Load			( std::string filename );
	static const char*		RegRef;
      };

      class MOLEBOX_LUA_API Music
      {
      protected:
	int				currentlyPlaying;
	std::list<sf::Music*>		musicList;
	int				listCounter;
      public:
					Music			();
					~Music			();
	sf::Music*			Load			(std::string name);
	void 				Play			(sf::Music* ref);
	static const char*		RegRef;
	
      };
      
    }
  }
}

#endif // CONTAINERS_HPP
