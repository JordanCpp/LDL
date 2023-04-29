#ifndef Arcanum_Graphics_Sprite_hpp
#define Arcanum_Graphics_Sprite_hpp

#include <Arcanum/Graphics/Image.hpp>
#include <vector>

namespace Arcanum
{
	namespace Graphics
	{
		class Sprite
		{
		public:
		private:
			std::vector<Image*> _Images;
		};
	}
}

#endif    