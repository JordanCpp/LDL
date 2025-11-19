// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Impls_TextureImpl_hpp
#define LDL_Graphics_Impls_TextureImpl_hpp

#include <LDL/Surface.hpp>
#include <LDL/Context.hpp>

class LDL_ITexture
{
public:
	virtual ~LDL_ITexture() {};
	virtual void Copy(const LDL_Vec2u& dstPos, const LDL_Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel) = 0;
	virtual void Copy(const LDL_Vec2u& dstPos, LDL_Surface* surface, const LDL_Vec2u& srcSize) = 0;
	virtual const LDL_Vec2u& Size() = 0;
	virtual const LDL_Vec2u& Quad() = 0;
};

LDL_ITexture* LDL_CreateTexture(LDL_RenderContext* renderContext, size_t pixelFormat, const LDL_Vec2u& size, uint8_t* pixels);
LDL_ITexture* LDL_CreateTexture(LDL_RenderContext* renderContext, size_t pixelFormat, const LDL_Vec2u& size);
LDL_ITexture* LDL_CreateTexture(LDL_RenderContext* renderContext, LDL_Surface* surface);

#endif    
