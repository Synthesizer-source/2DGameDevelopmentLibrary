#ifndef SCENE_HPP
#define SCENE_HPP
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
namespace gdl {
    class Entity;
    class Scene : public sf::Drawable {
    private:
        std::map<std::string, Entity*> objects; /* name , objects */
        const char * sceneName;
    public:
        Scene(const char* _sceneName);
        Entity* createNewObject(const std::string& name);
        void init();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void update(const float timestep);
    };
}
#endif // !SCENE_HPP