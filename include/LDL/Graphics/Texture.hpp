#ifndef LDL_Graphics_Texture_hpp
#define LDL_Graphics_Texture_hpp

#include <LDL/Core/FastPimpl.hpp>
#include <LDL/Math/Vec2.hpp>
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
			Texture(RenderContext* renderContext, const Math::Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel);
			Texture(RenderContext* renderContext, const Math::Vec2u& size, uint8_t bytesPerPixel);
			~Texture();
			void Copy(const Math::Vec2u& dstPos, const Math::Vec2u& srcSize, uint8_t* pixels, size_t bytesPerPixel);
			void Copy(const Math::Vec2u& dstPos, Surface * surface, const Math::Vec2u& srcSize);
			const Math::Vec2u& Size();
			TextureImpl* GetTextureImpl();
		private:
			TextureImpl* _TextureImpl;
		};
	}
}

#endif    