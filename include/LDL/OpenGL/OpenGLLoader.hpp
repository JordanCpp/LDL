#ifndef LDL_OpenGL_OpenGLLoader_hpp
#define LDL_OpenGL_OpenGLLoader_hpp

#include <LDL/Graphics/Functions.hpp>

namespace LDL
{
	class OpenGLLoader
	{
	public:
		OpenGLLoader(size_t major = 1, size_t minor = 0);
		~OpenGLLoader();
		bool Equal(size_t major, size_t minor);
		size_t Major();
		size_t Minor();
		void Init_1_0();
		void Init_1_1();
	private:
		LDL::Graphics::Functions _Functions;
		size_t _Major;
		size_t _Minor;
	};
}

#endif      