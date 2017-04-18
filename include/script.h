#ifndef H_SCRIPT
#define H_SCRIPT

#include "gameobject.h"

#include <lua.hpp>
#include <string>
#include <fstream>


class Script: public Component
{
private:
    lua_State *m_luaState;

public:
    Script(std::string filePath);
    ~Script();

    void update(GameObject &gameObject, float delta);
    void render(const GameObject &gameObject, glm::mat4 modelViewProjection) {}; // not sure if we will ever need a script for render
};


#endif
