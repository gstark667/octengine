#include "gameobject.h"

#include <iostream>

using namespace std;

extern "C" void update(GameObject &gameObject, float delta)
{
    gameObject.translate(1.0f, 0.0f, 0.0f);
    cout << "rotate" << endl;
}

