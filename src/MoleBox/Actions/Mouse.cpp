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


#include <MoleBox/Actions/Mouse.hpp>

namespace MB
{
	namespace Actions
	{
		
		Mouse::Mouse(sf::Mouse::Button button) : button(button),buttonDown( sf::Mouse::isButtonPressed(button) ) , buttonPressed( sf::Mouse::isButtonPressed(button) )
		{

		}
		Mouse::~Mouse()
		{

		}

		void Mouse::Update(sf::Time elapsed, MB::EventList* events)
		{
			MB::Actions::Action::Update(elapsed, events);
    
		  bool getButtonPress = sf::Mouse::isButtonPressed(this->button);
  
		  if ( this->buttonDown != getButtonPress ) {
    
			this->buttonPressed = getButtonPress;
    
			this->buttonDown = !this->buttonDown;
    
		  }
		}

		bool Mouse::IsActive()
		{
			return sf::Mouse::isButtonPressed(this->button) && WindowFocus;
		}

		bool Mouse::HasChanged()
		{
		  return this->buttonDown;
		}

		sf::Vector2i Mouse::Position() {
		  return sf::Mouse::getPosition();
		}

		sf::Vector2i Mouse::Position(const sf::Window& relativeTo) {
		  return sf::Mouse::getPosition(relativeTo);
		}

		bool Mouse::ButtonPressed()
		{
		  return this->buttonPressed;
		}

		bool Mouse::ButtonReleased()
		{
		  return !this->buttonPressed;
		}
	}
}
