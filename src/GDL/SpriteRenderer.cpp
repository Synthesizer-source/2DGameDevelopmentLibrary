#include <GDL/SpriteRenderer.hpp>
#include <GDL/Entity.hpp>
#include <string>



namespace gdl {

/**
 * @brief GDL_DIR is GDL library path like C:/user/desktop/GDL
 * 
 */
#ifdef GDL_DIR
#define GDL_FOLDER_PATH GDL_DIR
#else
#define GDL_FOLDER_PATH "error"
#endif


    void SpriteRenderer::init() {}

    void SpriteRenderer::update(const float timestep) {}

    /**
     * @brief load texture with path of texture. You use absolute resource path is better.
     * 
     * @param pathTexture 
     */
    void SpriteRenderer::loadTexture(const char* pathTexture) {
        
        // Ex : ../resources/spaceship.png
        // GDL_FOLDER_PATH + std::string(pathTexture)
        try
        {
            if (!this->texture.loadFromFile(pathTexture))
            {
                throw "Not loading texture.";
            }
            else
            {
                this->sprite.setTexture(texture);
            }
        }
        catch (std::exception e)
        {
            std::cout << e.what() << "\n";
        }
    }

    void SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform = this->getOwner()->getTransform();
        target.draw(this->sprite, states);
    }

    /**
     * @brief get center position of sprite
     * 
     * @return sf::Vector2f 
     */
    sf::Vector2f SpriteRenderer::getCenter() const
    {
        return { this->sprite.getGlobalBounds().width / 2.0f,
                this->sprite.getGlobalBounds().height / 2.0f };
    }

    /**
     * @brief get size of sprite
     * 
     * @return sf::Vector2f 
     */
    sf::Vector2f SpriteRenderer::getSize() const
    {
        return { this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().height };
    }
}