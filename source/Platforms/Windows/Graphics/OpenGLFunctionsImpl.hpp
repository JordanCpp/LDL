#ifndef LDL_Platforms_Windows_Graphics_OpenGL_OpenGLFunctionsImpl_hpp
#define LDL_Platforms_Windows_Graphics_OpenGL_OpenGLFunctionsImpl_hpp

#include "../Windows.hpp"
#include <LDL/Core/Library.hpp>

namespace LDL
{
	namespace Graphics
	{
		class OpenGLFunctionsImpl
		{
		public:
			OpenGLFunctionsImpl(const std::string& path);
			LDL::VoidFuncPtr Function(const std::string& name);
		private:
			bool IsValid(LDL::VoidFuncPtr ptr);
			LDL::Core::Library _Library;
		};
	}
}

#endif  
