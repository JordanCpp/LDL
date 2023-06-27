#ifndef LDL_Graphics_OpenGL3_RenderContextImpl_hpp
#define LDL_Graphics_OpenGL3_RenderContextImpl_hpp

#include "../RenderContextImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderContextImplOpenGL3 : public RenderContextImpl
		{
		public:
			RenderContextImplOpenGL3(size_t mode);
			size_t Mode();
			int Context;

		private:
			size_t _Mode;
		};
	}
}

#endif    