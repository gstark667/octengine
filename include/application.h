#ifndef H_APPLICATION
#define H_APPLICATION

#ifndef H_GL
#define H_GL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#endif

// GLM
#include <glm/glm.hpp>

// octengine
#include "scene.h"


class Application
{
private:
    GLFWwindow *m_window;
    Scene *m_scene;

public:
    Application();
    ~Application();

    void run();

    void setScene(Scene *scene);
};

#endif
