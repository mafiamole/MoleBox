#include <MoleBox/Content/Content.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace MB
{
  namespace Content
  {
    sf::Sprite NewSprite(std::string name)
    {
      return sf::Sprite( Load<sf::Texture>(name)  );
    }

    sf::Sound NewSound(std::string name)
    {
      return sf::Sound( Load<sf::SoundBuffer>(name) );
    }
  }
}