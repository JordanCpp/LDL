#ifndef LDL_Graphics_RenderContext_hpp
#define LDL_Graphics_RenderContext_hpp

#include <LDL/Enums/RenderMode.hpp>
#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderContextImpl;

		class LDL_LIBRARY RenderContext
		{
		public:
			RenderContext(size_t mode = Enums::RenderMode::OpenGL1);
			~RenderContext();
			RenderContextImpl* GetRenderContextImpl();
			size_t Mode();
			void* Context();
		private:
			RenderContextImpl* _impl;
		};
	}
}

#endif  
