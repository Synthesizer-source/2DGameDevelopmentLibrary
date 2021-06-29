#ifndef COLLIDER_HPP
#define COLLIDER_HPP
#include <SFML/Graphics.hpp>
#include <GDL/Component.hpp>
#include <vector>
namespace gdl {
    class Collider : public Component
    {
    private:
        std::vector<sf::Vector2f> xPos;
        std::vector<sf::Vector2f> yPos;
        sf::Vector2f base;
        sf::Vector2f maxX;
        sf::Vector2f maxY;
        sf::Vector2f size;
        sf::VertexArray axises;
        sf::VertexArray vertexArray;
        std::vector<sf::Vector2f> edgeCoordinates;
        std::vector<sf::Vector2f> intersection(const sf::Vector2f& point);
        void calculateAxis();
    public:
        void setSize(const sf::Vector2f& size);
        virtual void init() override;
        virtual void update(const float timestep);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual Collider* clone() const {
            return new Collider(*this);
        }
    };
}
#endif // !COLLIDER_HPP