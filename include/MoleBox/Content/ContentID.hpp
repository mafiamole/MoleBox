#ifndef CONTENTID_H
#define CONTENTID_H
#include <MoleBox/Export.hpp>
#include <MoleBox/Types.hpp>
#include <MoleBox/Content/ID.hpp>

namespace MB {

  namespace Content {
    
    /**
     * @brief Content ID class for sf::Content
     **/
    class MOLEBOX_API TextureID : public ID
    {
    public:
      /**
       * @brief Initiates TextureID and sets the type member.
       *
       * @param type string identifier Defaults to "texture".
       **/
      TextureID(std::string type = "texture");
      /**
       * @brief default destructor
       *
       **/
      ~TextureID();
      /**
       * @brief Returns a list of sf::Texture objects loaded into memory.
       *
       * @return MB:StrVector
       **/
      StrVector List();
      /**
       * @brief Checks to see if the provided extension is supported by sf::Texture. Returns bool if it does.
       *
       * @param extension The Extension to check against.
       * @return bool
       **/
      bool CheckExtension(std::string extension);
      /**
       * @brief Loads an sf::Texture into memory, but does not return it.
       *
       * @param fileLocation File location of texture to load.
       * @return void
       **/
      void Load(std::string fileLocation);
    };

    /**
     * @brief sf::SoundBuffer Identifier class
     **/
    class MOLEBOX_API SoundID : public ID
    {
    public:
      /**
       * @brief Initilises SoundID by setting type.
       *
       * @param type string identifier Defaults to "sound".
       **/
      SoundID(std::string type = "sound");
      /**
       * @brief default destructor
       *
       **/
      ~SoundID();
      /**
       * @brief returns a list of Sound Buffers loaded
       *
       * @return MB:StrVector
       **/
      StrVector List();
      /**
       * @brief Checks to see if provided extension is a sound file sf::SoundBuffer can load
       *
       * @param extension The extension to check against
       * @return bool
       **/
      bool CheckExtension(std::string extension);
      /**
       * @brief Load, but not return the sound buffer
       *
       * @param fileLocation File location of the sound file
       * @return void
       **/
      void Load(std::string fileLocation);
    };
    
    /**
     * @brief Identifier for sf::Music
     **/
    class MOLEBOX_API MusicID : public ID
    {
    public:
      /**
       * @brief Constructor that sets the member type.
       *
       * @param type string identifier Defaults to "music".
       **/
      MusicID(std::string type = "music");
      /**
       * @brief default destructor
       *
       **/
      ~MusicID();
      /**
       * @brief Obtain a list of music files loaded.
       *
       * @return MB:StrVector
       **/
      StrVector List();
      /**
       * @brief Checks a provided extension to see if it can be loaded by sf::Music.
       *
       * @param extension the extension to check against.
       * @return bool
       **/
      bool CheckExtension(std::string extension);
      /**
       * @brief Create, but not return an sf::Music object.
       *
       * @param fileLocation File for the sf::Music object to point to.
       * @return void
       **/
      void Load(std::string fileLocation);
    };
    
    /**
     * @brief Identifier for sf::Font
     **/
    class MOLEBOX_API FontID : public ID
    {
    public:
      /**
       * @brief Constructor that sets the member type.
       *
       * @param type string identifier Defaults to "music".
       **/
      FontID(std::string type = "font");
      /**
       * @brief default destructor
       *
       **/
      ~FontID();
      /**
       * @brief Obtain a list of music files loaded.
       *
       * @return MB:StrVector
       **/
      StrVector List();
      /**
       * @brief Checks a provided extension to see if it can be loaded by sf::Music.
       *
       * @param extension the extension to check against.
       * @return bool
       **/
      bool CheckExtension(std::string extension);
      /**
       * @brief Create, but not return an sf::Music object.
       *
       * @param fileLocation File for the sf::Music object to point to.
       * @return void
       **/
      void Load(std::string fileLocation);
    };    
    /**
     * @brief Luascript Identifier.
     **/
    #ifdef INCLUDE_LUA

    #endif 
  }

}

#endif