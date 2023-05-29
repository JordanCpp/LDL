#ifndef LDL_Graphics_DirectX9_Direct3D_TextureImpl_hpp
#define LDL_Graphics_DirectX9_Direct3D_TextureImpl_hpp

#include "RenderContextImpl.hpp"
#include <LDL/Graphics/Primitives/LDL::Math::Vec2u.hpp>
#include <d3d9.h>
#include <d3dx9.h>

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl
		{
		public:
			TextureImpl(RenderContextImpl* renderContextImpl, const LDL::Math::Vec2u & size, uint8_t* pixels, size_t bytesPerPixel);
			~TextureImpl();
			const Math::Vec2u& Size();
			IDirect3DTexture9* Texture();
		private:
			IDirect3DTexture9* _Texture;
			LDL::Math::Vec2u _Size;
		};
	}
}

#endif    