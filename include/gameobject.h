#ifndef H_GAMEOBJECT
#define H_GAMEOBJECT

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

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
    glm::vec3 m_position, m_rotation;

public:
    GameObject(): m_position(0.0, 0.0, 0.0), m_rotation(0.0, 0.0, 0.0) {};
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
        modelViewProjection *= glm::translate(glm::mat4(1.0f), m_position);
        modelViewProjection *= glm::eulerAngleYXZ(m_rotation.y, m_rotation.x, m_rotation.z);
        for (std::vector<Component*>::iterator it = m_components.begin(); it != m_components.end(); ++it)
        {
            (*it)->render(*this, modelViewProjection);
        }
    };

    void translate(float x, float y, float z)
    {
        m_position += glm::vec3(x, y, z);
    };

    void rotate(float x, float y, float z)
    {
        m_rotation += glm::vec3(x, y, z);
    };
};

#endif
