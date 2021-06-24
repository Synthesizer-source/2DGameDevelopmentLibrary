#include <SFML/Graphics.hpp>
#include <string>
namespace gdl::utils {
    std::string toString(const sf::Vector2f& v);
    std::string toString(const sf::FloatRect& r);
    void print(const std::string& str);
}