#ifndef CIRCLE_SHAPE_RENDERER_HPP
#define CIRCLE_SHAPE_RENDERER_HPP
#include <SFML/Graphics.hpp>
#include <GDL/ShapeRenderer.hpp>
#include <GDL/Component.hpp>

namespace gdl {
    class CircleShapeRenderer : public ShapeRenderer {
    public:
        void setRadius(const float r);
        float getRadius() const;
        virtual void init() override;
        virtual CircleShapeRenderer* clone() const {
            return new CircleShapeRenderer(*this);
        }
    };
}
#endif // !CIRCLE_SHAPE_RENDERER_HPP