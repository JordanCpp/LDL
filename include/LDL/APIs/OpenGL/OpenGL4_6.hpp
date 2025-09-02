// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_OpenGL_OpenGL4_6_hpp
#define LDL_OpenGL_OpenGL4_6_hpp

#include <LDL/APIs/OpenGL/OpenGL4_5.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_API_CALL* PFNGLSPECIALIZESHADERPROC)(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue);
typedef void (LDL_API_CALL* PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (LDL_API_CALL* PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (LDL_API_CALL* PFNGLPOLYGONOFFSETCLAMPPROC)(GLfloat factor, GLfloat units, GLfloat clamp);

LDL_API_ENTRY PFNGLSPECIALIZESHADERPROC glSpecializeShader;
LDL_API_ENTRY PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount;
LDL_API_ENTRY PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount;
LDL_API_ENTRY PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp;

#ifdef __cplusplus
}
#endif

#endif     
