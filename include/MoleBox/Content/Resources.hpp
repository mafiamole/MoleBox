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


#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <list>
#include <fstream>

#include <MoleBox/Export.hpp>
#include <MoleBox/Content/Content.hpp>
#include <MoleBox/Lua/Script.hpp>
#include <MoleBox/Types.hpp>


namespace MB {
  
  namespace Content {   
    /**
     * @brief Used to initialise resources at start.
     **/
    
    class MOLEBOX_API Resources
    {
    protected:
      /**
       * @brief Content directory
       **/
      std::string 			contentDir;
      /**
       * @brief Mutex to prevent multiple access on data.
       **/
      sf::Mutex 			mutex;
      /**
       * @brief Logs any and all errors.
       **/
      std::list<std::string> 		errorLog;
      /**
       * @brief List of content types supported.
       **/
      std::list<MB::Content::ID*> 	types;
    public:
      /**
       * @brief initiate the resources class, by setting the contentDir, MB::Content::location and the conten types in the types container.
       *
       * @param contentDir ... Defaults to "/".
       **/
					Resources(std::string contentDir = "/");
					      /**
       * @brief default destructor
       *
       **/
      virtual 				~Resources();
      
      /**
       * @brief Load a list of resources from a std::list of std::string. The resource need to be formatted as follows: <type> <location>
       *
       * @param resourceList List of resources
       * @return std:list< std::string, std::allocator< std::string > >
       **/
      std::list< std::string > 		LoadList(std::list< std::string > resourceList);
      /**
       * @brief Load a list of resources from a file. The resource need to be formatted as follows: <type> <location> on each line of the file.
       *
       * @param resourceList List of resources
       * @return std:list< std::string, std::allocator< std::string > >
       **/
      std::list< std::string > 		LoadList(std::string resourceListFile);
      /**
       * @brief Returns a list of all type identifiers.
       *
       * @return std:list< MB::Content::ID*, std::allocator< MB::Content::ID* > >
       **/
      
      std::list<MB::Content::ID*> 	GetIdentifiers();
      /**
       * @brief Add a new identifer.
       *
       * @param identifier A pointer to the identifier.
       * @return void
       **/
      void 				AddIdentifier(ID* identifier);

      
      /**
       * @brief returns a map of all resources. The reference parameter of the map is a string of the type identifer, and the value is a list of each file location.
       *
       * @return :map< std::string, std::less< std::string >, std::allocator< std::pair< const _Key, _Tp > > >
       **/
      std::map< std::string, StrVector > ResourceLists();
      
    };
  }
}
#endif // RESOURCES_HPP
