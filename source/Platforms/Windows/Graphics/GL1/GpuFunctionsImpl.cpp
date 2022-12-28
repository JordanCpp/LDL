#include "GpuFunctionsImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;

GpuFunctionsImpl::GpuFunctionsImpl(const char* path) :
    _Library(path)
{
}

void* GpuFunctionsImpl::Function(const char* name)
{
    void* p = (void*)wglGetProcAddress(name);

    if (p == 0 || (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) || (p == (void*)-1))
    {
        p = _Library.Function(name);
    }

    return p;
}