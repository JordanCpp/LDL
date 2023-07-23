#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include <LDL/Core/RuntimeError.hpp>

#include "Creators/RenderContextImplCreator.hpp"

using namespace LDL::Core;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

RenderContext::RenderContext(size_t mode)
{
    RenderContextImplCreator creator;
	
	_RenderContextImpl = creator.Create(mode);
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
