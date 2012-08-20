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


#include <MoleBox/GameConfig.hpp>

namespace MB
{

	GameConfig::GameConfig()
	{
  
	}

	GameConfig::~GameConfig()
	{
  
	}

	int GameConfig::StringToInt(std::string integer)
	{
	  return atoi(integer.c_str());
	}

	bool GameConfig::StringToBool(std::string boolean)
	{

	  std::transform(boolean.begin(), boolean.end(),boolean.begin(), ::tolower);
	  std::size_t foundTrue = boolean.find("true");
	  std::size_t foundYes = boolean.find("yes");
  
	  return (foundTrue != 0) || (foundYes !=0);

	}

	StrPair GameConfig::SplitString(std::string line,char centre)
	{
	  std::allocator< char >::size_type valuePos = line.find(centre);
	  std::string name = line.substr(0, valuePos - 1);
	  std::string value = line.substr(valuePos+1);
	  return StrPair( line.substr(0, valuePos - 1), line.substr(valuePos+1) );
	}

	std::string GameConfig::TruncateCMDArg(std::string line)
	{
	  std::allocator< char >::size_type dashPos = line.find("-");
	  return  line.substr(dashPos+1);
	}

	ConfList GameConfig::LoadFile (std::string file)
	{
	  std::ifstream configStream(file.c_str());
	  ConfList conf;
	  if ( configStream.is_open() )
	  {
    
		while ( !configStream.eof() )
		{
		  std::string fileLine;
		  std::getline(configStream,fileLine);
      
		  if (fileLine.size() > 0)
		  {
		StrPair values =  this->SplitString(fileLine,'=');
	
		RegisterValue(values,&conf);
	
		  }

		}
    
	  }
  
	  return conf;
	}

	ConfList GameConfig::LoadArgs(int argc,char **argv)
	{
	   ConfList conf;
 
	   for ( int argItr = 0; argItr < argc; argItr++ )
	   {
     
		 std::string fileline = this->TruncateCMDArg(argv[argItr]);
		 StrPair values =  this->SplitString(fileline,'=');
		 RegisterValue(values,&conf);
     
	   }
 
	   return conf;
	}

	ConfList GameConfig::LoadAll(std::string file,int argc,char **argv)
	{
	 return ConfList(); 
	}

	void GameConfig::RegisterValue(StrPair value,ConfList* config )
	{
	  if ( value.first == "resolution" )
	  {
		StrPair resTem = this->SplitString(value.second,'X');
    
		config->resolution = sf::VideoMode( this->StringToInt(resTem.first), this->StringToInt(resTem.second) );
	  }


	  if (value.first == "fullscreen")
		config->fullscreen = this->StringToBool(value.second);

	  if (value.first == "resource")
		config->resourceLocation = value.second;

	  if (value.first == "fps")
		config->fps = this->StringToInt(value.second);
	    
	}

	int GameConfig::GetArgCount ()
	{
	  return this->argc;
	}
	char** GameConfig::GetArgs()
	{
	  return this->argv;
	}
}