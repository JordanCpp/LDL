// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Software_TextureImpl_hpp
#define LDL_Graphics_Software_TextureImpl_hpp

#include <LDL/Surface.hpp>
#include <LDL/Texture.hpp>
#include <LDL/Context.hpp>

class LDL_IRender;

class TextureImplSoftware : public LDL_ITexture
{
public:
	TextureImplSoftware(LDL_RenderContext* renderContextImpl, size_t pixelFormat, const LDL_Vec2u& size, uint8_t* pixels);
	TextureImplSoftware(LDL_RenderContext* renderContextImpl, size_t pixelFormat, const LDL_Vec2u& size);
	~TextureImplSoftware();
	void Copy(const LDL_Vec2u& dstPos, const LDL_Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel);
	void Copy(const LDL_Vec2u& dstPos, LDL_Surface* surface, const LDL_Vec2u& srcSize);
	const LDL_Vec2u& Size();
	const LDL_Vec2u& Quad();
	LDL_Surface* GetSurface();
private:
	LDL_Vec2u       _size;
	LDL_Surface _surface;
};

#endif    
