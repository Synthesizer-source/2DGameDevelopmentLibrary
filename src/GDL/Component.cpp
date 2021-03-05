#include <GDL/Component.hpp>
#include <GDL/Entity.hpp>

namespace gdl {
    
    /**
     * @brief set component active
     * 
     * @param active 
     */
    void Component::setActive(bool active) {
        this->active = active;
    }

    /**
     * @brief get component active
     * 
     * @return true 
     * @return false 
     */
    bool Component::isActive() const {
        return this->active;
    }

    /**
     * @brief init
     *
     */
    void Component::init() {}

    /**
     * @brief set owner of component
     *
     * @param entity
     */
    void Component::setOwner(Entity* entity) {
        this->entity = entity;
    }

    /**
     * @brief get owner of component
     *
     * @param entity
     */
    Entity* Component::getOwner() const {
        return this->entity;
    }

}
