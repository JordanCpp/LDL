// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Renders_GL3_RndrGL3_hpp
#define LDL_Renders_GL3_RndrGL3_hpp

#include <LDL/BaseRndr.hpp>
#include <LDL/Window.hpp>
#include <LDL/Mat4.hpp>
#include <LDL/Texture.hpp>
#include <LDL/Render.hpp>
#include <LDL/Batcher.hpp>
#include <LDL/Renders/GL3/TexGL3.hpp>
#include <LDL/Renders/GL3/LineGL3.hpp>
#include <LDL/Renders/GL3/PaintGL3.hpp>

class LDL_RenderOpenGL3 : public LDL_IRender
{
public:
	LDL_RenderOpenGL3(LDL_Result& result, LDL_RenderContext* renderContextImpl, LDL_IWindow* window);
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
	void Draw(LDL_ITexture* image, const LDL_Vec2u& pos);
	void Draw(LDL_ITexture* image, const LDL_Vec2u& pos, const LDL_Vec2u& size);
	void Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void Draw(LDL_Surface* image, const LDL_Vec2u& pos);
	void Draw(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size);
	void Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void Draw(LDL_ISpriteBatcher* textureBatcher);
private:
	LDL_Result&                _result;
	LDL_IWindow*               _window;
	LDL_Color                  _color;
	LDL_Mat4f                  _projection;
	LDL_ShaderLoaderOpenGL3    _shaderLoader;
	LDL_LinePainterOpenGL3     _linePainter;
	LDL_TexturePainterOpenGL3  _texturePainter;
public:
	LDL_Mat4f                  _Projection;
	LDL_Mat4f                  _ModelView;
};

#endif    
