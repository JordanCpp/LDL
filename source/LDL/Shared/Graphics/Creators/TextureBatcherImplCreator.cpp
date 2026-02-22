// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include <LDL/Shared/Graphics/Creators/TextureImplCreator.hpp>
#include <LDL/Shared/Graphics/Creators/TextureBatcherImplCreator.hpp>
#include <LDL/Shared/Graphics/Renders/Software/TextureBatcherImplSoftware.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/TextureBatcherImplOpenGL1.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/TextureBatcherImplOpenGL3.hpp>
#include <LDL/Shared/Graphics/Renders/Glide/TextureBatcherImplGlide.hpp>

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

TextureBatcherImpl* TextureBatcherImplCreator::Create(RenderContext* renderContext, Texture* texture, size_t count)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	TextureBatcherImpl* result = NULL;

	switch (mode)
	{
	case RenderMode::Software:
		result = new TextureBatcherImplSoftware(texture, count);
		break;
	case RenderMode::OpenGL1:
		result = new TextureBatcherImplOpenGL1(texture, count);
		break;
	case RenderMode::OpenGL3:
		result = new TextureBatcherImplOpenGL3(texture, count);
		break;
	case RenderMode::Glide:
		result = new TextureBatcherImplGlide(texture, count);
		break;
	}

	return result;
}
