#ifndef LDL_Graphics_GDI_TextureImpl_hpp
#define LDL_Graphics_GDI_TextureImpl_hpp

#include "RenderImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl;

		class TextureImpl
		{
		public:
			TextureImpl(RenderImpl* renderImpl, const Point2u & size, uint8_t* pixels, size_t bytesPerPixel);
			~TextureImpl();
			const Point2u& Size();
		private:
			Point2u _Size;
		};
	}
}

#endif    