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

#include "luaScriptHelper.h"
// extracts a table into a std::map with provided types
/**
 * LuaHelper::TypeCheck
 * 
 */
bool LuaHelper::TypeCheck(lua_State *L,int index,int type) {

  return (bool)(lua_type(L,index) == type);
  
}


void LuaHelper::HandelError(lua_State *L,int status) {
  
  if ( status != 0 ) {
    
    std::cerr << "Script error: " << lua_tostring(L, -1) << std::endl;

    lua_pop(L, 1); // remove error message
    
  }
  
}

void LuaHelper::PushError(lua_State* L, std::string errorString)
{
  lua_pushstring(L,errorString.c_str());
  
  lua_error(L);  
}

template<class T> T LuaReturnType(lua_State* L, int index)
{

  throw std::string("Feature not supported.");

}

template <> std::string LuaReturnType< std::string >(lua_State* L, int index)
{

  std::string outputString;
  
  outputString = lua_tostring(L,index);
  
  return outputString;

}

template <> bool LuaReturnType< bool >(lua_State* L, int index)
{
  return lua_toboolean(L, index);
}


template <> double LuaReturnType< double >(lua_State* L, int index)
{
  return lua_tonumber(L,index);
}

template <> int LuaReturnType< int >(lua_State* L, int index)
{
  return lua_tointeger(L,index);
}

LuaSFML::Sounds& LuaSFML::Sounds::Instance()
{
	static Sounds sounds;
	return sounds;
}

LuaSFML::Sounds::Sounds()
{

}

LuaSFML::Sounds::~Sounds()
{

}

int LuaSFML::Sounds::Load(lua_State* L)
{

  int n = lua_gettop(L);
  
  if ( n != 1)
  {
    
    lua_pushstring(L,"Sounds.Plays Requires one argument, filename of sound.");
    
    lua_error(L);
    
  }
  
  std::string file;
  
  file = lua_tostring(L,1);
  
  Sounds::Instance().sounds.insert( std::pair<std::string,sf::Sound> ( file, sf::Sound( Content<sf::SoundBuffer>::Load(file) ) ) );

}

int LuaSFML::Sounds::Play(lua_State* L)
{

  int n = lua_gettop(L);
  
  if ( n != 1)
    
    LuaHelper::PushError( L, "Sounds.Plays Requires one argument, filename of sound." );
  
  std::string file;
  
  file = lua_tostring(L,1);
  
  if ( Sounds::Instance().sounds.find(file) != Sounds::Instance().sounds.end() )
  {
    Sounds().Instance().sounds[file].play();
  }
  
}

int LuaSFML::Sounds::Stop(lua_State* l)
{
  std::string file;
  
  if ( Sounds::Instance().sounds.find(file) != Sounds::Instance().sounds.end() )
  {
    Sounds().Instance().sounds[file].play();
  }
}    



int LuaSFML::Sounds::PauseUnPause(lua_State* l)
{
  std::string file;

  if ( Sounds::Instance().sounds.find(file) != Sounds::Instance().sounds.end() )
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

LuaSFML::Sprites::Sprites()
{

}

LuaSFML::Sprites::~Sprites()
{

}

LuaSFML::Sprites& LuaSFML::Sprites::Instance()
{
  static Sprites sprites;
  return sprites;
}

void LuaSFML::Sprites::SetWindow(sf::RenderWindow* window)
{
  this->window = window;
}

sf::RenderWindow* LuaSFML::Sprites::GetWindow()
{
  return this->window;
}

sf::Sprite LuaSFML::Sprites::GetSprite(std::string name)
{

  return luaSprites[name];

}


int LuaSFML::Sprites::Load(lua_State* L)
{
  int n = lua_gettop(L);
  
  if ( n != 2)
    
    LuaHelper::PushError( L, "Sprites.Load Requires two arguments, the name of the sprite followed by the initial texture to set.");
  
  std::string name, texture;
  
  name 		= lua_tostring(L,1);
  texture 	= lua_tostring(L,2);
  
  std::pair<std::string,sf::Sprite> spriteInsert( name , sf::Sprite( Content<sf::Texture>::Load(texture) ) );
  
  Sprites::Instance().luaSprites.insert( spriteInsert);
	
}

int LuaSFML::Sprites::Draw(lua_State* L)
{

  if ( Sprites::Instance().GetWindow() == NULL )
    
    LuaHelper::PushError( L, "INTERNAL ERROR: No handle on window." );
    

  int n = lua_gettop( L );
  
  if ( n != 1 )
    
    LuaHelper::PushError( L, "Sprites.Draw Requires one argument, the name of the sprite." );
  
  std::string sprite = lua_tostring(L,1);
  
  if ( Sprites::Instance().luaSprites.find(sprite) != Sprites::Instance().luaSprites.end() )
  {
    Sprites::Instance().GetWindow()->draw(  Sprites::Instance().luaSprites[sprite] );
  }
  else
  {
    std::string error;
    
    error = "Sprite " + sprite + " was not found";
    
    LuaHelper::PushError( L, error );
  }

}
