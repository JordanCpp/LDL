#ifndef LDL_OpenGL_OpenGLTypes_hpp
#define LDL_OpenGL_OpenGLTypes_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/Config.hpp>

#define LDL_OPENGL_API_CALL  __stdcall *
#define LDL_OPENGL_API_ENTRY LDL_EXPORT extern

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;
typedef unsigned int GLhandle;
typedef char GLchar;
typedef signed long int GLsizeiptr;
typedef intptr_t GLintptr;
typedef uint64_t GLint64;
typedef uint64_t GLuint64;
typedef struct __GLsync* GLsync;

typedef void (LDL_OPENGL_API_CALL GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

#endif      