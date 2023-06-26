#ifndef LDL_Graphics_OpenGL3_Screen_hpp
#define LDL_Graphics_OpenGL3_Screen_hpp

#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class ScreenOpenGL3
		{
		public:
			ScreenOpenGL3(const Math::Vec2u& size);
			~ScreenOpenGL3();
			void Draw(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Surface* image, const Math::Vec2u& pos);
		private:
			void DrawTexture(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void DrawPixels(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			LDL::Math::Vec2u _Size;
		};
	}
}

#endif    