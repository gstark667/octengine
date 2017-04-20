#ifndef H_SCRIPT
#define H_SCRIPT

#include "gameobject.h"

#include <string>
#include <fstream>


class Script: public Component
{
private:
    GameObject *m_gameObject;
    void *m_lib;
    void (*m_update)(GameObject&, float);

public:
    Script(std::string filePath);
    ~Script();

    void update(GameObject &gameObject, float delta);
    void render(const GameObject &gameObject, glm::mat4 modelViewProjection) {}; // not sure if we will ever need a script for render
};


#endif
