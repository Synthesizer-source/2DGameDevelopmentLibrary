#include <GDL/Scene.hpp>
#include <GDL/Entity.hpp>
namespace gdl {
    
    /**
     * @brief Construct a new Scene:: Scene object
     * 
     * @param _sceneName 
     */
    Scene::Scene(const char* _sceneName) :sceneName(_sceneName) {}

    /**
     * @brief Create new Entity for current Scene
     * 
     * @param name 
     * @return Entity* 
     */
    Entity* Scene::createNewObject(const std::string& name) {
        Entity* e = new Entity();
        e->setScene(this);
        this->objects.insert({ name,e });
        return e;
    }

    /**
     * @brief init objects of scene
     * 
     */
    void Scene::init() {
        for (auto obj : this->objects) {
            if (obj.second->isActive()) {
                obj.second->init();
            }
        }
    }

    /**
     * @brief draw entities of scene
     * 
     * @param target 
     * @param states 
     */
    void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        for (auto obj : this->objects) {
            if (obj.second->isActive()) {
                obj.second->draw(target, states);
            }
        }
    }

    /**
     * @brief update entities of scene
     * 
     * @param timestep 
     */
    void Scene::update(const float timestep) {
        for (auto obj : this->objects) {
            if (obj.second->isActive()) {
                obj.second->update(timestep);
            }
        }
    }
}