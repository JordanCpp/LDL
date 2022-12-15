#ifndef LDL_Graphics_GL1Screen_hpp
#define LDL_Graphics_GL1Screen_hpp

#include <LDL/Graphics/Cpu/CpuImage.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GL1Screen
		{
		public:
			GL1Screen(const Point2u& size);
			~GL1Screen();
			void Draw(CpuImage* image, const Point2u& pos, const Point2u& size);
			void Draw(CpuImage* image, const Point2u& pos);
		private:
			Point2u _Size;
			size_t _Screen;
		};
	}
}

#endif    