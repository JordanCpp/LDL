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
			RenderImpl(Window* window);
			~RenderImpl();
			void RenderImpl::Buffer(uint8_t* dst);
			void Mode2D();
			void Begin();
			void End();
			const Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Pixel(const Point2u& pos);
			void Fill(const Point2u& pos, const Point2u& size);
			void Line(const Point2u& pos1, const Point2u& pos2);
			void Draw(Texture* image, const Point2u& pos, const Point2u& size);
			void Draw(Texture* image, const Point2u& pos);
			void Draw(Surface* image, const Point2u& pos, const Point2u& size);
			void Draw(Surface* image, const Point2u& pos);
			void Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize);
		private:
			void Initialization();
			void Deinitialization();
			Window* _Window;
			BaseRender _BaseRender;
			ID3DXLine* _Line;
		public:
			IDirect3D9* _Direct3D;
			IDirect3DDevice9* _Direct3DDevice;
			IDirect3DVertexBuffer9* _VertexBuffer;
		};
	}
}

#endif    