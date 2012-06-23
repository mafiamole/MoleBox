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

#include <MoleBox/Content/Content.hpp>
#include <MoleBox/Lua/Script.hpp>
#include <MoleBox/ContainerDefinitions.hpp>
#include <list>
#include <fstream>

namespace MB {
  namespace Content {   
    
    class Resources
    {
    protected:
      sf::Mutex mutex;
      std::list<std::string> errorLog;
      std::list<MB::Content::ID*> types;
    public:
      Resources(std::string contentDir = "/");
      virtual ~Resources();
      
      std::list< std::string > LoadList(std::list< std::string > resourceList);
      std::list< std::string > LoadList(std::string resourceListFile);
      std::list<MB::Content::ID*> GetIdentifiers();
      void AddIdentifier(ID* identifier);
      MB::Lua::LuaScript* LoadScript(std::string scriptFile);
      std::map< std::string, Types::StrVect > ResourceLists();
      
    };
  }
}
#endif // RESOURCES_HPP