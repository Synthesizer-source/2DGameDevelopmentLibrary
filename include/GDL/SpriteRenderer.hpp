#ifndef SPRITE_RENDERER_HPP
#define SPRITE_RENDERER_HPP
#include <SFML/Graphics.hpp>
#include <GDL/Component.hpp>

namespace gdl {
    class SpriteRenderer : public Component {
    private:
        sf::Texture texture;
        sf::Sprite sprite;
    public:
        void loadTexture(const char* pathTexture);
        sf::Vector2f getCenter() const;
        sf::Vector2f getSize() const;
        virtual void init() override;
        virtual void update(const float timestep);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual SpriteRenderer* clone() const {
            return new SpriteRenderer(*this);
        }
    };
}
#endif // !SPRITE_RENDERER_HPP