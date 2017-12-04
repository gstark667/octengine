#include "scene.h"

using namespace std;


Scene::Scene()
{
    m_model = glm::mat4();
    m_view = glm::lookAt(
    glm::vec3(1.0f, 5.0f, 1.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, -1.0f));
    m_projection = glm::perspective(55.0f, 1280.0f / 720.0f, 1.0f, 10.0f);
}

Scene::~Scene()
{

}


void Scene::update(float delta)
{
    for (vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end(); it++)
        (*it)->update(delta);
}


void Scene::render()
{
    Camera *activeCamera = m_cameras.at(m_activeCamera);
    glm::mat4 modelViewProjection = activeCamera->getProjection() * activeCamera->getView() * m_model;
    for (vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end(); it++)
        (*it)->render(modelViewProjection);
}


void Scene::addGameObject(GameObject *gameObject)
{
    m_gameObjects.push_back(gameObject);
}

size_t Scene::addCamera()
{
    m_cameras.push_back(new Camera());
    return m_cameras.size() - 1;
}

Camera* Scene::getCamera(size_t index)
{
    return m_cameras.at(index);
}

void Scene::setCamera(size_t index)
{
    if (index < m_cameras.size())
        m_activeCamera = index;
}

