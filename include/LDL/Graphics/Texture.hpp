#ifndef LDL_Graphics_Texture_hpp
#define LDL_Graphics_Texture_hpp

#include <LDL/Core/FastPimpl.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl;

		class LDL_EXPORT Texture : public LDL::Core::FastPimpl
		{
		public:
			Texture(RenderContext* renderContext, const Point2u& size, uint8_t* pixels, uint8_t bytesPerPixel);
			Texture(RenderContext* renderContext, const Point2u& size, uint8_t bytesPerPixel);
			~Texture();
			void Copy(const Point2u& dstPos, const Point2u& srcSize, uint8_t* pixels, size_t bytesPerPixel);
			void Copy(const Point2u& dstPos, Surface * surface, const Point2u& srcSize);
			const Point2u& Size();
			TextureImpl* GetTextureImpl();
		private:
			TextureImpl* _TextureImpl;
		};
	}
}

#endif    