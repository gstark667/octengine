#ifndef H_CAMERA
#define H_CAMERA

#include "gameobject.h"


class Camera: public GameObject
{
private:
    glm::mat4 m_view;
    glm::mat4 m_projection;

public:
    Camera()
    {
        m_view = glm::mat4();
        m_projection = glm::perspective(55.0f, 1280.f / 720.f, 1.0f, 10.0f);
    };

    glm::mat4 getView() { return m_view; };
    glm::mat4 getProjection() { return m_projection; };
};

#endif
