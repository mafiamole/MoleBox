#include "content.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#ifndef SFMLCONTENT_H
#define SFMLCONTENT_H

/**
 * Template class to add sf::Texture as a loadable content.
 * 
 */

template <> class ContentContainer <sf::Texture> {
  
private:
  /**
   *  Container for all sf::Texture in the game.
   */
  std::map< std::string , sf::Texture > textures;

public:
  /**
   * Obtains a static instance of this class. A static instance ensures a single copy of it at run time.
   */
  static ContentContainer < sf::Texture >& I() {
    
    static ContentContainer < sf::Texture > instance;
    
    return instance;
    
  }
  /**
   * Used to load a sf::Texture from a given filesystem location.
   */
  const sf::Texture& Load(std::string reference)
  {
    
    if ( this->textures.find(reference) == this->textures.end() )
    {
      
      sf::Texture texture;
      
      if ( !texture.loadFromFile(reference) )
	throw std::string ("Unable to load texture: " + reference);
      
      this->textures.insert( std::pair< std::string , sf::Texture> ( reference , texture) );
      std::cout << "content loaded:" << reference << std::endl;
    }
    else 
    {
      std::cout << "content already in memory" << std::endl;  
    }
    
    return this->textures[reference];

    
  }
  
};

template <> class ContentContainer <sf::SoundBuffer> {
  
private:
  /**
   *  Container for all sf::SoundBuffer's in the game.
   */
  std::map< std::string , sf::SoundBuffer > sounds;

public:
  /**
   * Obtains a static instance of this class. A static instance ensures a single copy of it at run time.
   */
  static ContentContainer < sf::SoundBuffer >& I() {
    
    static ContentContainer < sf::SoundBuffer > instance;
    
    return instance;
    
  }
  /**
   * Used to load a sf::SoundBuffer from a given filesystem location.
   */
  const sf::SoundBuffer& Load(std::string reference)
  {
    
    if ( this->sounds.find(reference) == this->sounds.end() )
    {
      
      sf::SoundBuffer sound;
      
      if ( !sound.loadFromFile(reference) )
	throw std::string ("Unable to load " + reference);
      
      this->sounds.insert( std::pair< std::string , sf::SoundBuffer> ( reference , sound) );
      std::cout << "content loaded " << reference << std::endl;
    }
    else 
    {
      std::cout << "content already in memory" << std::endl;  
    }
    
    return this->sounds[reference];

    
  }
  
};

template <> class ContentContainer <sf::Music> {
  
private:
  /**
   *  Container for all sf::Music in the game.
   */
  std::map< std::string , sf::Music *> music;

public:
  
  ~ContentContainer < sf::Music > () {
    std::map< std::string , sf::Music *>::iterator musicIterator;
    
    for (musicIterator = music.begin(); musicIterator != music.end(); musicIterator++)
    {
      delete (*musicIterator).second;
    }
    music.clear();

  }
  /**
   * Obtains a static instance of this class. A static instance ensures a single copy of it at run time.
   */
  static ContentContainer < sf::Music >& I() {
    
    static ContentContainer < sf::Music > instance;
    
    return instance;
    
  }
  /**
   * Used to load a sf::Music from a given filesystem location.
   */
  sf::Music* Load(std::string reference)
  {
    if ( this->music.find(reference) == this->music.end() )
    {
      
      this->music.insert( std::pair< std::string , sf::Music*> ( reference , new sf::Music() ) );
      
      if (!this->music[reference]->openFromFile(reference))
      {
	this->music.erase(reference);
      	throw std::string ("Unable to load " + reference);
      }
      std::cout << "content loaded " << reference << std::endl;
    }
    else 
    {
      std::cout << "content already in memory" << std::endl;  
    }
    
    return this->music[reference];

  }
  
};
#endif