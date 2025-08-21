#ifndef LDL_Graphics_Software_TextureImpl_hpp
#define LDL_Graphics_Software_TextureImpl_hpp

#include "RenderContextImplSoftware.hpp"
#include <LDL/Graphics/Surface.hpp>
#include "../../Impls/TextureImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl;

		class TextureImplSoftware : public TextureImpl
		{
		public:
			TextureImplSoftware(RenderContextImpl* renderContextImpl, const LDL::Math::Vec2u & size, uint8_t* pixels, uint8_t bytesPerPixel);
			TextureImplSoftware(RenderContextImpl* renderContextImpl, const Math::Vec2u& size, uint8_t bytesPerPixel);
			~TextureImplSoftware();
			void Copy(const Math::Vec2u& dstPos, const Math::Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel);
			void Copy(const Math::Vec2u& dstPos, Surface* surface, const Math::Vec2u& srcSize);
			const Math::Vec2u& Size();
			const Math::Vec2u& Quad();
			Surface* GetSurface();
		private:
			LDL::Math::Vec2u _size;
			Surface          _surface;
		};
	}
}

#endif    
