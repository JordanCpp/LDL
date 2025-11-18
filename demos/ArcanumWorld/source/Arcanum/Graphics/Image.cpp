// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Graphics/Image.hpp>
#include <LDL/Graphics/TextureImplCreator.hpp>

using namespace Arcanum;
using namespace LDL;

Image::Image(RenderContext* renderContext, const Vec2u& size, uint8_t* pixels, const Vec2u& offset, const Vec2u& delta) :
	_texture(CreateTextureImpl( renderContext, LDL::PixelFormat::RGBA32, size, pixels)),
	_offset(offset),
	_delta(delta)
{
}

ITexture* Image::GetTexture()
{
	return _texture;
}

const Vec2u& Image::Offset()
{
	return _offset;
}

const Vec2u& Image::Delta()
{
	return _delta;
}
