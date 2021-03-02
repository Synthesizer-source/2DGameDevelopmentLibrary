#include <iostream>
#include <SFML/Graphics.hpp>

#include <GDL/Entity.hpp>
#include <CustomComponent.hpp>

int main(int argc, char** argv){
    
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    gdl::Entity* e = new gdl::Entity();

    e->addComponent<CustomComponent>();
    e->init();
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        e->update(60);

        window.clear();
        window.draw(*e);
        window.display();
    }
    return 0;
}