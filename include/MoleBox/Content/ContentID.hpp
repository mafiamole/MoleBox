#ifndef CONTENTID_H
#define CONTENTID_H
#include <MoleBox/Content/ContentTemplate.hpp>

namespace MB {

  namespace Content {
    
    class TextureID : public ID
    {
    public:
      TextureID(std::string type = "texture");
      ~TextureID();
      MB::Content::StrVect List();
      bool CheckExtension(std::string extension);
      void Load(std::string string);
    };

    class SoundID : public ID
    {
    public:
      SoundID(std::string type = "sound");
      ~SoundID();
      MB::Content::StrVect List();
      bool CheckExtension(std::string extension);
      void Load(std::string string);
    };
    
    class MusicID : public ID
    {
    public:
      MusicID(std::string type = "music");
      ~MusicID();
      MB::Content::StrVect List();
      bool CheckExtension(std::string extension);
      void Load(std::string string);
    };
    
    class LuaScriptID : public ID
    {
    public:
      LuaScriptID(std::string type = "luascript");
      ~LuaScriptID();
      MB::Content::StrVect List();
      bool CheckExtension(std::string extension);
      void Load(std::string string);
    };
    
  }

}

#endif