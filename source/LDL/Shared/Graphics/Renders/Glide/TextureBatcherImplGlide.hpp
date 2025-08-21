#ifndef LDL_Graphics_Renders_Glide_TextureBatcherImplGlide_hpp
#define LDL_Graphics_Renders_Glide_TextureBatcherImplGlide_hpp

#include <LDL/Graphics/Texture.hpp>
#include <vector>
#include "../../Impls/TextureBatcherImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class TextureBatcherImplGlide : public TextureBatcherImpl
		{
		public:
			TextureBatcherImplGlide(Texture* texture, size_t count);
			void Draw(const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Clear();
		private:
		};
	}
}

#endif    
