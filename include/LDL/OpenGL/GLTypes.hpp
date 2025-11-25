// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_GLTypes_hpp
#define LDL_GLTypes_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>

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

typedef void (LDL_API_CALL* GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

#endif      
