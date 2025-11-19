// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Graphics/Image.hpp>
#include <LDL/Texture.hpp>

using namespace Arcanum;

Image::Image(LDL_RenderContext* renderContext, const LDL_Vec2u& size, uint8_t* pixels, const LDL_Vec2u& offset, const LDL_Vec2u& delta) :
	_texture(LDL_CreateTexture( renderContext, LDL_PixelFormat::RGBA32, size, pixels)),
	_offset(offset),
	_delta(delta)
{
}

LDL_ITexture* Image::GetTexture()
{
	return _texture;
}

const LDL_Vec2u& Image::Offset()
{
	return _offset;
}

const LDL_Vec2u& Image::Delta()
{
	return _delta;
}
