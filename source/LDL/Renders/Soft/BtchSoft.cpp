// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Renders/Soft/TexSoft.hpp>
#include <LDL/Renders/Soft/BtchSoft.hpp>

LDL_SpriteBatcherSoftware::LDL_SpriteBatcherSoftware(LDL_ITexture* texture, size_t count)
{
	LDL_UNUSED(texture);
	LDL_UNUSED(count);
}

void LDL_SpriteBatcherSoftware::Draw(const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	LDL_UNUSED(dstPos);
	LDL_UNUSED(dstSize);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void LDL_SpriteBatcherSoftware::Clear()
{
}
