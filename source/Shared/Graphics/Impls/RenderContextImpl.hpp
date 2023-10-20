#ifndef LDL_Graphics_RenderContextImpl_hpp
#define LDL_Graphics_RenderContextImpl_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderContextImpl
		{
		public:
			virtual ~RenderContextImpl() {};
			virtual size_t Mode() = 0;
		private:
		};
	}
}

#endif    
