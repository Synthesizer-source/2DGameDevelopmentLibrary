#include <Game.hpp>
#include <CustomComponent.hpp>
#include <GDL/Entity.hpp>
#include <GDL/SpriteRenderer.hpp>
#include <PlayerMovement.hpp>

sf::RenderWindow* Game::window = nullptr;
gdl::Entity* e;


void Game::init() {

    window = new sf::RenderWindow(sf::VideoMode(1024, 768), "My window");

    e = new gdl::Entity();
    e->addComponent<CustomComponent>();
    e->getComponent<CustomComponent>()->setActive(false);
    e->addComponent<gdl::SpriteRenderer>();
    e->addComponent<PlayerMovement>();
    e->init();
    /* SpriteRenderer.cpp -> GDL -> src -> example -> resources -> spaceship.png */
    e->getComponent<gdl::SpriteRenderer>()->loadTexture("../../example/resources/spaceship.png");
    e->setOrigin(e->getComponent<gdl::SpriteRenderer>()->getCenter());
    e->setPosition({100, 100});
}

void Game::update(float timestep) {

    e->update(timestep);
}

void Game::render() {

    window->clear();
    window->draw(*e);
    window->display();

}

void Game::run() {

    init();

    sf::Clock clock;
    float accumulator = 0;
    const float timestep = 1.0f / 60.0f; //60hz update frequency

    while (window->isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }

        accumulator += clock.restart().asSeconds();
        while (accumulator >= timestep) {
            accumulator -= timestep;

            //Put time-reliant code here
            //Updates at nearly every 1/60th of a second
            update(timestep);
        }

        render();
    }
}