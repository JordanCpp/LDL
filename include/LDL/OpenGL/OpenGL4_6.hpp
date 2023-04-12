#ifndef LDL_OpenGL_OpenGL4_6_hpp
#define LDL_OpenGL_OpenGL4_6_hpp

#include <LDL/OpenGL/OpenGL4_5.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_OPENGL_API_CALL PFNGLSPECIALIZESHADERPROC)(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue);
typedef void (LDL_OPENGL_API_CALL PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (LDL_OPENGL_API_CALL PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (LDL_OPENGL_API_CALL PFNGLPOLYGONOFFSETCLAMPPROC)(GLfloat factor, GLfloat units, GLfloat clamp);

LDL_OPENGL_API_ENTRY PFNGLSPECIALIZESHADERPROC glSpecializeShader;
LDL_OPENGL_API_ENTRY PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount;
LDL_OPENGL_API_ENTRY PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount;
LDL_OPENGL_API_ENTRY PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp;

#ifdef __cplusplus
}
#endif

#endif     