#ifndef BASE_RENDERER_HPP
#define BASE_RENDERER_HPP
#include <SFML/Graphics.hpp>

namespace gdl {
    class BaseRenderer
    {
    public:
        virtual sf::Vector2f getCenter() const = 0;
        virtual sf::Vector2f getSize() const = 0;
        virtual ~BaseRenderer() = 0;
    };
}
#endif // !BASE_RENDERER_HPP