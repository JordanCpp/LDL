#ifndef LDL_Graphics_Software_RenderContextImpl_hpp
#define LDL_Graphics_Software_RenderContextImpl_hpp

#include "../RenderContextImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderContextImplSoftware : public RenderContextImpl
		{
		public:
			RenderContextImplSoftware(size_t mode);
			size_t Mode();
			size_t _Mode;
			int Context;
		};
	}
}

#endif    
