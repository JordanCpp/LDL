#ifndef LDL_Graphics_VideoMode_hpp
#define LDL_Graphics_VideoMode_hpp

#include <LDL/Config.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_EXPORT VideoMode
		{
		public:
			enum
			{
				Limit = 32
			};
			VideoMode();
			VideoMode(const Point2u& size, size_t bytesPerPixel);
			const Point2u& Size();
			size_t BitsPerPixel();
		private:
			Point2u _Size;
			size_t _BitsPerPixel;
		};
	}
}

#endif    