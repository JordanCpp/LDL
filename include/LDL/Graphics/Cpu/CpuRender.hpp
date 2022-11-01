#ifndef LDL_Graphics_CpuRender_hpp
#define LDL_Graphics_CpuRender_hpp

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
			CpuRender(LDL::Graphics::CpuWindow* window, LDL::Graphics::CpuImage* canvas);
			const LDL::Graphics::Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Present();
			LDL::Graphics::CpuImage* Canvas();
			void Pixel(const LDL::Graphics::Point2u& pos);
			const LDL::Graphics::Color& GetPixel(const LDL::Graphics::Point2u& pos);
			void Fill(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Rect(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Line(const LDL::Graphics::Point2u& pos1, const LDL::Graphics::Point2u& pos2);
			uint8_t* Pixels();
			size_t BytesPerPixel();
			void Draw(LDL::Graphics::CpuImage& image, const LDL::Graphics::Point2u& pos);
		private:
			LDL::Graphics::CpuWindow* _Window;
			LDL::Graphics::BaseRender _BaseRender;
			LDL::Graphics::CpuImage* _Canvas;
		};
	}
}

#endif    