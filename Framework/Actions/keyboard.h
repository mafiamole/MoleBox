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


#ifndef MB_KEYBOARD_H
#define MB_KEYBOARD_H

#include "../action.h"


namespace MB {

  class Keyboard : public MB::Action
    {
    private:
      bool keyDown; // true if the changed from being unpressed to pressed.
      bool keyPressed; // weather the key is simply down.
      sf::Keyboard::Key key;
    public:
	Keyboard(sf::Keyboard::Key key);
	virtual ~Keyboard();
	virtual void Update();
	virtual bool IsActive(); // returns if the button is down.
	virtual bool HasChanged(); // returns if there was a change in state // either up or down.
    };

}

#endif // MB_KEYBOARD_H
