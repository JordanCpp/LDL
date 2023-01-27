#ifndef LDL_Graphics_Software_TextureImpl_hpp
#define LDL_Graphics_Software_TextureImpl_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl
		{
		public:
			TextureImpl(const Point2u & size, uint8_t* pixels, uint8_t bytesPerPixel);
			~TextureImpl();
			const Point2u& Size();
			Surface* GetSurface();
		private:
			Point2u _Size;
			Surface _Surface;
		};
	}
}

#endif    