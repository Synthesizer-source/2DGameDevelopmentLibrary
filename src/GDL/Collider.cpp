#include <GDL/Collider.hpp>
#include <GDL/Entity.hpp>
#include <GDL/Utils.hpp>

namespace gdl {
    void Collider::init() {
        // this->rect.left = this->getOwner()->getPosition().x;
        // this->rect.top = this->getOwner()->getPosition().y;
    }
    void Collider::update(const float timestep) {
        // this->rect.left = (this->getOwner()->getPosition() - this->getOwner()->getOrigin()).x;
        // this->rect.top = (this->getOwner()->getPosition() - this->getOwner()->getOrigin()).y;
        // gdl::utils::print(gdl::utils::toString(getOwner()->getTransform().transformPoint(100, 100)));
    }
    void Collider::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform = this->getOwner()->getTransform();
        target.draw(this->vertexArray, states);

        for (sf::CircleShape s : points) {
            states.transform = this->getOwner()->getTransform();
            target.draw(s, states);
        }
    }

    void Collider::setSize(const sf::Vector2f& size) {
        this->rect.width = size.x;
        this->rect.height = size.y;
        sf::VertexArray vertexArr(sf::LinesStrip, 5);
        vertexArr[0].position = sf::Vector2f({ 0, 0 });
        vertexArr[0].color = sf::Color::Green;
        vertexArr[1].position = sf::Vector2f({ 0, size.y });
        vertexArr[1].color = sf::Color::Green;
        vertexArr[2].position = sf::Vector2f({ size.x, size.y });
        vertexArr[2].color = sf::Color::Green;
        vertexArr[3].position = sf::Vector2f({ size.x, 0 });
        vertexArr[3].color = sf::Color::Green;
        vertexArr[4].position = sf::Vector2f({ 0, 0 });
        vertexArr[4].color = sf::Color::Green;
        this->vertexArray = vertexArr;
        gdl::utils::print("Owner : " + gdl::utils::toString(getOwner()->getPosition()));
        edgeCoordinates.push_back({ sf::Vector2f({0, 0}) });
        edgeCoordinates.push_back({ sf::Vector2f({0, size.y}) });
        edgeCoordinates.push_back({ sf::Vector2f({size.x, size.y}) });
        edgeCoordinates.push_back({ sf::Vector2f({size.x, 0}) });

        for (const sf::Vector2f& i : edgeCoordinates) {
            sf::CircleShape c1(10);
            c1.setOrigin({ sf::Vector2f(5, 5) });
            c1.setPosition(i - c1.getOrigin());
            points.push_back(c1);
            gdl::utils::print(gdl::utils::toString(i));
        }
    }

    const sf::FloatRect& Collider::getBound() const {
        return this->rect;
    }
}