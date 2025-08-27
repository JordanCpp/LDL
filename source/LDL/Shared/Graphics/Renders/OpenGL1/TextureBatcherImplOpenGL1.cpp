// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "TextureBatcherImplOpenGL1.hpp"
#include "TextureImplOpenGL1.hpp"
#include "../OpenGL/Util.hpp"

using namespace LDL;

SpriteBatcherImplOpenGL1::SpriteBatcherImplOpenGL1(Texture* texture, size_t count) :
	_texture(((TextureImplOpenGL1*)texture->GetTextureImpl())->Id()),
	_textureSize(texture->GetTextureImpl()->Quad().x)
{
	_quads.reserve(count);
}

void SpriteBatcherImplOpenGL1::Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	Quad quad;

	CalcQuad(quad, (uint16_t)dstPos.x, (uint16_t)dstPos.y, (uint16_t)dstSize.x, (uint16_t)dstSize.y, (uint16_t)srcPos.x, (uint16_t)srcPos.y, (uint16_t)srcSize.x, (uint16_t)srcSize.y, _textureSize);

	_quads.push_back(quad);
}

void SpriteBatcherImplOpenGL1::Clear()
{
	_quads.clear();
}

size_t SpriteBatcherImplOpenGL1::TextureId()
{
	return _texture;
}

size_t SpriteBatcherImplOpenGL1::Count()
{
	return _quads.size();
}

Quad* SpriteBatcherImplOpenGL1::Content()
{
	return &_quads[0];
}
