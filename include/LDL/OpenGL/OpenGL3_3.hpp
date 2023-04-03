#ifndef LDL_OpenGL_OpenGL3_3_hpp
#define LDL_OpenGL_OpenGL3_3_hpp

#include <LDL/OpenGL/OpenGL3_2.hpp>

typedef void (OPENGL_API_CALL PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint program, GLuint colorNumber, GLuint index, const GLchar* name);
typedef GLint(OPENGL_API_CALL PFNGLGETFRAGDATAINDEXPROC)(GLuint program, const GLchar* name);
typedef void (OPENGL_API_CALL PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint* samplers);
typedef void (OPENGL_API_CALL PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint* samplers);
typedef GLboolean(OPENGL_API_CALL PFNGLISSAMPLERPROC)(GLuint sampler);
typedef void (OPENGL_API_CALL PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
typedef void (OPENGL_API_CALL PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
typedef void (OPENGL_API_CALL PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint* param);
typedef void (OPENGL_API_CALL PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
typedef void (OPENGL_API_CALL PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat* param);
typedef void (OPENGL_API_CALL PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint* param);
typedef void (OPENGL_API_CALL PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint* param);
typedef void (OPENGL_API_CALL PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint* params);
typedef void (OPENGL_API_CALL PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint* params);
typedef void (OPENGL_API_CALL PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat* params);
typedef void (OPENGL_API_CALL PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint* params);
typedef void (OPENGL_API_CALL PFNGLQUERYCOUNTERPROC)(GLuint id, GLenum target);
typedef void (OPENGL_API_CALL PFNGLGETQUERYOBJECTI64VPROC)(GLuint id, GLenum pname, GLint64* params);
typedef void (OPENGL_API_CALL PFNGLGETQUERYOBJECTUI64VPROC)(GLuint id, GLenum pname, GLuint64* params);
typedef void (OPENGL_API_CALL PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
typedef void (OPENGL_API_CALL PFNGLVERTEXATTRIBP1UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (OPENGL_API_CALL PFNGLVERTEXATTRIBP1UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (OPENGL_API_CALL PFNGLVERTEXATTRIBP2UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (OPENGL_API_CALL PFNGLVERTEXATTRIBP2UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (OPENGL_API_CALL PFNGLVERTEXATTRIBP3UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (OPENGL_API_CALL PFNGLVERTEXATTRIBP3UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (OPENGL_API_CALL PFNGLVERTEXATTRIBP4UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (OPENGL_API_CALL PFNGLVERTEXATTRIBP4UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (OPENGL_API_CALL PFNGLVERTEXP2UIPROC)(GLenum type, GLuint value);
typedef void (OPENGL_API_CALL PFNGLVERTEXP2UIVPROC)(GLenum type, const GLuint* value);
typedef void (OPENGL_API_CALL PFNGLVERTEXP3UIPROC)(GLenum type, GLuint value);
typedef void (OPENGL_API_CALL PFNGLVERTEXP3UIVPROC)(GLenum type, const GLuint* value);
typedef void (OPENGL_API_CALL PFNGLVERTEXP4UIPROC)(GLenum type, GLuint value);
typedef void (OPENGL_API_CALL PFNGLVERTEXP4UIVPROC)(GLenum type, const GLuint* value);
typedef void (OPENGL_API_CALL PFNGLTEXCOORDP1UIPROC)(GLenum type, GLuint coords);
typedef void (OPENGL_API_CALL PFNGLTEXCOORDP1UIVPROC)(GLenum type, const GLuint* coords);
typedef void (OPENGL_API_CALL PFNGLTEXCOORDP2UIPROC)(GLenum type, GLuint coords);
typedef void (OPENGL_API_CALL PFNGLTEXCOORDP2UIVPROC)(GLenum type, const GLuint* coords);
typedef void (OPENGL_API_CALL PFNGLTEXCOORDP3UIPROC)(GLenum type, GLuint coords);
typedef void (OPENGL_API_CALL PFNGLTEXCOORDP3UIVPROC)(GLenum type, const GLuint* coords);
typedef void (OPENGL_API_CALL PFNGLTEXCOORDP4UIPROC)(GLenum type, GLuint coords);
typedef void (OPENGL_API_CALL PFNGLTEXCOORDP4UIVPROC)(GLenum type, const GLuint* coords);
typedef void (OPENGL_API_CALL PFNGLMULTITEXCOORDP1UIPROC)(GLenum texture, GLenum type, GLuint coords);
typedef void (OPENGL_API_CALL PFNGLMULTITEXCOORDP1UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
typedef void (OPENGL_API_CALL PFNGLMULTITEXCOORDP2UIPROC)(GLenum texture, GLenum type, GLuint coords);
typedef void (OPENGL_API_CALL PFNGLMULTITEXCOORDP2UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
typedef void (OPENGL_API_CALL PFNGLMULTITEXCOORDP3UIPROC)(GLenum texture, GLenum type, GLuint coords);
typedef void (OPENGL_API_CALL PFNGLMULTITEXCOORDP3UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
typedef void (OPENGL_API_CALL PFNGLMULTITEXCOORDP4UIPROC)(GLenum texture, GLenum type, GLuint coords);
typedef void (OPENGL_API_CALL PFNGLMULTITEXCOORDP4UIVPROC)(GLenum texture, GLenum type, const GLuint* coords);
typedef void (OPENGL_API_CALL PFNGLNORMALP3UIPROC)(GLenum type, GLuint coords);
typedef void (OPENGL_API_CALL PFNGLNORMALP3UIVPROC)(GLenum type, const GLuint* coords);
typedef void (OPENGL_API_CALL PFNGLCOLORP3UIPROC)(GLenum type, GLuint color);
typedef void (OPENGL_API_CALL PFNGLCOLORP3UIVPROC)(GLenum type, const GLuint* color);
typedef void (OPENGL_API_CALL PFNGLCOLORP4UIPROC)(GLenum type, GLuint color);
typedef void (OPENGL_API_CALL PFNGLCOLORP4UIVPROC)(GLenum type, const GLuint* color);
typedef void (OPENGL_API_CALL PFNGLSECONDARYCOLORP3UIPROC)(GLenum type, GLuint color);
typedef void (OPENGL_API_CALL PFNGLSECONDARYCOLORP3UIVPROC)(GLenum type, const GLuint* color);

OPENGL_API_ENTRY PFNGLBINDFRAGDATALOCATIONINDEXEDPROC* glBindFragDataLocationIndexed;
OPENGL_API_ENTRY PFNGLGETFRAGDATAINDEXPROC* glGetFragDataIndex;
OPENGL_API_ENTRY PFNGLGENSAMPLERSPROC* glGenSamplers;
OPENGL_API_ENTRY PFNGLDELETESAMPLERSPROC* glDeleteSamplers;
OPENGL_API_ENTRY PFNGLISSAMPLERPROC* glIsSampler;
OPENGL_API_ENTRY PFNGLBINDSAMPLERPROC* glBindSampler;
OPENGL_API_ENTRY PFNGLSAMPLERPARAMETERIPROC* glSamplerParameteri;
OPENGL_API_ENTRY PFNGLSAMPLERPARAMETERIVPROC* glSamplerParameteriv;
OPENGL_API_ENTRY PFNGLSAMPLERPARAMETERFPROC* glSamplerParameterf;
OPENGL_API_ENTRY PFNGLSAMPLERPARAMETERFVPROC* glSamplerParameterfv;
OPENGL_API_ENTRY PFNGLSAMPLERPARAMETERIIVPROC* glSamplerParameterIiv;
OPENGL_API_ENTRY PFNGLSAMPLERPARAMETERIUIVPROC* glSamplerParameterIuiv;
OPENGL_API_ENTRY PFNGLGETSAMPLERPARAMETERIVPROC* glGetSamplerParameteriv;
OPENGL_API_ENTRY PFNGLGETSAMPLERPARAMETERIIVPROC* glGetSamplerParameterIiv;
OPENGL_API_ENTRY PFNGLGETSAMPLERPARAMETERFVPROC* glGetSamplerParameterfv;
OPENGL_API_ENTRY PFNGLGETSAMPLERPARAMETERIUIVPROC* glGetSamplerParameterIuiv;
OPENGL_API_ENTRY PFNGLQUERYCOUNTERPROC* glQueryCounter;
OPENGL_API_ENTRY PFNGLGETQUERYOBJECTI64VPROC* glGetQueryObjecti64v;
OPENGL_API_ENTRY PFNGLGETQUERYOBJECTUI64VPROC* glGetQueryObjectui64v;
OPENGL_API_ENTRY PFNGLVERTEXATTRIBDIVISORPROC* glVertexAttribDivisor;
OPENGL_API_ENTRY PFNGLVERTEXATTRIBP1UIPROC* glVertexAttribP1ui;
OPENGL_API_ENTRY PFNGLVERTEXATTRIBP1UIVPROC* glVertexAttribP1uiv;
OPENGL_API_ENTRY PFNGLVERTEXATTRIBP2UIPROC* glVertexAttribP2ui;
OPENGL_API_ENTRY PFNGLVERTEXATTRIBP2UIVPROC* glVertexAttribP2uiv;
OPENGL_API_ENTRY PFNGLVERTEXATTRIBP3UIPROC* glVertexAttribP3ui;
OPENGL_API_ENTRY PFNGLVERTEXATTRIBP3UIVPROC* glVertexAttribP3uiv;
OPENGL_API_ENTRY PFNGLVERTEXATTRIBP4UIPROC* glVertexAttribP4ui;
OPENGL_API_ENTRY PFNGLVERTEXATTRIBP4UIVPROC* glVertexAttribP4uiv;
OPENGL_API_ENTRY PFNGLVERTEXP2UIPROC* glVertexP2ui;
OPENGL_API_ENTRY PFNGLVERTEXP2UIVPROC* glVertexP2uiv;
OPENGL_API_ENTRY PFNGLVERTEXP3UIPROC* glVertexP3ui;
OPENGL_API_ENTRY PFNGLVERTEXP3UIVPROC* glVertexP3uiv;
OPENGL_API_ENTRY PFNGLVERTEXP4UIPROC* glVertexP4ui;
OPENGL_API_ENTRY PFNGLVERTEXP4UIVPROC* glVertexP4uiv;
OPENGL_API_ENTRY PFNGLTEXCOORDP1UIPROC* glTexCoordP1ui;
OPENGL_API_ENTRY PFNGLTEXCOORDP1UIVPROC* glTexCoordP1uiv;
OPENGL_API_ENTRY PFNGLTEXCOORDP2UIPROC* glTexCoordP2ui;
OPENGL_API_ENTRY PFNGLTEXCOORDP2UIVPROC* glTexCoordP2uiv;
OPENGL_API_ENTRY PFNGLTEXCOORDP3UIPROC* glTexCoordP3ui;
OPENGL_API_ENTRY PFNGLTEXCOORDP3UIVPROC* glTexCoordP3uiv;
OPENGL_API_ENTRY PFNGLTEXCOORDP4UIPROC* glTexCoordP4ui;
OPENGL_API_ENTRY PFNGLTEXCOORDP4UIVPROC* glTexCoordP4uiv;
OPENGL_API_ENTRY PFNGLMULTITEXCOORDP1UIPROC* glMultiTexCoordP1ui;
OPENGL_API_ENTRY PFNGLMULTITEXCOORDP1UIVPROC* glMultiTexCoordP1uiv;
OPENGL_API_ENTRY PFNGLMULTITEXCOORDP2UIPROC* glMultiTexCoordP2ui;
OPENGL_API_ENTRY PFNGLMULTITEXCOORDP2UIVPROC* glMultiTexCoordP2uiv;
OPENGL_API_ENTRY PFNGLMULTITEXCOORDP3UIPROC* glMultiTexCoordP3ui;
OPENGL_API_ENTRY PFNGLMULTITEXCOORDP3UIVPROC* glMultiTexCoordP3uiv;
OPENGL_API_ENTRY PFNGLMULTITEXCOORDP4UIPROC* glMultiTexCoordP4ui;
OPENGL_API_ENTRY PFNGLMULTITEXCOORDP4UIVPROC* glMultiTexCoordP4uiv;
OPENGL_API_ENTRY PFNGLNORMALP3UIPROC* glNormalP3ui;
OPENGL_API_ENTRY PFNGLNORMALP3UIVPROC* glNormalP3uiv;
OPENGL_API_ENTRY PFNGLCOLORP3UIPROC* glColorP3ui;
OPENGL_API_ENTRY PFNGLCOLORP3UIVPROC* glColorP3uiv;
OPENGL_API_ENTRY PFNGLCOLORP4UIPROC* glColorP4ui;
OPENGL_API_ENTRY PFNGLCOLORP4UIVPROC* glColorP4uiv;
OPENGL_API_ENTRY PFNGLSECONDARYCOLORP3UIPROC* glSecondaryColorP3ui;
OPENGL_API_ENTRY PFNGLSECONDARYCOLORP3UIVPROC* glSecondaryColorP3uiv;

#endif     