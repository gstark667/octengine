#include "scene.h"

using namespace std;


Scene::Scene()
{

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
