#ifndef LDL_OpenGL_OpenGL3_2_hpp
#define LDL_OpenGL_OpenGL3_2_hpp

#include <LDL/OpenGL/OpenGL3_1.hpp>

typedef void (OPENGL_API_CALL PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);
typedef void (OPENGL_API_CALL PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex);
typedef void (OPENGL_API_CALL PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex);
typedef void (OPENGL_API_CALL PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex);
typedef void (OPENGL_API_CALL PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
typedef GLsync(OPENGL_API_CALL PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
typedef GLboolean(OPENGL_API_CALL PFNGLISSYNCPROC)(GLsync sync);
typedef void (OPENGL_API_CALL PFNGLDELETESYNCPROC)(GLsync sync);
typedef GLenum(OPENGL_API_CALL PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (OPENGL_API_CALL PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (OPENGL_API_CALL PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64* data);
typedef void (OPENGL_API_CALL PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values);
typedef void (OPENGL_API_CALL PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64* data);
typedef void (OPENGL_API_CALL PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64* params);
typedef void (OPENGL_API_CALL PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (OPENGL_API_CALL PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (OPENGL_API_CALL PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (OPENGL_API_CALL PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat* val);
typedef void (OPENGL_API_CALL PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);

OPENGL_API_ENTRY PFNGLDRAWELEMENTSBASEVERTEXPROC* glDrawElementsBaseVertex;
OPENGL_API_ENTRY PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC* glDrawRangeElementsBaseVertex;
OPENGL_API_ENTRY PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC* glDrawElementsInstancedBaseVertex;
OPENGL_API_ENTRY PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC* glMultiDrawElementsBaseVertex;
OPENGL_API_ENTRY PFNGLPROVOKINGVERTEXPROC* glProvokingVertex;
OPENGL_API_ENTRY PFNGLFENCESYNCPROC* glFenceSync;
OPENGL_API_ENTRY PFNGLISSYNCPROC* glIsSync;
OPENGL_API_ENTRY PFNGLDELETESYNCPROC* glDeleteSync;
OPENGL_API_ENTRY PFNGLCLIENTWAITSYNCPROC* glClientWaitSync;
OPENGL_API_ENTRY PFNGLWAITSYNCPROC* glWaitSync;
OPENGL_API_ENTRY PFNGLGETINTEGER64VPROC* glGetInteger64v;
OPENGL_API_ENTRY PFNGLGETSYNCIVPROC* glGetSynciv;
OPENGL_API_ENTRY PFNGLGETINTEGER64I_VPROC* glGetInteger64i_v;
OPENGL_API_ENTRY PFNGLGETBUFFERPARAMETERI64VPROC* glGetBufferParameteri64v;
OPENGL_API_ENTRY PFNGLFRAMEBUFFERTEXTUREPROC* glFramebufferTexture;
OPENGL_API_ENTRY PFNGLTEXIMAGE2DMULTISAMPLEPROC* glTexImage2DMultisample;
OPENGL_API_ENTRY PFNGLTEXIMAGE3DMULTISAMPLEPROC* glTexImage3DMultisample;
OPENGL_API_ENTRY PFNGLGETMULTISAMPLEFVPROC* glGetMultisamplefv;
OPENGL_API_ENTRY PFNGLSAMPLEMASKIPROC* glSampleMaski;

#endif     