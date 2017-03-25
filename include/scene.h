#ifndef H_SCENE
#define H_SCENE

#include <vector>

#include "gameobject.h"


class Scene
{
private:
    std::vector<GameObject*> m_gameObjects;

public:
    Scene();
    ~Scene();

    void update();
    void render();

    void addGameObject(GameObject *gameObject);
};

#endif
