#ifndef LDL_OpenGL_OpenGL1_1_hpp
#define LDL_OpenGL_OpenGL1_1_hpp

#include <LDL/OpenGL/OpenGL1_0.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_OPENGL_API_CALL PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
typedef void (LDL_OPENGL_API_CALL PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void* indices);
typedef void (LDL_OPENGL_API_CALL PFNGLGETPOINTERVPROC)(GLenum pname, void** params);
typedef void (LDL_OPENGL_API_CALL PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
typedef void (LDL_OPENGL_API_CALL PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (LDL_OPENGL_API_CALL PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (LDL_OPENGL_API_CALL PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (LDL_OPENGL_API_CALL PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
typedef void (LDL_OPENGL_API_CALL PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
typedef void (LDL_OPENGL_API_CALL PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint* textures);
typedef void (LDL_OPENGL_API_CALL PFNGLGENTEXTURESPROC)(GLsizei n, GLuint* textures);
typedef GLboolean(LDL_OPENGL_API_CALL PFNGLISTEXTUREPROC)(GLuint texture);
typedef void (LDL_OPENGL_API_CALL PFNGLARRAYELEMENTPROC)(GLint i);
typedef void (LDL_OPENGL_API_CALL PFNGLCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void* pointer);
typedef void (LDL_OPENGL_API_CALL PFNGLDISABLECLIENTSTATEPROC)(GLenum array);
typedef void (LDL_OPENGL_API_CALL PFNGLEDGEFLAGPOINTERPROC)(GLsizei stride, const void* pointer);
typedef void (LDL_OPENGL_API_CALL PFNGLENABLECLIENTSTATEPROC)(GLenum array);
typedef void (LDL_OPENGL_API_CALL PFNGLINDEXPOINTERPROC)(GLenum type, GLsizei stride, const void* pointer);
typedef void (LDL_OPENGL_API_CALL PFNGLINTERLEAVEDARRAYSPROC)(GLenum format, GLsizei stride, const void* pointer);
typedef void (LDL_OPENGL_API_CALL PFNGLNORMALPOINTERPROC)(GLenum type, GLsizei stride, const void* pointer);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXCOORDPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void* pointer);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void* pointer);
typedef GLboolean(LDL_OPENGL_API_CALL PFNGLARETEXTURESRESIDENTPROC)(GLsizei n, const GLuint* textures, GLboolean* residences);
typedef void (LDL_OPENGL_API_CALL PFNGLPRIORITIZETEXTURESPROC)(GLsizei n, const GLuint* textures, const GLfloat* priorities);
typedef void (LDL_OPENGL_API_CALL PFNGLINDEXUBPROC)(GLubyte c);
typedef void (LDL_OPENGL_API_CALL PFNGLINDEXUBVPROC)(const GLubyte* c);
typedef void (LDL_OPENGL_API_CALL PFNGLPOPCLIENTATTRIBPROC)(void);
typedef void (LDL_OPENGL_API_CALL PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield mask);

LDL_OPENGL_API_ENTRY PFNGLDRAWARRAYSPROC glDrawArrays;
LDL_OPENGL_API_ENTRY PFNGLDRAWELEMENTSPROC glDrawElements;
LDL_OPENGL_API_ENTRY PFNGLGETPOINTERVPROC glGetPointerv;
LDL_OPENGL_API_ENTRY PFNGLPOLYGONOFFSETPROC glPolygonOffset;
LDL_OPENGL_API_ENTRY PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D;
LDL_OPENGL_API_ENTRY PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D;
LDL_OPENGL_API_ENTRY PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D;
LDL_OPENGL_API_ENTRY PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D;
LDL_OPENGL_API_ENTRY PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D;
LDL_OPENGL_API_ENTRY PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D;
LDL_OPENGL_API_ENTRY PFNGLBINDTEXTUREPROC glBindTexture;
LDL_OPENGL_API_ENTRY PFNGLDELETETEXTURESPROC glDeleteTextures;
LDL_OPENGL_API_ENTRY PFNGLGENTEXTURESPROC glGenTextures;
LDL_OPENGL_API_ENTRY PFNGLISTEXTUREPROC glIsTexture;
LDL_OPENGL_API_ENTRY PFNGLARRAYELEMENTPROC glArrayElement;
LDL_OPENGL_API_ENTRY PFNGLCOLORPOINTERPROC glColorPointer;
LDL_OPENGL_API_ENTRY PFNGLDISABLECLIENTSTATEPROC glDisableClientState;
LDL_OPENGL_API_ENTRY PFNGLEDGEFLAGPOINTERPROC glEdgeFlagPointer;
LDL_OPENGL_API_ENTRY PFNGLENABLECLIENTSTATEPROC glEnableClientState;
LDL_OPENGL_API_ENTRY PFNGLINDEXPOINTERPROC glIndexPointer;
LDL_OPENGL_API_ENTRY PFNGLINTERLEAVEDARRAYSPROC glInterleavedArrays;
LDL_OPENGL_API_ENTRY PFNGLNORMALPOINTERPROC glNormalPointer;
LDL_OPENGL_API_ENTRY PFNGLTEXCOORDPOINTERPROC glTexCoordPointer;
LDL_OPENGL_API_ENTRY PFNGLVERTEXPOINTERPROC glVertexPointer;
LDL_OPENGL_API_ENTRY PFNGLARETEXTURESRESIDENTPROC glAreTexturesResident;
LDL_OPENGL_API_ENTRY PFNGLPRIORITIZETEXTURESPROC glPrioritizeTextures;
LDL_OPENGL_API_ENTRY PFNGLINDEXUBPROC glIndexub;
LDL_OPENGL_API_ENTRY PFNGLINDEXUBVPROC glIndexubv;
LDL_OPENGL_API_ENTRY PFNGLPOPCLIENTATTRIBPROC glPopClientAttrib;
LDL_OPENGL_API_ENTRY PFNGLPUSHCLIENTATTRIBPROC glPushClientAttrib;

#ifdef __cplusplus
}
#endif

#endif     