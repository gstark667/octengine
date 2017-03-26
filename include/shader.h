#ifndef H_SHADER
#define H_SHADER

#include "gameobject.h"

#ifndef H_GL
#define H_GL
#include <GL/glew.h>
#endif

#include <string>


class Shader
{
private:
    GLuint m_vertex;
    GLuint m_fragment;
    GLuint m_shader;

public:
    Shader();
    ~Shader();

    void bind() const;
    void unbind() const;

    GLuint getUniformLocation(std::string name);
};

#endif
