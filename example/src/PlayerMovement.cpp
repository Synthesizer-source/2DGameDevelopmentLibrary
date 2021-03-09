#include <PlayerMovement.hpp>
#include <GDL/Entity.hpp>
#include <Game.hpp>
#include <math.h>
const float PI = 3.14159265;

void PlayerMovement::init() {}

void PlayerMovement::update(const float timestep) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->moveLeft();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->moveRight();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->moveUp();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->moveDown();

    this->rotate();
}

void PlayerMovement::draw(sf::RenderTarget& target, sf::RenderStates states) const {

}

void PlayerMovement::moveUp()
{   

    this->getOwner()->setPosition(this->getOwner()->getPosition().x,
                      this->getOwner()->getPosition().y - this->speed);
}
void PlayerMovement::moveDown()
{
    this->getOwner()->setPosition(this->getOwner()->getPosition().x,
                      this->getOwner()->getPosition().y + this->speed);
}
void PlayerMovement::moveLeft()
{
    this->getOwner()->setPosition(sf::Vector2f(this->getOwner()->getPosition().x - this->speed,
                                   this->getOwner()->getPosition().y));
}
void PlayerMovement::moveRight()
{
    this->getOwner()->setPosition(sf::Vector2f(this->getOwner()->getPosition().x + this->speed,
                                   this->getOwner()->getPosition().y));
}

void PlayerMovement::rotate(){
    this->getOwner()->setRotation(90 + atan2(sf::Mouse::getPosition(*Game::window).y - 
        (this->getOwner()->getPosition().y),
        sf::Mouse::getPosition(*Game::window).x - 
        (this->getOwner()->getPosition().x)) * 180 / PI);
}

void PlayerMovement::setSpeed(float speed) {
    this->speed = speed;
}

float PlayerMovement::getSpeed() const {
    return this->speed;
}