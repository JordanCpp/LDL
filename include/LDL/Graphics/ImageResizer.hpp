#ifndef LDL_Graphics_ImageResizer_hpp
#define LDL_Graphics_ImageResizer_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_EXPORT ImageResizer
		{
		public:
			ImageResizer(const Math::Vec2u& size);
			Surface* Resize(const Math::Vec2u& size, Surface* surface);
		private:
			Surface _Surface;
		};
	}
}

#endif    