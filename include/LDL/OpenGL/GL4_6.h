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

#ifndef LDL_APIs_OpenGL_OpenGL4_6_hpp
#define LDL_APIs_OpenGL_OpenGL4_6_hpp

#include <LDL/OpenGL/GL4_5.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_GL_CALL* PFNGLSPECIALIZESHADERPROC)(GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue);
typedef void (LDL_GL_CALL* PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)(GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (LDL_GL_CALL* PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)(GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (LDL_GL_CALL* PFNGLPOLYGONOFFSETCLAMPPROC)(GLfloat factor, GLfloat units, GLfloat clamp);

LDL_API_ENTRY PFNGLSPECIALIZESHADERPROC glSpecializeShader;
LDL_API_ENTRY PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount;
LDL_API_ENTRY PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount;
LDL_API_ENTRY PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp;

#ifdef __cplusplus
}
#endif

#endif     
