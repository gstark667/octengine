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
    StaticMesh *triangle = new StaticMesh("models/sphere.dae");
    Script *script = new Script("build/rotate.so");
    g->addComponent(triangle);
    g->addComponent(script);
    scene->addGameObject(g);

    size_t camera = scene->addCamera();
    scene->getCamera(camera)->translate(3.0f, 3.0f, 3.0f);
    scene->getCamera(camera)->lookAt(g);

    app->setScene(scene);
    app->run();
    delete app;
    delete scene;
}
