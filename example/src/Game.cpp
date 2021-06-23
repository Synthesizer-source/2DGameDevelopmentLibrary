#include <Game.hpp>
#include <GDL/GDL.hpp>
#include <PlayerMovement.hpp>

sf::RenderWindow* Game::window = nullptr;
gdl::Scene* scene;
gdl::Entity* player;
gdl::Entity* enemy;
gdl::Entity* circle;
gdl::Entity* rectangle;

void Game::init() {

    window = new sf::RenderWindow(sf::VideoMode(1024, 768), "My window");

    scene = new gdl::Scene("mainScene");
    player = scene->createNewObject("player");
    enemy = scene->createNewObject("enemy");
    circle = scene->createNewObject("circle");
    rectangle = scene->createNewObject("rectangle");

    player->addComponent<gdl::SpriteRenderer>();
    player->addComponent<PlayerMovement>();
    enemy->addComponent<gdl::SpriteRenderer>();
    circle->addComponent<gdl::CircleShapeRenderer>();
    rectangle->addComponent<gdl::RectangleShapeRenderer>();

    scene->init();

    /* SpriteRenderer.cpp -> GDL -> src -> example -> resources -> spaceship.png */
    player->getComponent<gdl::SpriteRenderer>()->loadTexture("../../example/resources/spaceship.png");
    player->setOrigin(player->getComponent<gdl::SpriteRenderer>()->getCenter());
    player->setPosition({ 100, 100 });

    enemy->getComponent<gdl::SpriteRenderer>()->loadTexture("../../example/resources/enemy.png");
    enemy->setOrigin(enemy->getComponent<gdl::SpriteRenderer>()->getCenter());
    enemy->setPosition({ 400, 400 });

    circle->getComponent<gdl::CircleShapeRenderer>()->setRadius(20.0f);
    circle->getComponent<gdl::CircleShapeRenderer>()->setColor(sf::Color::Cyan);
    circle->setPosition({ 120,120 });

    rectangle->getComponent<gdl::RectangleShapeRenderer>()->setSize({ 100,100 });
    rectangle->getComponent<gdl::RectangleShapeRenderer>()->setColor(sf::Color::Yellow);
    rectangle->setPosition({ 240,420 });
    std::cout << gdl::utils::toString(rectangle->getComponent<gdl::RectangleShapeRenderer>()->getCenter()) << "\n";
    sf::FloatRect f(10, 10, 10, 10);
    std::cout << gdl::utils::toString(f) << "\n";
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