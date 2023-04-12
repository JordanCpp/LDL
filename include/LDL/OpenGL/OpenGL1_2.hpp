#ifndef LDL_OpenGL_OpenGL1_2_hpp
#define LDL_OpenGL_OpenGL1_2_hpp

#include <LDL/OpenGL/OpenGL1_1.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_OPENGL_API_CALL PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
typedef void (LDL_OPENGL_API_CALL PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

LDL_OPENGL_API_ENTRY PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
LDL_OPENGL_API_ENTRY PFNGLTEXIMAGE3DPROC glTexImage3D;
LDL_OPENGL_API_ENTRY PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;
LDL_OPENGL_API_ENTRY PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;

#ifdef __cplusplus
}
#endif

#endif     