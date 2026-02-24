// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Direct3D6_RenderImpl_hpp
#define LDL_Graphics_Direct3D6_RenderImpl_hpp

#include "../../Base/BaseRender.hpp"
#include <LDL/Graphics/Window.hpp>
#include "TextureImplDirect3D6.hpp"
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/TextureBatcher.hpp>
#include <LDL/Math/Mat4.hpp>
#include "../../Impls/RenderImpl.hpp"
#include <LDL/APIs/DirectX6/DirectX6Loader.hpp>

namespace LDL
{
	class RenderImplDirect3D6 : public RenderImpl
	{
	public:
		void InitDirectDraw();
		void InitSurfaces();
		void InitDirect3D();
		void InitViewport();
		RenderImplDirect3D6(RenderContextImpl* renderContextImpl, Window* window);
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
		void Draw(Texture* image, const Vec2u& pos);
		void Draw(Texture* image, const Vec2u& pos, const Vec2u& size);
		void Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Draw(TextureBatcher* textureBatcher);
	private:
		DirectX6::DirectX6Loader       _directX6Loader;
		Window*                        _window;
		Color                          _color;
		RenderContextImpl*             _renderContextImpl;
		DirectX6::LPDIRECTDRAW         g_pDD1;
		DirectX6::LPDIRECTDRAW4        g_pDD4;
		DirectX6::LPDIRECTDRAWSURFACE4 g_pddsPrimary;
		DirectX6::LPDIRECTDRAWSURFACE4 g_pddsBackBuffer;
		DirectX6::LPDIRECT3D3          g_pD3D;
		DirectX6::LPDIRECT3DDEVICE3    g_pd3dDevice;
		DirectX6::LPDIRECT3DVIEWPORT3  g_pvViewport;
	};
}

#endif    
