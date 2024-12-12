#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Enums/RenderMode.hpp>

#include "Creators/RenderContextImplCreator.hpp"

using namespace LDL::Core;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

RenderContext::RenderContext(size_t mode)
{
    RenderContextImplCreator creator;
	
	_impl = creator.Create(mode);
}

RenderContext::~RenderContext()
{
	delete _impl;
}

RenderContextImpl* RenderContext::GetRenderContextImpl()
{
	return _impl;
}

size_t RenderContext::Mode()
{
    return _impl->Mode();
}

void* RenderContext::Context()
{
	return _impl;
}
