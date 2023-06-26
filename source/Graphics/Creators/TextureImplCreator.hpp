#ifndef LDL_Graphics_Creators_TextureImplCreator_hpp
#define LDL_Graphics_Creators_TextureImplCreator_hpp

#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include "../TextureImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		namespace Creators
		{
			class TextureImplCreator
			{
			public:
				TextureImpl* Create(RenderContext* renderContext, const Math::Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel);
				TextureImpl* Create(RenderContext* renderContext, const Math::Vec2u& size, uint8_t bytesPerPixel);
			private:
			};
		}
	}
}

#endif    