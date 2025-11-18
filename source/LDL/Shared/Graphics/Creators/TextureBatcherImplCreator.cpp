// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include <LDL/Graphics/TextureImplCreator.hpp>
#include <LDL/Shared/Graphics/Creators/TextureBatcherImplCreator.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/TextureBatcherImplOpenGL1.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/TextureBatcherImplOpenGL3.hpp>
#include <LDL/Shared/Graphics/Renders/Software/TextureBatcherImplSoftware.hpp>

using namespace LDL;

SpriteBatcherImpl* TextureBatcherImplCreator::Create(uint8_t* memory, RenderContext* renderContext, ITexture* texture, size_t count)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	SpriteBatcherImpl* result = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		result = new(memory) SpriteBatcherImplSoftware(texture, count);
		break;
	case RenderMode::OpenGL1:
		result = new(memory) SpriteBatcherImplOpenGL1(texture, count);
		break;
	case RenderMode::OpenGL3:
		result = new(memory) SpriteBatcherImplOpenGL3(texture, count);
		break;
	}

	return result;
}
