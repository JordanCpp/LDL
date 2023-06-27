#ifndef LDL_Graphics_Direct3D9_RenderContextImplDirect3D9_hpp
#define LDL_Graphics_Direct3D9_RenderContextImplDirect3D9_hpp

#include "../RenderContextImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderContextImplDirect3D9 : public RenderContextImpl
		{
		public:
			RenderContextImplDirect3D9(size_t mode);
			size_t Mode();
			size_t _Mode;
			int Context;
		};
	}
}

#endif    