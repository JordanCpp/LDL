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
	namespace Graphics
	{
		class RenderImplDirect3D6: public RenderImpl
		{
		public:
			void InitDirectDraw();
			void InitSurfaces();
			void InitDirect3D();
			void InitViewport();
			RenderImplDirect3D6(RenderContextImpl* renderContextImpl, Window* window);
			void Buffer(uint8_t * dst);
			void Begin();
			void End();
			const Math::Vec2u& Size();
			const Graphics::Color& Color();
			void Clear();
			void Color(const Graphics::Color& color);
			void Pixel(const Math::Vec2u& pos);
			void Fill(const Math::Vec2u& pos, const Math::Vec2u& size);
			void Line(const Math::Vec2u& pos1, const Math::Vec2u& pos2);
			void Draw(Surface* image, const Math::Vec2u& pos);
			void Draw(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Surface* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Surface* image, const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Texture* image, const Math::Vec2u& pos);
			void Draw(Texture* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(TextureBatcher* textureBatcher);
		private:
			DirectX6::DirectX6Loader       _directX6Loader;
			Window*                        _window;
			Graphics::Color                _color;
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
}

#endif    
