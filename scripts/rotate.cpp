#include "gameobject.h"

#include <iostream>

using namespace std;

extern "C" void update(GameObject &gameObject, float delta)
{
    gameObject.rotate(0.0f, 0.0f, 10.0f * delta);
    gameObject.translate(1.0f * delta, 0.0f, 0.0f);
}

