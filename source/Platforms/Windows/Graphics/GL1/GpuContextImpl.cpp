#include "GpuContextImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;

GpuContextImpl::GpuContextImpl(const char* path) :
    _HGLRC(NULL),
    _Library(path)
{
}

GpuContextImpl::~GpuContextImpl()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_HGLRC);
}

void GpuContextImpl::Create(HDC hdc)
{
    if (hdc == NULL)
        throw LDL::Core::RuntimeError("Argument hdc is null");

    _HGLRC = wglCreateContext(hdc);

    if (_HGLRC == NULL)
        throw LDL::Core::RuntimeError("wglCreateContext failed");

    if (!wglMakeCurrent(hdc, _HGLRC))
        throw LDL::Core::RuntimeError("wglMakeCurrent failed");
}

void* GpuContextImpl::Function(const char* name)
{
    void* p = (void*)wglGetProcAddress(name);

    if (p == 0 || (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) || (p == (void*)-1))
    {
        p = _Library.Function(name);
    }

    return p;
}