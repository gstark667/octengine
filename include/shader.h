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
    char *m_vertexSource;
    char *m_fragmentSource;
    GLuint m_vertex;
    GLuint m_fragment;
    GLuint m_shader;

public:
    Shader(std::string vertexPath, std::string fragmentPath);
    ~Shader();

    void bind() const;
    void unbind() const;

    GLuint getUniformLocation(std::string name);
};

#endif
