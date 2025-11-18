// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL3_RenderImpl_hpp
#define LDL_Graphics_OpenGL3_RenderImpl_hpp

#include "../../BaseRender.hpp"
#include <LDL/Graphics/Window.hpp>
#include "TextureImplOpenGL3.hpp"
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Math/Mat4.hpp>
#include "LinePainterOpenGL3.hpp"
#include "TexturePainterOpenGL3.hpp"
#include <LDL/Graphics/SpriteBatcher.hpp>
#include <LDL/Graphics/Render.hpp>

namespace LDL
{
	class RenderImplOpenGL3 : public IRender
	{
	public:
		RenderImplOpenGL3(Result& result, RenderContext* renderContextImpl, IWindow* window);
		void Buffer(uint8_t* dst);
		void Begin();
		void End();
		const Vec2u& Size();
		const Color& GetColor();
		void Clear();
		void SetColor(const Color& color);
		void Pixel(const Vec2u& pos);
		void Fill(const Vec2u& pos, const Vec2u& size);
		void Line(const Vec2u& pos1, const Vec2u& pos2);
		void Draw(ITexture* image, const Vec2u& pos);
		void Draw(ITexture* image, const Vec2u& pos, const Vec2u& size);
		void Draw(ITexture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(ITexture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(Surface* image, const Vec2u& pos);
		void Draw(Surface* image, const Vec2u& pos, const Vec2u& size);
		void Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(SpriteBatcher* textureBatcher);
	private:
		Result& _result;
		IWindow* _window;
		LDL::Color _color;
		Mat4f     _projection;
		ShaderLoader    _shaderLoader;
		LinePainter     _linePainter;
		TexturePainter  _texturePainter;
	public:
		Mat4f     _Projection;
		Mat4f     _ModelView;
	};
}

#endif    
