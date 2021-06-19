#include <GDL/CircleShapeRenderer.hpp>
#include <GDL/Entity.hpp>

namespace gdl {

    void CircleShapeRenderer::init() {
        this->shape = new sf::CircleShape();
    }

    /**
     * @brief set circle radius
     * 
     * @param r 
     */
    void CircleShapeRenderer::setRadius(const float r) {
        ((sf::CircleShape*) this->shape)->setRadius(r);
    }

    /**
     * @brief get circle radius
     * 
     * @return float 
     */
    float CircleShapeRenderer::getRadius() const {
        return ((sf::CircleShape*) this->shape)->getRadius();
    }
}