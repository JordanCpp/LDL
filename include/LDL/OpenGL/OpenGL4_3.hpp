#ifndef LDL_OpenGL_OpenGL4_3_hpp
#define LDL_OpenGL_OpenGL4_3_hpp

#include <LDL/OpenGL/OpenGL4_2.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_OPENGL_API_CALL PFNGLCLEARBUFFERDATAPROC)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data);
typedef void (LDL_OPENGL_API_CALL PFNGLCLEARBUFFERSUBDATAPROC)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
typedef void (LDL_OPENGL_API_CALL PFNGLDISPATCHCOMPUTEPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (LDL_OPENGL_API_CALL PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
typedef void (LDL_OPENGL_API_CALL PFNGLCOPYIMAGESUBDATAPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void (LDL_OPENGL_API_CALL PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (LDL_OPENGL_API_CALL PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (LDL_OPENGL_API_CALL PFNGLGETINTERNALFORMATI64VPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params);
typedef void (LDL_OPENGL_API_CALL PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void (LDL_OPENGL_API_CALL PFNGLINVALIDATETEXIMAGEPROC)(GLuint texture, GLint level);
typedef void (LDL_OPENGL_API_CALL PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (LDL_OPENGL_API_CALL PFNGLINVALIDATEBUFFERDATAPROC)(GLuint buffer);
typedef void (LDL_OPENGL_API_CALL PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum* attachments);
typedef void (LDL_OPENGL_API_CALL PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (LDL_OPENGL_API_CALL PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride);
typedef void (LDL_OPENGL_API_CALL PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride);
typedef void (LDL_OPENGL_API_CALL PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint program, GLenum programInterface, GLenum pname, GLint* params);
typedef GLuint(LDL_OPENGL_API_CALL PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint program, GLenum programInterface, const GLchar* name);
typedef void (LDL_OPENGL_API_CALL PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
typedef void (LDL_OPENGL_API_CALL PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params);
typedef GLint(LDL_OPENGL_API_CALL PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint program, GLenum programInterface, const GLchar* name);
typedef GLint(LDL_OPENGL_API_CALL PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint program, GLenum programInterface, const GLchar* name);
typedef void (LDL_OPENGL_API_CALL PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXBUFFERRANGEPROC)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTUREVIEWPROC)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef void (LDL_OPENGL_API_CALL PFNGLBINDVERTEXBUFFERPROC)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXATTRIBFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXATTRIBIFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXATTRIBLFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXATTRIBBINDINGPROC)(GLuint attribindex, GLuint bindingindex);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXBINDINGDIVISORPROC)(GLuint bindingindex, GLuint divisor);
typedef void (LDL_OPENGL_API_CALL PFNGLDEBUGMESSAGECONTROLPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
typedef void (LDL_OPENGL_API_CALL PFNGLDEBUGMESSAGEINSERTPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
typedef void (LDL_OPENGL_API_CALL PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void* userParam);
typedef GLuint(LDL_OPENGL_API_CALL PFNGLGETDEBUGMESSAGELOGPROC)(GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
typedef void (LDL_OPENGL_API_CALL PFNGLPUSHDEBUGGROUPPROC)(GLenum source, GLuint id, GLsizei length, const GLchar* message);
typedef void (LDL_OPENGL_API_CALL PFNGLPOPDEBUGGROUPPROC)(void);
typedef void (LDL_OPENGL_API_CALL PFNGLOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
typedef void (LDL_OPENGL_API_CALL PFNGLGETOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
typedef void (LDL_OPENGL_API_CALL PFNGLOBJECTPTRLABELPROC)(const void* ptr, GLsizei length, const GLchar* label);
typedef void (LDL_OPENGL_API_CALL PFNGLGETOBJECTPTRLABELPROC)(const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);

LDL_OPENGL_API_ENTRY PFNGLCLEARBUFFERDATAPROC glClearBufferData;
LDL_OPENGL_API_ENTRY PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData;
LDL_OPENGL_API_ENTRY PFNGLDISPATCHCOMPUTEPROC glDispatchCompute;
LDL_OPENGL_API_ENTRY PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect;
LDL_OPENGL_API_ENTRY PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData;
LDL_OPENGL_API_ENTRY PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri;
LDL_OPENGL_API_ENTRY PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv;
LDL_OPENGL_API_ENTRY PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v;
LDL_OPENGL_API_ENTRY PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage;
LDL_OPENGL_API_ENTRY PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage;
LDL_OPENGL_API_ENTRY PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData;
LDL_OPENGL_API_ENTRY PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData;
LDL_OPENGL_API_ENTRY PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer;
LDL_OPENGL_API_ENTRY PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer;
LDL_OPENGL_API_ENTRY PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect;
LDL_OPENGL_API_ENTRY PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect;
LDL_OPENGL_API_ENTRY PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv;
LDL_OPENGL_API_ENTRY PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex;
LDL_OPENGL_API_ENTRY PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName;
LDL_OPENGL_API_ENTRY PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv;
LDL_OPENGL_API_ENTRY PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation;
LDL_OPENGL_API_ENTRY PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex;
LDL_OPENGL_API_ENTRY PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding;
LDL_OPENGL_API_ENTRY PFNGLTEXBUFFERRANGEPROC glTexBufferRange;
LDL_OPENGL_API_ENTRY PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample;
LDL_OPENGL_API_ENTRY PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample;
LDL_OPENGL_API_ENTRY PFNGLTEXTUREVIEWPROC glTextureView;
LDL_OPENGL_API_ENTRY PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer;
LDL_OPENGL_API_ENTRY PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat;
LDL_OPENGL_API_ENTRY PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat;
LDL_OPENGL_API_ENTRY PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat;
LDL_OPENGL_API_ENTRY PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding;
LDL_OPENGL_API_ENTRY PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor;
LDL_OPENGL_API_ENTRY PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl;
LDL_OPENGL_API_ENTRY PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert;
LDL_OPENGL_API_ENTRY PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;
LDL_OPENGL_API_ENTRY PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog;
LDL_OPENGL_API_ENTRY PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;
LDL_OPENGL_API_ENTRY PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;
LDL_OPENGL_API_ENTRY PFNGLOBJECTLABELPROC glObjectLabel;
LDL_OPENGL_API_ENTRY PFNGLGETOBJECTLABELPROC glGetObjectLabel;
LDL_OPENGL_API_ENTRY PFNGLOBJECTPTRLABELPROC glObjectPtrLabel;
LDL_OPENGL_API_ENTRY PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel;

#ifdef __cplusplus
}
#endif

#endif 