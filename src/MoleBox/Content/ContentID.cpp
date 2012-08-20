#include <MoleBox/Content/ContentID.hpp>
#include <MoleBox/Content/ContainerTemplate.hpp>
#include <MoleBox/Content/Content.hpp>
#ifdef INCLUDE_LUA
#include <MoleBox/Lua/Script.hpp>
#endif
namespace MB
{
	namespace Content
	{
		TextureID::TextureID(std::string type) : MB::Content::ID(type)
		{
  
		}

		TextureID::~TextureID()
		{
  
		}

		MB::StrVector TextureID::List()
		{
		  return MB::Content::List<sf::Texture>(); 
		}

		bool TextureID::CheckExtension(std::string ext)
		{
		  std::string supportedImageTypes = "bmp dds jpg png tga psd";
		  return supportedImageTypes.find(ext);   
		}

		void TextureID::Load(std::string fileLocation)
		{
		  MB::Content::Load<sf::Texture>(fileLocation);
		}

		/**
		 * 
		 * 	Sound ID's
		 * 
		 * 
		 * 
		 */

		SoundID::SoundID(std::string type) : ID(type)
		{
  
		}

		SoundID::~SoundID()
		{
  
		}

		MB::StrVector SoundID::List()
		{
		  return MB::Content::List<sf::SoundBuffer>();
		}

		bool SoundID::CheckExtension(std::string ext)
		{
		  std::string supportedAudioTypes = "ogg wav flac aiff au raw paf svx nist voc ircam w64 mat4 mat5 pvf htk sds avr sd2 caf wve mpc2k rf64";
		  return supportedAudioTypes.find(ext); 
		}

		void SoundID::Load(std::string fileLocation)
		{
		  MB::Content::Load<sf::SoundBuffer>(fileLocation);
		}

		/**
		 * 
		 * 	Music ID's
		 * 
		 * 
		 * 
		 */

		MusicID::MusicID(std::string type) : ID(type)
		{
  
		}

		MusicID::~MusicID()
		{
  
		}

		MB::StrVector MusicID::List()
		{
		  return MB::Content::List<sf::Music*>();
		}

		bool MusicID::CheckExtension(std::string ext)
		{
		  std::string supportedAudioTypes = "ogg wav flac aiff au raw paf svx nist voc ircam w64 mat4 mat5 pvf htk sds avr sd2 caf wve mpc2k rf64";
  
		  return supportedAudioTypes.find(ext);  
		}

		void MusicID::Load(std::string fileLocation)
		{
		  MB::Content::Load<sf::Music*>(fileLocation);
		}

		/**
		 * 
		 * 	Font ID's
		 * 
		 * 
		 * 
		 */

		FontID::FontID(std::string type) : ID(type)
		{
  
		}

		FontID::~FontID()
		{
  
		}

		MB::StrVector FontID::List()
		{
		  return MB::Content::List<sf::Font>();
		}

		bool FontID::CheckExtension(std::string ext)
		{
		  std::string supportedTypes = ".ttf .fnt .otf";
  
		  return supportedTypes.find(ext);  
		}

		void FontID::Load(std::string fileLocation)
		{
		  MB::Content::Load<sf::Font>(fileLocation);
		}



		#ifdef INCLUDE_LUA


		#endif
	}
}