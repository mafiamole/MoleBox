#ifndef SPRITEBATCH_HPP
#define SPRITEBATCH_HPP

#include <vector>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <MoleBox/Export.hpp>
#include <MoleBox/Content/Container.hpp>

namespace MB

{
  namespace Content {
    
    /**
     * @brief Convenience class for storing and iterating over a number of sf::Drawable* objects.
     **/
    class MOLEBOX_API SpriteBatch : public sf::Drawable, public std::vector<sf::Drawable *> {
	
      private:
	sf::RenderTarget* 	target;
	sf::RenderStates 	renderState;
	//sf::RenderTexture renderTexture;
	/**
	 * @brief Sets various class parameters.
	 *
	 * @param size  Render area size
	 * @param target what to render the sprites to
	 * @param states render states for all sprites. Defaults to sf::RenderStates::Default.
	 * @return void
	 **/
	void 			initiate(sf::Vector2u size, sf::RenderTarget* target, sf::RenderStates states = sf::RenderStates::Default);
      public:
	/**
	 * @brief Constructor that calls initiate to set variables.
	 *
	 * @param size Render area size
	 * @param target Target to render to
	 * @param states Render states for all sprites Defaults to sf::RenderStates::Default.
	 **/
				SpriteBatch(sf::Vector2u size, sf::RenderTarget* target, sf::RenderStates states = sf::RenderStates::Default);  
	/**
	 * @brief Overloaded constructor that assumes size is the same size of the target.
	 *
	 * @param target Target to render to 
	 * @param states Render states for all sprites Defaults to sf::RenderStates::Default.
	 **/
				SpriteBatch(sf::RenderTarget* target, sf::RenderStates states = sf::RenderStates::Default);
	
	/**
	 * @brief default destructor.
	 *
	 **/
				~SpriteBatch();
	
	/**
	 * @brief Set the render state.
	 *
	 * @param states Render states for all sprite Defaults to sf::RenderStates::Default.
	 * @return void
	 **/
	void 			SetRenderState(sf::RenderStates states = sf::RenderStates::Default);
	/**
	 * @brief Render to target.
	 *
	 * @return void
	 **/
	void Draw();
	/**
	 * @brief Render to different target.
	 *
	 * @param target Target to render to 
	 * @param states Render states for all sprites Defaults to sf::RenderStates::Default.
	 * @return void
	 **/
	virtual void 		draw(sf::RenderTarget& target,const sf::RenderStates states = sf::RenderStates::Default) const;
      };
      
  }

}
#endif // SPRITEBATCH_HPP