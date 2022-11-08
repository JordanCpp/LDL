#ifndef LDL_Graphics_DX5Render_hpp
#define LDL_Graphics_DX5Render_hpp

#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/DX5/DX5Window.hpp>
#include <LDL/Graphics/DX5/DX5Image.hpp>
#include <LDL/Graphics/Cpu/CpuImage.hpp>

#include <windows.h>
#include <ddraw.h>
#include <d3d.h>    
#include <d3drm.h> 

namespace LDL
{
	namespace Graphics
	{
		class DX5Render
		{
		public:
			DX5Render(LDL::Graphics::DX5Window* window);
			~DX5Render();
			void Begin();
			void End();
			const LDL::Graphics::Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Pixel(const LDL::Graphics::Point2u& pos);
			void Fill(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Line(const LDL::Graphics::Point2u& pos1, const LDL::Graphics::Point2u& pos2);
			void Draw(LDL::Graphics::DX5Image* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Draw(LDL::Graphics::DX5Image* image, const LDL::Graphics::Point2u& pos);
			void Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos);
		private:
			LDL::Graphics::DX5Window* _Window;
			LDL::Graphics::BaseRender _BaseRender;
			LPDIRECT3DRM _Direct3Drm = NULL;
			LPDIRECTDRAWCLIPPER _DirectDrawClipper = NULL;
			LPDIRECT3DRMDEVICE _Direct3DrmDevice = NULL;
			GUID* _GUID = NULL;
		};
	}
}

#endif    