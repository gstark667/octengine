#include "scene.h"

using namespace std;


Scene::Scene()
{
    m_model = glm::mat4();
    m_view = glm::lookAt(
    glm::vec3(2.5f, 2.5f, 2.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 1.0f));
    m_projection = glm::perspective(45.0f, 1280.0f / 720.0f, 1.0f, 10.0f);
}

Scene::~Scene()
{

}


void Scene::update(float delta)
{
    for(vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end(); it++)
        (*it)->update(delta);
}


void Scene::render()
{
    glm::mat4 modelViewProjection = m_projection * m_view * m_model;
    for(vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end(); it++)
        (*it)->render(modelViewProjection);
}


void Scene::addGameObject(GameObject *gameObject)
{
    m_gameObjects.push_back(gameObject);
}
