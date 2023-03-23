#ifndef LDL_Graphics_ImageResizer_hpp
#define LDL_Graphics_ImageResizer_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_EXPORT ImageResizer
		{
		public:
			ImageResizer(const Point2u& size);
			Surface* Resize(const Point2u& size, Surface* surface);
		private:
			Surface _Surface;
		};
	}
}

#endif    