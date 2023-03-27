#ifndef LDL_Graphics_DirectX9_Direct3D_TextureImpl_hpp
#define LDL_Graphics_DirectX9_Direct3D_TextureImpl_hpp

#include "RenderContextImpl.hpp"
#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <d3d9.h>
#include <d3dx9.h>

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl
		{
		public:
			TextureImpl(RenderContextImpl* renderContextImpl, const Point2u & size, uint8_t* pixels, size_t bytesPerPixel);
			~TextureImpl();
			const Point2u& Size();
			IDirect3DTexture9* Texture();
		private:
			IDirect3DTexture9* _Texture;
			Point2u _Size;
		};
	}
}

#endif    