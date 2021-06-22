#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>

class Game {
private:
    static void init();
    static void render();
    static void update(float timestep);

public:
    static sf::RenderWindow* window;
    static void run();
};
#endif // !GAME_HPP