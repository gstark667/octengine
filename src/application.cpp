#include "application.h"

#include <iostream>
#include <exception>

#include <GL/gl.h>

using namespace std;


Application::Application()
{
    if(!glfwInit())
    {
        cerr << "Unable to initialize GLFW" << endl;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(1280, 720, "octengine", NULL, NULL);
    if(m_window == NULL)
    {
        glfwTerminate();
        cerr << "Unable to create GLFW window" << endl;
        throw -1;
    }
    glfwMakeContextCurrent(m_window);

    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}


Application::~Application()
{
    glfwTerminate();
}


void Application::run()
{
    while(true)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_scene->update();
        m_scene->render();

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}


void Application::setScene(Scene *scene)
{
    m_scene = scene;
}