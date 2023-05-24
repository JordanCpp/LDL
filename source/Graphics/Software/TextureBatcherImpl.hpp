#ifndef LDL_Graphics_Software_TextureBatcherImpl_hpp
#define LDL_Graphics_Software_TextureBatcherImpl_hpp

#include <LDL/Graphics/Texture.hpp>
#include "../OpenGL/Util.hpp"
#include <vector>

namespace LDL
{
	namespace Graphics
	{
		class TextureBatcherImpl
		{
		public:
			TextureBatcherImpl(Texture* texture, size_t count);
			void Draw(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize);
			void Clear();
		private:
		};
	}
}

#endif    