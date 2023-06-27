#ifndef LDL_Graphics_Direct3D9_TextureImplDirect3D9_hpp
#define LDL_Graphics_Direct3D9_TextureImplDirect3D9_hpp

#include "RenderContextImplDirect3D9.hpp"
#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Surface.hpp>
#include "../TextureImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl;

		class TextureImplDirect3D9 : public TextureImpl
		{
		public:
			TextureImplDirect3D9(RenderContextImpl* renderContextImpl, const LDL::Math::Vec2u & size, uint8_t* pixels, size_t bytesPerPixel);
			TextureImplDirect3D9(RenderContextImpl* renderContextImpl, const Math::Vec2u& size, size_t bytesPerPixel);
			~TextureImplDirect3D9();
			void Copy(const Math::Vec2u& dstPos, const Math::Vec2u& srcSize, uint8_t * pixels, size_t bytesPerPixel);
			void Copy(const Math::Vec2u& dstPos, Surface* surface, const Math::Vec2u& srcSize);
			const Math::Vec2u& Size();
			const Math::Vec2u& Quad();
			size_t Id();
		private:
			RenderContextImpl* _RenderContextImpl;
			size_t  _Id;
			LDL::Math::Vec2u _Size;
			LDL::Math::Vec2u _Quad;
		};
	}
}

#endif    