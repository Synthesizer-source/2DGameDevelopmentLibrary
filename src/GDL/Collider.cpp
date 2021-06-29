#include <GDL/Collider.hpp>
#include <GDL/Entity.hpp>
#include <GDL/Utils.hpp>
#include <math.h>

#define PI 3.14159265

namespace gdl {

    void Collider::init() {}

    void Collider::update(const float timestep) {
        sf::Vector2f ownerPos = getOwner()->getPosition();
        float rotation = getOwner()->getRotation();
        float sin = std::sin(rotation * PI / 180.0f);
        float cos = std::cos(rotation * PI / 180.0f);
        float tan = std::tan(rotation * PI / 180.0f);
        float cot = 1 / tan;
        maxX = getOwner()->getTransform().transformPoint(sf::Vector2f(size.x, 0));
        maxY = getOwner()->getTransform().transformPoint(sf::Vector2f(0, size.y));
        xPos = intersection(maxX);
        yPos = intersection(maxY);
    }

    void Collider::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform = this->getOwner()->getTransform();
        target.draw(this->vertexArray, states);

        sf::Transform transformAxises;
        float rotation = getOwner()->getRotation();
        transformAxises.rotate(rotation);
        states.transform = transformAxises;
        target.draw(axises, states);

        sf::Transform transformBase; // 0,0 base point, top-left corner
        states.transform = transformBase;

        for (int i = 0; i < xPos.size(); i++) {
            sf::CircleShape c;
            c.setRadius(10);
            c.setOrigin({ sf::Vector2f(10, 10) });
            if (i % 3 == 0) c.setFillColor(sf::Color::Green);
            else if (i % 3 == 1) c.setFillColor(sf::Color::Blue);
            else c.setFillColor(sf::Color::Red);
            c.setPosition(xPos[i]);
            target.draw(c, states);
            c.setPosition(yPos[i]);
            target.draw(c, states);
        }
    }

    void Collider::setSize(const sf::Vector2f& size) {
        this->size = size;
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
        edgeCoordinates.push_back({ getOwner()->getPosition() - getOwner()->getOrigin() + sf::Vector2f({0, 0}) });
        edgeCoordinates.push_back({ getOwner()->getPosition() - getOwner()->getOrigin() + sf::Vector2f({0, size.y}) });
        edgeCoordinates.push_back({ getOwner()->getPosition() - getOwner()->getOrigin() + sf::Vector2f({size.x, size.y}) });
        edgeCoordinates.push_back({ getOwner()->getPosition() - getOwner()->getOrigin() + sf::Vector2f({size.x, 0}) });
        calculateAxis();
    }

    void Collider::calculateAxis() {
        sf::VertexArray vertexArr(sf::Lines, 8);
        sf::Vertex originX = sf::Vertex({ 0, 0 });
        sf::Vertex xAxis = sf::Vertex({ 3000, 0 }, sf::Color::Blue);
        sf::Vertex originY = sf::Vertex({ 0, 0 });
        sf::Vertex yAxis = sf::Vertex({ 0, 3000 }, sf::Color::Red);
        sf::Vertex originNegativeX = sf::Vertex({ 0, 0 });
        sf::Vertex negativeXAxis = sf::Vertex({ -3000, 0 }, sf::Color::Blue);
        sf::Vertex originNegativeY = sf::Vertex({ 0, 0 });
        sf::Vertex negativeYAxis = sf::Vertex({ 0, -3000 }, sf::Color::Red);
        vertexArr[0] = originX;
        vertexArr[1] = (xAxis);
        vertexArr[2] = originY;
        vertexArr[3] = (yAxis);
        vertexArr[4] = originNegativeX;
        vertexArr[5] = negativeXAxis;
        vertexArr[6] = originNegativeY;
        vertexArr[7] = negativeYAxis;
        axises = vertexArr;
    }

    std::vector<sf::Vector2f> Collider::intersection(const sf::Vector2f& point) {
        std::vector<sf::Vector2f> res;
        float rotation = getOwner()->getRotation();
        float sin = std::sin(rotation * PI / 180.0f);
        float cos = std::cos(rotation * PI / 180.0f);
        float tan = std::tan(rotation * PI / 180.0f);
        float cot = 1 / tan;
        float startX = tan * point.x;
        float endX = cot * point.y;
        float distanceProjectionX = cos * (point.y - startX);
        res.push_back({ point.x, startX });
        res.push_back({ endX, point.y });
        res.push_back({ point.x + (distanceProjectionX * sin), point.y - (distanceProjectionX * cos) });
        float startY = -1 * tan * point.y;
        float endY = -1 * cot * point.x;
        float distanceProjectionY = cos * (point.x - startY);
        res.push_back({ startY, point.y });
        res.push_back({ point.x, endY });
        res.push_back({ point.x - (distanceProjectionY * cos), point.y - (distanceProjectionY * sin) });
        return res;
    }
}