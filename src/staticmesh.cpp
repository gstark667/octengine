#include "staticmesh.h"

#include <iostream>
#include <stdlib.h>


StaticMesh::StaticMesh()
{
    m_points = (float*)malloc(9 * sizeof(float));
    //m_points = new float[9];
    m_points[0] = 0.0f;
    m_points[1] = 0.0f;
    m_points[2] = 0.0f;
    m_points[3] = 0.0f;
    m_points[4] = 0.5f;
    m_points[5] = 0.0f;
    m_points[6] = 0.5f;
    m_points[7] = 0.0f;
    m_points[8] = 0.0f;
    m_numPoints = 9;

    m_vbo = 0;
    m_vao = 0;

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), m_points, GL_STATIC_DRAW);

    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_vao);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    m_shader = new Shader();
}


StaticMesh::~StaticMesh()
{
    glDeleteBuffers(1, &m_vbo);
    glDeleteVertexArrays(1, &m_vbo);
    delete m_shader;
}


void StaticMesh::update(GameObject &gameObject, float delta)
{

}


void StaticMesh::render(const GameObject &gameObject, glm::mat4 modelViewProjection)
{
    m_shader->bind();
    glBindVertexArray(m_vao);
    glUniformMatrix4fv(m_shader->getUniformLocation("modelViewProjection"), 1, GL_FALSE, &modelViewProjection[0][0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    m_shader->unbind();
}

