#ifndef LDL_OpenGL_OpenGLLoader_hpp
#define LDL_OpenGL_OpenGLLoader_hpp

#include <LDL/Core/Library.hpp>

namespace LDL
{
	class OpenGLLoader
	{
	public:
		OpenGLLoader(size_t major, size_t minor);
		~OpenGLLoader();
	private:
		size_t _Major;
		size_t _Minor;
	};
}

#endif      