#ifndef LDL_Graphics_Functions_hpp
#define LDL_Graphics_Functions_hpp

#include <LDL/Core/FastPimpl.hpp>

namespace LDL
{
	namespace Graphics
	{
		class FunctionsImpl;

		class LDL_EXPORT Functions : LDL::Core::FastPimpl
		{
		public:
			Functions();
			LDL::VoidFuncPtr Function(const char* name);
		private:
			FunctionsImpl* _GpuFunctionsImpl;
		};
	}
}

#endif  