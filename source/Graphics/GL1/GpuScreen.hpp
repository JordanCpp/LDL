#ifndef LDL_Graphics_GpuScreen_hpp
#define LDL_Graphics_GpuScreen_hpp

#include <LDL/Graphics/Cpu/CpuImage.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GpuScreen
		{
		public:
			GpuScreen(const Point2u& size);
			~GpuScreen();
			
			void Draw(CpuImage* image, const Point2u& pos, const Point2u& size);
			void Draw(CpuImage* image, const Point2u& pos);
		private:
			void DrawTexture(CpuImage* image, const Point2u& pos, const Point2u& size);
			void DrawPixels(CpuImage* image, const Point2u& pos, const Point2u& size);
			Point2u _Size;
			size_t _Screen;
			size_t _MaxTextureSize;
		};
	}
}

#endif    