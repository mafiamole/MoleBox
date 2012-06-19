#include "Content.h"

  
sf::Sprite MB::Content::NewSprite(std::string texture) 
{
 return sf::Sprite(MB::Content::Load<sf::Texture>(texture)); 
}

sf::Sound MB::Content::NewSound(std::string sound)

{
  return sf::Sound( MB::Content::Load<sf::SoundBuffer>(sound) );
}
  


MB::SpriteBatch::SpriteBatch(sf::Vector2u size, sf::RenderTarget* target, sf::RenderStates states) : sf::Drawable(),std::vector< sf::Drawable *>()
{
    this->initiate(size,target,states);
}

MB::SpriteBatch::SpriteBatch(sf::RenderTarget* target, sf::RenderStates states) : sf::Drawable(),std::vector< sf::Drawable *>() {

  this->initiate(target->getSize(),target,states);
  
}

void MB::SpriteBatch::initiate(sf::Vector2u size, sf::RenderTarget* target, sf::RenderStates states)
{
    this->target = target;
    this->renderState = renderState;
    //this->renderTexture.create(size.x,size.y);
}


MB::SpriteBatch::~SpriteBatch()
{

  
}


void MB::SpriteBatch::SetRenderState(sf::RenderStates states)
{
  this->renderState = states;
}


void MB::SpriteBatch::Draw()
{
  /*
   *  This implemenation does not work on Intel devices due to poor implemenation, by intel.
  this->renderTexture.clear();

  for ( std::vector< sf::Drawable* >::iterator itr = begin(); itr != end(); ++itr)
  {
    sf::Drawable *p_drawable = (*itr);
    this->renderTexture.draw(*p_drawable);
  }
  
  this->renderTexture.display();
  sf::Texture text;
  text = this->renderTexture.getTexture();
  sf::Sprite sprite( text );
  
  this->target->draw(sprite);
  */
  
  for ( std::vector< sf::Drawable* >::iterator itr = begin(); itr != end(); ++itr)
  { 
    sf::Drawable *p_drawable = (*itr);
    this->target->draw(*p_drawable,this->renderState);
  }
}

void MB::SpriteBatch::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
//    for(std::vector<sf::Drawable*>::iterator i = this->begin(); i != end(); ++i) {
//        target.draw(*(*i),states);
//    }
}
