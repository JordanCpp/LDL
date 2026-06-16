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

#ifndef LDL_APIs_OpenGL_OpenGL3_1_hpp
#define LDL_APIs_OpenGL_OpenGL3_1_hpp

#include <LDL/OpenGL/GL3_0.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_GL_CALL* PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (LDL_GL_CALL* PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
typedef void (LDL_GL_CALL* PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
typedef void (LDL_GL_CALL* PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
typedef void (LDL_GL_CALL* PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (LDL_GL_CALL* PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
typedef void (LDL_GL_CALL* PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
typedef void (LDL_GL_CALL* PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
typedef GLuint(LDL_GL_CALL* PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar* uniformBlockName);
typedef void (LDL_GL_CALL* PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
typedef void (LDL_GL_CALL* PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
typedef void (LDL_GL_CALL* PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

LDL_API_ENTRY PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
LDL_API_ENTRY PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
LDL_API_ENTRY PFNGLTEXBUFFERPROC glTexBuffer;
LDL_API_ENTRY PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
LDL_API_ENTRY PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;
LDL_API_ENTRY PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
LDL_API_ENTRY PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
LDL_API_ENTRY PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
LDL_API_ENTRY PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
LDL_API_ENTRY PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
LDL_API_ENTRY PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
LDL_API_ENTRY PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;

#ifdef __cplusplus
}
#endif

#endif     
