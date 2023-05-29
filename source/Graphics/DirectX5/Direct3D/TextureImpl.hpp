#ifndef LDL_Graphics_DirectX5_Direct3D_TextureImpl_hpp
#define LDL_Graphics_DirectX5_Direct3D_TextureImpl_hpp

#include "RenderImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl
		{
		public:
			TextureImpl(RenderImpl* renderImpl, const LDL::Graphics::LDL::Math::Vec2u & size, uint8_t* pixels, size_t bytesPerPixel);
			~TextureImpl();
			const LDL::Graphics::LDL::Math::Vec2u& Size();
			const size_t Id();
		private:
			size_t _Id;
			LDL::Graphics::LDL::Math::Vec2u _Size;
		};
	}
}

#endif    