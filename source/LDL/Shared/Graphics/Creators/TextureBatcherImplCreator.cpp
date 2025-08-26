// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "TextureImplCreator.hpp"
#include <LDL/Enums/RenderMode.hpp>

#include "../Renders/Software/TextureBatcherImplSoftware.hpp"
#include "../Renders/OpenGL1/TextureBatcherImplOpenGL1.hpp"
#include "../Renders/OpenGL3/TextureBatcherImplOpenGL3.hpp"

#include "TextureBatcherImplCreator.hpp"
#include <LDL/Core/Assert.hpp>

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Graphics;

TextureBatcherImpl* TextureBatcherImplCreator::Create(uint8_t* memory, RenderContext* renderContext, Texture* texture, size_t count)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	TextureBatcherImpl* result = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		result = new(memory) TextureBatcherImplSoftware(texture, count);
		break;
	case RenderMode::OpenGL1:
		result = new(memory) TextureBatcherImplOpenGL1(texture, count);
		break;
	case RenderMode::OpenGL3:
		result = new(memory) TextureBatcherImplOpenGL3(texture, count);
		break;
	}

	return result;
}
