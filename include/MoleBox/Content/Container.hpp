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


#ifndef MB_CONTENT_CONTAINER_H
#define MB_CONTENT_CONTAINER_H
#include <string>


#include <SFML/System/Lock.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <MoleBox/Export.hpp>
#include <MoleBox/Content/ContainerTemplate.hpp>
#include <MoleBox/Content/ContentID.hpp>

namespace MB {

  namespace Content {

    /**
    * @brief sf::Texture specialisation of the Container Class.
    **/
    template<> class MOLEBOX_API Container<sf::Texture>
    {

	Container_Base<const sf::Texture> base;
	TextureID *id;
    public:

	Container()
	{
	  this->id = new TextureID();
	}
	~Container()
	{
	  delete id;
	}

	/**
	* @brief Loads a texture from file
	*
	* @param fileLocation The file location that the texture resides.
	* @return sf:Texture&
	**/
	const sf::Texture& Load(std::string fileLocation)
	{
	    fileLocation = fileLocation;
	    if ( this->base.contents.find(fileLocation) == this->base.contents.end())
	    {
		sf::Texture texture;

		if (!texture.loadFromFile(fileLocation))
		    throw Exception(COULD_NOT_LOAD,fileLocation);

		this->base.contents.insert(std::pair<std::string,sf::Texture>(fileLocation,texture));

	    }
	    return this->base.contents[fileLocation];
	}

	/**
	* @brief Returns an static instance of this class
	*
	* @return MB:Content::Container&
	**/
	static Container<sf::Texture>& I()
	{
	    static Container<sf::Texture> container;
	    return container;
	}

	/**
	 * @brief Returns a list of  variables
	 *
	 * @return StrVect
	 **/
	StrVector List()
	{
	    sf::Lock(this->base.mutex);
	    return base.List();
	}

	/**
	 * @brief Returns a TextureID instance as an identifier for this content.
	 *
	 * @return TextureID*
	 **/
	TextureID* GetID()
	{
	    return id;
	}

    };

    
    /**
     * @brief sf::SoundBuffer specialisation of the container class
     **/
    template<> class MOLEBOX_API Container<sf::SoundBuffer>
    {

      
      Container_Base<const sf::SoundBuffer> base;
      SoundID* id;
      public:
	
      Container()
      {
	this->id = new SoundID();
      }
      ~Container()
      {
	delete id;
      }
	
      /**
	* @brief Loads a sound buffer into memory
	*
	* @param fileLocation ...
	* @return sf:SoundBuffer&
	**/
      const sf::SoundBuffer& Load(std::string fileLocation)
      {
	
	if ( this->base.contents.find(fileLocation) == this->base.contents.end())
	{
	  
	  sf::SoundBuffer buffer;
	  
	  if (!buffer.loadFromFile(fileLocation))
	  {
	    throw Exception(COULD_NOT_LOAD,fileLocation);
	  }
	  
	  std::pair<std::string,const sf::SoundBuffer> newBuffer(fileLocation,buffer);

	  this->base.contents.insert(newBuffer);
	}
	
	return this->base.contents[fileLocation];
      }
      
      /**
       * @brief Returns the static instance of this class.
       *
       * @return MB:Content::Container< sf::SoundBuffer >&
       **/
      static Container<sf::SoundBuffer>& I()
      {
	static Container<sf::SoundBuffer> container;
	
	return container;
	
      }
      
      /**
       * @brief Returns a list of stored sound buffers.
       *
       * @return MB:StrVector
       **/
      StrVector List()
      {
	sf::Lock(this->base.mutex);
	
	return base.List();
	
      }
      
      /**
       * @brief Returns SoundId, which is a unique identifer for this content type.
       *
       * @return :Content::SoundID*
       **/
      SoundID* GetID()
      {
	return id;
      }
      
    };    

    /**
     * @brief sf::Music specialisation of the Container class. Unlike sf::Texture and sf::SoundBuffer, the whole file is not read into memory. For this reason, the content is a pointer to the object in memory.
     **/
    template<> class MOLEBOX_API Container<sf::Music *> 
    {
      
      Container_Base<sf::Music *> base;
      MusicID *id;
      public:
      

      Container()
      {
	id = new MusicID;
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
	
	delete id;
      }
      /**
       * @brief Creates a new instance of sf::Music which points to a music file on disk
       *
       * @param fileLocation ...
       * @return :Music*
       **/
      sf::Music * Load(std::string fileLocation)
      {
	
	if ( this->base.contents.find(fileLocation) == this->base.contents.end()) {
	  sf::Music * buffer = new sf::Music();
	  
	  if (!buffer->openFromFile(fileLocation))
	    throw Exception(COULD_NOT_LOAD,fileLocation);
	  
	  std::pair<std::string,sf::Music *> newBuffer(fileLocation,buffer);

	  this->base.contents.insert(newBuffer);
	}
	
	return this->base.contents[fileLocation];
      }
    
    /**
     * @brief Obtains the static instance of this class
     *
     * @return MB:Content::Container< sf::Music* >&
     **/
    static Container<sf::Music*>& I()
      {
	static Container<sf::Music*> container;
	return container;	
      }
      
      /**
       * @brief returns a list of music files loaded
       *
       * @return MB:StrVector
       **/
      StrVector List()
      {
	sf::Lock(this->base.mutex);
	return base.List();
      }
	      
      /**
       * @brief Deletes all music from memory.
       *
       **/

      
      /**
       * @brief ...
       *
       * @return MB:Content::MusicID*
       **/
      MusicID* GetID()
      {
	return id;
      }
      
    };

    /**
    * @brief sf::Font specialisation of the Container Class.
    **/
    template<> class MOLEBOX_API Container<sf::Font>
    {

	Container_Base<const sf::Font> base;
	FontID *id;
    public:

	Container()
	{
	  this->id = new FontID();
	}
	~Container()
	{
	  delete id;
	}

	/**
	* @brief Loads a font from file
	*
	* @param fileLocation The file location that the texture resides.
	* @return sf:Texture&
	**/
	const sf::Font& Load(std::string fileLocation)
	{
	    fileLocation = fileLocation;
	    if ( this->base.contents.find(fileLocation) == this->base.contents.end())
	    {
		sf::Font font;

		if (!font.loadFromFile(fileLocation))
		    throw Exception(COULD_NOT_LOAD,fileLocation);

		this->base.contents.insert(std::pair<std::string,sf::Font>(fileLocation,font));

	    }
	    return this->base.contents[fileLocation];
	}

	/**
	* @brief Returns an static instance of this class
	*
	* @return MB:Content::Container&
	**/
	static Container<sf::Font>& I()
	{
	    static Container<sf::Font> container;
	    return container;
	}

	/**
	 * @brief Returns a list of  variables
	 *
	 * @return StrVect
	 **/
	StrVector List()
	{
	    sf::Lock(this->base.mutex);
	    return base.List();
	}

	/**
	 * @brief Returns a TextureID instance as an identifier for this content.
	 *
	 * @return TextureID*
	 **/
	FontID* GetID()
	{
	    return id;
	}

    };

    
#ifdef INCLUDE_LUA
    
//     template<> class MOLEBOX_API Container<MB::Lua::Script *>
//     {
//       
//       Container_Base<MB::Lua::Script *> base;
//       LuaScriptID* id;
//       
//       public:
// 	
//       Container()
//       {
// 	id = new LuaScriptID();
//       }
// 	
//       ~Container()
//       {
// 	std::map<std::string,MB::Lua::Script* >::iterator musicItr;
// 	for ( musicItr = base.contents.begin(); musicItr != base.contents.end(); musicItr++)
// 	{
// 	 MB::Lua::Script* file = (*musicItr).second;
// 	  delete file;
// 	}
// 	
// 	base.contents.clear();
//       } 
// 	
//       MB::Lua::Script * Load(std::string reference)
//       {
// 
// 	if ( this->base.contents.find(reference) == this->base.contents.end())
// 	{
// 	  
// 	  std::ifstream file(reference.c_str());
// 
// 	  if ( file.good() )
// 	  {
// 	    file.close();
// 	    Lua::Script* script = new MB::Lua::Script();
// 	    
// 	  }
// 	  else
// 	  {
// 	    file.close();
// 	    throw Exception(COULD_NOT_LOAD,reference);
// 	  }
// 	  Lua::Script* script = new MB::Lua::Script();
// 	  if (!script->LoadFromFile(reference))
// 	    throw Exception(COULD_NOT_LOAD,reference);
// 	  
// 	  this->base.contents.insert(std::pair<std::string,MB::Lua::Script *>(reference,script));
// 	  
// 	}
// 	return this->base.contents[reference];
//       }
//       
//       static Container<MB::Lua::Script *>& I()
//       {
// 	static Container<MB::Lua::Script *> container;
// 	return container;	
//       }
//       
//       StrVector List()
//       {
// 	sf::Lock(this->base.mutex);
// 	return base.List();
//       }
//  
// 	      
//       
//       LuaScriptID* GetID()
//       {
// 	return id;
//       }
//       
//     }; 
    
#endif   
  } // MB::Content

} // MB

#endif // MB_CONTENT_CONTAINER_H
