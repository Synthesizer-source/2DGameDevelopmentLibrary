#include <GDL/Utils.hpp>
#include <iostream>
#include <sstream>

namespace gdl::utils {

    template <typename T>
    std::string to_string_with_precision(const T a_value, const int n = 2)
    {
        std::ostringstream out;
        out.precision(n);
        out << std::fixed << a_value;
        return out.str();
    }

    /**
     * @brief vector2f to string
     *
     * @param v
     * @return std::string
     */
    std::string toString(const sf::Vector2f& v) {
        return "{ X : " + to_string_with_precision(v.x)
            + ", Y : " + to_string_with_precision(v.y) + " }";
    }

    /**
     * @brief floatRect to string
     *
     * @param r
     * @return std::string
     */
    std::string toString(const sf::FloatRect& r) {
        return "{ Width : " + to_string_with_precision(r.width)
            + ", Height : " + to_string_with_precision(r.height)
            + ", Top : " + to_string_with_precision(r.top)
            + ", Left : " + to_string_with_precision(r.left) + " }";
    }

    /**
     * @brief print string
     * 
     * @param str 
     */
    void print(const std::string& str) {
        std::cout << str << "\n";
    }
}