#ifndef LDL_Graphics_Direct3D9_TextureBatcherImplDirect3D9_hpp
#define LDL_Graphics_Direct3D9_TextureBatcherImplDirect3D9_hpp

#include <LDL/Graphics/Texture.hpp>
#include <vector>
#include "../TextureBatcherImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class TextureBatcherImplDirect3D9 : public TextureBatcherImpl
		{
		public:
			TextureBatcherImplDirect3D9(Texture* texture, size_t count);
			void Draw(const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Clear();
			size_t TextureId();
			size_t Count();
		private:
			size_t _Texture;
			size_t _TextureSize;
		};
	}
}

#endif    