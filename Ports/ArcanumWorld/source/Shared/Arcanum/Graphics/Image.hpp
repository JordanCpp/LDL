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
			Image(LDL::RenderContext* renderContext, const LDL::Vec2u& size, uint8_t* pixels, const LDL::Vec2u& offset, const LDL::Vec2u& delta);
			LDL::Texture* GetTexture();
			const LDL::Vec2u& Offset();
			const LDL::Vec2u& Delta();
		private:
			LDL::Texture      _texture;
			LDL::Vec2u  _offset;
			LDL::Vec2u  _delta;
		};
	}
}

#endif    