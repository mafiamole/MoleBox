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


#include <MoleBox/Content/Resources.hpp>
#include <MoleBox/Lua/Script.hpp>

namespace MB
{
	namespace Content
	{
		Resources::Resources(std::string contentDir)
		{
		  this->contentDir = contentDir;
		  MB::Content::location = contentDir;
		  types.push_back(MB::Content::GetID<sf::Texture>());
		  types.push_back(MB::Content::GetID<sf::SoundBuffer>());
		  types.push_back(MB::Content::GetID<sf::Music*>());
		  //types.push_back(MB::Content::GetID<MB::Lua::Script*>());
  
		}


		Resources::~Resources()
		{

		}



		std::list<std::string> Resources::LoadList(std::list< std::string > resourceList)
		{

		  std::list< std::string >::iterator itr;
  
		  for (itr = resourceList.begin(); itr != resourceList.end(); itr++)
		  {
    
			std::string file = (*itr).substr((*itr).find(" ") + 1);
			std::string contentType = (*itr).substr(0,(*itr).find(" "));
			std::size_t position = file.find_last_of(".");
    
			std::string fileExt = file.substr(position + 1);

			std::list<MB::Content::ID*>::iterator typeItr;
    
			bool resolvedType = false;
			bool resolvedExtension = false;
			MB::Content::ID* ID;
    
			for (typeItr = this->types.begin(); typeItr != this->types.end(); typeItr++)
			{

			  ID = (*typeItr);
            
			  if ( ID->Type() == contentType)
			  {
			resolvedType = true;
			  }
      
			  if ( ID->CheckExtension(fileExt) )
			  {
			resolvedExtension = true;
			  }
      
			  if ( resolvedType && resolvedExtension)
			break;
      
			}

			if (!resolvedType)
			{
			  this->errorLog.push_back( "Unknown content type " + contentType);
			}
			if (!resolvedExtension)
			{
			  this->errorLog.push_back( "Unknown extention '"+ fileExt + "'  for content of type:" + contentType );
			}
			try
			{
			  if (resolvedType && resolvedExtension)
			  {
			ID->Load(file);
	
			  }
      
			}
			catch (MB::Content::Exception exception)
			{
			  this->errorLog.push_back(exception.toString());
			}
    
		  }

		  return this->errorLog;
  
		}

		std::list< std::string > Resources::LoadList(std::string resourceListFile)
		{
  
		  std::ifstream file(resourceListFile.c_str());
		  std::list<std::string> resourceList;

		  if (file.is_open()) {

			while (!file.eof())
			{
      
			  std::string row;
			  std::getline(file,row);
			  if (row.size() > 0) {
			resourceList.push_back(row);
			  }
			}
			file.close();
		  }
  
		  else
		  {
			throw MB::Content::Exception(MB::Content::COULD_NOT_LOAD,"resources.txt");
		  }
		  return this->LoadList(resourceList);
  
		}

		void Resources::AddIdentifier(ID* identifier)
		{
		  this->types.push_back(identifier);
		}

		std::list<MB::Content::ID*> Resources::GetIdentifiers()
		{
		  return this->types;
		}

		std::map< std::string, MB::StrVector > Resources::ResourceLists() 
		{
		  sf::Lock(this->mutex);
		  std::map<std::string,MB::StrVector> ResourceList;
			std::list<MB::Content::ID*>::iterator typeItr;
    
			for (typeItr = this->types.begin(); typeItr != this->types.end(); typeItr++)
			{
			  ID* resource = (*typeItr);
			  resource->Type();
      
			  std::pair<std::string,MB::StrVector> insertPair(resource->Type(),resource->List());
			  ResourceList.insert(insertPair);
			}
  
		  return ResourceList;
		}
	}
}
