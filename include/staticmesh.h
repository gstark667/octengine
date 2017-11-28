#ifndef H_STATICMESH
#define H_STATICMESH

#include "gameobject.h"
#include "shader.h"

#ifndef H_GL
#define H_GL
#include <GL/glew.h>
#endif

#include <string>


class StaticMesh: public Component
{
private:
    float *m_points;
    float *m_normals;
    size_t m_numPoints;

    GLuint m_vbo;
    GLuint m_nbo;
    GLuint m_vao;

    Shader *m_shader;

public:
    StaticMesh(std::string meshPath);
    ~StaticMesh();

    void update(GameObject &gameObject, float delta);
    void render(const GameObject &gameObject, glm::mat4 modelViewProjection);
};

#endif
