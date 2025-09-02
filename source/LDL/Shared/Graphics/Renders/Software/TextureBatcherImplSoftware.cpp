// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/Graphics/Renders/Software/TextureImplSoftware.hpp>
#include <LDL/Shared/Graphics/Renders/Software/TextureBatcherImplSoftware.hpp>

using namespace LDL;

SpriteBatcherImplSoftware::SpriteBatcherImplSoftware(Texture* texture, size_t count)
{
	LDL_UNUSED(texture);
	LDL_UNUSED(count);
}

void SpriteBatcherImplSoftware::Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	LDL_UNUSED(dstPos);
	LDL_UNUSED(dstSize);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void SpriteBatcherImplSoftware::Clear()
{
}
