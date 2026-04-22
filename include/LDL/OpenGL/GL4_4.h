/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#ifndef LDL_APIs_OpenGL_OpenGL4_4_hpp
#define LDL_APIs_OpenGL_OpenGL4_4_hpp

#include <LDL/OpenGL/GL4_3.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_API_CALL* PFNGLBUFFERSTORAGEPROC)(GLenum target, GLsizeiptr size, const void* data, GLbitfield flags);
typedef void (LDL_API_CALL* PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const void* data);
typedef void (LDL_API_CALL* PFNGLCLEARTEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data);
typedef void (LDL_API_CALL* PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
typedef void (LDL_API_CALL* PFNGLBINDBUFFERSRANGEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
typedef void (LDL_API_CALL* PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint* textures);
typedef void (LDL_API_CALL* PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint* samplers);
typedef void (LDL_API_CALL* PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint* textures);
typedef void (LDL_API_CALL* PFNGLBINDVERTEXBUFFERSPROC)(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);

LDL_API_ENTRY PFNGLBUFFERSTORAGEPROC glBufferStorage;
LDL_API_ENTRY PFNGLCLEARTEXIMAGEPROC glClearTexImage;
LDL_API_ENTRY PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage;
LDL_API_ENTRY PFNGLBINDBUFFERSBASEPROC glBindBuffersBase;
LDL_API_ENTRY PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange;
LDL_API_ENTRY PFNGLBINDTEXTURESPROC glBindTextures;
LDL_API_ENTRY PFNGLBINDSAMPLERSPROC glBindSamplers;
LDL_API_ENTRY PFNGLBINDIMAGETEXTURESPROC glBindImageTextures;
LDL_API_ENTRY PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers;

#ifdef __cplusplus
}
#endif

#endif 
