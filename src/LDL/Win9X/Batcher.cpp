// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/Enums.hpp>
#include <LDL/Texture.hpp>
#include <LDL/Batcher.hpp>
#include <LDL/Renders/GL1/BatchGL1.hpp>
#include <LDL/Renders/Soft/BtchSoft.hpp>

LDL_ISpriteBatcher* LDL_CreateSpriteBatcher(LDL_RenderContext* renderContext, LDL_ITexture* texture, size_t count)
{
	size_t mode = renderContext->Mode();

	LDL_ASSERT_DETAIL(mode < LDL_RenderMode::Max, "Unknown graphics mode");

	LDL_ISpriteBatcher* result = NULL;

	switch (mode)
	{
	case LDL_RenderMode::Software:
		result = new LDL_SpriteBatcherSoftware(texture, count);
		break;
	case LDL_RenderMode::OpenGL1:
		result = new LDL_SpriteBatcherOpenGL1(texture, count);
		break;
	}

	return result;
}
