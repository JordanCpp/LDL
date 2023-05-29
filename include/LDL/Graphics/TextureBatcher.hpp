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
			void Draw(const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Clear();
		private:
			TextureBatcherImpl* _TextureBatcherImpl;
		};
	}
}

#endif    