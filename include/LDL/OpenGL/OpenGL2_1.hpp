#ifndef LDL_OpenGL_OpenGL2_1_hpp
#define LDL_OpenGL_OpenGL2_1_hpp

#include <LDL/OpenGL/OpenGL2_0.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_OPENGL_API_CALL PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_OPENGL_API_CALL PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_OPENGL_API_CALL PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_OPENGL_API_CALL PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_OPENGL_API_CALL PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (LDL_OPENGL_API_CALL PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

LDL_OPENGL_API_ENTRY PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
LDL_OPENGL_API_ENTRY PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
LDL_OPENGL_API_ENTRY PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
LDL_OPENGL_API_ENTRY PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
LDL_OPENGL_API_ENTRY PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
LDL_OPENGL_API_ENTRY PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;

#ifdef __cplusplus
}
#endif

#endif     