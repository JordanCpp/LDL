#ifndef LDL_Graphics_DX9Render_hpp
#define LDL_Graphics_DX9Render_hpp

#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/DX9/DX9Window.hpp>
#include <LDL/Graphics/DX9/DX9Image.hpp>
#include <LDL/Graphics/Cpu/CpuImage.hpp>

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

namespace LDL
{
	namespace Graphics
	{
		class DX9Render
		{
		public:
			DX9Render(LDL::Graphics::DX9Window* window);
			~DX9Render();
			void Begin();
			void End();
			const LDL::Graphics::Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Pixel(const LDL::Graphics::Point2u& pos);
			void Fill(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Line(const LDL::Graphics::Point2u& pos1, const LDL::Graphics::Point2u& pos2);
			void Draw(LDL::Graphics::DX9Image* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Draw(LDL::Graphics::DX9Image* image, const LDL::Graphics::Point2u& pos);
			void Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos);
		private:
			LDL::Graphics::DX9Window* _Window;
			LDL::Graphics::BaseRender _BaseRender;
			IDirect3D9* _Direct3D = NULL;
			IDirect3DDevice9* _Direct3DDevice = NULL;
			ID3DXLine* _Line = NULL;
		};
	}
}

#endif    