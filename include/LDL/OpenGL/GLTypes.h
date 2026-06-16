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

#ifndef LDL_OpenGL_GLTypes_H
#define LDL_OpenGL_GLTypes_H

#include <LDL/Config.h>
#include <LDL/Types.h>

typedef uint32_t  GLenum;
typedef uint8_t   GLboolean;
typedef uint32_t  GLbitfield;
typedef int8_t    GLbyte;
typedef int16_t   GLshort;
typedef int32_t   GLint;
typedef int32_t   GLsizei;
typedef uint8_t   GLubyte;
typedef uint16_t  GLushort;
typedef uint32_t  GLuint;
typedef float     GLfloat;
typedef float     GLclampf;
typedef double    GLdouble;
typedef double    GLclampd;
typedef void      GLvoid;
typedef uint32_t  GLhandle;
typedef char      GLchar;
typedef int32_t   GLsizeiptr;
typedef intptr_t  GLintptr;
typedef uint64_t  GLint64;
typedef uint64_t  GLuint64;
typedef struct __GLsync* GLsync;

typedef void (LDL_GL_CALL* GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

#endif      
