#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <SFML/Graphics.hpp>

namespace gdl {
    class Entity;
    class Component : public sf::Drawable {
    private:
        Entity* entity;
    public:

        void setOwner(Entity* entity);
        Entity* getOwner() const;
        virtual void init();
        virtual void update(const float timestep) = 0;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {};
        virtual Component* clone() const = 0;
        virtual ~Component() = default;
    };
}



#endif // COMPONENT_HPP