// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Shared/Graphics/Creators/RenderContextImplCreator.hpp>

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
