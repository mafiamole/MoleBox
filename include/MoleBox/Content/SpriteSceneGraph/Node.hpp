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


#ifndef NODE_HPP
#define NODE_HPP


#include <list>

#include <SFML/Graphics/Sprite.hpp>

#include <MoleBox/Export.hpp>

/**
 * @brief Represents a node in a 'sprite scene graph'.
 *        Each node is capable of containing a number of child node in which it can pass transformations to.
 **/
class MOLEBOX_API Node
{
protected:
  Node* 		parent;
  std::list<Node*> 	children;
  sf::Sprite 		sprite;

public:
  /**
   * @brief Sets the sprite of the node and the nodes parent.
   *
   * @param sprite The sprite of the node
   * @param parent If applicable, the parent of the node. Defaults to 0.
   **/
			Node(sf::Sprite sprite, Node* parent = 0);
  /**
    * @brief Default destructor.
    *
    **/
  virtual 		~Node();       
  /**
   * @brief Set the parent node.
   *
   * @param parent The node to be the parent of this node.
   * @return void
   **/
  void			SetParent(Node * parent);
  /**
   * @brief Obtains a reference to the node's sprite
   *
   * @return sf::Sprite&
   **/
  const sf::Sprite & 	GetSprite();
  /**
   * @brief Adds a new child to the node. It also sets the child's parent.
   *
   * @param newChild the node to append to the child list.
   * @return void
   **/
  void 			AddChild(Node* newChild);   
  /**
   * @brief Rotate the sprite, and optionally the children as well
   *
   * @param angle Angle to rotate by
   * @param cascade Ensure that the child nodes and grandchild and so on and so forth will rotate as well by the same value. Defaults to true.
   * @return void
   **/
  void 			Rotate( float angle,bool cascade = true);
  /**
   * @brief Moves the sprite by a given x and y amount and optionally the children as well
   *
   * @param x The amount of pixels to move horizontally by.
   * @param y The amount of pixels to move vertically by.
   * @param cascade If child nodes and grandchild and so on and so forth will move as well by the same values. Defaults to true.
   * @return void
   **/
  void 			Translate( float x, float y, bool cascade = true);
  /**
   * @brief Scale the sprite by a given quantities and optionally the children as well
   *
   * @param xFactor Other than a horrific television show, this is the amount in pixels to increase the size of the sprite by horizontally
   * @param yFactor this is the amount in pixels to increase the size of the sprite by vertically
   * @param cascade ... Defaults to true.
   * @return void
   **/
  void 			Scale(float xFactor, float yFactor, bool cascade = true);
  

};

#endif // NODE_HPP
