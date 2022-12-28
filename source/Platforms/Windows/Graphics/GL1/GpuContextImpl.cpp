#include "GpuContextImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;

GpuContextImpl::GpuContextImpl(const char* path) :
    _HGLRC(NULL)
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