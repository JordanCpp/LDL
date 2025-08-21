#ifndef Arcanum_Graphics_Image_hpp
#define Arcanum_Graphics_Image_hpp

#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Math/Vec2.hpp>

namespace Arcanum
{
	namespace Graphics
	{
		class Image
		{
		public:
			Image(LDL::Graphics::RenderContext* renderContext, const LDL::Math::Vec2u& size, uint8_t* pixels, const LDL::Math::Vec2u& offset, const LDL::Math::Vec2u& delta);
			LDL::Graphics::Texture* GetTexture();
			const LDL::Math::Vec2u& Offset();
			const LDL::Math::Vec2u& Delta();
		private:
			LDL::Graphics::Texture _texture;
			LDL::Math::Vec2u       _offset;
			LDL::Math::Vec2u       _delta;
		};
	}
}

#endif    