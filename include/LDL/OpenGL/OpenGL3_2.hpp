#ifndef LDL_OpenGL_OpenGL3_2_hpp
#define LDL_OpenGL_OpenGL3_2_hpp

#include <LDL/OpenGL/OpenGL3_1.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_OPENGL_API_CALL PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);
typedef void (LDL_OPENGL_API_CALL PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex);
typedef void (LDL_OPENGL_API_CALL PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex);
typedef void (LDL_OPENGL_API_CALL PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex);
typedef void (LDL_OPENGL_API_CALL PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
typedef GLsync(LDL_OPENGL_API_CALL PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
typedef GLboolean(LDL_OPENGL_API_CALL PFNGLISSYNCPROC)(GLsync sync);
typedef void (LDL_OPENGL_API_CALL PFNGLDELETESYNCPROC)(GLsync sync);
typedef GLenum(LDL_OPENGL_API_CALL PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (LDL_OPENGL_API_CALL PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (LDL_OPENGL_API_CALL PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64* data);
typedef void (LDL_OPENGL_API_CALL PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values);
typedef void (LDL_OPENGL_API_CALL PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64* data);
typedef void (LDL_OPENGL_API_CALL PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64* params);
typedef void (LDL_OPENGL_API_CALL PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (LDL_OPENGL_API_CALL PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat* val);
typedef void (LDL_OPENGL_API_CALL PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);

LDL_OPENGL_API_ENTRY PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;
LDL_OPENGL_API_ENTRY PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;
LDL_OPENGL_API_ENTRY PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;
LDL_OPENGL_API_ENTRY PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;
LDL_OPENGL_API_ENTRY PFNGLPROVOKINGVERTEXPROC glProvokingVertex;
LDL_OPENGL_API_ENTRY PFNGLFENCESYNCPROC glFenceSync;
LDL_OPENGL_API_ENTRY PFNGLISSYNCPROC glIsSync;
LDL_OPENGL_API_ENTRY PFNGLDELETESYNCPROC glDeleteSync;
LDL_OPENGL_API_ENTRY PFNGLCLIENTWAITSYNCPROC glClientWaitSync;
LDL_OPENGL_API_ENTRY PFNGLWAITSYNCPROC glWaitSync;
LDL_OPENGL_API_ENTRY PFNGLGETINTEGER64VPROC glGetInteger64v;
LDL_OPENGL_API_ENTRY PFNGLGETSYNCIVPROC glGetSynciv;
LDL_OPENGL_API_ENTRY PFNGLGETINTEGER64I_VPROC glGetInteger64i_v;
LDL_OPENGL_API_ENTRY PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
LDL_OPENGL_API_ENTRY PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;
LDL_OPENGL_API_ENTRY PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;
LDL_OPENGL_API_ENTRY PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample;
LDL_OPENGL_API_ENTRY PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv;
LDL_OPENGL_API_ENTRY PFNGLSAMPLEMASKIPROC glSampleMaski;

#ifdef __cplusplus
}
#endif

#endif     