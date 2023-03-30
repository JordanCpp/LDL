#ifndef LDL_OpenGL_OpenGL3_3_hpp
#define LDL_OpenGL_OpenGL3_3_hpp

#include <LDL/OpenGL/OpenGL1_1.hpp>

#define GL_STREAM_DRAW                    0x88E0
#define GL_STATIC_DRAW                    0x88E4
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C 
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C 
#define GL_VERTEX_SHADER                  0x8B31 
#define GL_COMPILE_STATUS                 0x8B81  
#define GL_FRAGMENT_SHADER                0x8B30   
#define GL_LINK_STATUS                    0x8B82    
#define GL_ARRAY_BUFFER                   0x8892  
#define GL_ELEMENT_ARRAY_BUFFER           0x8893 
#define GL_GEOMETRY_SHADER                0x8DD9   

#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1   

#define GL_CLAMP_TO_EDGE                  0x812F 

typedef GLuint (OPENGL_API_CALL PFNGLCREATESHADERPROC           ) (GLenum type);
typedef void   (OPENGL_API_CALL PFNGLSHADERSOURCEPROC           ) (GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
typedef void   (OPENGL_API_CALL PFNGLCOMPILESHADERPROC          ) (GLuint shader);
typedef void   (OPENGL_API_CALL PFNGLGETSHADERIVPROC            ) (GLuint shader, GLenum pname, GLint* params);
typedef void   (OPENGL_API_CALL PFNGLGETSHADERINFOLOGPROC       ) (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef GLuint (OPENGL_API_CALL PFNGLCREATEPROGRAMPROC          ) (void);
typedef void   (OPENGL_API_CALL PFNGLATTACHSHADERPROC           ) (GLuint program, GLuint shader);
typedef void   (OPENGL_API_CALL PFNGLLINKPROGRAMPROC            ) (GLuint program);
typedef void   (OPENGL_API_CALL PFNGLGETPROGRAMIVPROC           ) (GLuint program, GLenum pname, GLint* params);
typedef void   (OPENGL_API_CALL PFNGLGETPROGRAMINFOLOGPROC      ) (GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void   (OPENGL_API_CALL PFNGLDELETESHADERPROC           ) (GLuint shader);
typedef void   (OPENGL_API_CALL PFNGLGENVERTEXARRAYSPROC        ) (GLsizei n, GLuint* arrays);
typedef void   (OPENGL_API_CALL PFNGLGENBUFFERSARBPROC          ) (GLsizei n, GLuint* buffers);
typedef void   (OPENGL_API_CALL PFNGLBINDVERTEXARRAYPROC        ) (GLuint array);
typedef void   (OPENGL_API_CALL PFNGLBINDBUFFERPROC             ) (GLenum target, GLuint buffer);
typedef void   (OPENGL_API_CALL PFNGLBUFFERDATAPROC             ) (GLenum target, GLsizeiptr size, const void* data, GLenum usage);
typedef void   (OPENGL_API_CALL PFNGLVERTEXATTRIBPOINTERPROC    ) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
typedef void   (OPENGL_API_CALL PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void   (OPENGL_API_CALL PFNGLUSEPROGRAMPROC             ) (GLuint program);
typedef void   (OPENGL_API_CALL PFNGLUNIFORM1IPROC              ) (GLint location, GLint v0);

typedef GLint  (OPENGL_API_CALL PFNGLGETUNIFORMLOCATIONPROC     ) (GLuint program, const GLchar* name);
typedef void   (OPENGL_API_CALL PFNGLDELETEVERTEXARRAYSPROC     ) (GLsizei n, const GLuint* arrays);
typedef void   (OPENGL_API_CALL PFNGLDELETEBUFFERSPROC          ) (GLsizei n, const GLuint* buffers);
typedef void   (OPENGL_API_CALL PFNGLGENERATEMIPMAPPROC         ) (GLenum target);
typedef void   (OPENGL_API_CALL PFNGLACTIVETEXTUREPROC          ) (GLenum texture);

typedef void   (OPENGL_API_CALL PFNGLUNIFORMMATRIX2FVPROC       ) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void   (OPENGL_API_CALL PFNGLUNIFORMMATRIX3FVPROC       ) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void   (OPENGL_API_CALL PFNGLUNIFORMMATRIX4FVPROC       ) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);

typedef void   (OPENGL_API_CALL PFNGLUNIFORM1FVPROC             ) (GLint location, GLsizei count, const GLfloat* value);
typedef void   (OPENGL_API_CALL PFNGLUNIFORM2FVPROC             ) (GLint location, GLsizei count, const GLfloat* value);
typedef void   (OPENGL_API_CALL PFNGLUNIFORM3FVPROC             ) (GLint location, GLsizei count, const GLfloat* value);
typedef void   (OPENGL_API_CALL PFNGLUNIFORM4FVPROC             ) (GLint location, GLsizei count, const GLfloat* value);

typedef void   (OPENGL_API_CALL PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void   (OPENGL_API_CALL PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void   (OPENGL_API_CALL PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void   (OPENGL_API_CALL PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);

typedef void   (OPENGL_API_CALL PFNGLDELETEPROGRAMPROC) (GLuint program);

extern PFNGLCREATESHADERPROC            * glCreateShader;
extern PFNGLSHADERSOURCEPROC            * glShaderSource;
extern PFNGLCOMPILESHADERPROC           * glCompileShader;
extern PFNGLGETSHADERIVPROC             * glGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC        * glGetShaderInfoLog;
extern PFNGLCREATEPROGRAMPROC           * glCreateProgram;
extern PFNGLATTACHSHADERPROC            * glAttachShader;
extern PFNGLLINKPROGRAMPROC             * glLinkProgram;
extern PFNGLGETPROGRAMIVPROC            * glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC       * glGetProgramInfoLog;
extern PFNGLDELETESHADERPROC            * glDeleteShader;
extern PFNGLGENVERTEXARRAYSPROC         * glGenVertexArrays;
extern PFNGLGENBUFFERSARBPROC           * glGenBuffers;
extern PFNGLBINDVERTEXARRAYPROC         * glBindVertexArray;
extern PFNGLBINDBUFFERPROC              * glBindBuffer;
extern PFNGLBUFFERDATAPROC              * glBufferData;
extern PFNGLVERTEXATTRIBPOINTERPROC     * glVertexAttribPointer;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC * glEnableVertexAttribArray;
extern PFNGLUSEPROGRAMPROC              * glUseProgram;
extern PFNGLUNIFORM1IPROC               * glUniform1i;

extern PFNGLGETUNIFORMLOCATIONPROC      * glGetUniformLocation;
extern PFNGLDELETEVERTEXARRAYSPROC      * glDeleteVertexArrays;
extern PFNGLDELETEBUFFERSPROC           * glDeleteBuffers;
extern PFNGLGENERATEMIPMAPPROC          * glGenerateMipmap;
extern PFNGLACTIVETEXTUREPROC           * glActiveTexture;

extern PFNGLUNIFORMMATRIX2FVPROC        * glUniformMatrix2fv;
extern PFNGLUNIFORMMATRIX3FVPROC        * glUniformMatrix3fv;
extern PFNGLUNIFORMMATRIX4FVPROC        * glUniformMatrix4fv;

extern PFNGLUNIFORM1FVPROC              * glUniform1fv;
extern PFNGLUNIFORM2FVPROC              * glUniform2fv;
extern PFNGLUNIFORM3FVPROC              * glUniform3fv;
extern PFNGLUNIFORM4FVPROC              * glUniform4fv;

extern PFNGLUNIFORM1FPROC* glUniform1f;
extern PFNGLUNIFORM2FPROC* glUniform2f;
extern PFNGLUNIFORM3FPROC* glUniform3f;
extern PFNGLUNIFORM4FPROC* glUniform4f;

extern PFNGLDELETEPROGRAMPROC* glDeleteProgram;

#endif     