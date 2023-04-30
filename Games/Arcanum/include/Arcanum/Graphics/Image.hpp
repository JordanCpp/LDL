#ifndef Arcanum_Graphics_Image_hpp
#define Arcanum_Graphics_Image_hpp

#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace Arcanum
{
	namespace Graphics
	{
		class Image
		{
		public:
			Image(LDL::Graphics::RenderContext* renderContext, const LDL::Graphics::Point2u& size, uint8_t* pixels, const LDL::Graphics::Point2u& offset, const LDL::Graphics::Point2u& delta);
			LDL::Graphics::Texture* GetTexture();
		private:
			LDL::Graphics::Texture _Texture;
			LDL::Graphics::Point2u _Offset;
			LDL::Graphics::Point2u _Delta;
		};
	}
}

#endif    