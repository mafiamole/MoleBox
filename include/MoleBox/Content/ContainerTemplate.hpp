#ifndef CONTAINERTEMPLATE_HPP
#define CONTAINERTEMPLATE_HPP

#include <SFML/System/Mutex.hpp>
#include <MoleBox/Export.hpp>
#include <MoleBox/Content/ID.hpp>

namespace MB {
  
  namespace Content {
  
    /**
     * @brief Enumeration containing different types of errors that can occur in the content loader system
     **/
    enum ERR_TYPE { OTHER, COULD_NOT_LOAD, NOT_IMPLEMENTED };
    
    class MOLEBOX_API Exception
    {
      std::string resource;
      
      ERR_TYPE type;
      
    public:
      /**
       * @brief Content::Exception initialises the exception by storing the resource name and ERR_TYPE value passed
       *
       * @param type ...
       * @param resource ...
       **/
      Exception(ERR_TYPE type,std::string resource);
      
      /**
       * @brief Returns an easy to read English version of the exception.
       *
       * @return :string
       **/
      std::string toString();
      
    };

      static std::string location;
  
    /**
    * @brief This struct contains the common functions and members for all container classes.
    * 
    * T is required to be the type that the resource needs to be stored as , (eg, if it is a pointer or const reference) 
    **/
    template <class T> struct Container_Base
    {
      std::map<std::string,T> contents;
      
      sf::Mutex mutex;
      
      StrVector List()
      {
	typename std::map<std::string, T>::iterator contentItr;
	StrVector returnList;
	
	for ( contentItr = this->contents.begin(); contentItr != contents.end();contentItr++)
	{
	  returnList.push_back( (*contentItr).first );
	}
	
	return returnList;
      } 
    };

    /**
     * @brief Template for a container type.
     **/
    template <typename T> class MOLEBOX_API Container {
      Container_Base<T> base;
    public:
      
      /**
       * @brief Default constructor
       *
       **/
      Container() {}
      /**
       * @brief default destructor
       *
       **/
      ~Container() {}
      
      /**
       * @brief Return an instance of the container type
       *
       * @return Container< T >&
       **/
      static Container<T>& I()
      {
	static Container<T> container;
	return container;	
      }
      
      /**
       * @brief Load some content from file. Always throws MB::Content::Exception. Specailisation is needed to make things usefull...
       * 
       * @param fileLocation the location of the file.
       * @return const T&
       **/
      const T& Load(std::string fileLocation)
      {
	throw MB::Content::Exception(NOT_IMPLEMENTED,fileLocation);
      }
      
      /**
       * @brief List all items of this content type.
       *
       * @return MB:StrVector
       **/
      StrVector List()
      {
	return this->base.List();
      }
      
      /**
       * @brief REturn a identifier object for this class.
       *
       * @return MB:Content::ID*
       **/
      ID* GetID()
      {
	return new ID("");
      }
      
    };

      
    
    
  }
}
#endif // CONTAINERTEMPLATE_HPP