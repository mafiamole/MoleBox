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


#ifndef MB_CONTENT_SPRITESHEET_H
#define MB_CONTENT_SPRITESHEET_H

#include <string>

#include <SFML/Graphics/Sprite.hpp>

#include <MoleBox/Export.hpp>


namespace MB {

  namespace Content {

    /**
     * @brief Represents a basic sprite sheet with all elements of the same size.
     **/
    class MOLEBOX_API SpriteSheet
    {
    protected:
      sf::Sprite 	sheet;
      int 		frameCount;
      sf::IntRect 	frame;
      sf::IntRect 	imageRect;
    public:
      /**
       * @brief  Calculates the frame dimensions from the frame width, height and sheet size.
       *
       * @param file The file in which to read the sprite froms.
       * @param frameWidth Width of the frame
       * @param frameHeight Height of the frames.
       **/
      SpriteSheet(std::string file, int frameWidth, int frameHeight);
      virtual 		~SpriteSheet();
      int 		FrameCount();
      sf::Sprite	GetFrame(int frame);
    };

  }

}

#endif // MB_CONTENT_SPRITESHEET_H
