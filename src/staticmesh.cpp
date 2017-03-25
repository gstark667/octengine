#include "staticmesh.h"

#include <iostream>


StaticMesh::StaticMesh()
{
    m_points = new float[9];
    m_points[0] = 0.0f;
    m_points[1] = 0.5f;
    m_points[2] = 0.0f;
    m_points[3] = 0.5f;
    m_points[4] = -0.5f;
    m_points[5] = 0.0f;
    m_points[6] = -0.5f;
    m_points[7] = -0.5f;
    m_points[8] = 0.0f;
    m_numPoints = 9;

    m_vbo = 0;
    m_vao = 0;
    m_vs = 0;
    m_fs = 0;
    m_shader = 0;

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), m_points, GL_STATIC_DRAW);

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_vao);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    const char* vertex_shader =
    "#version 400\n"
    "in vec3 vp;"
    "void main() {"
    "  gl_Position = vec4(vp, 1.0);"
    "}";

    const char* fragment_shader =
    "#version 400\n"
    "out vec4 frag_colour;\n"
    "void main() {\n"
    "  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);\n"
    "}\n";

    GLuint m_vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_vs, 1, &vertex_shader, NULL);
    glCompileShader(m_vs);
    GLint isCompiled = 0;
    glGetShaderiv(m_vs, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(m_vs, GL_INFO_LOG_LENGTH, &maxLength);

	std::vector<GLchar> errorLog(maxLength);
	glGetShaderInfoLog(m_vs, maxLength, &maxLength, &errorLog[0]);

	glDeleteShader(m_vs);
        throw -1;
    }

    GLuint m_fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_fs, 1, &fragment_shader, NULL);
    glCompileShader(m_fs);
    isCompiled = 0;
    glGetShaderiv(m_fs, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(m_fs, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(m_fs, maxLength, &maxLength, &errorLog[0]);

        glDeleteShader(m_fs);
        throw -1;
    }

    GLuint m_shader = glCreateProgram();
    glAttachShader(m_shader, m_fs);
    glAttachShader(m_shader, m_vs);
    glLinkProgram(m_shader);
}


StaticMesh::~StaticMesh()
{

}


void StaticMesh::update(GameObject &gameObject)
{

}


void StaticMesh::render(const GameObject &gameObject)
{
    std::cout << "VS: " << m_vs << std::endl;
    std::cout << "FS: " << m_fs << std::endl;
    std::cout << "Shader: " << m_shader << std::endl;
    glUseProgram(m_shader);
    glBindVertexArray(m_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

