#ifndef LDL_Graphics_OpenGL1_TextureBatcherImpl_hpp
#define LDL_Graphics_OpenGL1_TextureBatcherImpl_hpp

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
			size_t TextureId();
			size_t Count();
			Util::Quad* Content();
		private:
			size_t _Texture;
			size_t _TextureSize;
			std::vector<Util::Quad> _Quads;
		};
	}
}

#endif    