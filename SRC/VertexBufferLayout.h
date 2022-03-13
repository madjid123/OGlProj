#pragma once

#include <iostream>
#include <vector>
#include "Renderer.h"

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT:
                return 4;
            case GL_INT:
                return 4;
            case GL_UNSIGNED_INT :
                return 4;
            case GL_UNSIGNED_BYTE:
                return 1;
        }
        return 0;
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;

public:
    VertexBufferLayout();

    const std::vector<VertexBufferElement> GetElements() const &;

    unsigned int GetStride() const;

    template<class T>
    void Push(unsigned int count);
};
