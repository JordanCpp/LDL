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

#ifndef LDL_APIs_OpenGL_OpenGL1_2_hpp
#define LDL_APIs_OpenGL_OpenGL1_2_hpp

#include <LDL/OpenGL/GL1_1.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_API_CALL* PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
typedef void (LDL_API_CALL* PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (LDL_API_CALL* PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
typedef void (LDL_API_CALL* PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

LDL_API_ENTRY PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
LDL_API_ENTRY PFNGLTEXIMAGE3DPROC glTexImage3D;
LDL_API_ENTRY PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;
LDL_API_ENTRY PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;

#ifdef __cplusplus
}
#endif

#endif     
