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


#include <MoleBox/Content/SpriteSheet.hpp>
#include <MoleBox/Content/Content.hpp>

namespace MB {
	
	namespace Content
	{

		SpriteSheet::SpriteSheet(std::string file, int frameWidth, int frameHeight)
		{
		  this->sheet.setTexture( MB::Content::Load<sf::Texture>(file) );
		  int width = this->sheet.getTextureRect().width;
		  int height = this->sheet.getTextureRect().height;
  
		  int xframes = width / frameWidth;
		  int yframes = height / frameHeight;
  
		  frameCount = xframes * yframes;
		  this->frame.width = frameWidth;
		  this->frame.height = frameHeight;
  
		  this->imageRect = this->sheet.getTextureRect();
  
		}

		SpriteSheet::~SpriteSheet()
		{

		}

		int SpriteSheet::FrameCount()
		{
		  return frameCount;
		}

		sf::Sprite SpriteSheet::GetFrame(int frame)
		{
		  sf::IntRect rect = this->frame;

		  int column = frame % 4;
		  int row = frame / 4;
  
		  rect.top = frame * this->imageRect.width;
		  rect.left = frame * this->imageRect.height;
  
		  this->sheet.setTextureRect(rect);
		  return this->sheet;
		}

	}
}