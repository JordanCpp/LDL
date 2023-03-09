#ifndef LDL_Graphics_DX5_TextureImpl_hpp
#define LDL_Graphics_DX5_TextureImpl_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl
		{
		public:
			TextureImpl(const LDL::Graphics::Point2u & size, uint8_t* pixels, size_t bytesPerPixel);
			~TextureImpl();
			const LDL::Graphics::Point2u& Size();
			const size_t Id();
		private:
			size_t _Id;
			LDL::Graphics::Point2u _Size;
		};
	}
}

#endif    