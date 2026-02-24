// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/Graphics/Renders/Direct3D6/TextureImplDirect3D6.hpp>

using namespace LDL;

TextureImplDirect3D6::TextureImplDirect3D6(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_renderContextImpl(renderContextImpl)
{
}

TextureImplDirect3D6::TextureImplDirect3D6(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t bytesPerPixel) :
	_renderContextImpl(renderContextImpl)
{
}

TextureImplDirect3D6::~TextureImplDirect3D6()
{
}

void TextureImplDirect3D6::Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel)
{
}

void TextureImplDirect3D6::Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize)
{
	Copy(dstPos, srcSize, surface->Pixels(), surface->BytesPerPixel());
}

const Vec2u& TextureImplDirect3D6::Size()
{
	return _size;
}

const Vec2u& TextureImplDirect3D6::Quad()
{
	return _quad;
}
