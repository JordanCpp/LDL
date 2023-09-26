#ifndef LDL_Cpp98_RenderContext_hpp
#define LDL_Cpp98_RenderContext_hpp

#include <LDL/Cpp/RContext.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderContext: public LDL_RenderContext
		{
		public:
			RenderContext(size_t mode = LDL_RenderMode::OpenGL1) :
				LDL_RenderContext(mode)
			{
			}
		private:
		};
	}
}

#endif
