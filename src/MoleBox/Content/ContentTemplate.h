#ifndef CONTENTTEMPLATE_H
#define CONTENTTEMPLATE_H
#include <map>
#include <string>
#include <functional>
#include <vector>
#include <stdlib.h>
#include <SFML/System/Mutex.hpp>

namespace MB {
  
  namespace Content {
    
    typedef std::vector<std::string> StrVect;

    template <class T,class C> struct Container_Base
    {
      
    public:
      std::map<std::string,C> contents;
      sf::Mutex mutex;
      StrVect List()
      {
	typename std::map<std::string, C>::iterator contentItr;
	StrVect returnList;
	
	for ( contentItr = this->contents.begin(); contentItr != contents.end();contentItr++)
	{
	  returnList.push_back( (*contentItr).first );
	}
	
	return returnList;
      } 
      
    };

    template <typename T> class Container {
      Container_Base<T,T> base;
    public:
      
      static Container<T>& I()
      {
	static Container<T> container;
	return container;	
      }
      
      const T& Load(std::string reference)
      {
	throw "Feature not implemented";
      }
      
      StrVect List()
      {
	return this->base.List();
      }
      
    };
  
  template <typename T> static const T& Load(std::string name) {
      return Container<T>::I().Load(name);
    }
    
  template <typename T> static StrVect List() {
    return Container<T>::I().List();
    }  
  
  }
}
#endif