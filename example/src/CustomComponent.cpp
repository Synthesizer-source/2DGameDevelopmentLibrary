#include <CustomComponent.hpp>
#include <iostream>

void CustomComponent::init(){
    std::cout<<"Custom component init function.\n";
}


void CustomComponent::update(const float timestep){
    std::cout<<"Custom component update function.\n";
}


void CustomComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    std::cout<<"Custom component render function.\n";
}