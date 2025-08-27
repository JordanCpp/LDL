// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/TextureBatcher.hpp>
#include <LDL/Shared/Graphics/Creators/TextureBatcherImplCreator.hpp>

using namespace LDL;

SpriteBatcher::SpriteBatcher(RenderContext* renderContext, Texture* texture, size_t count)
{
	TextureBatcherImplCreator creator;

	_impl = creator.Create(_memory, renderContext, texture, count);
}

SpriteBatcher::~SpriteBatcher()
{
	 _impl->~SpriteBatcherImpl();
}

SpriteBatcherImpl* SpriteBatcher::GetTextureBatcherImpl()
{
	return _impl;
}

void SpriteBatcher::Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_impl->Draw(dstPos, dstSize, srcPos, srcSize);
}

void SpriteBatcher::Clear()
{
	_impl->Clear();
}
