#ifndef PLAYER_MOVEMENT_HPP
#define PLAYER_MOVEMENT_HPP
#include <GDL/Component.hpp>

class PlayerMovement : public gdl::Component
{
private:
    float speed = 20;
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void rotate();

public:
    void setSpeed(float speed);
    float getSpeed() const;
    virtual void init() override;
    virtual void update(const float timestep);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual PlayerMovement* clone() const {
        return new PlayerMovement(*this);
    }
};


#endif // !PLAYER_MOVEMENT_HPP