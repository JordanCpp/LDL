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
			~Sprite();
			void Append(Image* image);
			Image* GetImage(size_t index);
			Image* Single();
		private:
			std::vector<Image*> _images;
		};
	}
}

#endif    