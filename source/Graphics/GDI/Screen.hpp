#ifndef LDL_Graphics_GDI_Screen_hpp
#define LDL_Graphics_GDI_Screen_hpp

#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class Screen
		{
		public:
			Screen(const Point2u& size);
			~Screen();
			void Draw(Surface* image, const Point2u& pos, const Point2u& size);
			void Draw(Surface* image, const Point2u& pos);
		private:
			void DrawTexture(Surface* image, const Point2u& pos, const Point2u& size);
			void DrawPixels(Surface* image, const Point2u& pos, const Point2u& size);
			Point2u _Size;
		};
	}
}

#endif    