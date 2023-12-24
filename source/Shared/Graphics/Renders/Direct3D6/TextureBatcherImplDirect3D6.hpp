#ifndef LDL_Graphics_Direct3D6_TextureBatcherImpl_hpp
#define LDL_Graphics_Direct3D6_TextureBatcherImpl_hpp

#include <LDL/Graphics/Texture.hpp>
#include <vector>
#include "../../Impls/TextureBatcherImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class TextureBatcherImplDirect3D6 : public TextureBatcherImpl
		{
		public:
			TextureBatcherImplDirect3D6(Texture* texture, size_t count);
			void Draw(const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Clear();
		private:
		};
	}
}

#endif    
