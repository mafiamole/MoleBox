#ifndef SFML_CONTAINERDEF_H
#define SFML_CONTAINERDEF_H
/**
 * This definition is used by the SFMLGame and SFMLGameComponent classes and their subclasses.
 * It holds a list of events and uses the event type as a key to allow simple locating by the user.
 */
typedef std::map<sf::Event::EventType,sf::Event> EventList;
#endif