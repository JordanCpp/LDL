#ifndef LDL_Graphics_OpenGLFunctions_hpp
#define LDL_Graphics_OpenGLFunctions_hpp

#include <LDL/Core/Library.hpp>

namespace LDL
{
	class OpenGLFunctionsImpl;

	class LDL_LIBRARY OpenGLFunctions
	{
	public:
		OpenGLFunctions();
		LDL::VoidFuncPtr Function(const char* name);
	private:
		OpenGLFunctionsImpl* _FunctionsImpl;
	};
}

#endif  
