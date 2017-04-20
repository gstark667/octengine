#include "script.h"

#include <iostream>

#include "file.h"

using namespace std;


Script::Script(string filePath)
{
    string content = File(filePath).getContent();
    cout << content << endl;
    m_luaState = luaL_newstate();
    luaL_openlibs(m_luaState);
    luaL_dostring(m_luaState, content.c_str());
}


Script::~Script()
{
    lua_close(m_luaState);
}


void Script::update(GameObject &gameObject, float delta)
{
    lua_getglobal(m_luaState, "update");
    lua_pushnumber(m_luaState, delta);
    lua_call(m_luaState, 1, 1);
    int result = (int)lua_tointeger(m_luaState, -1);
    lua_pop(m_luaState, 1);
}

