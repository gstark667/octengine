#include "application.h"


int main()
{
    Application *app = new Application();
    Scene *scene = new Scene();

    app->setScene(scene);
    app->run();
}
