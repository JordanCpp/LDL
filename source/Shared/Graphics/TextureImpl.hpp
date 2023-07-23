#ifndef LDL_Graphics_TextureImpl_hpp
#define LDL_Graphics_TextureImpl_hpp

#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextureImpl
		{
		public:
			virtual ~TextureImpl() {};
			virtual void Copy(const Math::Vec2u& dstPos, const Math::Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel) = 0;
			virtual void Copy(const Math::Vec2u& dstPos, Surface* surface, const Math::Vec2u& srcSize) = 0;
			virtual const Math::Vec2u& Size() = 0;
			virtual const Math::Vec2u& Quad() = 0;
		private:
		};
	}
}

#endif    
