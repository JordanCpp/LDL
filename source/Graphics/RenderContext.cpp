#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include <LDL/Core/RuntimeError.hpp>

#ifdef LDL_RENDER_SOFTWARE

#elif LDL_RENDER_GDI
#include "GDI/RenderContextImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/RenderContextImplOpenGL1.hpp"
#include "Software/RenderContextImplSoftware.hpp"
#elif LDL_RENDER_OPENGL3
#include "OpenGL3/RenderContextImpl.hpp"
#elif LDL_RENDER_DIRECT_DRAW
#include "DirectDraw/RenderContextImpl.hpp"
#elif LDL_RENDER_DIRECTX5
#include "DirectX5/Direct3D/RenderContextImpl.hpp"
#elif LDL_RENDER_DIRECTX9
#include "DirectX9/Direct3D/RenderContextImpl.hpp"
#elif LDL_RENDER_DIRECTX10
#include "DirectX10/Direct3D/RenderContextImpl.hpp"
#endif

using namespace LDL::Core;
using namespace LDL::Graphics;

RenderContext::RenderContext(size_t mode)
{
    switch (mode)
    {
    case Enums::RenderMode::Software:
        _RenderContextImpl = new RenderContextImplSoftware(mode);
        break;
    case Enums::RenderMode::OpenGL1:
        _RenderContextImpl = new RenderContextImplOpenGL1(mode);
        break;
    default:
        throw RuntimeError("Unknown graphics mode");
        break;
    }
}

RenderContext::~RenderContext()
{
	delete _RenderContextImpl;
}

RenderContextImpl* RenderContext::GetRenderContextImpl()
{
	return _RenderContextImpl;
}

size_t RenderContext::Mode()
{
    return _RenderContextImpl->Mode();
}

void* RenderContext::Context()
{
	return _RenderContextImpl;
}