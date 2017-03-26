#ifndef H_SCENE
#define H_SCENE

#include <vector>

#include "gameobject.h"


class Scene
{
private:
    std::vector<GameObject*> m_gameObjects;
    glm::mat4 m_model;
    glm::mat4 m_view;
    glm::mat4 m_projection;

public:
    Scene();
    ~Scene();

    void update();
    void render();

    void addGameObject(GameObject *gameObject);
};

#endif
