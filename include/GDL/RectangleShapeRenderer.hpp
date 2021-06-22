#ifndef RECTANGLE_SHAPE_RENDERER_HPP
#define RECTANGLE_SHAPE_RENDERER_HPP
#include <SFML/Graphics.hpp>
#include <GDL/ShapeRenderer.hpp>

namespace gdl {
    class RectangleShapeRenderer : public ShapeRenderer {
    public:
        void setSize(const sf::Vector2f& size);
        void init() override;
        virtual RectangleShapeRenderer* clone() const{
            return new RectangleShapeRenderer(*this);
        }
    };
}
#endif // !RECTANGLE_SHAPE_RENDERER_HPP