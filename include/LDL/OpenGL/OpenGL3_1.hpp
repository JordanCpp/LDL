#ifndef LDL_OpenGL_OpenGL3_1_hpp
#define LDL_OpenGL_OpenGL3_1_hpp

#include <LDL/OpenGL/OpenGL3_0.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (OPENGL_API_CALL PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (OPENGL_API_CALL PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
typedef void (OPENGL_API_CALL PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
typedef void (OPENGL_API_CALL PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
typedef void (OPENGL_API_CALL PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (OPENGL_API_CALL PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
typedef void (OPENGL_API_CALL PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
typedef void (OPENGL_API_CALL PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
typedef GLuint(OPENGL_API_CALL PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar* uniformBlockName);
typedef void (OPENGL_API_CALL PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
typedef void (OPENGL_API_CALL PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
typedef void (OPENGL_API_CALL PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

OPENGL_API_ENTRY PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
OPENGL_API_ENTRY PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
OPENGL_API_ENTRY PFNGLTEXBUFFERPROC glTexBuffer;
OPENGL_API_ENTRY PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
OPENGL_API_ENTRY PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;
OPENGL_API_ENTRY PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
OPENGL_API_ENTRY PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
OPENGL_API_ENTRY PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
OPENGL_API_ENTRY PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
OPENGL_API_ENTRY PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
OPENGL_API_ENTRY PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
OPENGL_API_ENTRY PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;

#ifdef __cplusplus
}
#endif

#endif     