#include <GDL/Entity.hpp>
#include <GDL/Scene.hpp>
namespace gdl {
    
    /**
     * @brief set Scene
     * 
     * @param scene 
     */
    void Entity::setScene(Scene* scene) {
        this->scene = scene;
    }

    /**
     * @brief Get the Scene that contains this object
     * 
     * @return Scene* 
     */
    Scene* Entity::getScene() const {
        return this->scene;
    }
}