#ifndef LDL_Graphics_RenderContext_hpp
#define LDL_Graphics_RenderContext_hpp

#include <LDL/Core/FastPimpl.hpp>
#include <LDL/Enums/RenderMode.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderContextImpl;

		class LDL_EXPORT RenderContext : public LDL::Core::FastPimpl
		{
		public:
			RenderContext(size_t mode = Enums::RenderMode::OpenGL1);
			~RenderContext();
			RenderContextImpl* GetRenderContextImpl();
			size_t Mode();
			void* Context();
		private:
			RenderContextImpl* _RenderContextImpl;
		};
	}
}

#endif  