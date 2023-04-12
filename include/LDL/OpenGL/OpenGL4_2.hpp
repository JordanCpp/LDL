#ifndef LDL_OpenGL_OpenGL4_2_hpp
#define LDL_OpenGL_OpenGL4_2_hpp

#include <LDL/OpenGL/OpenGL4_1.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (OPENGL_API_CALL PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void (OPENGL_API_CALL PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance);
typedef void (OPENGL_API_CALL PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef void (OPENGL_API_CALL PFNGLGETINTERNALFORMATIVPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params);
typedef void (OPENGL_API_CALL PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);
typedef void (OPENGL_API_CALL PFNGLBINDIMAGETEXTUREPROC)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (OPENGL_API_CALL PFNGLMEMORYBARRIERPROC)(GLbitfield barriers);
typedef void (OPENGL_API_CALL PFNGLTEXSTORAGE1DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (OPENGL_API_CALL PFNGLTEXSTORAGE2DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (OPENGL_API_CALL PFNGLTEXSTORAGE3DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (OPENGL_API_CALL PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum mode, GLuint id, GLsizei instancecount);
typedef void (OPENGL_API_CALL PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);

OPENGL_API_ENTRY PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance;
OPENGL_API_ENTRY PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance;
OPENGL_API_ENTRY PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance;
OPENGL_API_ENTRY PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ;
OPENGL_API_ENTRY PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv;
OPENGL_API_ENTRY PFNGLBINDIMAGETEXTUREPROC glBindImageTexture;
OPENGL_API_ENTRY PFNGLMEMORYBARRIERPROC glMemoryBarrier;
OPENGL_API_ENTRY PFNGLTEXSTORAGE1DPROC glTexStorage1D;
OPENGL_API_ENTRY PFNGLTEXSTORAGE2DPROC glTexStorage2D;
OPENGL_API_ENTRY PFNGLTEXSTORAGE3DPROC glTexStorage3D;
OPENGL_API_ENTRY PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced;
OPENGL_API_ENTRY PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced;

#ifdef __cplusplus
}
#endif

#endif 