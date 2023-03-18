#ifndef LDL_Graphics_DirectX5_Direct3D_RenderImpl_hpp
#define LDL_Graphics_DirectX5_Direct3D_RenderImpl_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Base/BaseRender.hpp>

#include <windows.h>
#include <ddraw.h>
#include <d3d.h>    
#include <d3drm.h> 

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl
		{
		public:
			RenderImpl(Window* window);
			~RenderImpl();
			void Buffer(uint8_t* dst);
			void Begin();
			void End();
			const Point2u& Size();
			const Color& Color();
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
			LDL::Graphics::Window* _Window;
			LDL::Graphics::BaseRender _BaseRender;
			LPDIRECT3DRM _Direct3Drm = NULL;
			LPDIRECTDRAWCLIPPER _DirectDrawClipper = NULL;
			LPDIRECT3DRMDEVICE _Direct3DrmDevice = NULL;
			GUID* _GUID = NULL;
		};
	}
}

#endif    