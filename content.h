#ifndef CONTENT_H
#define CONTENT_H
#include <map>
#include <string>
#include <functional>
#include <stdlib.h>

/**
 * Allow simple types to be added as 'content'
 * 
 */
template <class T>
const T& ContentLoader(std::string value) {
      throw std::string("Content type has no implementation.");
  T emptyReturn;
  return emptyReturn;
}
/**
 * This template class is the general layout for a basic content loader container. 
 * This uses a standard library map with a method for loading the particular content into memory.
 */
template <class T> class ContentContainer {

private:
  /**
   * Map container for type T with a string key.
   */
  std::map<std::string,T> genericMedia;
public:
  /**
   * Method returns a single instance of this class.
   */
  static ContentContainer<T>& I() {
    static ContentContainer <T> instance;
    return instance;
  }
  /**
   * Loads and returns content of type T given a reference string.
   */
  const T& Load(std::string reference)
  {
    if (genericMedia.find(reference) == genericMedia.end() ) {
      
      std::pair<std::string, T> temp (reference,ContentLoader<T>(reference));
      
    }
    return genericMedia[reference];
  }
  
};
/**
 * Convenience class for loading T into memory.
 * 
 */
template <class T>
class Content {
public:
/**
 * Static method for calls the ContentContainer.load method for type T.
 */
 static const T& Load(std::string itemName) {
    return ContentContainer<T>::I().Load(itemName);
 }
 
 static T* Open(std::string itemName) {
    return ContentContainer<T>::I().Load(itemName);
 }
};


#endif