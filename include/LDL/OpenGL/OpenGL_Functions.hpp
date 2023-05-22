#ifndef LDL_Graphics_OpenGLFunctions_hpp
#define LDL_Graphics_OpenGLFunctions_hpp

#include <LDL/Core/FastPimpl.hpp>
#include <LDL/Core/Library.hpp>

namespace LDL
{
	namespace Graphics
	{
		class OpenGLFunctionsImpl;

		class LDL_EXPORT OpenGLFunctions : LDL::Core::FastPimpl
		{
		public:
			OpenGLFunctions();
			LDL::VoidFuncPtr Function(const char* name);
		private:
			OpenGLFunctionsImpl* _FunctionsImpl;
		};
	}
}

#endif  