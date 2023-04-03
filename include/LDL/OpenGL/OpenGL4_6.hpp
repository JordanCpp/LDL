#ifndef LDL_OpenGL_OpenGL4_6_hpp
#define LDL_OpenGL_OpenGL4_6_hpp

#include <LDL/OpenGL/OpenGL4_5.hpp>

typedef void (OPENGL_API_CALL PFNGLSPECIALIZESHADERPROC)(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue);
typedef void (OPENGL_API_CALL PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (OPENGL_API_CALL PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (OPENGL_API_CALL PFNGLPOLYGONOFFSETCLAMPPROC)(GLfloat factor, GLfloat units, GLfloat clamp);

OPENGL_API_ENTRY PFNGLSPECIALIZESHADERPROC* glSpecializeShader;
OPENGL_API_ENTRY PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC* glMultiDrawArraysIndirectCount;
OPENGL_API_ENTRY PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC* glMultiDrawElementsIndirectCount;
OPENGL_API_ENTRY PFNGLPOLYGONOFFSETCLAMPPROC* glPolygonOffsetClamp;

#endif     