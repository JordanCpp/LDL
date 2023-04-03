#ifndef LDL_OpenGL_OpenGL4_4_hpp
#define LDL_OpenGL_OpenGL4_4_hpp

#include <LDL/OpenGL/OpenGL4_3.hpp>

typedef void (OPENGL_API_CALL PFNGLBUFFERSTORAGEPROC)(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags);
typedef void (OPENGL_API_CALL PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const void* data);
typedef void (OPENGL_API_CALL PFNGLCLEARTEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data);
typedef void (OPENGL_API_CALL PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
typedef void (OPENGL_API_CALL PFNGLBINDBUFFERSRANGEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
typedef void (OPENGL_API_CALL PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint* textures);
typedef void (OPENGL_API_CALL PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint* samplers);
typedef void (OPENGL_API_CALL PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint* textures);
typedef void (OPENGL_API_CALL PFNGLBINDVERTEXBUFFERSPROC)(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);

OPENGL_API_ENTRY PFNGLBUFFERSTORAGEPROC* glBufferStorage;
OPENGL_API_ENTRY PFNGLCLEARTEXIMAGEPROC* glClearTexImage;
OPENGL_API_ENTRY PFNGLCLEARTEXSUBIMAGEPROC* glClearTexSubImage;
OPENGL_API_ENTRY PFNGLBINDBUFFERSBASEPROC* glBindBuffersBase;
OPENGL_API_ENTRY PFNGLBINDBUFFERSRANGEPROC* glBindBuffersRange;
OPENGL_API_ENTRY PFNGLBINDTEXTURESPROC* glBindTextures;
OPENGL_API_ENTRY PFNGLBINDSAMPLERSPROC* glBindSamplers;
OPENGL_API_ENTRY PFNGLBINDIMAGETEXTURESPROC* glBindImageTextures;
OPENGL_API_ENTRY PFNGLBINDVERTEXBUFFERSPROC* glBindVertexBuffers;

#endif 