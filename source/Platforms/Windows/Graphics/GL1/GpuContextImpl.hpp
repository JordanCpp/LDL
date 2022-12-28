#ifndef LDL_Platforms_Windows_Graphics_GL1_GpuContextImpl_hpp
#define LDL_Platforms_Windows_Graphics_GL1_GpuContextImpl_hpp

#include "../../Windows.hpp"

namespace LDL
{
	namespace Graphics
	{
		class GpuContextImpl
		{
		public:
			GpuContextImpl(const char* path);
			~GpuContextImpl();
			void Create(HDC hdc);
		private:
			HGLRC _HGLRC;
		};
	}
}

#endif  