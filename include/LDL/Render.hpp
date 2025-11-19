// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Impls_RenderImpl_hpp
#define LDL_Graphics_Impls_RenderImpl_hpp

#include <LDL/Texture.hpp>
#include <LDL/Surface.hpp>
#include <LDL/Batcher.hpp>
#include <LDL/Window.hpp>

class LDL_IRender
{
public:
	virtual ~LDL_IRender() {};
	virtual void Buffer(uint8_t* dst) = 0;
	virtual void Begin() = 0;
	virtual void End() = 0;
	virtual const LDL_Vec2u& Size() = 0;
	virtual const LDL_Color& GetColor() = 0;
	virtual void Clear() = 0;
	virtual void SetColor(const LDL_Color& color) = 0;
	virtual void Pixel(const LDL_Vec2u& pos) = 0;
	virtual void Fill(const LDL_Vec2u& pos, const LDL_Vec2u& size) = 0;
	virtual void Line(const LDL_Vec2u& pos1, const LDL_Vec2u& pos2) = 0;
	virtual void Draw(LDL_ITexture* image, const LDL_Vec2u& pos) = 0;
	virtual void Draw(LDL_ITexture* image, const LDL_Vec2u& pos, const LDL_Vec2u& size) = 0;
	virtual void Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize) = 0;
	virtual void Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize) = 0;
	virtual void Draw(LDL_Surface* image, const LDL_Vec2u& pos) = 0;
	virtual void Draw(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size) = 0;
	virtual void Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize) = 0;
	virtual void Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize) = 0;
	virtual void Draw(LDL_ISpriteBatcher* textureBatcher) = 0;
};

LDL_IRender* LDL_CreateRender(LDL_Result& result, LDL_RenderContext& renderContext, LDL_IWindow* window);

#endif    
