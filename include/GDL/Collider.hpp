#ifndef COLLIDER_HPP
#define COLLIDER_HPP
#include <SFML/Graphics.hpp>
#include <GDL/Component.hpp>
#include <vector>
namespace gdl {
    float distance(sf::Vector2f v1, sf::Vector2f v2);
    class Collider : public Component
    {
    private:
        std::vector<sf::Vector2f> xPos;
        std::vector<sf::Vector2f> yPos;
        sf::Vector2f base;
        sf::Vector2f maxX;
        sf::Vector2f maxY;
        sf::Vector2f size;
        sf::CircleShape startPointX;
        sf::CircleShape endPointX;
        sf::CircleShape startPointY;
        sf::CircleShape endPointY;
        sf::CircleShape projectionPointX;
        sf::CircleShape projectionPointY;
        sf::VertexArray axises;
        std::vector<sf::CircleShape> points;
        sf::VertexArray vertexArray;
        std::vector<sf::Vector2f> edgeCoordinates;
        sf::FloatRect rect;
    public:
        std::vector<sf::Vector2f> intersection(sf::Vector2f point);
        void setSize(const sf::Vector2f& size);
        void findLongestDistancePoints(const Collider& other);
        void calculateAxis();
        void calculatePointWhichIntersectsAxis();
        virtual void init() override;
        virtual void update(const float timestep);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual Collider* clone() const {
            return new Collider(*this);
        }
    };
}
#endif // !COLLIDER_HPP