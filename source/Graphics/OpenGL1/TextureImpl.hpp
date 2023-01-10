#ifndef LDL_Graphics_OpengGL1_TextureImpl_hpp
#define LDL_Graphics_OpengGL1_TextureImpl_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl
		{
		public:
			TextureImpl(const Point2u& size, size_t bytesPerPixel, uint8_t* pixels);
			~TextureImpl();
			const Point2u& Size();
			size_t Id();
		private:
			size_t _Id;
			Point2u _Size;
		};
	}
}

#endif    