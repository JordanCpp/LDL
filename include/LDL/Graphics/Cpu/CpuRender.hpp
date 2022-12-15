#ifndef LDL_Graphics_Cpu_CpuRender_hpp
#define LDL_Graphics_Cpu_CpuRender_hpp

#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/Cpu/CpuWindow.hpp>
#include <LDL/Graphics/Cpu/CpuImage.hpp>

namespace LDL
{
	namespace Graphics
	{
		class CpuRender
		{
		public:
			CpuRender(CpuWindow* window);
			const Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Present();
			CpuImage* Canvas();
			void Pixel(const Point2u& pos);
			const LDL::Graphics::Color& GetPixel(const Point2u& pos);
			void Fill(const Point2u& pos, const Point2u& size);
			void Rect(const Point2u& pos, const Point2u& size);
			void Line(const Point2u& pos1, const Point2u& pos2);
			uint8_t* Pixels();
			size_t BytesPerPixel();
			void Draw(CpuImage& image, const Point2u& pos);
		private:
			CpuWindow* _Window;
			BaseRender _BaseRender;
			CpuImage _Canvas;
		};
	}
}

#endif    