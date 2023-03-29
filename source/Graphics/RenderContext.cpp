#include <LDL/Graphics/RenderContext.hpp>

#ifdef LDL_RENDER_SOFTWARE
#include "Software/RenderContextImpl.hpp"
#elif LDL_RENDER_GDI
#include "GDI/RenderContextImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/RenderContextImpl.hpp"
#elif LDL_RENDER_OPENGL3
#include "OpenGL3/RenderContextImpl.hpp"
#elif LDL_RENDER_DIRECTX1
#include "DirectDraw/RenderContextImpl.hpp"
#elif LDL_RENDER_DIRECTX5
#include "DirectX5/Direct3D/RenderContextImpl.hpp"
#elif LDL_RENDER_DIRECTX9
#include "DirectX9/Direct3D/RenderContextImpl.hpp"
#elif LDL_RENDER_DIRECTX10
#include "DirectX10/Direct3D/RenderContextImpl.hpp"
#endif

using namespace LDL::Graphics;

RenderContext::RenderContext() :
	_RenderContextImpl(new RenderContextImpl())
{
}

RenderContext::~RenderContext()
{
	delete _RenderContextImpl;
}

RenderContextImpl* RenderContext::GetRenderContextImpl()
{
	return _RenderContextImpl;
}

void* RenderContext::Context()
{
	return _RenderContextImpl;
}