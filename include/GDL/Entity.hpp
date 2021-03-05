#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <map>
#include <typeinfo>
#include <typeindex>
#include <vector>
#include <iostream>

#include <GDL/Component.hpp>

namespace gdl {

    class Entity : public sf::Drawable, public sf::Transformable {
    private:
        bool active = true;
    protected:
        std::map<std::type_index, Component*> components;
    public:

        /**
         * @brief add Components to entity
         *
         * @tparam C
         */
        template<class C>
        void addComponent() {
            auto it = components.find(std::type_index(typeid(C)));
            if (it == components.end()) {
                C* c = new C();
                c->setOwner(this);
                this->components.insert({ std::type_index(typeid(C)), c });
            }
        }

        /**
         * @brief Get the Component object
         *
         * @tparam C
         * @return C*
         */
        template<class C>
        C* getComponent() {
            auto it = components.find(std::type_index(typeid(C)));
            return it == components.end() ? nullptr : static_cast<C*>(it->second);
        }

        /**
         * @brief init components of entity
         *
         */
        void init() {

            for (auto component : this->components) {
                component.second->init();
            }
        }

        /**
         * @brief update components of entity
         *
         * @param timestep
         */
        void update(const float timestep) {
            for (auto component : this->components) {
                if (component.second->isActive()) component.second->update(timestep);
            }
        }

        /**
         * @brief draw components of entity
         *
         * @param target
         * @param states
         */
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
            for (auto component : this->components) {
                if (component.second->isActive()) component.second->draw(target, states);
            }
        }

        /**
         * @brief Destroy the Entity object
         *
         */
        virtual ~Entity() {

            for (auto& component : this->components) {
                delete component.second;
            }

            components.clear();
        }

        /**
         * @brief Set the Active object
         *
         * @param active
         */
        void setActive(bool active) {
            this->active = active;
        }

        /**
         * @brief get entity active
         *
         * @return true
         * @return false
         */
        bool isActive() const {
            return this->active;
        }

    };
}

#endif // ENTITY_HPP