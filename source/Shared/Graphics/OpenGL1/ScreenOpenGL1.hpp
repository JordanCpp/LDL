#ifndef LDL_Graphics_OpenGL1_Screen_hpp
#define LDL_Graphics_OpenGL1_Screen_hpp

#include <LDL/Graphics/Surface.hpp>
#include "../Utils/PotTextureSizer.hpp"

namespace LDL
{
	namespace Graphics
	{
		class ScreenOpenGL1
		{
		public:
			ScreenOpenGL1(const Math::Vec2u& size);
			~ScreenOpenGL1();
			void Draw(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Surface* image, const Math::Vec2u& pos);
		private:
			void DrawTexture(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void DrawPixels(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			LDL::Math::Vec2u _Size;
			size_t _Screen;
			size_t _MaxTextureSize;
			size_t _CurTextureSize;
			Utils::PotTextureSizer _PotTextureSizer;
		};
	}
}

#endif    