#include <GDL/Collider.hpp>
#include <GDL/Entity.hpp>
#include <GDL/Utils.hpp>
#include <math.h>

#define PI 3.14159265

namespace gdl {

    void Collider::init() {
        startPointX.setRadius(10);
        startPointX.setOrigin({ sf::Vector2f(10, 10) });
        startPointX.setFillColor(sf::Color::Green);
        endPointX.setRadius(10);
        endPointX.setOrigin({ sf::Vector2f(10, 10) });
        endPointX.setFillColor(sf::Color::Blue);
        startPointY.setRadius(10);
        startPointY.setOrigin({ sf::Vector2f(10, 10) });
        startPointY.setFillColor(sf::Color::Green);
        endPointY.setRadius(10);
        endPointY.setOrigin({ sf::Vector2f(10, 10) });
        endPointY.setFillColor(sf::Color::Blue);
        projectionPointX.setRadius(10);
        projectionPointX.setOrigin({ sf::Vector2f(10, 10) });
        projectionPointX.setFillColor(sf::Color::Red);
        projectionPointY.setRadius(10);
        projectionPointY.setOrigin({ sf::Vector2f(10, 10) });
        projectionPointY.setFillColor(sf::Color::Red);
    }

    void Collider::update(const float timestep) {
        this->calculatePointWhichIntersectsAxis();
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
        target.draw(startPointX, states);
        target.draw(endPointX, states);
        target.draw(projectionPointX, states);
        target.draw(startPointY, states);
        target.draw(endPointY, states);
        target.draw(projectionPointY, states);
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
        edgeCoordinates.push_back({ getOwner()->getPosition() - getOwner()->getOrigin() + sf::Vector2f({0, 0}) });
        edgeCoordinates.push_back({ getOwner()->getPosition() - getOwner()->getOrigin() + sf::Vector2f({0, size.y}) });
        edgeCoordinates.push_back({ getOwner()->getPosition() - getOwner()->getOrigin() + sf::Vector2f({size.x, size.y}) });
        edgeCoordinates.push_back({ getOwner()->getPosition() - getOwner()->getOrigin() + sf::Vector2f({size.x, 0}) });

        for (const sf::Vector2f& i : edgeCoordinates) {
            sf::CircleShape c1(10);
            c1.setOrigin({ sf::Vector2f(5, 5) });
            c1.setPosition(i - c1.getOrigin() - getOwner()->getPosition() + getOwner()->getOrigin());
            points.push_back(c1);
            gdl::utils::print(gdl::utils::toString(i));
        }

        calculateAxis();
    }

    void Collider::findLongestDistancePoints(const Collider& other) {
        sf::Vector2f one;
        sf::Vector2f two;
        sf::Vector2f currMax;
        float currMaxDistance = 0.0f;

        for (sf::Vector2f i : edgeCoordinates) {
            for (sf::Vector2f j : other.edgeCoordinates) {
                float d = distance(i, j);
                if (d > currMaxDistance) {
                    currMaxDistance = d;
                    one = i;
                    two = j;
                }

            }
        }

        utils::print(utils::toString(one) + " -- " + utils::toString(two));
    }

    float distance(sf::Vector2f v1, sf::Vector2f v2) {
        return std::sqrt(std::pow((v1.x - v2.x), 2) + std::pow((v1.y - v2.y), 2));
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

    void Collider::calculatePointWhichIntersectsAxis() {

        sf::Vector2f ownerPos = getOwner()->getPosition();
        float rotation = getOwner()->getRotation();
        float sin = std::sin(rotation * PI / 180.0f);
        float cos = std::cos(rotation * PI / 180.0f);
        float tan = std::tan(rotation * PI / 180.0f);
        float cot = 1 / tan;
        float startX = tan * ownerPos.x;
        float endX = cot * ownerPos.y;
        startPointX.setPosition({ ownerPos.x, startX });
        endPointX.setPosition({ endX, ownerPos.y });
        float distanceProjectionX = cos * (ownerPos.y - startX);
        projectionPointX.setPosition({ ownerPos.x + (distanceProjectionX * sin), ownerPos.y - (distanceProjectionX * cos) });

        float startY = -1 * tan * ownerPos.y;
        float endY = -1 * cot * ownerPos.x;
        startPointY.setPosition({ startY, ownerPos.y });
        endPointY.setPosition({ ownerPos.x, endY });
        float distanceProjectionY = cos * (ownerPos.x - startY);
        projectionPointY.setPosition({ ownerPos.x - (distanceProjectionY * cos), ownerPos.y - (distanceProjectionY * sin) });
        utils::print(utils::toString(projectionPointY.getPosition()));
    }

    const sf::FloatRect& Collider::getBound() const {
        return this->rect;
    }
}