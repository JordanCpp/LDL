#ifndef LDL_OpenGL_OpenGL4_4_hpp
#define LDL_OpenGL_OpenGL4_4_hpp

#include <LDL/OpenGL/OpenGL4_3.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_OPENGL_API_CALL PFNGLBUFFERSTORAGEPROC)(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags);
typedef void (LDL_OPENGL_API_CALL PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const void* data);
typedef void (LDL_OPENGL_API_CALL PFNGLCLEARTEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data);
typedef void (LDL_OPENGL_API_CALL PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
typedef void (LDL_OPENGL_API_CALL PFNGLBINDBUFFERSRANGEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
typedef void (LDL_OPENGL_API_CALL PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint* textures);
typedef void (LDL_OPENGL_API_CALL PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint* samplers);
typedef void (LDL_OPENGL_API_CALL PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint* textures);
typedef void (LDL_OPENGL_API_CALL PFNGLBINDVERTEXBUFFERSPROC)(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);

LDL_OPENGL_API_ENTRY PFNGLBUFFERSTORAGEPROC glBufferStorage;
LDL_OPENGL_API_ENTRY PFNGLCLEARTEXIMAGEPROC glClearTexImage;
LDL_OPENGL_API_ENTRY PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage;
LDL_OPENGL_API_ENTRY PFNGLBINDBUFFERSBASEPROC glBindBuffersBase;
LDL_OPENGL_API_ENTRY PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange;
LDL_OPENGL_API_ENTRY PFNGLBINDTEXTURESPROC glBindTextures;
LDL_OPENGL_API_ENTRY PFNGLBINDSAMPLERSPROC glBindSamplers;
LDL_OPENGL_API_ENTRY PFNGLBINDIMAGETEXTURESPROC glBindImageTextures;
LDL_OPENGL_API_ENTRY PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers;

#ifdef __cplusplus
}
#endif

#endif 