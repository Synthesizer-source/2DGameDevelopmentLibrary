#ifndef CUSTOM_COMPONENT_HPP
#define CUSTOM_COMPONENT_HPP

#include <GDL/Component.hpp>

class CustomComponent: public gdl::Component{
private:

public:
    virtual void init() override;
    virtual void update(const float timestep);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual CustomComponent* clone() const{
        return new CustomComponent(*this);
    }
};

#endif // CUSTOM_COMPONENT_HPP