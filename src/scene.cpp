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
    for(vector<GameObject*>::iterator it; it != m_gameobjects.end(); it++)
        (*it)->update();
}


void Scene::render()
{
    for(vector<GameObject*>::iterator it; it != m_gameobjects.end(); it++)
        (*it)->render();
}
