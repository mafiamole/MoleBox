#include <MoleBox/Content/ContentID.hpp>
#include <MoleBox/Content/Content.hpp>
#include <MoleBox/Lua/Script.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


/**
 * 
 * 	Texture ID's
 * 
 * 
 * 
 */

MB::Content::TextureID::TextureID(std::string type) : MB::Content::ID(type)
{
  
}

MB::Content::TextureID::~TextureID()
{
  
}

MB::Content::StrVect MB::Content::TextureID::List()
{
  return MB::Content::List<sf::Texture>(); 
}

bool MB::Content::TextureID::CheckExtension(std::string ext)
{
  std::string supportedImageTypes = "bmp dds jpg png tga psd";
  return supportedImageTypes.find(ext);   
}

void MB::Content::TextureID::Load(std::string file)
{
  MB::Content::Load<sf::Texture>(file);
}

/**
 * 
 * 	Sound ID's
 * 
 * 
 * 
 */

MB::Content::SoundID::SoundID(std::string type) : MB::Content::ID(type)
{
  
}

MB::Content::SoundID::~SoundID()
{
  
}

MB::Content::StrVect MB::Content::SoundID::List()
{
  return MB::Content::List<sf::SoundBuffer>();
}

bool MB::Content::SoundID::CheckExtension(std::string ext)
{
  std::string supportedAudioTypes = "ogg wav flac aiff au raw paf svx nist voc ircam w64 mat4 mat5 pvf htk sds avr sd2 caf wve mpc2k rf64";
  return supportedAudioTypes.find(ext); 
}

void MB::Content::SoundID::Load(std::string file)
{
  MB::Content::Load<sf::SoundBuffer>(file);
}

/**
 * 
 * 	Music ID's
 * 
 * 
 * 
 */

MB::Content::MusicID::MusicID(std::string type) : MB::Content::ID(type)
{
  
}

MB::Content::MusicID::~MusicID()
{
  
}

MB::Content::StrVect MB::Content::MusicID::List()
{
  return MB::Content::List<sf::Music*>();
}

bool MB::Content::MusicID::CheckExtension(std::string ext)
{
  std::string supportedAudioTypes = "ogg wav flac aiff au raw paf svx nist voc ircam w64 mat4 mat5 pvf htk sds avr sd2 caf wve mpc2k rf64";
  
  return supportedAudioTypes.find(ext);  
}

void MB::Content::MusicID::Load(std::string file)
{
  MB::Content::Load<sf::Music*>(file);
}

/**
 * 
 * 	Lua ID's
 * 
 * 
 * 
 */

MB::Content::LuaScriptID::LuaScriptID(std::string type) : MB::Content::ID(type)
{
  
}

MB::Content::LuaScriptID::~LuaScriptID()
{
  
}

MB::Content::StrVect MB::Content::LuaScriptID::List()
{
  return MB::Content::List<MB::Lua::LuaScript*>();
}

bool MB::Content::LuaScriptID::CheckExtension(std::string ext)
{
  return ext == "lua";
}

void MB::Content::LuaScriptID::Load(std::string file)
{
  MB::Content::Load<MB::Lua::LuaScript *>(file);
}
