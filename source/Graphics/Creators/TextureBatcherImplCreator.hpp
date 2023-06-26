#ifndef LDL_Graphics_Creators_TextureBatcherImplCreator_hpp
#define LDL_Graphics_Creators_TextureBatcherImplCreator_hpp

#include <LDL/Graphics/TextureBatcher.hpp>
#include "../TextureBatcherImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		namespace Creators
		{
			class TextureBatcherImplCreator
			{
			public:
				TextureBatcherImpl* Create(RenderContext* renderContext, Texture* texture, size_t count);
			private:
			};
		}
	}
}

#endif    