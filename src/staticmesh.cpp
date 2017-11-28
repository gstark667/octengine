#include "staticmesh.h"

#include <assimp/Importer.hpp>
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <iostream>
#include <vector>
#include <stdlib.h>


StaticMesh::StaticMesh()
{
    Assimp::Importer importer;

    const aiScene *scene = importer.ReadFile("models/cube.dae",
        aiProcess_CalcTangentSpace       |
        aiProcess_Triangulate            |
        aiProcess_JoinIdenticalVertices  |
        aiProcess_SortByPType);

    std::vector<float> vertices;
    for (unsigned int i = 0; i < scene->mNumMeshes; ++i)
    {
        std::cout << "Mesh" << std::endl;
        for (unsigned int j = 0; j < scene->mMeshes[i]->mNumFaces; ++j)
        {
            for (unsigned int k = 0; k < scene->mMeshes[i]->mFaces[j].mNumIndices; k++)
            {
                for (unsigned int v = 0; v < 3; ++v)
                {
                    vertices.push_back(scene->mMeshes[i]->mVertices[scene->mMeshes[i]->mFaces[j].mIndices[k]][v]);
                }
            }
        }
    }

    if (!scene)
        std::cout << "failed to import asset" << std::endl;

    m_points = (float*)malloc(sizeof(float) * vertices.size());
    for (size_t i = 0; i < vertices.size(); ++i)
    {
        m_points[i] = vertices.at(i);
    }
    m_numPoints = vertices.size() / 3;
    std::cout << m_numPoints << "," << vertices.size() << std::endl;

    m_vbo = 0;
    m_vao = 0;

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_numPoints * 3, m_points, GL_STATIC_DRAW);

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
    glDrawArrays(GL_TRIANGLES, 0, m_numPoints);
    m_shader->unbind();
}

