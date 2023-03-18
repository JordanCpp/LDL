#ifndef LDL_Graphics_DirectX9_Direct3D_TextureImpl_hpp
#define LDL_Graphics_DirectX9_Direct3D_TextureImpl_hpp

#include "RenderImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl
		{
		public:
			TextureImpl(RenderImpl* renderImpl, const Point2u & size, uint8_t* pixels, size_t bytesPerPixel);
			~TextureImpl();
			const Point2u& Size();
			const size_t Id();
		private:
			IDirect3DTexture9* _Texture;
			Point2u _Size;
		};
	}
}

#endif    