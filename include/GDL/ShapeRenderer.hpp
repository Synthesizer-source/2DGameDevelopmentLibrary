#ifndef SHAPE_RENDERER_HPP
#define SHAPE_RENDERER_HPP
#include <SFML/Graphics.hpp>
#include <GDL/Component.hpp>

namespace gdl {
    class ShapeRenderer : public Component {
    protected:
        sf::Shape* shape;
    public:
        void setColor(const sf::Color color);
        sf::Color getColor() const;
        virtual void init() override;
        virtual void update(const float timestep);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual ~ShapeRenderer() = 0;
    };
}
#endif // !SHAPE_RENDERER_HPP