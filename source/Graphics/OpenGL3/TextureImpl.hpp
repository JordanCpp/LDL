#ifndef LDL_Graphics_OpenGL3_TextureImpl_hpp
#define LDL_Graphics_OpenGL3_TextureImpl_hpp

#include "RenderContextImpl.hpp"
#include <LDL/Math/Vec2u.hpp>

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
			const Math::Vec2u& Quad();
			size_t Id();
		private:
			RenderContextImpl* _RenderContextImpl;
			size_t _Id;
			LDL::Math::Vec2u _Size;
			LDL::Math::Vec2u _Quad;
		};
	}
}

#endif    