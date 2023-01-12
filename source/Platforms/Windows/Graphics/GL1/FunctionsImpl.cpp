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

    if (p == 0 || (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) || (p == (void*)-1))
    {
        p = _Library.Function(name);
    }

    return (LDL::VoidFuncPtr)p;
}