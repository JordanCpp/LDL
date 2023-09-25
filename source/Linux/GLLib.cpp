#include "GLLib.hpp"
#include "GLX.hpp"

LDL_VoidFuncPtr LDL_ImpOpenGLLibrary::Function(const char* name)
{
    LDL_VoidFuncPtr result = glXGetProcAddress((const GLubyte*)name);

    return result;
}
