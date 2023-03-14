#ifndef LDL_Platforms_Windows_Graphics_OpenGL1_ContextImpl_hpp
#define LDL_Platforms_Windows_Graphics_OpenGL1_ContextImpl_hpp

#include "../../Windows.hpp"

namespace LDL
{
	namespace Graphics
	{
		class ContextImpl
		{
		public:
			ContextImpl();
			~ContextImpl();
			void Create(HDC hdc);
		private:
			HGLRC _HGLRC;
		};
	}
}

#endif  