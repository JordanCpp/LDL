#ifndef LDL_Graphics_Direct3D6_RenderContextImplDirect3D6_hpp
#define LDL_Graphics_Direct3D6_RenderContextImplDirect3D6_hpp

#include "../../Impls/RenderContextImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderContextImplDirect3D6 : public RenderContextImpl
		{
		public:
			RenderContextImplDirect3D6(size_t mode);
			size_t Mode();
		private:
			size_t _mode;
		};
	}
}

#endif    
