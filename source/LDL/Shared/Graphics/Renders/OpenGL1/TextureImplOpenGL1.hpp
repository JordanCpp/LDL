#ifndef LDL_Graphics_OpenGL1_TextureImpl_hpp
#define LDL_Graphics_OpenGL1_TextureImpl_hpp

#include "RenderContextImplOpenGL1.hpp"
#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Surface.hpp>
#include "../../Impls/TextureImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl;

		class TextureImplOpenGL1: public TextureImpl
		{
		public:
			TextureImplOpenGL1(RenderContextImpl* renderContextImpl, const LDL::Math::Vec2u & size, uint8_t* pixels, uint8_t bytesPerPixel);
			TextureImplOpenGL1(RenderContextImpl* renderContextImpl, const Math::Vec2u& size, uint8_t bytesPerPixel);
			~TextureImplOpenGL1();
			void Copy(const Math::Vec2u& dstPos, const Math::Vec2u& srcSize, uint8_t * pixels, uint8_t bytesPerPixel);
			void Copy(const Math::Vec2u& dstPos, Surface* surface, const Math::Vec2u& srcSize);
			const Math::Vec2u& Size();
			const Math::Vec2u& Quad();
			size_t Id();
		private:
			RenderContextImpl* _renderContextImpl;
			size_t             _id;
			LDL::Math::Vec2u   _size;
			LDL::Math::Vec2u   _quad;
		};
	}
}

#endif    
