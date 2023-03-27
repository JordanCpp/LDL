#ifndef LDL_Graphics_RenderContext_hpp
#define LDL_Graphics_RenderContext_hpp

#include <LDL/Core/FastPimpl.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderContextImpl;

		class LDL_EXPORT RenderContext : public LDL::Core::FastPimpl
		{
		public:
			RenderContext();
			~RenderContext();
			RenderContextImpl* GetRenderContextImpl();
			void* Context();
		private:
			RenderContextImpl* _RenderContextImpl;
		};
	}
}

#endif  