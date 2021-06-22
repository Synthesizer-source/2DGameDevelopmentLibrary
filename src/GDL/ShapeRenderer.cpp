#include <GDL/ShapeRenderer.hpp>
#include <GDL/Entity.hpp>

namespace gdl {

    void ShapeRenderer::init() {}
    void ShapeRenderer::update(const float timestep) {}

    void ShapeRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        if (this->shape != nullptr) {
            states.transform = this->getOwner()->getTransform();
            target.draw(*this->shape, states);
        }
    }

    /**
     * @brief set shape color
     *
     * @param color
     */
    void ShapeRenderer::setColor(const sf::Color color) {
        if (this->shape != nullptr) this->shape->setFillColor(color);
    }

    /**
     * @brief get shape color
     *
     * @return sf::Color
     */
    sf::Color ShapeRenderer::getColor() const {
        return this->shape != nullptr ? this->shape->getFillColor() : sf::Color::Transparent;
    }

    /**
     * @brief get center position of shape
     * 
     * @return sf::Vector2f 
     */
    sf::Vector2f ShapeRenderer::getCenter() const {
        return { this->shape->getGlobalBounds().width / 2.0f,
                this->shape->getGlobalBounds().height / 2.0f };
    }

    /**
     * @brief get size of shape
     * 
     * @return sf::Vector2f 
     */
    sf::Vector2f ShapeRenderer::getSize() const {
        return { this->shape->getGlobalBounds().width, 
                this->shape->getGlobalBounds().height };
    }

    /**
     * @brief Destroy the Shape Renderer:: Shape Renderer object
     *
     */
    ShapeRenderer::~ShapeRenderer() {
        delete this->shape;
    }
}