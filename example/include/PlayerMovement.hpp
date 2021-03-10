#ifndef PLAYER_MOVEMENT_HPP
#define PLAYER_MOVEMENT_HPP
#include <GDL/Component.hpp>

class PlayerMovement : public gdl::Component
{
private:
    float currentSpeed = 0.0f;
    float maxSpeed = 10;
    float acceleration = 5.0f;
    sf::Vector2f velocity;
    void rotate();

public:
    void setMaxSpeed(float speed);
    float getMaxSpeed() const;
    virtual void init() override;
    virtual void update(const float timestep);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual PlayerMovement* clone() const {
        return new PlayerMovement(*this);
    }
};


#endif // !PLAYER_MOVEMENT_HPP