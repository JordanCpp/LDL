#ifndef LDL_Graphics_OpenGL1_TextureBatcherImpl_hpp
#define LDL_Graphics_OpenGL1_TextureBatcherImpl_hpp

#include <LDL/Graphics/Texture.hpp>
#include <vector>

namespace LDL
{
	namespace Graphics
	{
		struct Quad
		{
			float data[5 * 6];
		};

		class TextureBatcherImpl
		{
		public:
			TextureBatcherImpl(Texture* texture, size_t count);
			void Draw(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize);
			void Clear();
			size_t TextureId();
			size_t Count();
			Quad* Content();
		private:
			size_t _Texture;
			size_t _TextureSize;
			std::vector<Quad> _Quads;
		};
	}
}

#endif    