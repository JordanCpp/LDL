// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL1_RenderImpl_hpp
#define LDL_Graphics_OpenGL1_RenderImpl_hpp

#include <LDL/Math/Mat4.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/SpriteBatcher.hpp>
#include <LDL/Shared/Graphics/BaseRender.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/ScreenOpenGL1.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/TextureImplOpenGL1.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/RenderBufferOpenGL1.hpp>

namespace LDL
{
	class RenderImplOpenGL1 : public IRender
	{
	public:
		RenderImplOpenGL1(Result& result, RenderContext* renderContextImpl, IWindow* window);
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
		void Draw(Surface* image, const Vec2u& pos);
		void Draw(Surface* image, const Vec2u& pos, const Vec2u& size);
		void Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(ITexture* image, const Vec2u& pos);
		void Draw(ITexture* image, const Vec2u& pos, const Vec2u& size);
		void Draw(ITexture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(ITexture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(SpriteBatcher* textureBatcher);
	private:
		Result&            _result;
		IWindow*            _window;
		ScreenOpenGL1      _screen;
		LDL::Color         _color;
		RenderContext* _renderContextImpl;
		RenderBuffer       _renderBuffer;
	public:
		Mat4f              _projection;
		Mat4f              _modelView;
	};
}

#endif    
