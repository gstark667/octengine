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

    virtual void update(GameObject &gameobject, float delta) {};
    virtual void render(const GameObject &gameobject, glm::mat4 modelViewProjection) {};
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

    void update(float delta)
    {
        for (std::vector<Component*>::iterator it = m_components.begin(); it != m_components.end(); ++it)
        {
            (*it)->update(*this, delta);
        }
    };

    void render(glm::mat4 modelViewProjection)
    {
        for (std::vector<Component*>::iterator it = m_components.begin(); it != m_components.end(); ++it)
        {
            (*it)->render(*this, modelViewProjection);
        }
    };

    void translate(float x, float y, float z)
    {
        glm::vec4 temp(x, y, z, 1.0f);
        m_position += temp;
    };
};

#endif
