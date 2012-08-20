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


#ifndef ACTION_H
#define ACTION_H

#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

#include <MoleBox/Export.hpp>
#include <MoleBox/Types.hpp>

namespace MB
{
  
  namespace Actions
  {

    /**
     * @brief Base class for defining an 'action'. Which is an abstract idea for somthing that would happend on an event?
     **/
    class MOLEBOX_API Action
    {
    protected:
      bool WindowFocus;
      sf::Event::EventType eventType;
    public:
      /**
       * @brief Action potential!
       *
       **/
      Action();
      /**
       * @brief No potential
       *
       **/
      virtual ~Action();
      /**
       * @brief Update the action.
       *
       * @param elapsed Time elapsed since last update
       * @param events Pass all input events.
       * @return void
       **/
      virtual void Update( sf::Time elapsed, EventList* events );
      /**
       * @brief Returns if this actions state is active or not.
       *
       * @return bool
       **/
      virtual bool IsActive();
      /**
       * @brief Returns if the action state has changed on the last update.
       *
       * @return bool
       **/
      virtual bool HasChanged();


    };

  }
}

#endif
