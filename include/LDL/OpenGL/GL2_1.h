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

#ifndef LDL_APIs_OpenGL_OpenGL2_1_hpp
#define LDL_APIs_OpenGL_OpenGL2_1_hpp

#include <LDL/OpenGL/GL2_0.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_GL_CALL* PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_GL_CALL* PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_GL_CALL* PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_GL_CALL* PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_GL_CALL* PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_GL_CALL* PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

LDL_API_ENTRY PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
LDL_API_ENTRY PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
LDL_API_ENTRY PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
LDL_API_ENTRY PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
LDL_API_ENTRY PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
LDL_API_ENTRY PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;

#ifdef __cplusplus
}
#endif

#endif     
