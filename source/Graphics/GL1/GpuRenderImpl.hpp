#ifndef LDL_Graphics_GpuRenderImpl_hpp
#define LDL_Graphics_GpuRenderImpl_hpp

#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/GpuWindow.hpp>
#include "GL1Image.hpp"
#include "GL1Screen.hpp"

namespace LDL
{
	namespace Graphics
	{
		class GpuRenderImpl
		{
		public:
			GpuRenderImpl(LDL::Graphics::GpuWindow* window);
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
			LDL::Graphics::GpuWindow* _Window;
			LDL::Graphics::BaseRender _BaseRender;
			LDL::Graphics::GL1Screen _Screen;
		};
	}
}

#endif    