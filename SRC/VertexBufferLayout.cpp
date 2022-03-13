// #pragma once

#include "VertexBufferLayout.h"
// template <typename T>

// void VertexBufferLayout::Push(unsigned int count, T t)
// {
// 	ASSERT(true);

// 	std::cout << t << "\n";
// 	// Push<T>(count);
// 	// static_assert(false);
// }

// template <class T>
// void VertexBufferLayout::Push(unsigned int count, T t)
// {
//     std::cout << "Work is done\n";
//     switch (typeid(T))
//     {
//     case typeid(float):
//     {
//     }
//     break;

//     case typeid(unsigned int):
//     {
//     }
//     break;
//     case typeid(unsigned char):
//     {
//     }
//     break;
//     default:
//     {
//         ASSERT(false);
//     }
//     }
//     // if (typeid(T) == typeid(float))
//     // {
//     // 	std::cout << tkdsjf;
//     // }

// }

VertexBufferLayout::VertexBufferLayout() : m_Stride{0} {}
const std::vector<VertexBufferElement> VertexBufferLayout::GetElements() const & { return m_Elements; }
unsigned int VertexBufferLayout::GetStride() const { return m_Stride; }
template <>
void VertexBufferLayout::Push<float>(unsigned int count)
{
    std::cout << "Work is done\n";

    m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
}
template <>
void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
}
template<>
void VertexBufferLayout::Push<int>(unsigned int count)
{
    m_Elements.push_back({GL_INT, count, GL_FALSE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_INT);
}
template <>
void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
}