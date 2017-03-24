#ifndef H_SCENE
#define H_SCENE

#include <vector>

#include "gameobject.h"


class Scene
{
private:
   std::vector<GameObject*> m_gameobjects;

public:
   Scene();
   ~Scene();

   void update();
   void render();
};

#endif
