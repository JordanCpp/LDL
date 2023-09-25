#ifndef LDL_Renders_OpenGL_hpp
#define LDL_Renders_OpenGL_hpp

#include <LDL/Low/Types.hpp>
#include <LDL/Low/Color.hpp>
#include <LDL/OpenGL/OpenGLTypes.hpp>

void GLCheck(const char* file, size_t line, const char* expression);
void GLNormalize(const LDL_Color& color, GLclampf& r, GLclampf& g, GLclampf& b);
GLuint GLCreateTexture(GLsizei width, GLsizei heigth, GLint format);
void GLDeleteTexture(GLint id);

#define GL_CHECK(expr)                      \
    do                                      \
    {                                       \
        expr;                               \
        GLCheck(__FILE__, __LINE__, #expr); \
    } while (false) 

#endif