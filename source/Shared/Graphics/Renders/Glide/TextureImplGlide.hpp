#ifndef LDL_Graphics_Renders_Glide_TextureImplGlide_hpp
#define LDL_Graphics_Renders_Glide_TextureImplGlide_hpp

#include "RenderContextImplGlide.hpp"
#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Surface.hpp>
#include "../../Impls/TextureImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl;

		class TextureImplGlide : public TextureImpl
		{
		public:
			TextureImplGlide(RenderContextImpl* renderContextImpl, const LDL::Math::Vec2u & size, uint8_t* pixels, uint8_t bytesPerPixel);
			TextureImplGlide(RenderContextImpl* renderContextImpl, const Math::Vec2u& size, uint8_t bytesPerPixel);
			~TextureImplGlide();
			void Copy(const Math::Vec2u& dstPos, const Math::Vec2u& srcSize, uint8_t * pixels, uint8_t bytesPerPixel);
			void Copy(const Math::Vec2u& dstPos, Surface* surface, const Math::Vec2u& srcSize);
			const Math::Vec2u& Size();
			const Math::Vec2u& Quad();
		private:
			RenderContextImpl* _renderContextImpl;
			LDL::Math::Vec2u   _size;
			LDL::Math::Vec2u   _quad;
		};
	}
}

#endif    
