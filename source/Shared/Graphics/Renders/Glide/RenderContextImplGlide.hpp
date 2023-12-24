#ifndef LDL_Graphics_Renders_Glide_RenderContextImplGlide_hpp
#define LDL_Graphics_Renders_Glide_RenderContextImplGlide_hpp

#include "../../Impls/RenderContextImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderContextImplGlide : public RenderContextImpl
		{
		public:
			RenderContextImplGlide(size_t mode);
			size_t Mode();
		private:
			size_t _Mode;
		};
	}
}

#endif    
