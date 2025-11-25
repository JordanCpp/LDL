// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Renders/GL1/TexGL1.hpp>
#include <LDL/Renders/GL1/BatchGL1.hpp>

LDL_SpriteBatcherOpenGL1::LDL_SpriteBatcherOpenGL1(LDL_ITexture* texture, size_t count) :
	_texture(((LDL_TextureOpenGL1*)texture)->Id()),
	_textureSize(texture->Quad().x)
{
	_quads.reserve(count);
}

void LDL_SpriteBatcherOpenGL1::Draw(const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	Quad quad;

	CalcQuad(quad, (uint16_t)dstPos.x, (uint16_t)dstPos.y, (uint16_t)dstSize.x, (uint16_t)dstSize.y, (uint16_t)srcPos.x, (uint16_t)srcPos.y, (uint16_t)srcSize.x, (uint16_t)srcSize.y, _textureSize);

	_quads.push_back(quad);
}

void LDL_SpriteBatcherOpenGL1::Clear()
{
	_quads.clear();
}

size_t LDL_SpriteBatcherOpenGL1::TextureId()
{
	return _texture;
}

size_t LDL_SpriteBatcherOpenGL1::Count()
{
	return _quads.size();
}

Quad* LDL_SpriteBatcherOpenGL1::Content()
{
	return &_quads[0];
}
