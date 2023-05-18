#ifndef LDL_Graphics_TextureBatcher_hpp
#define LDL_Graphics_TextureBatcher_hpp

#include <LDL/Graphics/Texture.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextureBatcherImpl;

		class LDL_EXPORT TextureBatcher : public LDL::Core::FastPimpl
		{
		public:
			TextureBatcher(Texture* texture, size_t count);
			~TextureBatcher();
			TextureBatcherImpl* GetTextureBatcherImpl();
			void Draw(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize);
			void Clear();
		private:
			TextureBatcherImpl* _TextureBatcherImpl;
		};
	}
}

#endif    