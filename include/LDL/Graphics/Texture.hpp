#ifndef LDL_Graphics_Texture_hpp
#define LDL_Graphics_Texture_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Core/FastPimpl.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl;

		class Texture : public LDL::Core::FastPimpl
		{
		public:
			Texture(const Point2u& size, uint8_t bytesPerPixel, uint8_t* pixels);
			~Texture();
			const Point2u& Size();
			size_t Id();
		private:
			TextureImpl* _TextureImpl;
		};
	}
}

#endif    