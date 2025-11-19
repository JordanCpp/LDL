// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Renders/Software/TextureImplSoftware.hpp>

TextureImplSoftware::TextureImplSoftware(LDL_RenderContext* renderContextImpl, size_t pixelFormat, const LDL_Vec2u& size, uint8_t* pixels) :
	_surface(pixelFormat, size, pixels)
{
	LDL_UNUSED(renderContextImpl);
}

TextureImplSoftware::TextureImplSoftware(LDL_RenderContext* renderContextImpl, size_t pixelFormat, const LDL_Vec2u& size) :
	_surface(pixelFormat, size, size)
{
	LDL_UNUSED(renderContextImpl);
}

TextureImplSoftware::~TextureImplSoftware()
{
}

void TextureImplSoftware::Copy(const LDL_Vec2u& dstPos, const LDL_Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel)
{
	LDL_UNUSED(dstPos);
	LDL_UNUSED(srcSize);
	LDL_UNUSED(pixels);
	LDL_UNUSED(bytesPerPixel);
}

void TextureImplSoftware::Copy(const LDL_Vec2u& dstPos, LDL_Surface* surface, const LDL_Vec2u& srcSize)
{
	LDL_UNUSED(dstPos);
	LDL_UNUSED(surface);
	LDL_UNUSED(srcSize);
}

const LDL_Vec2u& TextureImplSoftware::Size()
{
	return _surface.Size();
}

const LDL_Vec2u& TextureImplSoftware::Quad()
{
	return _surface.Size();
}

LDL_Surface* TextureImplSoftware::GetSurface()
{
	return &_surface;
}
