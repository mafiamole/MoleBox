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


#ifndef MB_GAMECONFIG_H
#define MB_GAMECONFIG_H

#include <fstream>
#include <MoleBox/Export.hpp>
#include <SFML/System.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <algorithm>
#include <string>
#include <map>

namespace MB {

  /**
   * @brief The game config class is a class used to load many basic configuration values from a file into the framework. Below is a list of attributes that are reconised.
   * 
   * sf::Vector2i Resolution.      - The resolution your game should run at by default.
   * bool         FullScreen.      - If the game should run full screen.
   * std::string  ResourceLocation - The locaition that resources are loaded from
   * 
   * 
   **/

  struct MOLEBOX_API ConfList
  {
    sf::VideoMode 	resolution;
    bool 		fullscreen;
    std::string 	resourceLocation;
    int 		fps;
  };
  
  typedef std::pair<std::string,std::string> StrPair;
  
  class MOLEBOX_API GameConfig
  {
  private:
    std::string		configFileLocation;
    
  protected:
   
    /**
     * @brief Convert a std::string to int.
     *
     * @param integer integer in string form.
     * @return int
     **/
    /**
     * @brief Convert a std::string to integer
     *
     * @param integer The string of the supposed number to convert. 
     * @return bool
     **/
    int			StringToInt(std::string integer);
    /**
     * @brief Convert a std::string to bool if the string contains true or yes. Otherwise is false
     *
     * @param boolean ...
     * @return bool
     **/
    bool 		StringToBool(std::string boolean);
    /**
     * @brief Splits a string, given 
     *
     * @param line Line to split Defaults to =
     * @return :StrPair
     **/
    /**
     * @brief Split a string by a given character
     *
     * @param line The string to split
     * @param centre The character to split the string around Defaults to '='.
     * @return MB::StrPair
     **/
    StrPair 		SplitString(std::string line,char centre = '=');
    /**
     * @brief Removes the - from a command line argument.
     *
     * @param line The command line argument to remove - from
     * @return std:::string
     **/
    std::string		TruncateCMDArg(std::string line);
    int 		argc;
    char **		argv;
    std::map<std::string,std::string> ConfigList;
  public:
    /**
     * @brief Default Constructor
     *
     **/
    GameConfig		();
    /**
     * @brief Register a value to a config object
     *
     * @param value Value to convert
     * @param config Config object to pass value to
     * @return void
     **/
    void		RegisterValue		(MB::StrPair value, MB::ConfList* config);
    /**
     * @brief Load file into memory
     *
     * @param file File location to load.
     * @return :ConfList
     **/
    ConfList 		LoadFile		(std::string file);
    /**
     * @brief Load Command line arguments as configurations.
     *
     * @param argc Argument count
     * @param argv Argument array
     * @return MB::ConfList
     **/
    ConfList 		LoadArgs		(int argc,char **argv);
    /**
     * @brief Loads from a file and the command line args overide the config file.
     *
     * @param file File to load
     * @param argc Argument count
     * @param argv Argument array
     * @return :ConfList
     **/
    ConfList 		LoadAll			(std::string file,int argc,char **argv);
    /**
     * @brief Get the command line argument count.
     *
     * @return int
     **/
    int 		GetArgCount	();
    /**
     * @brief Get the command line argument array.
     *
     * @return char**
     **/
    char**		GetArgs		();
    /**
     * @brief Checks to see if a certain configuration value is stored and attempt to return it's value as a integer
     *
     * @param identifier Identifier to check by. 
     * @return int
     **/
    int			GetIntValue(std::string identifier);
    /**
     * @brief Checks to see if a certain configuration value is stored and attempt to return it's value as a integer
     *
     * @param identifier Identifier to check by.
     * @return :string
     **/
    std::string 	GetStringValue(std::string identifier);
    /**
     * @brief Checks to see if a certain configuration value is stored and attempt to return it's value as a integer
     *
     * @param identifier Identifier to check by.
     * @return bool
     **/
    bool		GetBooleanValue(std::string identifier);
    
    /**
     * @brief Destructor.
     *
     **/
    virtual 		~GameConfig		();
  };

}

#endif // MB_GAMECONFIG_H
