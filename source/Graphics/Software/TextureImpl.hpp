#ifndef LDL_Graphics_Software_TextureImpl_hpp
#define LDL_Graphics_Software_TextureImpl_hpp

#include "RenderImpl.hpp"
#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl;

		class TextureImpl
		{
		public:
			TextureImpl(RenderImpl* renderImpl, const Point2u & size, uint8_t* pixels, uint8_t bytesPerPixel);
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