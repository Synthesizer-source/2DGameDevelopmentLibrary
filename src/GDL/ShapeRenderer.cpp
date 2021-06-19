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
     * @brief Destroy the Shape Renderer:: Shape Renderer object
     * 
     */
    ShapeRenderer::~ShapeRenderer() {
        delete this->shape;
    }
}