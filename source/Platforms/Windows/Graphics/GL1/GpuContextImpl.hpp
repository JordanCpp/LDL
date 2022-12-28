#ifndef LDL_Platforms_Windows_Graphics_GL1_GpuContextImpl_hpp
#define LDL_Platforms_Windows_Graphics_GL1_GpuContextImpl_hpp

#include "../../Windows.hpp"
#include <LDL/Core/Library.hpp>

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
			void* Function(const char* name);
		private:
			HGLRC _HGLRC;
			LDL::Core::Library _Library;
		};
	}
}

#endif  