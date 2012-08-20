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


#ifndef MB_ACTIONS_KEYBOARD_HPP
#define MB_ACTIONS_KEYBOARD_HPP

#include <MoleBox/Export.hpp>
#include <MoleBox/Actions/Action.hpp>


namespace MB {

  namespace Actions {

    /**
     * @brief An action event based around an keyboard event.
     **/
    class MOLEBOX_API Keyboard : public MB::Actions::Action
    {
    private:
      bool 		keyDown; // true if the changed from being unpressed to pressed.
      bool 		keyPressed; // weather the key is simply down.
      sf::Keyboard::Key key;
    public:
      /**
       * @brief Sets the key to bind with on initalisation
       *
       * @param key key to bind to this action
       **/
			Keyboard(sf::Keyboard::Key key);
      /**
       * @brief Nothing to remove.
       *
       **/
      virtual 		~Keyboard();
      /**
       * @brief Update this action with the latest keyboard input
       *
       * @param elapsed Time since last update
       * @param events Input event list
       * @return void
       **/
      virtual void 	Update(sf::Time elapsed, MB::EventList* events);
      /**
       * @brief Returns if a key is down
       *
       * @return bool
       **/
      virtual bool 	IsActive();
      /**
       * @brief Returns true if the key changed from being pressed to not, and vice versa
       *
       * @return bool
       **/
      virtual bool 	HasChanged();

    };

  }

}

#endif // MB_ACTIONS_KEYBOARD_HPP
