#include "FunctionsImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;

FunctionsImpl::FunctionsImpl(const char* path) :
    _Library(path)
{
}

LDL::VoidFuncPtr FunctionsImpl::Function(const char* name)
{
    LDL::VoidFuncPtr p = (LDL::VoidFuncPtr)wglGetProcAddress(name);

    if (p == 0 || (p == (LDL::VoidFuncPtr)0x1) || (p == (LDL::VoidFuncPtr)0x2) || (p == (LDL::VoidFuncPtr)0x3) || (p == (LDL::VoidFuncPtr)-1))
    {
        p = _Library.Function(name);
    }

    return (LDL::VoidFuncPtr)p;
}