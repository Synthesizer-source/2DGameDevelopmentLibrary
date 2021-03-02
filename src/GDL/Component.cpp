#include <GDL/Component.hpp>
#include <GDL/Entity.hpp>

namespace gdl {

    /**
     * @brief init
     * 
     */
    void Component::init(){}

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
