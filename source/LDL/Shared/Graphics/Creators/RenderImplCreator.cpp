// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include <LDL/Shared/Graphics/Creators/RenderImplCreator.hpp>
#include <LDL/Shared/Graphics/Renders/Software/RenderImplSoftware.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/RenderImplOpenGL1.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/RenderImplOpenGL3.hpp>
#include <LDL/Shared/Graphics/Renders/Glide/RenderImplGlide.hpp>

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

RenderImpl* RenderImplCreator::Create(Result& result, RenderContext& renderContext, Window* window)
{
	size_t mode = renderContext.Mode();
	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	RenderImpl* impl = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		impl = new RenderImplSoftware(result, renderContext.GetRenderContextImpl(), window);
		break;
	case RenderMode::OpenGL1:
		impl = new RenderImplOpenGL1(result, renderContext.GetRenderContextImpl(), window);
		break;
	case RenderMode::OpenGL3:
		impl = new RenderImplOpenGL3(result, renderContext.GetRenderContextImpl(), window);
		break;
	case RenderMode::Glide:
		impl = new RenderImplGlide(result, renderContext.GetRenderContextImpl(), window);
		break;
	}

	return impl;
}
