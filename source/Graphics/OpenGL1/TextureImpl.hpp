#ifndef LDL_Graphics_OpenGL1_TextureImpl_hpp
#define LDL_Graphics_OpenGL1_TextureImpl_hpp

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
			size_t Id();
		private:
			RenderImpl* _RenderImpl;
			size_t _Id;
			Point2u _Size;
		};
	}
}

#endif    