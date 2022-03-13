
#pragma once

#include <GL/glew.h>
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#ifdef _MSC_VER
#define ERROR_TRAP_FUNCTION __debugbreak
#else
#define ERROR_TRAP_FUNCTION __builtin_trap
#endif

#define ASSERT(x) \
       if (!(x))  \
                ERROR_TRAP_FUNCTION();
//              __builtin_trap();
//#define ASSERT(x) if (!(x)) __debugbreak();
#define glCall(x)      \
       GlClearError(); \
       x;              \
       ASSERT(GlLogCall(#x, __FILE__, __LINE__))

void GlClearError();
bool GlLogCall(const char *function, const char *file, int line);

class VertexArray;
class Renderer
{
public:
       void Clear() const;
       void Draw(const VertexArray &va, const IndexBuffer &ib, const shader &shader) const;
};
