#include "scene.h"

using namespace std;


Scene::Scene()
{

}

Scene::~Scene()
{

}


void Scene::update()
{
    for(vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end(); it++)
        (*it)->update();
}


void Scene::render()
{
    for(vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end(); it++)
        (*it)->render();
}


void Scene::addGameObject(GameObject *gameObject)
{
    m_gameObjects.push_back(gameObject);
}
