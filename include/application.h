#ifndef H_APPLICATION
#define H_APPLICATION

// GLEW
#include <GLFW/glfw3.h>

//GLM
#include <glm/glm.hpp>


class Application
{
public:
    Application();
    ~Application();

    void run();

private:
    GLFWwindow *window;
};

#endif
