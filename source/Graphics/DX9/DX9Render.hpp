#ifndef LDL_Graphics_DX9Render_hpp
#define LDL_Graphics_DX9Render_hpp

#include <LDL/Graphics/IGpuRender.hpp>
#include <LDL/Graphics/IGpuWindow.hpp>
#include <LDL/Graphics/IGpuImage.hpp>
#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/Cpu/CpuImage.hpp>

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

namespace LDL
{
	namespace Graphics
	{
		class DX9Render: public LDL::Graphics::IGpuRender
		{
		public:
			DX9Render(LDL::Graphics::IGpuWindow* window);
			~DX9Render();
			void Mode2D();
			void Begin();
			void End();
			const LDL::Graphics::Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Pixel(const LDL::Graphics::Point2u& pos);
			void Fill(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Line(const LDL::Graphics::Point2u& pos1, const LDL::Graphics::Point2u& pos2);
			void Draw(LDL::Graphics::IGpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Draw(LDL::Graphics::IGpuImage* image, const LDL::Graphics::Point2u& pos);
			void Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos);
		private:
			void Initialization();
			void Deinitialization();
			LDL::Graphics::IGpuWindow* _Window;
			LDL::Graphics::BaseRender _BaseRender;
			IDirect3D9* _Direct3D = NULL;
			IDirect3DDevice9* _Direct3DDevice = NULL;
			ID3DXLine* _Line = NULL;
		};
	}
}

#endif    