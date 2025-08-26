// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/Texture.hpp>
#include <LDL/Shared/Graphics/Creators/TextureImplCreator.hpp>

using namespace LDL::Math;
using namespace LDL::Graphics;

Texture::Texture(RenderContext* renderContext, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel)
{
	TextureImplCreator creator;

	_impl = creator.Create(_memory, renderContext, size, pixels, bytesPerPixel);
}

Texture::Texture(RenderContext* renderContext, const Vec2u& size, uint8_t bytesPerPixel)
{
	TextureImplCreator creator;

	_impl = creator.Create(_memory, renderContext, size, bytesPerPixel);
}

Texture::Texture(RenderContext* renderContext, Surface* surface)
{
	TextureImplCreator creator;

	_impl = creator.Create(_memory, renderContext, surface);
}

Texture::~Texture()
{
	_impl->~TextureImpl();
}

void Texture::Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel)
{
	_impl->Copy(dstPos, srcSize, pixels, bytesPerPixel);
}

void Texture::Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize)
{
	_impl->Copy(dstPos, surface, srcSize);
}

const Vec2u& Texture::Size()
{
	return _impl->Size();
}

TextureImpl* Texture::GetTextureImpl()
{
	return _impl;
}
