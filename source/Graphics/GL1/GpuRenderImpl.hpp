#ifndef LDL_Graphics_GpuRenderImpl_hpp
#define LDL_Graphics_GpuRenderImpl_hpp

#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/Gpu/GpuWindow.hpp>
#include "GpuImageImpl.hpp"
#include "GL1Screen.hpp"
#include <LDL/Graphics/Gpu/GpuImage.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GpuRenderImpl
		{
		public:
			GpuRenderImpl(GpuWindow* window);
			void Begin();
			void End();
			const Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Pixel(const Point2u& pos);
			void Fill(const Point2u& pos, const Point2u& size);
			void Line(const Point2u& pos1, const Point2u& pos2);
			void Draw(GpuImage* image, const Point2u& pos, const Point2u& size);
			void Draw(GpuImage* image, const Point2u& pos);
			void Draw(CpuImage* image, const Point2u& pos, const Point2u& size);
			void Draw(CpuImage* image, const Point2u& pos);
			void Draw(GpuImage* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize);
		private:
			GpuWindow* _Window;
			BaseRender _BaseRender;
			GL1Screen _Screen;
		};
	}
}

#endif    