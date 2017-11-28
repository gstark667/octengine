#include "shader.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>


Shader::Shader(std::string vertexPath, std::string fragmentPath)
{
    std::ifstream vertexSourceFile(vertexPath);
    std::string vertexSource((std::istreambuf_iterator<char>(vertexSourceFile)), std::istreambuf_iterator<char>());
    vertexSourceFile.close();
    m_vertexSource = new char[vertexSource.size()];
    strcpy(m_vertexSource, vertexSource.c_str());

    std::ifstream fragmentSourceFile(fragmentPath);
    std::string fragmentSource((std::istreambuf_iterator<char>(fragmentSourceFile)), std::istreambuf_iterator<char>());
    fragmentSourceFile.close();
    m_fragmentSource = new char[fragmentSource.size()];
    strcpy(m_fragmentSource, fragmentSource.c_str());

    m_vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_vertex, 1, &m_vertexSource, NULL);
    glCompileShader(m_vertex);
    GLint isCompiled = 0;
    glGetShaderiv(m_vertex, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(m_vertex, GL_INFO_LOG_LENGTH, &maxLength);

        GLchar *errorLog = (GLchar*)malloc(sizeof(GLchar) * maxLength);
        glGetShaderInfoLog(m_vertex, maxLength, &maxLength, errorLog);
        std::cerr << errorLog << std::endl;

        glDeleteShader(m_vertex);
        throw -1;
    }

    m_fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_fragment, 1, &m_fragmentSource, NULL);
    glCompileShader(m_fragment);
    isCompiled = 0;
    glGetShaderiv(m_fragment, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(m_fragment, GL_INFO_LOG_LENGTH, &maxLength);

        GLchar *errorLog = (GLchar*)malloc(sizeof(GLchar) * maxLength);
        glGetShaderInfoLog(m_fragment, maxLength, &maxLength, &errorLog[0]);
        std::cerr << errorLog << std::endl;

        glDeleteShader(m_fragment);
        throw -1;
    }

    m_shader = glCreateProgram();
    glAttachShader(m_shader, m_fragment);
    glAttachShader(m_shader, m_vertex);
    glLinkProgram(m_shader);

    GLint isLinked = 0;
    glGetProgramiv(m_shader, GL_LINK_STATUS, &isLinked);
    if(isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(m_shader, GL_INFO_LOG_LENGTH, &maxLength);

        GLchar *errorLog = (GLchar*)malloc(sizeof(GLchar) * maxLength);
        glGetProgramInfoLog(m_shader, maxLength, &maxLength, &errorLog[0]);
        std::cerr << errorLog << std::endl;

        glDeleteProgram(m_shader);
        throw -1;
    }
}


Shader::~Shader()
{
    delete m_vertexSource;
    delete m_fragmentSource;
    if (m_vertex)
        glDeleteShader(m_vertex);
    if (m_fragment)
        glDeleteShader(m_fragment);
    if (m_shader)
        glDeleteProgram(m_shader);
}


void Shader::bind() const
{
    glUseProgram(m_shader);
}


void Shader::unbind() const
{
    glUseProgram(0);
}


GLuint Shader::getUniformLocation(std::string name)
{
    // TODO throw an exception if we don't find it
    return glGetUniformLocation(m_shader, name.c_str());
}

