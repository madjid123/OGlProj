#pragma once
#include<memory>
#include <string>
#include <vector>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include"Shader.h"
#define MAX_BONE_INFLUENCE 4

struct texture_t
{
    unsigned int id;
    std::string type;
    std::string path;
};
struct vertex_t
{
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
    // bone indexes which will influence this vertex
    int m_BoneIDs[MAX_BONE_INFLUENCE];
    // weights from each bone
    float m_Weights[MAX_BONE_INFLUENCE];
};
class Mesh
{
    std::vector<vertex_t> m_vertices;
    std::vector<texture_t> m_textures;
    std::vector<unsigned int> m_indices;
    // VertexBuffer m_VertexBuffer;
    // IndexBuffer m_IndexBuffer;
    std::unique_ptr<VertexArray> m_VAO;
    std::unique_ptr<VertexBuffer> m_VertexBuffer;
    std::unique_ptr<IndexBuffer> m_IndexBuffer;
public:
    Mesh(const std::vector<vertex_t> &vertices, const std::vector<unsigned int> &indices, const std::vector<texture_t> &textures);
    ~Mesh();
    void SetUpMesh();
    void Draw(shader &shader);
    std::vector<vertex_t> vertices() const { return m_vertices; }
    void setVertices(const std::vector<vertex_t> &vertices) { m_vertices = vertices; }

    std::vector<texture_t> textures() const { return m_textures; }
    void setTextures(const std::vector<texture_t> &textures) { m_textures = textures; }

    std::vector<unsigned int> indices() const { return m_indices; }
    void setIndices(const std::vector<unsigned int> &indices) { m_indices = indices; }

};