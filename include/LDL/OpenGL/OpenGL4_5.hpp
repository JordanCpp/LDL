#ifndef LDL_OpenGL_OpenGL4_5_hpp
#define LDL_OpenGL_OpenGL4_5_hpp

#include <LDL/OpenGL/OpenGL4_4.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_OPENGL_API_CALL PFNGLCLIPCONTROLPROC)(GLenum origin, GLenum depth);
typedef void (LDL_OPENGL_API_CALL PFNGLCREATETRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint* ids);
typedef void (LDL_OPENGL_API_CALL PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint xfb, GLuint index, GLuint buffer);
typedef void (LDL_OPENGL_API_CALL PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (LDL_OPENGL_API_CALL PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint xfb, GLenum pname, GLint* param);
typedef void (LDL_OPENGL_API_CALL PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint* param);
typedef void (LDL_OPENGL_API_CALL PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint64* param);
typedef void (LDL_OPENGL_API_CALL PFNGLCREATEBUFFERSPROC)(GLsizei n, GLuint* buffers);
typedef void (LDL_OPENGL_API_CALL PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags);
typedef void (LDL_OPENGL_API_CALL PFNGLNAMEDBUFFERDATAPROC)(GLuint buffer, GLsizeiptr size, const void* data, GLenum usage);
typedef void (LDL_OPENGL_API_CALL PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data);
typedef void (LDL_OPENGL_API_CALL PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (LDL_OPENGL_API_CALL PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
typedef void (LDL_OPENGL_API_CALL PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
typedef void* (LDL_OPENGL_API_CALL PFNGLMAPNAMEDBUFFERPROC)(GLuint buffer, GLenum access);
typedef void* (LDL_OPENGL_API_CALL PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLboolean(LDL_OPENGL_API_CALL PFNGLUNMAPNAMEDBUFFERPROC)(GLuint buffer);
typedef void (LDL_OPENGL_API_CALL PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint buffer, GLenum pname, GLint* params);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint buffer, GLenum pname, GLint64* params);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint buffer, GLenum pname, void** params);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void* data);
typedef void (LDL_OPENGL_API_CALL PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei n, GLuint* framebuffers);
typedef void (LDL_OPENGL_API_CALL PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (LDL_OPENGL_API_CALL PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint framebuffer, GLenum pname, GLint param);
typedef void (LDL_OPENGL_API_CALL PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (LDL_OPENGL_API_CALL PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (LDL_OPENGL_API_CALL PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint framebuffer, GLenum buf);
typedef void (LDL_OPENGL_API_CALL PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint framebuffer, GLsizei n, const GLenum* bufs);
typedef void (LDL_OPENGL_API_CALL PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint framebuffer, GLenum src);
typedef void (LDL_OPENGL_API_CALL PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments);
typedef void (LDL_OPENGL_API_CALL PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (LDL_OPENGL_API_CALL PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value);
typedef void (LDL_OPENGL_API_CALL PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value);
typedef void (LDL_OPENGL_API_CALL PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value);
typedef void (LDL_OPENGL_API_CALL PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (LDL_OPENGL_API_CALL PFNGLBLITNAMEDFRAMEBUFFERPROC)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLenum(LDL_OPENGL_API_CALL PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint framebuffer, GLenum target);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint framebuffer, GLenum pname, GLint* param);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
typedef void (LDL_OPENGL_API_CALL PFNGLCREATERENDERBUFFERSPROC)(GLsizei n, GLuint* renderbuffers);
typedef void (LDL_OPENGL_API_CALL PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (LDL_OPENGL_API_CALL PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint renderbuffer, GLenum pname, GLint* params);
typedef void (LDL_OPENGL_API_CALL PFNGLCREATETEXTURESPROC)(GLenum target, GLsizei n, GLuint* textures);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTUREBUFFERPROC)(GLuint texture, GLenum internalformat, GLuint buffer);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTUREBUFFERRANGEPROC)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTURESTORAGE1DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTURESTORAGE2DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTURESTORAGE3DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
typedef void (LDL_OPENGL_API_CALL PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
typedef void (LDL_OPENGL_API_CALL PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
typedef void (LDL_OPENGL_API_CALL PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
typedef void (LDL_OPENGL_API_CALL PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (LDL_OPENGL_API_CALL PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (LDL_OPENGL_API_CALL PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTUREPARAMETERFPROC)(GLuint texture, GLenum pname, GLfloat param);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, const GLfloat* param);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTUREPARAMETERIPROC)(GLuint texture, GLenum pname, GLint param);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, const GLint* params);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, const GLuint* params);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, const GLint* param);
typedef void (LDL_OPENGL_API_CALL PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint texture);
typedef void (LDL_OPENGL_API_CALL PFNGLBINDTEXTUREUNITPROC)(GLuint unit, GLuint texture);
typedef void (LDL_OPENGL_API_CALL PFNGLGETTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
typedef void (LDL_OPENGL_API_CALL PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLsizei bufSize, void* pixels);
typedef void (LDL_OPENGL_API_CALL PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint texture, GLint level, GLenum pname, GLfloat* params);
typedef void (LDL_OPENGL_API_CALL PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint texture, GLint level, GLenum pname, GLint* params);
typedef void (LDL_OPENGL_API_CALL PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, GLfloat* params);
typedef void (LDL_OPENGL_API_CALL PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, GLint* params);
typedef void (LDL_OPENGL_API_CALL PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, GLuint* params);
typedef void (LDL_OPENGL_API_CALL PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, GLint* params);
typedef void (LDL_OPENGL_API_CALL PFNGLCREATEVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays);
typedef void (LDL_OPENGL_API_CALL PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
typedef void (LDL_OPENGL_API_CALL PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint vaobj, GLuint buffer);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (LDL_OPENGL_API_CALL PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (LDL_OPENGL_API_CALL PFNGLGETVERTEXARRAYIVPROC)(GLuint vaobj, GLenum pname, GLint* param);
typedef void (LDL_OPENGL_API_CALL PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint* param);
typedef void (LDL_OPENGL_API_CALL PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint64* param);
typedef void (LDL_OPENGL_API_CALL PFNGLCREATESAMPLERSPROC)(GLsizei n, GLuint* samplers);
typedef void (LDL_OPENGL_API_CALL PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei n, GLuint* pipelines);
typedef void (LDL_OPENGL_API_CALL PFNGLCREATEQUERIESPROC)(GLenum target, GLsizei n, GLuint* ids);
typedef void (LDL_OPENGL_API_CALL PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (LDL_OPENGL_API_CALL PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (LDL_OPENGL_API_CALL PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (LDL_OPENGL_API_CALL PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (LDL_OPENGL_API_CALL PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield barriers);
typedef void (LDL_OPENGL_API_CALL PFNGLGETTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
typedef void (LDL_OPENGL_API_CALL PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels);
typedef GLenum(LDL_OPENGL_API_CALL PFNGLGETGRAPHICSRESETSTATUSPROC)(void);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint lod, GLsizei bufSize, void* pixels);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNUNIFORMDVPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNUNIFORMFVPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNUNIFORMIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLint* params);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNUNIFORMUIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
typedef void (LDL_OPENGL_API_CALL PFNGLREADNPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNMAPDVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNMAPFVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNMAPIVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLint* v);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNPIXELMAPFVPROC)(GLenum map, GLsizei bufSize, GLfloat* values);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNPIXELMAPUIVPROC)(GLenum map, GLsizei bufSize, GLuint* values);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNPIXELMAPUSVPROC)(GLenum map, GLsizei bufSize, GLushort* values);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNPOLYGONSTIPPLEPROC)(GLsizei bufSize, GLubyte* pattern);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNCOLORTABLEPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNCONVOLUTIONFILTERPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* image);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNSEPARABLEFILTERPROC)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void* row, GLsizei columnBufSize, void* column, void* span);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNHISTOGRAMPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values);
typedef void (LDL_OPENGL_API_CALL PFNGLGETNMINMAXPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values);
typedef void (LDL_OPENGL_API_CALL PFNGLTEXTUREBARRIERPROC)(void);

LDL_OPENGL_API_ENTRY PFNGLCLIPCONTROLPROC glClipControl;
LDL_OPENGL_API_ENTRY PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks;
LDL_OPENGL_API_ENTRY PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase;
LDL_OPENGL_API_ENTRY PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange;
LDL_OPENGL_API_ENTRY PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv;
LDL_OPENGL_API_ENTRY PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v;
LDL_OPENGL_API_ENTRY PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v;
LDL_OPENGL_API_ENTRY PFNGLCREATEBUFFERSPROC glCreateBuffers;
LDL_OPENGL_API_ENTRY PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage;
LDL_OPENGL_API_ENTRY PFNGLNAMEDBUFFERDATAPROC glNamedBufferData;
LDL_OPENGL_API_ENTRY PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData;
LDL_OPENGL_API_ENTRY PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData;
LDL_OPENGL_API_ENTRY PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData;
LDL_OPENGL_API_ENTRY PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData;
LDL_OPENGL_API_ENTRY PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer;
LDL_OPENGL_API_ENTRY PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange;
LDL_OPENGL_API_ENTRY PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer;
LDL_OPENGL_API_ENTRY PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange;
LDL_OPENGL_API_ENTRY PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv;
LDL_OPENGL_API_ENTRY PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v;
LDL_OPENGL_API_ENTRY PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv;
LDL_OPENGL_API_ENTRY PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData;
LDL_OPENGL_API_ENTRY PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers;
LDL_OPENGL_API_ENTRY PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer;
LDL_OPENGL_API_ENTRY PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri;
LDL_OPENGL_API_ENTRY PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture;
LDL_OPENGL_API_ENTRY PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer;
LDL_OPENGL_API_ENTRY PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer;
LDL_OPENGL_API_ENTRY PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers;
LDL_OPENGL_API_ENTRY PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer;
LDL_OPENGL_API_ENTRY PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData;
LDL_OPENGL_API_ENTRY PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData;
LDL_OPENGL_API_ENTRY PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv;
LDL_OPENGL_API_ENTRY PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv;
LDL_OPENGL_API_ENTRY PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv;
LDL_OPENGL_API_ENTRY PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi;
LDL_OPENGL_API_ENTRY PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer;
LDL_OPENGL_API_ENTRY PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus;
LDL_OPENGL_API_ENTRY PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv;
LDL_OPENGL_API_ENTRY PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv;
LDL_OPENGL_API_ENTRY PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers;
LDL_OPENGL_API_ENTRY PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage;
LDL_OPENGL_API_ENTRY PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample;
LDL_OPENGL_API_ENTRY PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv;
LDL_OPENGL_API_ENTRY PFNGLCREATETEXTURESPROC glCreateTextures;
LDL_OPENGL_API_ENTRY PFNGLTEXTUREBUFFERPROC glTextureBuffer;
LDL_OPENGL_API_ENTRY PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange;
LDL_OPENGL_API_ENTRY PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D;
LDL_OPENGL_API_ENTRY PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D;
LDL_OPENGL_API_ENTRY PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D;
LDL_OPENGL_API_ENTRY PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample;
LDL_OPENGL_API_ENTRY PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample;
LDL_OPENGL_API_ENTRY PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D;
LDL_OPENGL_API_ENTRY PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D;
LDL_OPENGL_API_ENTRY PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D;
LDL_OPENGL_API_ENTRY PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D;
LDL_OPENGL_API_ENTRY PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D;
LDL_OPENGL_API_ENTRY PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D;
LDL_OPENGL_API_ENTRY PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D;
LDL_OPENGL_API_ENTRY PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D;
LDL_OPENGL_API_ENTRY PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D;
LDL_OPENGL_API_ENTRY PFNGLTEXTUREPARAMETERFPROC glTextureParameterf;
LDL_OPENGL_API_ENTRY PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv;
LDL_OPENGL_API_ENTRY PFNGLTEXTUREPARAMETERIPROC glTextureParameteri;
LDL_OPENGL_API_ENTRY PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv;
LDL_OPENGL_API_ENTRY PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv;
LDL_OPENGL_API_ENTRY PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv;
LDL_OPENGL_API_ENTRY PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap;
LDL_OPENGL_API_ENTRY PFNGLBINDTEXTUREUNITPROC glBindTextureUnit;
LDL_OPENGL_API_ENTRY PFNGLGETTEXTUREIMAGEPROC glGetTextureImage;
LDL_OPENGL_API_ENTRY PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage;
LDL_OPENGL_API_ENTRY PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv;
LDL_OPENGL_API_ENTRY PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv;
LDL_OPENGL_API_ENTRY PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv;
LDL_OPENGL_API_ENTRY PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv;
LDL_OPENGL_API_ENTRY PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv;
LDL_OPENGL_API_ENTRY PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv;
LDL_OPENGL_API_ENTRY PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays;
LDL_OPENGL_API_ENTRY PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib;
LDL_OPENGL_API_ENTRY PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib;
LDL_OPENGL_API_ENTRY PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer;
LDL_OPENGL_API_ENTRY PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer;
LDL_OPENGL_API_ENTRY PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers;
LDL_OPENGL_API_ENTRY PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding;
LDL_OPENGL_API_ENTRY PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat;
LDL_OPENGL_API_ENTRY PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat;
LDL_OPENGL_API_ENTRY PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat;
LDL_OPENGL_API_ENTRY PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor;
LDL_OPENGL_API_ENTRY PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv;
LDL_OPENGL_API_ENTRY PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv;
LDL_OPENGL_API_ENTRY PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv;
LDL_OPENGL_API_ENTRY PFNGLCREATESAMPLERSPROC glCreateSamplers;
LDL_OPENGL_API_ENTRY PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines;
LDL_OPENGL_API_ENTRY PFNGLCREATEQUERIESPROC glCreateQueries;
LDL_OPENGL_API_ENTRY PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v;
LDL_OPENGL_API_ENTRY PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv;
LDL_OPENGL_API_ENTRY PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v;
LDL_OPENGL_API_ENTRY PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv;
LDL_OPENGL_API_ENTRY PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion;
LDL_OPENGL_API_ENTRY PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage;
LDL_OPENGL_API_ENTRY PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage;
LDL_OPENGL_API_ENTRY PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus;
LDL_OPENGL_API_ENTRY PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage;
LDL_OPENGL_API_ENTRY PFNGLGETNTEXIMAGEPROC glGetnTexImage;
LDL_OPENGL_API_ENTRY PFNGLGETNUNIFORMDVPROC glGetnUniformdv;
LDL_OPENGL_API_ENTRY PFNGLGETNUNIFORMFVPROC glGetnUniformfv;
LDL_OPENGL_API_ENTRY PFNGLGETNUNIFORMIVPROC glGetnUniformiv;
LDL_OPENGL_API_ENTRY PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv;
LDL_OPENGL_API_ENTRY PFNGLREADNPIXELSPROC glReadnPixels;
LDL_OPENGL_API_ENTRY PFNGLGETNMAPDVPROC glGetnMapdv;
LDL_OPENGL_API_ENTRY PFNGLGETNMAPFVPROC glGetnMapfv;
LDL_OPENGL_API_ENTRY PFNGLGETNMAPIVPROC glGetnMapiv;
LDL_OPENGL_API_ENTRY PFNGLGETNPIXELMAPFVPROC glGetnPixelMapfv;
LDL_OPENGL_API_ENTRY PFNGLGETNPIXELMAPUIVPROC glGetnPixelMapuiv;
LDL_OPENGL_API_ENTRY PFNGLGETNPIXELMAPUSVPROC glGetnPixelMapusv;
LDL_OPENGL_API_ENTRY PFNGLGETNPOLYGONSTIPPLEPROC glGetnPolygonStipple;
LDL_OPENGL_API_ENTRY PFNGLGETNCOLORTABLEPROC glGetnColorTable;
LDL_OPENGL_API_ENTRY PFNGLGETNCONVOLUTIONFILTERPROC glGetnConvolutionFilter;
LDL_OPENGL_API_ENTRY PFNGLGETNSEPARABLEFILTERPROC glGetnSeparableFilter;
LDL_OPENGL_API_ENTRY PFNGLGETNHISTOGRAMPROC glGetnHistogram;
LDL_OPENGL_API_ENTRY PFNGLGETNMINMAXPROC glGetnMinmax;
LDL_OPENGL_API_ENTRY PFNGLTEXTUREBARRIERPROC glTextureBarrier;

#ifdef __cplusplus
}
#endif

#endif 
