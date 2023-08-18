#ifndef LDL_OpenGL_OpenGL1_0_hpp
#define LDL_OpenGL_OpenGL1_0_hpp

#include <LDL/OpenGL/OpenGLTypes.hpp>
#include <LDL/OpenGL/OpenGL_Constants.hpp>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (LDL_API_CALL PFNGLCULLFACEPROC)(GLenum mode);
typedef void (LDL_API_CALL PFNGLFRONTFACEPROC)(GLenum mode);
typedef void (LDL_API_CALL PFNGLHINTPROC)(GLenum target, GLenum mode);
typedef void (LDL_API_CALL PFNGLLINEWIDTHPROC)(GLfloat width);
typedef void (LDL_API_CALL PFNGLPOINTSIZEPROC)(GLfloat size);
typedef void (LDL_API_CALL PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
typedef void (LDL_API_CALL PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (LDL_API_CALL PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (LDL_API_CALL PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat* params);
typedef void (LDL_API_CALL PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (LDL_API_CALL PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint* params);
typedef void (LDL_API_CALL PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (LDL_API_CALL PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (LDL_API_CALL PFNGLDRAWBUFFERPROC)(GLenum buf);
typedef void (LDL_API_CALL PFNGLCLEARPROC)(GLbitfield mask);
typedef void (LDL_API_CALL PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (LDL_API_CALL PFNGLCLEARSTENCILPROC)(GLint s);
typedef void (LDL_API_CALL PFNGLCLEARDEPTHPROC)(GLdouble depth);
typedef void (LDL_API_CALL PFNGLSTENCILMASKPROC)(GLuint mask);
typedef void (LDL_API_CALL PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (LDL_API_CALL PFNGLDEPTHMASKPROC)(GLboolean flag);
typedef void (LDL_API_CALL PFNGLDISABLEPROC)(GLenum cap);
typedef void (LDL_API_CALL PFNGLENABLEPROC)(GLenum cap);
typedef void (LDL_API_CALL PFNGLFINISHPROC)(void);
typedef void (LDL_API_CALL PFNGLFLUSHPROC)(void);
typedef void (LDL_API_CALL PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
typedef void (LDL_API_CALL PFNGLLOGICOPPROC)(GLenum opcode);
typedef void (LDL_API_CALL PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
typedef void (LDL_API_CALL PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
typedef void (LDL_API_CALL PFNGLDEPTHFUNCPROC)(GLenum func);
typedef void (LDL_API_CALL PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
typedef void (LDL_API_CALL PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
typedef void (LDL_API_CALL PFNGLREADBUFFERPROC)(GLenum src);
typedef void (LDL_API_CALL PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);
typedef void (LDL_API_CALL PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean* data);
typedef void (LDL_API_CALL PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble* data);
typedef GLenum(LDL_API_CALL PFNGLGETERRORPROC)(void);
typedef void (LDL_API_CALL PFNGLGETFLOATVPROC)(GLenum pname, GLfloat* data);
typedef void (LDL_API_CALL PFNGLGETINTEGERVPROC)(GLenum pname, GLint* data);
typedef const GLubyte* (LDL_API_CALL PFNGLGETSTRINGPROC)(GLenum name);
typedef void (LDL_API_CALL PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
typedef void (LDL_API_CALL PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat* params);
typedef void (LDL_API_CALL PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (LDL_API_CALL PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat* params);
typedef void (LDL_API_CALL PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint* params);
typedef GLboolean(LDL_API_CALL PFNGLISENABLEDPROC)(GLenum cap);
typedef void (LDL_API_CALL PFNGLDEPTHRANGEPROC)(GLdouble n, GLdouble f);
typedef void (LDL_API_CALL PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (LDL_API_CALL PFNGLNEWLISTPROC)(GLuint list, GLenum mode);
typedef void (LDL_API_CALL PFNGLENDLISTPROC)(void);
typedef void (LDL_API_CALL PFNGLCALLLISTPROC)(GLuint list);
typedef void (LDL_API_CALL PFNGLCALLLISTSPROC)(GLsizei n, GLenum type, const void* lists);
typedef void (LDL_API_CALL PFNGLDELETELISTSPROC)(GLuint list, GLsizei range);
typedef GLuint(LDL_API_CALL PFNGLGENLISTSPROC)(GLsizei range);
typedef void (LDL_API_CALL PFNGLLISTBASEPROC)(GLuint base);
typedef void (LDL_API_CALL PFNGLBEGINPROC)(GLenum mode);
typedef void (LDL_API_CALL PFNGLBITMAPPROC)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte* bitmap);
typedef void (LDL_API_CALL PFNGLCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
typedef void (LDL_API_CALL PFNGLCOLOR3BVPROC)(const GLbyte* v);
typedef void (LDL_API_CALL PFNGLCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
typedef void (LDL_API_CALL PFNGLCOLOR3DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
typedef void (LDL_API_CALL PFNGLCOLOR3FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLCOLOR3IPROC)(GLint red, GLint green, GLint blue);
typedef void (LDL_API_CALL PFNGLCOLOR3IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
typedef void (LDL_API_CALL PFNGLCOLOR3SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
typedef void (LDL_API_CALL PFNGLCOLOR3UBVPROC)(const GLubyte* v);
typedef void (LDL_API_CALL PFNGLCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
typedef void (LDL_API_CALL PFNGLCOLOR3UIVPROC)(const GLuint* v);
typedef void (LDL_API_CALL PFNGLCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
typedef void (LDL_API_CALL PFNGLCOLOR3USVPROC)(const GLushort* v);
typedef void (LDL_API_CALL PFNGLCOLOR4BPROC)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
typedef void (LDL_API_CALL PFNGLCOLOR4BVPROC)(const GLbyte* v);
typedef void (LDL_API_CALL PFNGLCOLOR4DPROC)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
typedef void (LDL_API_CALL PFNGLCOLOR4DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLCOLOR4FPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (LDL_API_CALL PFNGLCOLOR4FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLCOLOR4IPROC)(GLint red, GLint green, GLint blue, GLint alpha);
typedef void (LDL_API_CALL PFNGLCOLOR4IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLCOLOR4SPROC)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
typedef void (LDL_API_CALL PFNGLCOLOR4SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLCOLOR4UBPROC)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
typedef void (LDL_API_CALL PFNGLCOLOR4UBVPROC)(const GLubyte* v);
typedef void (LDL_API_CALL PFNGLCOLOR4UIPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
typedef void (LDL_API_CALL PFNGLCOLOR4UIVPROC)(const GLuint* v);
typedef void (LDL_API_CALL PFNGLCOLOR4USPROC)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
typedef void (LDL_API_CALL PFNGLCOLOR4USVPROC)(const GLushort* v);
typedef void (LDL_API_CALL PFNGLEDGEFLAGPROC)(GLboolean flag);
typedef void (LDL_API_CALL PFNGLEDGEFLAGVPROC)(const GLboolean* flag);
typedef void (LDL_API_CALL PFNGLENDPROC)(void);
typedef void (LDL_API_CALL PFNGLINDEXDPROC)(GLdouble c);
typedef void (LDL_API_CALL PFNGLINDEXDVPROC)(const GLdouble* c);
typedef void (LDL_API_CALL PFNGLINDEXFPROC)(GLfloat c);
typedef void (LDL_API_CALL PFNGLINDEXFVPROC)(const GLfloat* c);
typedef void (LDL_API_CALL PFNGLINDEXIPROC)(GLint c);
typedef void (LDL_API_CALL PFNGLINDEXIVPROC)(const GLint* c);
typedef void (LDL_API_CALL PFNGLINDEXSPROC)(GLshort c);
typedef void (LDL_API_CALL PFNGLINDEXSVPROC)(const GLshort* c);
typedef void (LDL_API_CALL PFNGLNORMAL3BPROC)(GLbyte nx, GLbyte ny, GLbyte nz);
typedef void (LDL_API_CALL PFNGLNORMAL3BVPROC)(const GLbyte* v);
typedef void (LDL_API_CALL PFNGLNORMAL3DPROC)(GLdouble nx, GLdouble ny, GLdouble nz);
typedef void (LDL_API_CALL PFNGLNORMAL3DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLNORMAL3FPROC)(GLfloat nx, GLfloat ny, GLfloat nz);
typedef void (LDL_API_CALL PFNGLNORMAL3FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLNORMAL3IPROC)(GLint nx, GLint ny, GLint nz);
typedef void (LDL_API_CALL PFNGLNORMAL3IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLNORMAL3SPROC)(GLshort nx, GLshort ny, GLshort nz);
typedef void (LDL_API_CALL PFNGLNORMAL3SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLRASTERPOS2DPROC)(GLdouble x, GLdouble y);
typedef void (LDL_API_CALL PFNGLRASTERPOS2DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLRASTERPOS2FPROC)(GLfloat x, GLfloat y);
typedef void (LDL_API_CALL PFNGLRASTERPOS2FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLRASTERPOS2IPROC)(GLint x, GLint y);
typedef void (LDL_API_CALL PFNGLRASTERPOS2IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLRASTERPOS2SPROC)(GLshort x, GLshort y);
typedef void (LDL_API_CALL PFNGLRASTERPOS2SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLRASTERPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (LDL_API_CALL PFNGLRASTERPOS3DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLRASTERPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (LDL_API_CALL PFNGLRASTERPOS3FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLRASTERPOS3IPROC)(GLint x, GLint y, GLint z);
typedef void (LDL_API_CALL PFNGLRASTERPOS3IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLRASTERPOS3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (LDL_API_CALL PFNGLRASTERPOS3SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLRASTERPOS4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (LDL_API_CALL PFNGLRASTERPOS4DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLRASTERPOS4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (LDL_API_CALL PFNGLRASTERPOS4FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLRASTERPOS4IPROC)(GLint x, GLint y, GLint z, GLint w);
typedef void (LDL_API_CALL PFNGLRASTERPOS4IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLRASTERPOS4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (LDL_API_CALL PFNGLRASTERPOS4SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLRECTDPROC)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
typedef void (LDL_API_CALL PFNGLRECTDVPROC)(const GLdouble* v1, const GLdouble* v2);
typedef void (LDL_API_CALL PFNGLRECTFPROC)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
typedef void (LDL_API_CALL PFNGLRECTFVPROC)(const GLfloat* v1, const GLfloat* v2);
typedef void (LDL_API_CALL PFNGLRECTIPROC)(GLint x1, GLint y1, GLint x2, GLint y2);
typedef void (LDL_API_CALL PFNGLRECTIVPROC)(const GLint* v1, const GLint* v2);
typedef void (LDL_API_CALL PFNGLRECTSPROC)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
typedef void (LDL_API_CALL PFNGLRECTSVPROC)(const GLshort* v1, const GLshort* v2);
typedef void (LDL_API_CALL PFNGLTEXCOORD1DPROC)(GLdouble s);
typedef void (LDL_API_CALL PFNGLTEXCOORD1DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD1FPROC)(GLfloat s);
typedef void (LDL_API_CALL PFNGLTEXCOORD1FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD1IPROC)(GLint s);
typedef void (LDL_API_CALL PFNGLTEXCOORD1IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD1SPROC)(GLshort s);
typedef void (LDL_API_CALL PFNGLTEXCOORD1SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD2DPROC)(GLdouble s, GLdouble t);
typedef void (LDL_API_CALL PFNGLTEXCOORD2DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD2FPROC)(GLfloat s, GLfloat t);
typedef void (LDL_API_CALL PFNGLTEXCOORD2FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD2IPROC)(GLint s, GLint t);
typedef void (LDL_API_CALL PFNGLTEXCOORD2IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD2SPROC)(GLshort s, GLshort t);
typedef void (LDL_API_CALL PFNGLTEXCOORD2SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD3DPROC)(GLdouble s, GLdouble t, GLdouble r);
typedef void (LDL_API_CALL PFNGLTEXCOORD3DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD3FPROC)(GLfloat s, GLfloat t, GLfloat r);
typedef void (LDL_API_CALL PFNGLTEXCOORD3FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD3IPROC)(GLint s, GLint t, GLint r);
typedef void (LDL_API_CALL PFNGLTEXCOORD3IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD3SPROC)(GLshort s, GLshort t, GLshort r);
typedef void (LDL_API_CALL PFNGLTEXCOORD3SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD4DPROC)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (LDL_API_CALL PFNGLTEXCOORD4DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD4FPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (LDL_API_CALL PFNGLTEXCOORD4FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD4IPROC)(GLint s, GLint t, GLint r, GLint q);
typedef void (LDL_API_CALL PFNGLTEXCOORD4IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLTEXCOORD4SPROC)(GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (LDL_API_CALL PFNGLTEXCOORD4SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLVERTEX2DPROC)(GLdouble x, GLdouble y);
typedef void (LDL_API_CALL PFNGLVERTEX2DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLVERTEX2FPROC)(GLfloat x, GLfloat y);
typedef void (LDL_API_CALL PFNGLVERTEX2FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLVERTEX2IPROC)(GLint x, GLint y);
typedef void (LDL_API_CALL PFNGLVERTEX2IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLVERTEX2SPROC)(GLshort x, GLshort y);
typedef void (LDL_API_CALL PFNGLVERTEX2SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLVERTEX3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (LDL_API_CALL PFNGLVERTEX3DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLVERTEX3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (LDL_API_CALL PFNGLVERTEX3FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLVERTEX3IPROC)(GLint x, GLint y, GLint z);
typedef void (LDL_API_CALL PFNGLVERTEX3IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLVERTEX3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (LDL_API_CALL PFNGLVERTEX3SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLVERTEX4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (LDL_API_CALL PFNGLVERTEX4DVPROC)(const GLdouble* v);
typedef void (LDL_API_CALL PFNGLVERTEX4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (LDL_API_CALL PFNGLVERTEX4FVPROC)(const GLfloat* v);
typedef void (LDL_API_CALL PFNGLVERTEX4IPROC)(GLint x, GLint y, GLint z, GLint w);
typedef void (LDL_API_CALL PFNGLVERTEX4IVPROC)(const GLint* v);
typedef void (LDL_API_CALL PFNGLVERTEX4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (LDL_API_CALL PFNGLVERTEX4SVPROC)(const GLshort* v);
typedef void (LDL_API_CALL PFNGLCLIPPLANEPROC)(GLenum plane, const GLdouble* equation);
typedef void (LDL_API_CALL PFNGLCOLORMATERIALPROC)(GLenum face, GLenum mode);
typedef void (LDL_API_CALL PFNGLFOGFPROC)(GLenum pname, GLfloat param);
typedef void (LDL_API_CALL PFNGLFOGFVPROC)(GLenum pname, const GLfloat* params);
typedef void (LDL_API_CALL PFNGLFOGIPROC)(GLenum pname, GLint param);
typedef void (LDL_API_CALL PFNGLFOGIVPROC)(GLenum pname, const GLint* params);
typedef void (LDL_API_CALL PFNGLLIGHTFPROC)(GLenum light, GLenum pname, GLfloat param);
typedef void (LDL_API_CALL PFNGLLIGHTFVPROC)(GLenum light, GLenum pname, const GLfloat* params);
typedef void (LDL_API_CALL PFNGLLIGHTIPROC)(GLenum light, GLenum pname, GLint param);
typedef void (LDL_API_CALL PFNGLLIGHTIVPROC)(GLenum light, GLenum pname, const GLint* params);
typedef void (LDL_API_CALL PFNGLLIGHTMODELFPROC)(GLenum pname, GLfloat param);
typedef void (LDL_API_CALL PFNGLLIGHTMODELFVPROC)(GLenum pname, const GLfloat* params);
typedef void (LDL_API_CALL PFNGLLIGHTMODELIPROC)(GLenum pname, GLint param);
typedef void (LDL_API_CALL PFNGLLIGHTMODELIVPROC)(GLenum pname, const GLint* params);
typedef void (LDL_API_CALL PFNGLLINESTIPPLEPROC)(GLint factor, GLushort pattern);
typedef void (LDL_API_CALL PFNGLMATERIALFPROC)(GLenum face, GLenum pname, GLfloat param);
typedef void (LDL_API_CALL PFNGLMATERIALFVPROC)(GLenum face, GLenum pname, const GLfloat* params);
typedef void (LDL_API_CALL PFNGLMATERIALIPROC)(GLenum face, GLenum pname, GLint param);
typedef void (LDL_API_CALL PFNGLMATERIALIVPROC)(GLenum face, GLenum pname, const GLint* params);
typedef void (LDL_API_CALL PFNGLPOLYGONSTIPPLEPROC)(const GLubyte* mask);
typedef void (LDL_API_CALL PFNGLSHADEMODELPROC)(GLenum mode);
typedef void (LDL_API_CALL PFNGLTEXENVFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (LDL_API_CALL PFNGLTEXENVFVPROC)(GLenum target, GLenum pname, const GLfloat* params);
typedef void (LDL_API_CALL PFNGLTEXENVIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (LDL_API_CALL PFNGLTEXENVIVPROC)(GLenum target, GLenum pname, const GLint* params);
typedef void (LDL_API_CALL PFNGLTEXGENDPROC)(GLenum coord, GLenum pname, GLdouble param);
typedef void (LDL_API_CALL PFNGLTEXGENDVPROC)(GLenum coord, GLenum pname, const GLdouble* params);
typedef void (LDL_API_CALL PFNGLTEXGENFPROC)(GLenum coord, GLenum pname, GLfloat param);
typedef void (LDL_API_CALL PFNGLTEXGENFVPROC)(GLenum coord, GLenum pname, const GLfloat* params);
typedef void (LDL_API_CALL PFNGLTEXGENIPROC)(GLenum coord, GLenum pname, GLint param);
typedef void (LDL_API_CALL PFNGLTEXGENIVPROC)(GLenum coord, GLenum pname, const GLint* params);
typedef void (LDL_API_CALL PFNGLFEEDBACKBUFFERPROC)(GLsizei size, GLenum type, GLfloat* buffer);
typedef void (LDL_API_CALL PFNGLSELECTBUFFERPROC)(GLsizei size, GLuint* buffer);
typedef GLint(LDL_API_CALL PFNGLRENDERMODEPROC)(GLenum mode);
typedef void (LDL_API_CALL PFNGLINITNAMESPROC)(void);
typedef void (LDL_API_CALL PFNGLLOADNAMEPROC)(GLuint name);
typedef void (LDL_API_CALL PFNGLPASSTHROUGHPROC)(GLfloat token);
typedef void (LDL_API_CALL PFNGLPOPNAMEPROC)(void);
typedef void (LDL_API_CALL PFNGLPUSHNAMEPROC)(GLuint name);
typedef void (LDL_API_CALL PFNGLCLEARACCUMPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (LDL_API_CALL PFNGLCLEARINDEXPROC)(GLfloat c);
typedef void (LDL_API_CALL PFNGLINDEXMASKPROC)(GLuint mask);
typedef void (LDL_API_CALL PFNGLACCUMPROC)(GLenum op, GLfloat value);
typedef void (LDL_API_CALL PFNGLPOPATTRIBPROC)(void);
typedef void (LDL_API_CALL PFNGLPUSHATTRIBPROC)(GLbitfield mask);
typedef void (LDL_API_CALL PFNGLMAP1DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble* points);
typedef void (LDL_API_CALL PFNGLMAP1FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat* points);
typedef void (LDL_API_CALL PFNGLMAP2DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble* points);
typedef void (LDL_API_CALL PFNGLMAP2FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat* points);
typedef void (LDL_API_CALL PFNGLMAPGRID1DPROC)(GLint un, GLdouble u1, GLdouble u2);
typedef void (LDL_API_CALL PFNGLMAPGRID1FPROC)(GLint un, GLfloat u1, GLfloat u2);
typedef void (LDL_API_CALL PFNGLMAPGRID2DPROC)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
typedef void (LDL_API_CALL PFNGLMAPGRID2FPROC)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
typedef void (LDL_API_CALL PFNGLEVALCOORD1DPROC)(GLdouble u);
typedef void (LDL_API_CALL PFNGLEVALCOORD1DVPROC)(const GLdouble* u);
typedef void (LDL_API_CALL PFNGLEVALCOORD1FPROC)(GLfloat u);
typedef void (LDL_API_CALL PFNGLEVALCOORD1FVPROC)(const GLfloat* u);
typedef void (LDL_API_CALL PFNGLEVALCOORD2DPROC)(GLdouble u, GLdouble v);
typedef void (LDL_API_CALL PFNGLEVALCOORD2DVPROC)(const GLdouble* u);
typedef void (LDL_API_CALL PFNGLEVALCOORD2FPROC)(GLfloat u, GLfloat v);
typedef void (LDL_API_CALL PFNGLEVALCOORD2FVPROC)(const GLfloat* u);
typedef void (LDL_API_CALL PFNGLEVALMESH1PROC)(GLenum mode, GLint i1, GLint i2);
typedef void (LDL_API_CALL PFNGLEVALPOINT1PROC)(GLint i);
typedef void (LDL_API_CALL PFNGLEVALMESH2PROC)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
typedef void (LDL_API_CALL PFNGLEVALPOINT2PROC)(GLint i, GLint j);
typedef void (LDL_API_CALL PFNGLALPHAFUNCPROC)(GLenum func, GLfloat ref);
typedef void (LDL_API_CALL PFNGLPIXELZOOMPROC)(GLfloat xfactor, GLfloat yfactor);
typedef void (LDL_API_CALL PFNGLPIXELTRANSFERFPROC)(GLenum pname, GLfloat param);
typedef void (LDL_API_CALL PFNGLPIXELTRANSFERIPROC)(GLenum pname, GLint param);
typedef void (LDL_API_CALL PFNGLPIXELMAPFVPROC)(GLenum map, GLsizei mapsize, const GLfloat* values);
typedef void (LDL_API_CALL PFNGLPIXELMAPUIVPROC)(GLenum map, GLsizei mapsize, const GLuint* values);
typedef void (LDL_API_CALL PFNGLPIXELMAPUSVPROC)(GLenum map, GLsizei mapsize, const GLushort* values);
typedef void (LDL_API_CALL PFNGLCOPYPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
typedef void (LDL_API_CALL PFNGLDRAWPIXELSPROC)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
typedef void (LDL_API_CALL PFNGLGETCLIPPLANEPROC)(GLenum plane, GLdouble* equation);
typedef void (LDL_API_CALL PFNGLGETLIGHTFVPROC)(GLenum light, GLenum pname, GLfloat* params);
typedef void (LDL_API_CALL PFNGLGETLIGHTIVPROC)(GLenum light, GLenum pname, GLint* params);
typedef void (LDL_API_CALL PFNGLGETMAPDVPROC)(GLenum target, GLenum query, GLdouble* v);
typedef void (LDL_API_CALL PFNGLGETMAPFVPROC)(GLenum target, GLenum query, GLfloat* v);
typedef void (LDL_API_CALL PFNGLGETMAPIVPROC)(GLenum target, GLenum query, GLint* v);
typedef void (LDL_API_CALL PFNGLGETMATERIALFVPROC)(GLenum face, GLenum pname, GLfloat* params);
typedef void (LDL_API_CALL PFNGLGETMATERIALIVPROC)(GLenum face, GLenum pname, GLint* params);
typedef void (LDL_API_CALL PFNGLGETPIXELMAPFVPROC)(GLenum map, GLfloat* values);
typedef void (LDL_API_CALL PFNGLGETPIXELMAPUIVPROC)(GLenum map, GLuint* values);
typedef void (LDL_API_CALL PFNGLGETPIXELMAPUSVPROC)(GLenum map, GLushort* values);
typedef void (LDL_API_CALL PFNGLGETPOLYGONSTIPPLEPROC)(GLubyte* mask);
typedef void (LDL_API_CALL PFNGLGETTEXENVFVPROC)(GLenum target, GLenum pname, GLfloat* params);
typedef void (LDL_API_CALL PFNGLGETTEXENVIVPROC)(GLenum target, GLenum pname, GLint* params);
typedef void (LDL_API_CALL PFNGLGETTEXGENDVPROC)(GLenum coord, GLenum pname, GLdouble* params);
typedef void (LDL_API_CALL PFNGLGETTEXGENFVPROC)(GLenum coord, GLenum pname, GLfloat* params);
typedef void (LDL_API_CALL PFNGLGETTEXGENIVPROC)(GLenum coord, GLenum pname, GLint* params);
typedef GLboolean(LDL_API_CALL PFNGLISLISTPROC)(GLuint list);
typedef void (LDL_API_CALL PFNGLFRUSTUMPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (LDL_API_CALL PFNGLLOADIDENTITYPROC)(void);
typedef void (LDL_API_CALL PFNGLLOADMATRIXFPROC)(const GLfloat* m);
typedef void (LDL_API_CALL PFNGLLOADMATRIXDPROC)(const GLdouble* m);
typedef void (LDL_API_CALL PFNGLMATRIXMODEPROC)(GLenum mode);
typedef void (LDL_API_CALL PFNGLMULTMATRIXFPROC)(const GLfloat* m);
typedef void (LDL_API_CALL PFNGLMULTMATRIXDPROC)(const GLdouble* m);
typedef void (LDL_API_CALL PFNGLORTHOPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (LDL_API_CALL PFNGLPOPMATRIXPROC)(void);
typedef void (LDL_API_CALL PFNGLPUSHMATRIXPROC)(void);
typedef void (LDL_API_CALL PFNGLROTATEDPROC)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef void (LDL_API_CALL PFNGLROTATEFPROC)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void (LDL_API_CALL PFNGLSCALEDPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (LDL_API_CALL PFNGLSCALEFPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (LDL_API_CALL PFNGLTRANSLATEDPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (LDL_API_CALL PFNGLTRANSLATEFPROC)(GLfloat x, GLfloat y, GLfloat z);

LDL_API_ENTRY PFNGLCULLFACEPROC glCullFace;
LDL_API_ENTRY PFNGLFRONTFACEPROC glFrontFace;
LDL_API_ENTRY PFNGLHINTPROC glHint;
LDL_API_ENTRY PFNGLLINEWIDTHPROC glLineWidth;
LDL_API_ENTRY PFNGLPOINTSIZEPROC glPointSize;
LDL_API_ENTRY PFNGLPOLYGONMODEPROC glPolygonMode;
LDL_API_ENTRY PFNGLSCISSORPROC glScissor;
LDL_API_ENTRY PFNGLTEXPARAMETERFPROC glTexParameterf;
LDL_API_ENTRY PFNGLTEXPARAMETERFVPROC glTexParameterfv;
LDL_API_ENTRY PFNGLTEXPARAMETERIPROC glTexParameteri;
LDL_API_ENTRY PFNGLTEXPARAMETERIVPROC glTexParameteriv;
LDL_API_ENTRY PFNGLTEXIMAGE1DPROC glTexImage1D;
LDL_API_ENTRY PFNGLTEXIMAGE2DPROC glTexImage2D;
LDL_API_ENTRY PFNGLDRAWBUFFERPROC glDrawBuffer;
LDL_API_ENTRY PFNGLCLEARPROC glClear;
LDL_API_ENTRY PFNGLCLEARCOLORPROC glClearColor;
LDL_API_ENTRY PFNGLCLEARSTENCILPROC glClearStencil;
LDL_API_ENTRY PFNGLCLEARDEPTHPROC glClearDepth;
LDL_API_ENTRY PFNGLSTENCILMASKPROC glStencilMask;
LDL_API_ENTRY PFNGLCOLORMASKPROC glColorMask;
LDL_API_ENTRY PFNGLDEPTHMASKPROC glDepthMask;
LDL_API_ENTRY PFNGLDISABLEPROC glDisable;
LDL_API_ENTRY PFNGLENABLEPROC glEnable;
LDL_API_ENTRY PFNGLFINISHPROC glFinish;
LDL_API_ENTRY PFNGLFLUSHPROC glFlush;
LDL_API_ENTRY PFNGLBLENDFUNCPROC glBlendFunc;
LDL_API_ENTRY PFNGLLOGICOPPROC glLogicOp;
LDL_API_ENTRY PFNGLSTENCILFUNCPROC glStencilFunc;
LDL_API_ENTRY PFNGLSTENCILOPPROC glStencilOp;
LDL_API_ENTRY PFNGLDEPTHFUNCPROC glDepthFunc;
LDL_API_ENTRY PFNGLPIXELSTOREFPROC glPixelStoref;
LDL_API_ENTRY PFNGLPIXELSTOREIPROC glPixelStorei;
LDL_API_ENTRY PFNGLREADBUFFERPROC glReadBuffer;
LDL_API_ENTRY PFNGLREADPIXELSPROC glReadPixels;
LDL_API_ENTRY PFNGLGETBOOLEANVPROC glGetBooleanv;
LDL_API_ENTRY PFNGLGETDOUBLEVPROC glGetDoublev;
LDL_API_ENTRY PFNGLGETERRORPROC glGetError;
LDL_API_ENTRY PFNGLGETFLOATVPROC glGetFloatv;
LDL_API_ENTRY PFNGLGETINTEGERVPROC glGetIntegerv;
LDL_API_ENTRY PFNGLGETSTRINGPROC glGetString;
LDL_API_ENTRY PFNGLGETTEXIMAGEPROC glGetTexImage;
LDL_API_ENTRY PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv;
LDL_API_ENTRY PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv;
LDL_API_ENTRY PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv;
LDL_API_ENTRY PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv;
LDL_API_ENTRY PFNGLISENABLEDPROC glIsEnabled;
LDL_API_ENTRY PFNGLDEPTHRANGEPROC glDepthRange;
LDL_API_ENTRY PFNGLVIEWPORTPROC glViewport;
LDL_API_ENTRY PFNGLNEWLISTPROC glNewList;
LDL_API_ENTRY PFNGLENDLISTPROC glEndList;
LDL_API_ENTRY PFNGLCALLLISTPROC glCallList;
LDL_API_ENTRY PFNGLCALLLISTSPROC glCallLists;
LDL_API_ENTRY PFNGLDELETELISTSPROC glDeleteLists;
LDL_API_ENTRY PFNGLGENLISTSPROC glGenLists;
LDL_API_ENTRY PFNGLLISTBASEPROC glListBase;
LDL_API_ENTRY PFNGLBEGINPROC glBegin;
LDL_API_ENTRY PFNGLBITMAPPROC glBitmap;
LDL_API_ENTRY PFNGLCOLOR3BPROC glColor3b;
LDL_API_ENTRY PFNGLCOLOR3BVPROC glColor3bv;
LDL_API_ENTRY PFNGLCOLOR3DPROC glColor3d;
LDL_API_ENTRY PFNGLCOLOR3DVPROC glColor3dv;
LDL_API_ENTRY PFNGLCOLOR3FPROC glColor3f;
LDL_API_ENTRY PFNGLCOLOR3FVPROC glColor3fv;
LDL_API_ENTRY PFNGLCOLOR3IPROC glColor3i;
LDL_API_ENTRY PFNGLCOLOR3IVPROC glColor3iv;
LDL_API_ENTRY PFNGLCOLOR3SPROC glColor3s;
LDL_API_ENTRY PFNGLCOLOR3SVPROC glColor3sv;
LDL_API_ENTRY PFNGLCOLOR3UBPROC glColor3ub;
LDL_API_ENTRY PFNGLCOLOR3UBVPROC glColor3ubv;
LDL_API_ENTRY PFNGLCOLOR3UIPROC glColor3ui;
LDL_API_ENTRY PFNGLCOLOR3UIVPROC glColor3uiv;
LDL_API_ENTRY PFNGLCOLOR3USPROC glColor3us;
LDL_API_ENTRY PFNGLCOLOR3USVPROC glColor3usv;
LDL_API_ENTRY PFNGLCOLOR4BPROC glColor4b;
LDL_API_ENTRY PFNGLCOLOR4BVPROC glColor4bv;
LDL_API_ENTRY PFNGLCOLOR4DPROC glColor4d;
LDL_API_ENTRY PFNGLCOLOR4DVPROC glColor4dv;
LDL_API_ENTRY PFNGLCOLOR4FPROC glColor4f;
LDL_API_ENTRY PFNGLCOLOR4FVPROC glColor4fv;
LDL_API_ENTRY PFNGLCOLOR4IPROC glColor4i;
LDL_API_ENTRY PFNGLCOLOR4IVPROC glColor4iv;
LDL_API_ENTRY PFNGLCOLOR4SPROC glColor4s;
LDL_API_ENTRY PFNGLCOLOR4SVPROC glColor4sv;
LDL_API_ENTRY PFNGLCOLOR4UBPROC glColor4ub;
LDL_API_ENTRY PFNGLCOLOR4UBVPROC glColor4ubv;
LDL_API_ENTRY PFNGLCOLOR4UIPROC glColor4ui;
LDL_API_ENTRY PFNGLCOLOR4UIVPROC glColor4uiv;
LDL_API_ENTRY PFNGLCOLOR4USPROC glColor4us;
LDL_API_ENTRY PFNGLCOLOR4USVPROC glColor4usv;
LDL_API_ENTRY PFNGLEDGEFLAGPROC glEdgeFlag;
LDL_API_ENTRY PFNGLEDGEFLAGVPROC glEdgeFlagv;
LDL_API_ENTRY PFNGLENDPROC glEnd;
LDL_API_ENTRY PFNGLINDEXDPROC glIndexd;
LDL_API_ENTRY PFNGLINDEXDVPROC glIndexdv;
LDL_API_ENTRY PFNGLINDEXFPROC glIndexf;
LDL_API_ENTRY PFNGLINDEXFVPROC glIndexfv;
LDL_API_ENTRY PFNGLINDEXIPROC glIndexi;
LDL_API_ENTRY PFNGLINDEXIVPROC glIndexiv;
LDL_API_ENTRY PFNGLINDEXSPROC glIndexs;
LDL_API_ENTRY PFNGLINDEXSVPROC glIndexsv;
LDL_API_ENTRY PFNGLNORMAL3BPROC glNormal3b;
LDL_API_ENTRY PFNGLNORMAL3BVPROC glNormal3bv;
LDL_API_ENTRY PFNGLNORMAL3DPROC glNormal3d;
LDL_API_ENTRY PFNGLNORMAL3DVPROC glNormal3dv;
LDL_API_ENTRY PFNGLNORMAL3FPROC glNormal3f;
LDL_API_ENTRY PFNGLNORMAL3FVPROC glNormal3fv;
LDL_API_ENTRY PFNGLNORMAL3IPROC glNormal3i;
LDL_API_ENTRY PFNGLNORMAL3IVPROC glNormal3iv;
LDL_API_ENTRY PFNGLNORMAL3SPROC glNormal3s;
LDL_API_ENTRY PFNGLNORMAL3SVPROC glNormal3sv;
LDL_API_ENTRY PFNGLRASTERPOS2DPROC glRasterPos2d;
LDL_API_ENTRY PFNGLRASTERPOS2DVPROC glRasterPos2dv;
LDL_API_ENTRY PFNGLRASTERPOS2FPROC glRasterPos2f;
LDL_API_ENTRY PFNGLRASTERPOS2FVPROC glRasterPos2fv;
LDL_API_ENTRY PFNGLRASTERPOS2IPROC glRasterPos2i;
LDL_API_ENTRY PFNGLRASTERPOS2IVPROC glRasterPos2iv;
LDL_API_ENTRY PFNGLRASTERPOS2SPROC glRasterPos2s;
LDL_API_ENTRY PFNGLRASTERPOS2SVPROC glRasterPos2sv;
LDL_API_ENTRY PFNGLRASTERPOS3DPROC glRasterPos3d;
LDL_API_ENTRY PFNGLRASTERPOS3DVPROC glRasterPos3dv;
LDL_API_ENTRY PFNGLRASTERPOS3FPROC glRasterPos3f;
LDL_API_ENTRY PFNGLRASTERPOS3FVPROC glRasterPos3fv;
LDL_API_ENTRY PFNGLRASTERPOS3IPROC glRasterPos3i;
LDL_API_ENTRY PFNGLRASTERPOS3IVPROC glRasterPos3iv;
LDL_API_ENTRY PFNGLRASTERPOS3SPROC glRasterPos3s;
LDL_API_ENTRY PFNGLRASTERPOS3SVPROC glRasterPos3sv;
LDL_API_ENTRY PFNGLRASTERPOS4DPROC glRasterPos4d;
LDL_API_ENTRY PFNGLRASTERPOS4DVPROC glRasterPos4dv;
LDL_API_ENTRY PFNGLRASTERPOS4FPROC glRasterPos4f;
LDL_API_ENTRY PFNGLRASTERPOS4FVPROC glRasterPos4fv;
LDL_API_ENTRY PFNGLRASTERPOS4IPROC glRasterPos4i;
LDL_API_ENTRY PFNGLRASTERPOS4IVPROC glRasterPos4iv;
LDL_API_ENTRY PFNGLRASTERPOS4SPROC glRasterPos4s;
LDL_API_ENTRY PFNGLRASTERPOS4SVPROC glRasterPos4sv;
LDL_API_ENTRY PFNGLRECTDPROC glRectd;
LDL_API_ENTRY PFNGLRECTDVPROC glRectdv;
LDL_API_ENTRY PFNGLRECTFPROC glRectf;
LDL_API_ENTRY PFNGLRECTFVPROC glRectfv;
LDL_API_ENTRY PFNGLRECTIPROC glRecti;
LDL_API_ENTRY PFNGLRECTIVPROC glRectiv;
LDL_API_ENTRY PFNGLRECTSPROC glRects;
LDL_API_ENTRY PFNGLRECTSVPROC glRectsv;
LDL_API_ENTRY PFNGLTEXCOORD1DPROC glTexCoord1d;
LDL_API_ENTRY PFNGLTEXCOORD1DVPROC glTexCoord1dv;
LDL_API_ENTRY PFNGLTEXCOORD1FPROC glTexCoord1f;
LDL_API_ENTRY PFNGLTEXCOORD1FVPROC glTexCoord1fv;
LDL_API_ENTRY PFNGLTEXCOORD1IPROC glTexCoord1i;
LDL_API_ENTRY PFNGLTEXCOORD1IVPROC glTexCoord1iv;
LDL_API_ENTRY PFNGLTEXCOORD1SPROC glTexCoord1s;
LDL_API_ENTRY PFNGLTEXCOORD1SVPROC glTexCoord1sv;
LDL_API_ENTRY PFNGLTEXCOORD2DPROC glTexCoord2d;
LDL_API_ENTRY PFNGLTEXCOORD2DVPROC glTexCoord2dv;
LDL_API_ENTRY PFNGLTEXCOORD2FPROC glTexCoord2f;
LDL_API_ENTRY PFNGLTEXCOORD2FVPROC glTexCoord2fv;
LDL_API_ENTRY PFNGLTEXCOORD2IPROC glTexCoord2i;
LDL_API_ENTRY PFNGLTEXCOORD2IVPROC glTexCoord2iv;
LDL_API_ENTRY PFNGLTEXCOORD2SPROC glTexCoord2s;
LDL_API_ENTRY PFNGLTEXCOORD2SVPROC glTexCoord2sv;
LDL_API_ENTRY PFNGLTEXCOORD3DPROC glTexCoord3d;
LDL_API_ENTRY PFNGLTEXCOORD3DVPROC glTexCoord3dv;
LDL_API_ENTRY PFNGLTEXCOORD3FPROC glTexCoord3f;
LDL_API_ENTRY PFNGLTEXCOORD3FVPROC glTexCoord3fv;
LDL_API_ENTRY PFNGLTEXCOORD3IPROC glTexCoord3i;
LDL_API_ENTRY PFNGLTEXCOORD3IVPROC glTexCoord3iv;
LDL_API_ENTRY PFNGLTEXCOORD3SPROC glTexCoord3s;
LDL_API_ENTRY PFNGLTEXCOORD3SVPROC glTexCoord3sv;
LDL_API_ENTRY PFNGLTEXCOORD4DPROC glTexCoord4d;
LDL_API_ENTRY PFNGLTEXCOORD4DVPROC glTexCoord4dv;
LDL_API_ENTRY PFNGLTEXCOORD4FPROC glTexCoord4f;
LDL_API_ENTRY PFNGLTEXCOORD4FVPROC glTexCoord4fv;
LDL_API_ENTRY PFNGLTEXCOORD4IPROC glTexCoord4i;
LDL_API_ENTRY PFNGLTEXCOORD4IVPROC glTexCoord4iv;
LDL_API_ENTRY PFNGLTEXCOORD4SPROC glTexCoord4s;
LDL_API_ENTRY PFNGLTEXCOORD4SVPROC glTexCoord4sv;
LDL_API_ENTRY PFNGLVERTEX2DPROC glVertex2d;
LDL_API_ENTRY PFNGLVERTEX2DVPROC glVertex2dv;
LDL_API_ENTRY PFNGLVERTEX2FPROC glVertex2f;
LDL_API_ENTRY PFNGLVERTEX2FVPROC glVertex2fv;
LDL_API_ENTRY PFNGLVERTEX2IPROC glVertex2i;
LDL_API_ENTRY PFNGLVERTEX2IVPROC glVertex2iv;
LDL_API_ENTRY PFNGLVERTEX2SPROC glVertex2s;
LDL_API_ENTRY PFNGLVERTEX2SVPROC glVertex2sv;
LDL_API_ENTRY PFNGLVERTEX3DPROC glVertex3d;
LDL_API_ENTRY PFNGLVERTEX3DVPROC glVertex3dv;
LDL_API_ENTRY PFNGLVERTEX3FPROC glVertex3f;
LDL_API_ENTRY PFNGLVERTEX3FVPROC glVertex3fv;
LDL_API_ENTRY PFNGLVERTEX3IPROC glVertex3i;
LDL_API_ENTRY PFNGLVERTEX3IVPROC glVertex3iv;
LDL_API_ENTRY PFNGLVERTEX3SPROC glVertex3s;
LDL_API_ENTRY PFNGLVERTEX3SVPROC glVertex3sv;
LDL_API_ENTRY PFNGLVERTEX4DPROC glVertex4d;
LDL_API_ENTRY PFNGLVERTEX4DVPROC glVertex4dv;
LDL_API_ENTRY PFNGLVERTEX4FPROC glVertex4f;
LDL_API_ENTRY PFNGLVERTEX4FVPROC glVertex4fv;
LDL_API_ENTRY PFNGLVERTEX4IPROC glVertex4i;
LDL_API_ENTRY PFNGLVERTEX4IVPROC glVertex4iv;
LDL_API_ENTRY PFNGLVERTEX4SPROC glVertex4s;
LDL_API_ENTRY PFNGLVERTEX4SVPROC glVertex4sv;
LDL_API_ENTRY PFNGLCLIPPLANEPROC glClipPlane;
LDL_API_ENTRY PFNGLCOLORMATERIALPROC glColorMaterial;
LDL_API_ENTRY PFNGLFOGFPROC glFogf;
LDL_API_ENTRY PFNGLFOGFVPROC glFogfv;
LDL_API_ENTRY PFNGLFOGIPROC glFogi;
LDL_API_ENTRY PFNGLFOGIVPROC glFogiv;
LDL_API_ENTRY PFNGLLIGHTFPROC glLightf;
LDL_API_ENTRY PFNGLLIGHTFVPROC glLightfv;
LDL_API_ENTRY PFNGLLIGHTIPROC glLighti;
LDL_API_ENTRY PFNGLLIGHTIVPROC glLightiv;
LDL_API_ENTRY PFNGLLIGHTMODELFPROC glLightModelf;
LDL_API_ENTRY PFNGLLIGHTMODELFVPROC glLightModelfv;
LDL_API_ENTRY PFNGLLIGHTMODELIPROC glLightModeli;
LDL_API_ENTRY PFNGLLIGHTMODELIVPROC glLightModeliv;
LDL_API_ENTRY PFNGLLINESTIPPLEPROC glLineStipple;
LDL_API_ENTRY PFNGLMATERIALFPROC glMaterialf;
LDL_API_ENTRY PFNGLMATERIALFVPROC glMaterialfv;
LDL_API_ENTRY PFNGLMATERIALIPROC glMateriali;
LDL_API_ENTRY PFNGLMATERIALIVPROC glMaterialiv;
LDL_API_ENTRY PFNGLPOLYGONSTIPPLEPROC glPolygonStipple;
LDL_API_ENTRY PFNGLSHADEMODELPROC glShadeModel;
LDL_API_ENTRY PFNGLTEXENVFPROC glTexEnvf;
LDL_API_ENTRY PFNGLTEXENVFVPROC glTexEnvfv;
LDL_API_ENTRY PFNGLTEXENVIPROC glTexEnvi;
LDL_API_ENTRY PFNGLTEXENVIVPROC glTexEnviv;
LDL_API_ENTRY PFNGLTEXGENDPROC glTexGend;
LDL_API_ENTRY PFNGLTEXGENDVPROC glTexGendv;
LDL_API_ENTRY PFNGLTEXGENFPROC glTexGenf;
LDL_API_ENTRY PFNGLTEXGENFVPROC glTexGenfv;
LDL_API_ENTRY PFNGLTEXGENIPROC glTexGeni;
LDL_API_ENTRY PFNGLTEXGENIVPROC glTexGeniv;
LDL_API_ENTRY PFNGLFEEDBACKBUFFERPROC glFeedbackBuffer;
LDL_API_ENTRY PFNGLSELECTBUFFERPROC glSelectBuffer;
LDL_API_ENTRY PFNGLRENDERMODEPROC glRenderMode;
LDL_API_ENTRY PFNGLINITNAMESPROC glInitNames;
LDL_API_ENTRY PFNGLLOADNAMEPROC glLoadName;
LDL_API_ENTRY PFNGLPASSTHROUGHPROC glPassThrough;
LDL_API_ENTRY PFNGLPOPNAMEPROC glPopName;
LDL_API_ENTRY PFNGLPUSHNAMEPROC glPushName;
LDL_API_ENTRY PFNGLCLEARACCUMPROC glClearAccum;
LDL_API_ENTRY PFNGLCLEARINDEXPROC glClearIndex;
LDL_API_ENTRY PFNGLINDEXMASKPROC glIndexMask;
LDL_API_ENTRY PFNGLACCUMPROC glAccum;
LDL_API_ENTRY PFNGLPOPATTRIBPROC glPopAttrib;
LDL_API_ENTRY PFNGLPUSHATTRIBPROC glPushAttrib;
LDL_API_ENTRY PFNGLMAP1DPROC glMap1d;
LDL_API_ENTRY PFNGLMAP1FPROC glMap1f;
LDL_API_ENTRY PFNGLMAP2DPROC glMap2d;
LDL_API_ENTRY PFNGLMAP2FPROC glMap2f;
LDL_API_ENTRY PFNGLMAPGRID1DPROC glMapGrid1d;
LDL_API_ENTRY PFNGLMAPGRID1FPROC glMapGrid1f;
LDL_API_ENTRY PFNGLMAPGRID2DPROC glMapGrid2d;
LDL_API_ENTRY PFNGLMAPGRID2FPROC glMapGrid2f;
LDL_API_ENTRY PFNGLEVALCOORD1DPROC glEvalCoord1d;
LDL_API_ENTRY PFNGLEVALCOORD1DVPROC glEvalCoord1dv;
LDL_API_ENTRY PFNGLEVALCOORD1FPROC glEvalCoord1f;
LDL_API_ENTRY PFNGLEVALCOORD1FVPROC glEvalCoord1fv;
LDL_API_ENTRY PFNGLEVALCOORD2DPROC glEvalCoord2d;
LDL_API_ENTRY PFNGLEVALCOORD2DVPROC glEvalCoord2dv;
LDL_API_ENTRY PFNGLEVALCOORD2FPROC glEvalCoord2f;
LDL_API_ENTRY PFNGLEVALCOORD2FVPROC glEvalCoord2fv;
LDL_API_ENTRY PFNGLEVALMESH1PROC glEvalMesh1;
LDL_API_ENTRY PFNGLEVALPOINT1PROC glEvalPoint1;
LDL_API_ENTRY PFNGLEVALMESH2PROC glEvalMesh2;
LDL_API_ENTRY PFNGLEVALPOINT2PROC glEvalPoint2;
LDL_API_ENTRY PFNGLALPHAFUNCPROC glAlphaFunc;
LDL_API_ENTRY PFNGLPIXELZOOMPROC glPixelZoom;
LDL_API_ENTRY PFNGLPIXELTRANSFERFPROC glPixelTransferf;
LDL_API_ENTRY PFNGLPIXELTRANSFERIPROC glPixelTransferi;
LDL_API_ENTRY PFNGLPIXELMAPFVPROC glPixelMapfv;
LDL_API_ENTRY PFNGLPIXELMAPUIVPROC glPixelMapuiv;
LDL_API_ENTRY PFNGLPIXELMAPUSVPROC glPixelMapusv;
LDL_API_ENTRY PFNGLCOPYPIXELSPROC glCopyPixels;
LDL_API_ENTRY PFNGLDRAWPIXELSPROC glDrawPixels;
LDL_API_ENTRY PFNGLGETCLIPPLANEPROC glGetClipPlane;
LDL_API_ENTRY PFNGLGETLIGHTFVPROC glGetLightfv;
LDL_API_ENTRY PFNGLGETLIGHTIVPROC glGetLightiv;
LDL_API_ENTRY PFNGLGETMAPDVPROC glGetMapdv;
LDL_API_ENTRY PFNGLGETMAPFVPROC glGetMapfv;
LDL_API_ENTRY PFNGLGETMAPIVPROC glGetMapiv;
LDL_API_ENTRY PFNGLGETMATERIALFVPROC glGetMaterialfv;
LDL_API_ENTRY PFNGLGETMATERIALIVPROC glGetMaterialiv;
LDL_API_ENTRY PFNGLGETPIXELMAPFVPROC glGetPixelMapfv;
LDL_API_ENTRY PFNGLGETPIXELMAPUIVPROC glGetPixelMapuiv;
LDL_API_ENTRY PFNGLGETPIXELMAPUSVPROC glGetPixelMapusv;
LDL_API_ENTRY PFNGLGETPOLYGONSTIPPLEPROC glGetPolygonStipple;
LDL_API_ENTRY PFNGLGETTEXENVFVPROC glGetTexEnvfv;
LDL_API_ENTRY PFNGLGETTEXENVIVPROC glGetTexEnviv;
LDL_API_ENTRY PFNGLGETTEXGENDVPROC glGetTexGendv;
LDL_API_ENTRY PFNGLGETTEXGENFVPROC glGetTexGenfv;
LDL_API_ENTRY PFNGLGETTEXGENIVPROC glGetTexGeniv;
LDL_API_ENTRY PFNGLISLISTPROC glIsList;
LDL_API_ENTRY PFNGLFRUSTUMPROC glFrustum;
LDL_API_ENTRY PFNGLLOADIDENTITYPROC glLoadIdentity;
LDL_API_ENTRY PFNGLLOADMATRIXFPROC glLoadMatrixf;
LDL_API_ENTRY PFNGLLOADMATRIXDPROC glLoadMatrixd;
LDL_API_ENTRY PFNGLMATRIXMODEPROC glMatrixMode;
LDL_API_ENTRY PFNGLMULTMATRIXFPROC glMultMatrixf;
LDL_API_ENTRY PFNGLMULTMATRIXDPROC glMultMatrixd;
LDL_API_ENTRY PFNGLORTHOPROC glOrtho;
LDL_API_ENTRY PFNGLPOPMATRIXPROC glPopMatrix;
LDL_API_ENTRY PFNGLPUSHMATRIXPROC glPushMatrix;
LDL_API_ENTRY PFNGLROTATEDPROC glRotated;
LDL_API_ENTRY PFNGLROTATEFPROC glRotatef;
LDL_API_ENTRY PFNGLSCALEDPROC glScaled;
LDL_API_ENTRY PFNGLSCALEFPROC glScalef;
LDL_API_ENTRY PFNGLTRANSLATEDPROC glTranslated;
LDL_API_ENTRY PFNGLTRANSLATEFPROC glTranslatef;

#ifdef __cplusplus
}
#endif

#endif     
