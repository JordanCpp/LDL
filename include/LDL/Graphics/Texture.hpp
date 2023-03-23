#ifndef LDL_Graphics_Texture_hpp
#define LDL_Graphics_Texture_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Core/FastPimpl.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl;
		class Render;

		class LDL_EXPORT Texture : public LDL::Core::FastPimpl
		{
		public:
			Texture(Render * render, const Point2u& size, uint8_t* pixels, uint8_t bytesPerPixel);
			~Texture();
			const Point2u& Size();
			TextureImpl* GetTextureImpl();
		private:
			TextureImpl* _TextureImpl;
		};
	}
}

#endif    