#ifndef LDL_Graphics_DirectDraw1_TextureImpl_hpp
#define LDL_Graphics_DirectDraw1_TextureImpl_hpp

#include "RenderImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl
		{
		public:
			TextureImpl(RenderImpl* renderImpl, const LDL::Math::Vec2u & size, uint8_t* pixels, size_t bytesPerPixel);
			~TextureImpl();
			const Math::Vec2u& Size();
			size_t Id();
		private:
			size_t _Id;
			LDL::Math::Vec2u _Size;
		};
	}
}

#endif    