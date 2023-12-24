#ifndef LDL_Graphics_OpenGL1_RenderContextImpl_hpp
#define LDL_Graphics_OpenGL1_RenderContextImpl_hpp

#include "../../Impls/RenderContextImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderContextImplOpenGL1: public RenderContextImpl
		{
		public:
			RenderContextImplOpenGL1(size_t mode);
			size_t Mode();
		private:
			size_t _Mode;
		};
	}
}

#endif    
