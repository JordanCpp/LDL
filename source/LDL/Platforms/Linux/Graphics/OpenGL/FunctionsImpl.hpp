#ifndef LDL_Platforms_Windows_Linux_OpenGL_OpenGLFunctionsImpl_hpp
#define LDL_Platforms_Windows_Linux_OpenGL_OpenGLFunctionsImpl_hpp

#include <LDL/Core/Library.hpp>

namespace LDL
{
	namespace Graphics
	{
		class OpenGLFunctionsImpl
		{
		public:
			OpenGLFunctionsImpl(const char* path);
			LDL::VoidFuncPtr Function(const char* name);
		private:
			LDL::Core::Library _Library;
		};
	}
}

#endif  
