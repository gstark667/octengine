#ifndef H_SCENE
#define H_SCENE

#include <vector>

#include "gameobject.h"
#include "camera.h"


class Scene
{
private:
    std::vector<GameObject*> m_gameObjects;
    std::vector<Camera*> m_cameras;
    size_t m_activeCamera = 0;
    glm::mat4 m_model;
    glm::mat4 m_view;
    glm::mat4 m_projection;

public:
    Scene();
    ~Scene();

    void update(float delta);
    void render();

    void addGameObject(GameObject *gameObject);

    size_t addCamera();
    Camera* getCamera(size_t index);
    void setCamera(size_t index);
};

#endif
