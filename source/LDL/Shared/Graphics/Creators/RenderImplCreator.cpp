// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "RenderImplCreator.hpp"

#include "../Renders/Software/RenderImplSoftware.hpp"
#include "../Renders/OpenGL1/RenderImplOpenGL1.hpp"
#include "../Renders/OpenGL3/RenderImplOpenGL3.hpp"

#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/RenderMode.hpp>

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Graphics;

RenderImpl* RenderImplCreator::Create(uint8_t* memory, Result& result, RenderContext& renderContext, Window* window)
{
	size_t mode = renderContext.Mode();

	if (mode >= RenderMode::Max)
	{
		result.Message("Unknown graphics mode");
		return NULL;
	}

	RenderImpl* impl = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		impl = new(memory) RenderImplSoftware(result, renderContext.GetRenderContextImpl(), window);
		break;
	case RenderMode::OpenGL1:
		impl = new(memory) RenderImplOpenGL1(result, renderContext.GetRenderContextImpl(), window);
		break;
	case RenderMode::OpenGL3:
		impl = new(memory) RenderImplOpenGL3(result, renderContext.GetRenderContextImpl(), window);
		break;
	}

	return impl;
}
