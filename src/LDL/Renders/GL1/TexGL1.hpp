// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Renders_GL1_TexGL1_hpp
#define LDL_Renders_GL1_TexGL1_hpp

#include <LDL/Texture.hpp>
#include <LDL/Context.hpp>

class LDL_IRender;

class LDL_TextureOpenGL1 : public LDL_ITexture
{
public:
	LDL_TextureOpenGL1(LDL_RenderContext* renderContextImpl, LDL_Surface* surface);
	LDL_TextureOpenGL1(LDL_RenderContext* renderContextImpl, size_t pixelFormat, const LDL_Vec2u& size, uint8_t* pixels);
	LDL_TextureOpenGL1(LDL_RenderContext* renderContextImpl, size_t pixelFormat, const LDL_Vec2u& size);
	~LDL_TextureOpenGL1();
	void Copy(const LDL_Vec2u& dstPos, const LDL_Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel);
	void Copy(const LDL_Vec2u& dstPos, LDL_Surface* surface, const LDL_Vec2u& srcSize);
	const LDL_Vec2u& Size();
	const LDL_Vec2u& Quad();
	size_t Id();
private:
	LDL_RenderContext* _context;
	size_t             _id;
	LDL_Vec2u          _size;
	LDL_Vec2u          _quad;
};

#endif    
