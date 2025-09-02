// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/Graphics/Renders/Software/TextureImplSoftware.hpp>

using namespace LDL;

TextureImplSoftware::TextureImplSoftware(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_surface(PixelFormat::RGBA32, size, pixels)
{
	LDL_UNUSED(renderContextImpl);
}

TextureImplSoftware::TextureImplSoftware(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t bytesPerPixel) :
	_surface(PixelFormat::RGBA32, size, size)
{
	LDL_UNUSED(renderContextImpl);
}

TextureImplSoftware::~TextureImplSoftware()
{
}

void TextureImplSoftware::Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel)
{
	LDL_UNUSED(dstPos);
	LDL_UNUSED(srcSize);
	LDL_UNUSED(pixels);
	LDL_UNUSED(bytesPerPixel);
}

void TextureImplSoftware::Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize)
{
	LDL_UNUSED(dstPos);
	LDL_UNUSED(surface);
	LDL_UNUSED(srcSize);
}

const Vec2u& TextureImplSoftware::Size()
{
	return _surface.Size();
}

const Vec2u& TextureImplSoftware::Quad()
{
	return _surface.Size();
}

Surface* TextureImplSoftware::GetSurface()
{
	return &_surface;
}
