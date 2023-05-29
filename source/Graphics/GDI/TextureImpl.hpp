#ifndef LDL_Graphics_GDI_TextureImpl_hpp
#define LDL_Graphics_GDI_TextureImpl_hpp

#include "RenderContextImpl.hpp"
#include <LDL/Graphics/Primitives/LDL::Math::Vec2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl;

		class TextureImpl
		{
		public:
			TextureImpl(RenderContextImpl* renderContextImpl, const LDL::Math::Vec2u & size, uint8_t* pixels, size_t bytesPerPixel);
			~TextureImpl();
			const Math::Vec2u& Size();
		private:
			LDL::Math::Vec2u _Size;
		};
	}
}

#endif    