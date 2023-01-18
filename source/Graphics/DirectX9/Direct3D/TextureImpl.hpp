#ifndef LDL_Graphics_DirectX9_Direct3D_TextureImpl_hpp
#define LDL_Graphics_DirectX9_Direct3D_TextureImpl_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl
		{
		public:
			TextureImpl(const Point2u & size, size_t bytesPerPixel, uint8_t* pixels);
			~TextureImpl();
			const Point2u& Size();
			const size_t Id();
		private:
			Point2u _Size;
		};
	}
}

#endif    