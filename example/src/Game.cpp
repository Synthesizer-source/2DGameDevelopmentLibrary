#include <Game.hpp>
#include <GDL/GDL.hpp>
#include <CustomComponent.hpp>
// #include <GDL/Entity.hpp>
// #include <GDL/SpriteRenderer.hpp>
#include <PlayerMovement.hpp>

sf::RenderWindow* Game::window = nullptr;
gdl::Scene* scene;
gdl::Entity* player;
gdl::Entity* enemy;

void Game::init() {

    window = new sf::RenderWindow(sf::VideoMode(1024, 768), "My window");

    scene = new gdl::Scene("mainScene");
    player = scene->createNewObject("player");
    enemy = scene->createNewObject("enemy");

    player->addComponent<gdl::SpriteRenderer>();
    player->addComponent<PlayerMovement>();
    enemy->addComponent<gdl::SpriteRenderer>();

    scene->init();

    /* SpriteRenderer.cpp -> GDL -> src -> example -> resources -> spaceship.png */
    player->getComponent<gdl::SpriteRenderer>()->loadTexture("../../example/resources/spaceship.png");
    player->setOrigin(player->getComponent<gdl::SpriteRenderer>()->getCenter());
    player->setPosition({ 100, 100 });

    enemy->getComponent<gdl::SpriteRenderer>()->loadTexture("../../example/resources/enemy.png");
    enemy->setOrigin(enemy->getComponent<gdl::SpriteRenderer>()->getCenter());
    enemy->setPosition({ 400, 400 });

}

void Game::update(float timestep) {
    scene->update(timestep);
}

void Game::render() {
    window->clear();
    window->draw(*scene);
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