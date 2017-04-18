#ifndef H_STATICMESH
#define H_STATICMESH

#include "gameobject.h"
#include "shader.h"

#ifndef H_GL
#define H_GL
#include <GL/glew.h>
#endif


class StaticMesh: public Component
{
private:
    float *m_points;
    size_t m_numPoints;

    GLuint m_vbo;
    GLuint m_vao;

    Shader *m_shader;

public:
    StaticMesh();
    ~StaticMesh();

    void update(GameObject &gameObject, float delta);
    void render(const GameObject &gameObject, glm::mat4 modelViewProjection);
};

#endif
