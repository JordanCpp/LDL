#ifndef LDL_Graphics_GpuFunctions_hpp
#define LDL_Graphics_GpuFunctions_hpp

#include <LDL/Core/FastPimpl.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GpuFunctionsImpl;

		class GpuFunctions : LDL::Core::FastPimpl
		{
		public:
			GpuFunctions();
			LDL::VoidFuncPtr Function(const char* name);
		private:
			GpuFunctionsImpl* _GpuFunctionsImpl;
		};
	}
}

#endif  