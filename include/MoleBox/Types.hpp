/**
 *
 * 	Common definitions.
 *
 *
 *
 */


#include <list>
#include <vector>
#include <map>
#include <SFML/Window/Event.hpp>
#include <string>

#include <MoleBox/Export.hpp>
namespace MB {

  /**
   * @brief StrList is a list of strings using the standard types.
   **/
  typedef MOLEBOX_API std::list<std::string> 				StrList;
  /**
   * @brief StrList is a vector of strings using the standard types. 
   **/
  typedef MOLEBOX_API std::vector<std::string> 			StrVector;

  /**
   * @brief EventList is a map of SFML Events, using the enum EventType as the keys.
   **/
  typedef MOLEBOX_API std::map<sf::Event::EventType,sf::Event> 	EventList;
}
