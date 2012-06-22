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
#ifndef SFMLCONTENT_H
#define SFMLCONTENT_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <MoleBox/Content/ContentTemplate.hpp>
#include <MoleBox/Content/ContentID.hpp>
#include <MoleBox/Lua/Script.hpp>
#include <fstream>



namespace MB {

  namespace Content {

    /**
     * 
     * MB::Content::Exception is an exception class for content related errors.
     * 
     */
    
    enum ERR_TYPE { OTHER, COULD_NOT_LOAD };
    
    class Exception
    {
      std::string resource;
      ERR_TYPE type;
    public:
      Exception(ERR_TYPE type,std::string resource);
      std::string toString();
    };
    /**
     * 
     *  Container for sf::Texture
     * 
     */
    template<> class Container<sf::Texture>
    {
      
      Container_Base<sf::Texture,const sf::Texture> base;
 
      public:

	
      const sf::Texture& Load(std::string reference)
      {

	if ( this->base.contents.find(reference) == this->base.contents.end())
	{
	  sf::Texture texture;
	  
	  if (!texture.loadFromFile(reference))
	    throw Exception(COULD_NOT_LOAD,reference);
	  
	  this->base.contents.insert(std::pair<std::string,sf::Texture>(reference,texture));
	  
	}
	return this->base.contents[reference];
      }
      
      static Container<sf::Texture>& I()
      {
	static Container<sf::Texture> container;
	return container;	
      }
      
      StrVect List()
      {
	sf::Lock(this->base.mutex);
	return base.List();
      }
      
      TextureID* GetID()
      {
	return new TextureID();
      }
      
    };
    
    template<> class Container<sf::SoundBuffer>
    {

      
      Container_Base<sf::SoundBuffer,const sf::SoundBuffer> base;
      
      public:
	
      const sf::SoundBuffer& Load(std::string reference)
      {
	
	if ( this->base.contents.find(reference) == this->base.contents.end())
	{
	  
	  sf::SoundBuffer buffer;
	  
	  if (!buffer.loadFromFile(reference))
	  {
	    throw Exception(COULD_NOT_LOAD,reference);
	  }
	  
	  std::pair<std::string,const sf::SoundBuffer> newBuffer(reference,buffer);

	  this->base.contents.insert(newBuffer);
	}
	
	return this->base.contents[reference];
      }
      
      static Container<sf::SoundBuffer>& I()
      {
	static Container<sf::SoundBuffer> container;
	
	return container;
	
      }
      
      StrVect List()
      {
	sf::Lock(this->base.mutex);
	
	return base.List();
	
      }
      
      SoundID* GetID()
      {
	return new SoundID();
      }
      
    };

    template<> class Container<sf::Music *> 
    {
      
      Container_Base<sf::Music*,sf::Music *> base;
      
      public:
      
      sf::Music * Load(std::string reference)
      {
	
	if ( this->base.contents.find(reference) == this->base.contents.end()) {
	  sf::Music * buffer = new sf::Music();
	  
	  if (!buffer->openFromFile(reference))
	    throw Exception(COULD_NOT_LOAD,reference);
	  
	  std::pair<std::string,sf::Music *> newBuffer(reference,buffer);

	  this->base.contents.insert(newBuffer);
	}
	
	return this->base.contents[reference];
      }
      
      static Container<sf::Music*>& I()
      {
	static Container<sf::Music*> container;
	return container;	
      }
      
      StrVect List()
      {
	sf::Lock(this->base.mutex);
	return base.List();
      }
	      
      ~Container()
      {
	std::map<std::string,sf::Music* >::iterator musicItr;
	for ( musicItr = base.contents.begin(); musicItr != base.contents.end(); musicItr++)
	{
	  sf::Music* file = (*musicItr).second;
	  delete file;
	}
	
	base.contents.clear();
      }
      
      MusicID* GetID()
      {
	return new MusicID();
      }
      
    };
    
    
    sf::Sprite NewSprite(std::string texture);
    sf::Sound NewSound(std::string sound);
    
  

    template<> class Container<MB::Lua::LuaScript *>
    {
      
      Container_Base<MB::Lua::LuaScript *,MB::Lua::LuaScript *> base;
 
      public:

	
      MB::Lua::LuaScript * Load(std::string reference)
      {

	if ( this->base.contents.find(reference) == this->base.contents.end())
	{
	  
	  std::ifstream file(reference.c_str());

	  if ( file.good() )
	  {
	    file.close();
	    Lua::LuaScript* script = new MB::Lua::LuaScript();
	    
	  }
	  else
	  {
	    file.close();
	    throw Exception(COULD_NOT_LOAD,reference);
	  }
	  Lua::LuaScript* script = new MB::Lua::LuaScript();
	  if (!script->LoadFromFile(reference))
	    throw Exception(COULD_NOT_LOAD,reference);
	  
	  this->base.contents.insert(std::pair<std::string,MB::Lua::LuaScript *>(reference,script));
	  
	}
	return this->base.contents[reference];
      }
      
      static Container<MB::Lua::LuaScript *>& I()
      {
	static Container<MB::Lua::LuaScript *> container;
	return container;	
      }
      
      StrVect List()
      {
	sf::Lock(this->base.mutex);
	return base.List();
      }
 
	      
      ~Container()
      {
	std::map<std::string,MB::Lua::LuaScript* >::iterator musicItr;
	for ( musicItr = base.contents.begin(); musicItr != base.contents.end(); musicItr++)
	{
	 MB::Lua::LuaScript* file = (*musicItr).second;
	  delete file;
	}
	
	base.contents.clear();
      } 
      
      LuaScriptID* GetID()
      {
	return new LuaScriptID();
      }
      
    }; 

  }
class SpriteBatch : public sf::Drawable, public std::vector<sf::Drawable *> {
    
  private:
    sf::RenderTarget* target;
    sf::RenderStates renderState;
    //sf::RenderTexture renderTexture;
    void initiate(sf::Vector2u size, sf::RenderTarget* target, sf::RenderStates states = sf::RenderStates::Default);
  public:
    SpriteBatch(sf::Vector2u size, sf::RenderTarget* target, sf::RenderStates states = sf::RenderStates::Default);  
    SpriteBatch(sf::RenderTarget* target, sf::RenderStates states = sf::RenderStates::Default);
    
    ~SpriteBatch();
    
    void SetRenderState(sf::RenderStates states = sf::RenderStates::Default);
    void Draw();
    virtual void draw(sf::RenderTarget& target,const sf::RenderStates states = sf::RenderStates::Default) const;
  };
}
#endif