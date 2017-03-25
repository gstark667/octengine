#ifndef H_GAMEOBJECT
#define H_GAMEOBJECT

#include <glm/glm.hpp>

#include <vector>
#include <iostream>


class GameObject;


class Component
{
public:
    Component() {};
    ~Component() {};

    virtual void update(GameObject &gameobject) {};
    virtual void render(const GameObject &gameobject) {};
};


class GameObject
{
private:
    std::vector<Component*> m_components;
    glm::vec4 m_position;

public:
    GameObject(): m_position(0.0, 0.0, 0.0, 1.0) {};
    ~GameObject();

    void addComponent(Component *component) { m_components.push_back(component); };

    void update()
    {
        for (std::vector<Component*>::iterator it = m_components.begin(); it != m_components.end(); ++it)
        {
            (*it)->update(*this);
        }
    };

    void render()
    {
        for (std::vector<Component*>::iterator it = m_components.begin(); it != m_components.end(); ++it)
        {
            std::cout << *it << std::endl;
            (*it)->render(*this);
        }
    };
};

#endif
