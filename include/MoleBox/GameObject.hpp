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


#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <MoleBox/Export.hpp>
#include <SFML/System/Time.hpp>
#include <MoleBox/Types.hpp>


namespace MB {
/**
 * @brief GameObject defines common functions found through the API. Uses requires extending.
 **/  
  class MOLEBOX_API GameObject
  {
  public:
	  GameObject();
	  virtual ~GameObject();
    /**
    * @brief Update function should be called once a loop. The update function needs to perform all buisness logic of the game object
    *
    * @param elapsed The time that elapsed since the last frame. This takes a sfml class called sf::Time.
    * @param events These are a list of events for this loop.
    * 
    * @return void
    **/
    virtual void Update(sf::Time elapsed,EventList* events) = 0;
    /**
     * @brief Draw function should be called once a loop. The draw function should contain the calls for drawing the game object.
     *
     * @return void
     **/
    virtual void Draw() = 0;
  };

}
#endif // GAMEOBJECT_HPP
