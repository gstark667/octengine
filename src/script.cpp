#include "script.h"

// TODO make it work on windows and mac
#include <dlfcn.h>
#include <iostream>

#include "file.h"

using namespace std;


Script::Script(string filePath)
{
    m_lib = dlopen(filePath.c_str(), RTLD_LAZY);
    // TODO handle load failures
    m_update = (void (*)(GameObject&, float))dlsym(m_lib, "update");
}


Script::~Script()
{
    dlclose(m_lib);
}


void Script::update(GameObject &gameObject, float delta)
{
    m_update(gameObject, delta);
}

