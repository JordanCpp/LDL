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
			TextureImpl(RenderContextImpl* renderContextImpl, const LDL::Math::Vec2u & size, uint8_t* pixels, uint8_t bytesPerPixel);
			TextureImpl(RenderContextImpl* renderContextImpl, const Math::Vec2u& size, size_t bytesPerPixel);
			~TextureImpl();
			void Copy(const Math::Vec2u& dstPos, const Math::Vec2u& srcSize, uint8_t* pixels, size_t bytesPerPixel);
			void Copy(const Math::Vec2u& dstPos, Surface* surface, const Math::Vec2u& srcSize);
			const Math::Vec2u& Size();
			Surface* GetSurface();
		private:
			LDL::Math::Vec2u _Size;
			Surface _Surface;
		};
	}
}

#endif    