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


#include <MoleBox/Content/SpriteSceneGraph/Node.hpp>

Node::Node(sf::Sprite sprite, Node* parent) : parent(parent), sprite(sprite)
{
  
}

Node::~Node()
{

}

void Node::SetParent(Node* parent)
{
  this->parent = parent;
}

const sf::Sprite & Node::GetSprite() 
{
  return this->sprite;
}

void Node::AddChild(Node* newChild)
{
  newChild->SetParent(this);
  this->children.push_back(newChild);
}

void Node::Rotate( float angle,bool cascade)
{
  this->sprite.rotate(angle);
  
  if (cascade)
  {
    std::list<Node*>::iterator itr;
    for (itr = this->children.begin(); itr != this->children.end(); itr++)
    {
	(*itr)->Rotate(angle,cascade);
    }
    
  }
}

void Node::Translate( float x, float y, bool cascade)
{
  this->sprite.move(x,y);
  
  if (cascade)
  {
    std::list<Node*>::iterator itr;
    for (itr = this->children.begin(); itr != this->children.end(); itr++)
    {
	(*itr)->Translate(x,y,cascade);
    }
    
  }
  
}

void Node::Scale(float xFactor, float yFactor, bool cascade) 
{
  this->sprite.scale(xFactor,yFactor);
  
  if (cascade)
  {
    std::list<Node*>::iterator itr;
    for (itr = this->children.begin(); itr != this->children.end(); itr++)
    {
	(*itr)->Scale(xFactor,yFactor,cascade);
    }
    
  }
  
}