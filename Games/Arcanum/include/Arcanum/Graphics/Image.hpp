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
			Image(LDL::Graphics::RenderContext* renderContext, const LDL::Graphics::Point2u& size, uint8_t* pixels, const LDL::Graphics::Point2u& pos);
		private:
			LDL::Graphics::Texture _Texture;
			LDL::Graphics::Point2u _Pos;
		};
	}
}

#endif    