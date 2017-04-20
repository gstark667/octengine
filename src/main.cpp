#include "application.h"
#include "gameobject.h"
#include "staticmesh.h"
#include "script.h"

#include <iostream>


int main()
{
    Application *app = new Application();
    Scene *scene = new Scene();

    GameObject *g = new GameObject();
    StaticMesh *triangle = new StaticMesh();
    Script *script = new Script("build/rotate.so");
    g->addComponent(triangle);
    g->addComponent(script);
    scene->addGameObject(g);

    app->setScene(scene);
    app->run();
}
