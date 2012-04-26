
#ifndef LUASCRIPTHELPER
#define LUASCRIPTHELPER

extern "C" {
  #include "lua.hpp"
  #include "lualib.h"
  #include "lauxlib.h"
}

#include <iostream>
#include <string>
#include <map>
#include "../SFMLContent.h"

bool TypeCheck(lua_State* L,int index,int type);

void HandelError(lua_State* L,int status);


template <class T> T LuaReturnType(lua_State* L, int index);

template <> std::string LuaReturnType<std::string>(lua_State* L,int index);

template <> bool LuaReturnType<bool>(lua_State* L,int index);

template <> int LuaReturnType<int>(lua_State* L, int index);

template <> double LuaReturnType<double>(lua_State* L, int index);

/*
class LuaSFMLGlobal {
  
protected:
  std::map<std::string,sf::Sprite> LuaSprites; //no need to know about the textures.

public:
  LuaSFMLGlobal();
  ~LuaSFMLGlobal();
  static LuaSFMLGlobal* Instance();
  static int LoadTexture(lua_State *L);
  static int LoadSprite(lua_State *L);
  static int SetTexture(lua_State *L);
  static int LoadMusic(lua_State *L);
  static int LoadSound(lua_State *L);
  
  static int PlaySound(lua_State *L);
  
  static int PlayMusic(lua_State *L);
  static int StopMusic(lua_State *L);
  static int TogglePauseMusic(lua_State *L);
  
  static int DrawSprite(lua_State *L);
  
  
};

*/
namespace LuaSFML {


  class Sounds {
  private:
    Sounds() { }
    
    ~Sounds() { };    
      void operator=(Sounds const&);    
  protected:
  std::map <std::string,sf::Sound> sounds;
    
  public:
    

    
    static Sounds& Instance() {
	static Sounds sounds;
	return sounds;
    }
    
    static int Load(lua_State *l) {
      std::string file;      
      Sounds::Instance().sounds.insert( std::pair<std::string,sf::Sound> ( file, sf::Sound( Content<sf::SoundBuffer>::Load("test.wav") ) ) );
      
    }
    
    static int Play(lua_State *l) {
      
      std::string file;
      
      if (Sounds::Instance().sounds.find(file) != Sounds::Instance().sounds.end())
      {
	Sounds().Instance().sounds[file].play();
      }
    }

    static int PauseUnPause(lua_State *l) {
      
      std::string file;
      
      if (Sounds::Instance().sounds.find(file) != Sounds::Instance().sounds.end())
      {
	
	sf::Sound::Status status = Sounds().Instance().sounds[file].getStatus();
	
	switch (status)
	{
	  case 2:
	    Sounds().Instance().sounds[file].play();
	    break;
	  case 1:
	    Sounds().Instance().sounds[file].pause();
	    break;
	}

      }
    }    
 
    static int Stop(lua_State *l) {
      
      std::string file;
      
      if (Sounds::Instance().sounds.find(file) != Sounds::Instance().sounds.end())
      {
	Sounds().Instance().sounds[file].play();
      }
    }    
 
   
  };
  
  class Sprites {
  private:
      Sprites() {}
      ~Sprites() {}
      void operator=(Sprites const&);
  protected:
    
    std::map<std::string, sf::Sprite> 	luaSprites;
    sf::RenderWindow* 			window;
    
    public:

      static Sprites& Instance()
      {
	static Sprites sprites;
	return sprites;
      }
      
      void SetWindow(sf::RenderWindow* window)
      {
	this->window = window;
      }
      
      sf::RenderWindow* GetWindow()
      {
	return this->window;
      }
      
      sf::Sprite GetSprite(std::string name)
      {
	return luaSprites[name];
      }
      
      sf::RenderWindow* getWin() {
	
	return this->window;
	
      }

      
      static int Load(lua_State *L) {
	
	int n 	= lua_gettop(L);
	
	if ( n != 2) {
	  
	  lua_pushstring(L,"Sprites.Load Requires two arguments, the name of the sprite followed by the initial texture to set.");
	  
	  lua_error(L);
	  
	}
	
	std::string name, texture;
	
	name 	= lua_tostring(L,1);
	
	texture = lua_tostring(L,2);
	
	Sprites::Instance().luaSprites.insert( std::pair<std::string,sf::Sprite> 
					( name , sf::Sprite( Content<sf::Texture>::Load(texture) ) ) 
					     );
	
      }
      
      static int Draw(lua_State *L) {

	if ( Sprites::Instance().getWin() == NULL )
	{
	  lua_pushstring( L , "INTERNAL ERROR: No handle on window." );
	  
	  lua_error( L );
	}

	int n = lua_gettop( L );
	
	if ( n != 1 )
	{
	  lua_pushstring( L , "Sprites.Draw Requires one argument, the name of the sprite." );
	  
	  lua_error( L );
	}
	
	std::string sprite = lua_tostring(L,1);
	
	if ( Sprites::Instance().luaSprites.find(sprite) != Sprites::Instance().luaSprites.end() )
	{
	  Sprites::Instance().window->draw(  Sprites::Instance().luaSprites[sprite] );
	}
	else
	{
	  std::string error;
	  
	  error = "Sprite " + sprite + " was not found";
	  
	  lua_pushstring( L, error.c_str() );
	  
	  lua_error( L );
	}
	
	
      }
      
  };
  
  
/*  
  class GlobalContainer {
    
    private:
      static std::map<std::string,lua_State*> globalLuaStates;
    public:
      static lua_State* GetState(std::String scriptLoc);
      
  };
*/

  
}
template <class K,class V> std::map<K,V> LuaMapTable(lua_State *L,std::string name,int valueType,int keyType) {
  lua_getglobal(L,name.c_str());
  LuaMapTable<K,V>(L,valueType,keyType);
}

template <class K,class V> std::map<K,V> LuaMapTable(lua_State *L,int valueType,int keyType) {
  
  std::map<K,V> outputMap;
  
  if ( lua_istable(L,-1) )
  {
    for (lua_pushnil(L);lua_next(L,-2);lua_pop(L,1) )
    {

      if ( !TypeCheck(L,-1,valueType)) {
	std::string error = "Value type was not expected ";
	error += lua_typename(L,lua_type(L,-1));
	throw error;
      }
      if ( !TypeCheck(L,-2,keyType) ) {
	throw std::string("Key type was not expected");
      }
      
    std::pair<K,V> test(  LuaReturnType<K>(L,-2),LuaReturnType<V>(L,-1));
    
    outputMap.insert(test);
    
    }

  return outputMap;
  }
  else
  {
    throw std::string("Type is not a table");
  }  
  
}

#endif