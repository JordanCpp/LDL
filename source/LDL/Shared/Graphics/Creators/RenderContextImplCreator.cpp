// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/STL/new.hpp>
#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include <LDL/Shared/Graphics/Creators/RenderContextImplCreator.hpp>
#include <LDL/Shared/Graphics/Renders/Software/RenderContextImplSoftware.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/RenderContextImplOpenGL1.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/RenderContextImplOpenGL3.hpp>

using namespace LDL;

RenderContextImpl* RenderContextImplCreator::Create(uint8_t* memory, size_t mode)
{
	RenderContextImpl* result = NULL;

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	switch (mode)
	{
	case RenderMode::Software:
		result = new(memory) RenderContextImplSoftware(mode);
		break;
	case RenderMode::OpenGL1:
		result = new(memory) RenderContextImplOpenGL1(mode);
		break;
	case RenderMode::OpenGL3:
		result = new(memory) RenderContextImplOpenGL3(mode);
		break;
	}

	return result;
}
