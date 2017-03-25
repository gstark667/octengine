#include "application.h"
#include "gameobject.h"
#include "staticmesh.h"

#include <iostream>


int main()
{
    Application *app = new Application();
    Scene *scene = new Scene();

    GameObject *g = new GameObject();
    StaticMesh *triangle = new StaticMesh();
    g->addComponent(triangle);
    scene->addGameObject(g);

    app->setScene(scene);
    app->run();
}
