// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_OpenGL_OpenGL2_1_hpp
#define LDL_APIs_OpenGL_OpenGL2_1_hpp

#include <LDL/APIs/OpenGL/OpenGL2_0.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_API_CALL* PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_API_CALL* PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_API_CALL* PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_API_CALL* PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_API_CALL* PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_API_CALL* PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

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
