#include "application.h"
#include "gameobject.h"
#include "staticmesh.h"


int main()
{
    Application *app = new Application();
    Scene *scene = new Scene();

    GameObject *g = new GameObject();
    Component *triangle = new StaticMesh();
    g->addComponent(triangle);
    scene->addGameObject(g);

    app->setScene(scene);
    app->run();
}
