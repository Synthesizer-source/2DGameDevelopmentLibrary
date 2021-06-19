#include <GDL/RectangleShapeRenderer.hpp>
#include <GDL/Entity.hpp>

namespace gdl{

    void RectangleShapeRenderer::init(){
        this->shape = new sf::RectangleShape();
    }

    /**
     * @brief set rectangle size
     * 
     * @param size 
     */
    void RectangleShapeRenderer::setSize(const sf::Vector2f& size){
        ((sf::RectangleShape*) this->shape)->setSize(size);
    }
    
    /**
     * @brief get rectangle size
     * 
     * @return const sf::Vector2f& 
     */
    const sf::Vector2f& RectangleShapeRenderer::getSize() const{
        return ((sf::RectangleShape*) this->shape)->getSize();
    }
}