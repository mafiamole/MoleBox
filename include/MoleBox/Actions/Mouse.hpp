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


#ifndef MB_ACTIONS_MOUSE_HPP
#define MB_ACTIONS_MOUSE_HPP

#include <MoleBox/Export.hpp>
#include <MoleBox/Actions/Action.hpp>


namespace MB {

  namespace Actions {

    /**
     * @brief The Mouse Action event is used to bind an action with a mouse button press.
     **/
    class MOLEBOX_API Mouse : public MB::Actions::Action
    {
    private:
      bool buttonDown;
      sf::Mouse::Button button;
      bool buttonPressed;
    public:
      /**
       * @brief Initalise the Mouse action event with the mouse button.
       *
       * @param button The button to register with this action event.
       **/
      Mouse(sf::Mouse::Button button);
      /**
       * @brief Default destructor.
       *
       **/
      virtual ~Mouse();
      /**
       * @brief Return the global postion of the mouse cursor.
       *
       * @return sf::Vector2i
       **/
      sf::Vector2i Position();
      /**
       * @brief Returns the position of the mouse cursor relative to a particular window
       *
       * @param relativeTo the position relativ to a particular window.
       * @return sf::Vector2i
       **/
      sf::Vector2i Position(const sf::Window& relativeTo);
      /**
       * @brief returns if the button is up.
       *
       * @return bool
       **/
      bool ButtonReleased();
      /**
       * @brief returns if the button is down
       *
       * @return bool
       **/
      bool ButtonPressed();
      /**
       * @brief Updates the mouse action event
       *
       * @param elapsed The time since the last update
       * @param events List of input events.
       * @return void
       **/
      virtual void Update(sf::Time elapsed, MB::EventList* events);
      /**
       * @brief Returns if the mouse button is currently down.
       *
       * @return bool
       **/
      virtual bool IsActive();
      /**
       * @brief Returns true if the mouse button changed from being pressed to unpressed (and vice versa) on the last update.
       *
       * @return bool
       **/
      virtual bool HasChanged();

    };

  }

}

#endif // MB_ACTIONS_MOUSE_HPP
