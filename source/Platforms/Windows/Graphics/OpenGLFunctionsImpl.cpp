#include "OpenGLFunctionsImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL;
using namespace LDL::Graphics;

OpenGLFunctionsImpl::OpenGLFunctionsImpl(const std::string& path) :
    _Library(path)
{
}

VoidFuncPtr OpenGLFunctionsImpl::Function(const std::string& name)
{
    VoidFuncPtr result = (VoidFuncPtr)wglGetProcAddress(name.c_str());

    if (IsValid(result))
    {
        result = _Library.Function(name);
    }

    return result;
}

bool OpenGLFunctionsImpl::IsValid(VoidFuncPtr ptr)
{
    return (ptr == 0 || (ptr == (VoidFuncPtr)0x1) || (ptr == (VoidFuncPtr)0x2) || (ptr == (VoidFuncPtr)0x3) || (ptr == (VoidFuncPtr)-1));
}
