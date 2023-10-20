#ifndef LDL_Graphics_Creators_RenderContext_hpp
#define LDL_Graphics_Creators_RenderContext_hpp

#include <LDL/Graphics/RenderContext.hpp>
#include "../Impls/RenderContextImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		namespace Creators
		{
			class RenderContextImplCreator
			{
			public:
				RenderContextImpl* Create(size_t mode);
			private:
			};
		}
	}
}

#endif  
