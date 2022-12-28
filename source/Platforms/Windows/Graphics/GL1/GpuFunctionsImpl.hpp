#ifndef LDL_Platforms_Windows_Graphics_GL1_GpuFunctionsImpl_hpp
#define LDL_Platforms_Windows_Graphics_GL1_GpuFunctionsImpl_hpp

#include "../../Windows.hpp"
#include <LDL/Core/Library.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GpuFunctionsImpl
		{
		public:
			GpuFunctionsImpl(const char* path);
			void* Function(const char* name);
		private:
			LDL::Core::Library _Library;
		};
	}
}

#endif  