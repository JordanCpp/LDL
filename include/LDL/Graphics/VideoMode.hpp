#ifndef LDL_Graphics_VideoMode_hpp
#define LDL_Graphics_VideoMode_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class VideoMode
		{
		public:
			enum
			{
				Limit = 32
			};
			VideoMode();
			VideoMode(const LDL::Graphics::Point2u& size, size_t bytesPerPixel);
			const LDL::Graphics::Point2u& Size();
			size_t BitsPerPixel();
		private:
			LDL::Graphics::Point2u _Size;
			size_t _BitsPerPixel;
		};
	}
}

#endif    