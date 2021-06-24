#include <PlayerMovement.hpp>
#include <GDL/Entity.hpp>
#include <Game.hpp>
#include <math.h>
const float PI = 3.14159265;

void PlayerMovement::init() {}

void PlayerMovement::update(const float timestep) {
    maxSpeed = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->getOwner()->setPosition(this->getOwner()->getPosition() + sf::Vector2f(-maxSpeed, 0));
        // velocity.x -= (acceleration * timestep);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->getOwner()->setPosition(this->getOwner()->getPosition() + sf::Vector2f(maxSpeed, 0));

        // velocity.x += (acceleration * timestep);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->getOwner()->setPosition(this->getOwner()->getPosition() + sf::Vector2f(0, -maxSpeed));

        // velocity.y -= (acceleration * timestep);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->getOwner()->setPosition(this->getOwner()->getPosition() + sf::Vector2f(0, maxSpeed));

        // velocity.y += (acceleration * timestep);
    }

    // if (velocity.y > maxSpeed) velocity.y = maxSpeed;
    // if (velocity.y < -maxSpeed) velocity.y = -maxSpeed;
    // if (velocity.x < -maxSpeed) velocity.x = -maxSpeed;
    // if (velocity.x > maxSpeed) velocity.x = maxSpeed;

    // this->getOwner()->setPosition(this->getOwner()->getPosition() + velocity);
    // float actualspeed = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));

    // if (actualspeed > maxSpeed)
    // {
    //     velocity *= maxSpeed / actualspeed;
    // }

    this->rotate();
}

void PlayerMovement::draw(sf::RenderTarget& target, sf::RenderStates states) const {

}

void PlayerMovement::rotate() {
    this->getOwner()->setRotation(90 + atan2(sf::Mouse::getPosition(*Game::window).y -
        (this->getOwner()->getPosition().y),
        sf::Mouse::getPosition(*Game::window).x -
        (this->getOwner()->getPosition().x)) * 180 / PI);
}

void PlayerMovement::setMaxSpeed(float speed) {
    this->maxSpeed = speed;
}

float PlayerMovement::getMaxSpeed() const {
    return this->maxSpeed;
}