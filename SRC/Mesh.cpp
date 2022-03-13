#include "Mesh.h"
#include<memory>

Mesh::Mesh(const std::vector<vertex_t> &vertices, const std::vector<unsigned int> &indices,
           const std::vector<texture_t> &textures  ) {
    this->m_vertices = vertices;
    this->m_textures = textures;
    this->m_indices = indices;
    this->SetUpMesh();
}

void Mesh::SetUpMesh() {
    m_VertexBuffer= std::make_unique<VertexBuffer>(&m_vertices[0], m_vertices.size() * sizeof(vertex_t));
    m_IndexBuffer = std::make_unique<IndexBuffer>(&m_indices[0], m_indices.size() * sizeof(unsigned int));
    auto layout = VertexBufferLayout();
    layout.Push<float>(3);
    layout.Push<float>(3);
    layout.Push<float>(2);
    layout.Push<float>(3);
    layout.Push<int>(4);
    layout.Push<float>(4);
    this->m_VAO->AddBuffer(*m_VertexBuffer, layout);
    this->m_VAO->Bind();
}
void Mesh::Draw(shader &shader)
{
    // bind appropriate textures
    unsigned int diffuseNr  = 1;
    unsigned int specularNr = 1;
    unsigned int normalNr   = 1;
    unsigned int heightNr   = 1;
    for(unsigned int i = 0; i < m_textures.size(); i++)
    {
        glCall(glActiveTexture(GL_TEXTURE0 + i)); // active proper texture unit before binding
        // retrieve texture number (the N in diffuse_textureN)
        std::string number;
        std::string name = m_textures[i].type;
        if(name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if(name == "texture_specular")
            number = std::to_string(specularNr++); // transfer unsigned int to string
        else if(name == "texture_normal")
            number = std::to_string(normalNr++); // transfer unsigned int to string
        else if(name == "texture_height")
            number = std::to_string(heightNr++); // transfer unsigned int to string

        // now set the sampler to the correct texture unit
        shader.SetUniformi((name + number).c_str(), i);
//        glUniform1i(glGetUniformLocation(shader.ID, (name + number).c_str()), i);
        // and finally bind the texture
        glBindTexture(GL_TEXTURE_2D, m_textures[i].id);
    }

    // draw mesh
//    glBindVertexArray(m_VAO);
    m_VAO->Bind();
    Renderer renderer ;
//    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(m_indices.size()), GL_UNSIGNED_INT, 0);
    renderer.Draw(*m_VAO,*m_IndexBuffer,shader);
//    glBindVertexArray(0);
    this->m_VAO->Unbind();

    // always good practice to set everything back to defaults once configured.
    glActiveTexture(GL_TEXTURE0);
}
