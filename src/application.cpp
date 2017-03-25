#include "application.h"

#include <iostream>
#include <exception>


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

    glewExperimental=true;
    GLenum err=glewInit();
    if(err!=GLEW_OK) {
        cerr << "Error Initializing GLEW: " << glewGetErrorString(err) << endl;
        throw -1;
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0.0, 0.0, 0.0, 1.0);
}


Application::~Application()
{
    glfwTerminate();
}


void Application::run()
{
    while(!glfwWindowShouldClose(m_window))
    {
        float delta = glfwGetTime();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_scene->update();
        m_scene->render();

        glfwSetTime(0);
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
    glfwDestroyWindow(m_window);
}


void Application::setScene(Scene *scene)
{
    m_scene = scene;
}
