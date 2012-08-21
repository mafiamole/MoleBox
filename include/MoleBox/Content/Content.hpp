
#ifndef CONTENT_HPP
#define CONTENT_HPP

#include <MoleBox/Export.hpp>
#include <MoleBox/Content/Container.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Sound.hpp>

namespace MB {

  namespace Content {

    /**
     * @brief Load a content of type T and return a reference to it. Type T require a specailisation of the Container class.
     *
     * @param fileLocation File location relative to MB::Content::location.
     * @return const T&
     **/
      template <typename T> MOLEBOX_API const T &  Load(std::string fileLocation) {
	return Container<T>::I().Load( location + fileLocation);
      }
      
      /**
       * @brief Return a list of all loaded items for type T
       *
       * @return MB:StrVector
       **/
     template <typename T> MOLEBOX_API StrVector List() {
      return Container<T>::I().List();
      }  
    
    
    /**
     * @brief Obtain the identifier class for type T. The container specailisation of type T needs to implement GetID() with it's own ID type extended from MB::Content:ID
     *
     * @return MB:Content::ID*
     **/
    template <typename T> MOLEBOX_API ID * GetID()
    {
      
      return Container<T>::I().GetID();
    }

    MOLEBOX_API sf::Sprite NewSprite(std::string name);
    MOLEBOX_API sf::Sound NewSound(std::string name);
  }
}

#endif