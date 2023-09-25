#include "GLLib.hpp"
#include "WinX.hpp"

LDL_ImpOpenGLLibrary::LDL_ImpOpenGLLibrary() :
	_Library("opengl32.dll")
{
}

LDL_VoidFuncPtr LDL_ImpOpenGLLibrary::Function(const char* name)
{
    LDL_VoidFuncPtr p = (LDL_VoidFuncPtr)wglGetProcAddress(name);

    if (p == 0 || (p == (LDL_VoidFuncPtr)0x1) || (p == (LDL_VoidFuncPtr)0x2) || (p == (LDL_VoidFuncPtr)0x3) || (p == (LDL_VoidFuncPtr)-1))
    {
        p = _Library.Function(name);
    }

    return (LDL_VoidFuncPtr)p;
}
