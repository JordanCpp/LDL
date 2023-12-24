#ifndef LDL_Graphics_Software_RenderContextImpl_hpp
#define LDL_Graphics_Software_RenderContextImpl_hpp

#include "../../Impls/RenderContextImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderContextImplSoftware : public RenderContextImpl
		{
		public:
			RenderContextImplSoftware(size_t mode);
			size_t Mode();
		private:
			size_t _Mode;
		};
	}
}

#endif    
