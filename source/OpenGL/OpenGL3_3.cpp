#include <LDL/OpenGL/OpenGL3_3.hpp>

PFNGLCREATESHADERPROC      * glCreateShader      = NULL;
PFNGLSHADERSOURCEPROC      * glShaderSource      = NULL;
PFNGLCOMPILESHADERPROC     * glCompileShader     = NULL;
PFNGLGETSHADERIVPROC       * glGetShaderiv       = NULL;
PFNGLGETSHADERINFOLOGPROC  * glGetShaderInfoLog  = NULL;
PFNGLCREATEPROGRAMPROC     * glCreateProgram     = NULL;
PFNGLATTACHSHADERPROC      * glAttachShader      = NULL;
PFNGLLINKPROGRAMPROC       * glLinkProgram       = NULL;
PFNGLGETPROGRAMIVPROC      * glGetProgramiv      = NULL;
PFNGLGETPROGRAMINFOLOGPROC * glGetProgramInfoLog = NULL;
PFNGLDELETESHADERPROC      * glDeleteShader      = NULL;
PFNGLGENVERTEXARRAYSPROC* glGenVertexArrays = NULL;
PFNGLGENBUFFERSARBPROC* glGenBuffers = NULL;
PFNGLBINDVERTEXARRAYPROC* glBindVertexArray = NULL;
PFNGLBINDBUFFERPROC* glBindBuffer = NULL;
PFNGLBUFFERDATAPROC* glBufferData = NULL;
PFNGLVERTEXATTRIBPOINTERPROC* glVertexAttribPointer = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC* glEnableVertexAttribArray = NULL;
PFNGLUSEPROGRAMPROC* glUseProgram = NULL;
PFNGLUNIFORM1IPROC* glUniform1i = NULL;
PFNGLUNIFORM1FPROC* glUniform1f = NULL;
PFNGLGETUNIFORMLOCATIONPROC* glGetUniformLocation = NULL;
PFNGLDELETEVERTEXARRAYSPROC* glDeleteVertexArrays = NULL;
PFNGLDELETEBUFFERSPROC* glDeleteBuffers = NULL;
PFNGLGENERATEMIPMAPPROC* glGenerateMipmap = NULL;
PFNGLACTIVETEXTUREPROC* glActiveTexture = NULL;