#ifndef LDL_Graphics_Software_TextureImpl_hpp
#define LDL_Graphics_Software_TextureImpl_hpp

#include "RenderContextImpl.hpp"
#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl;

		class TextureImpl
		{
		public:
			TextureImpl(RenderContextImpl* renderContextImpl, const Point2u & size, uint8_t* pixels, uint8_t bytesPerPixel);
			TextureImpl(RenderContextImpl* renderContextImpl, const Point2u& size, size_t bytesPerPixel);
			~TextureImpl();
			void Copy(const Point2u& dstPos, const Point2u& srcSize, uint8_t* pixels, size_t bytesPerPixel);
			void Copy(const Point2u& dstPos, Surface* surface, const Point2u& srcSize);
			const Point2u& Size();
			Surface* GetSurface();
		private:
			Point2u _Size;
			Surface _Surface;
		};
	}
}

#endif    