#ifndef Arcanum_Graphics_Sprite_hpp
#define Arcanum_Graphics_Sprite_hpp

#include <LDL/Graphics/Texture.hpp>

namespace Arcanum
{
	namespace Graphics
	{
		class Sprite
		{
		public:
		private:
			LDL::Graphics::Texture _Texture;
			LDL::Graphics::Point2u _Pos;
		};
	}
}

#endif    