#ifndef LDL_Graphics_DirectX9_Direct3D_RenderImpl_hpp
#define LDL_Graphics_DirectX9_Direct3D_RenderImpl_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Base/BaseRender.hpp>

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl
		{
		public:
			RenderImpl(RenderContextImpl* renderContextImpl, Window* window);
			~RenderImpl();
			void RenderImpl::Buffer(uint8_t* dst);
			void Mode2D();
			void Begin();
			void End();
			const Math::Vec2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Pixel(const Math::Vec2u& pos);
			void Fill(const Math::Vec2u& pos, const Math::Vec2u& size);
			void Line(const Math::Vec2u& pos1, const Math::Vec2u& pos2);
			void Draw(Texture* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Texture* image, const Math::Vec2u& pos);
			void Draw(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Surface* image, const Math::Vec2u& pos);
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
		private:
			void Initialization();
			void Deinitialization();
			Window* _Window;
			BaseRender _BaseRender;
			ID3DXLine* _Line;
		public:
			RenderContextImpl* _RenderContextImpl;
			IDirect3DVertexBuffer9* _VertexBuffer;
		};
	}
}

#endif    