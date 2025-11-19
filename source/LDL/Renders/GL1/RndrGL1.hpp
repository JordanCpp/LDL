// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL1_RenderImpl_hpp
#define LDL_Graphics_OpenGL1_RenderImpl_hpp

#include <LDL/Mat4.hpp>
#include <LDL/Window.hpp>
#include <LDL/Texture.hpp>
#include <LDL/Batcher.hpp>
#include <LDL/BaseRndr.hpp>
#include <LDL/Render.hpp>
#include <LDL/Renders/GL1/ScrnGL1.hpp>
#include <LDL/Renders/GL1/TexGL1.hpp>
#include <LDL/Renders/GL1/BufGL1.hpp>

class RenderImplOpenGL1 : public LDL_IRender
{
public:
	RenderImplOpenGL1(LDL_Result& result, LDL_RenderContext* renderContextImpl, LDL_IWindow* window);
	void Buffer(uint8_t* dst);
	void Begin();
	void End();
	const LDL_Vec2u& Size();
	const LDL_Color& GetColor();
	void Clear();
	void SetColor(const LDL_Color& color);
	void Pixel(const LDL_Vec2u& pos);
	void Fill(const LDL_Vec2u& pos, const LDL_Vec2u& size);
	void Line(const LDL_Vec2u& pos1, const LDL_Vec2u& pos2);
	void Draw(LDL_Surface* image, const LDL_Vec2u& pos);
	void Draw(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size);
	void Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void Draw(LDL_ITexture* image, const LDL_Vec2u& pos);
	void Draw(LDL_ITexture* image, const LDL_Vec2u& pos, const LDL_Vec2u& size);
	void Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void Draw(LDL_ISpriteBatcher* textureBatcher);
private:
	LDL_Result& _result;
	LDL_IWindow* _window;
	ScreenOpenGL1      _screen;
	LDL_Color         _color;
	LDL_RenderContext* _context;
	RenderBuffer       _renderBuffer;
public:
	Mat4f              _projection;
	Mat4f              _modelView;
};

#endif    
