#ifndef LDL_OpenGL_OpenGLLoader_hpp
#define LDL_OpenGL_OpenGLLoader_hpp

#include <LDL/OpenGL/OpenGL_Functions.hpp>

namespace LDL
{
	class LDL_EXPORT OpenGLLoader
	{
	public:
		OpenGLLoader(size_t major = 1, size_t minor = 0);
		~OpenGLLoader();
		void Init();
		bool Equal(size_t major, size_t minor);
		size_t Major();
		size_t Minor();
		void Init_1_0();
		void Init_1_1();
		void Init_3_3();
	private:
		LDL::Graphics::Functions _Functions;
		size_t _Major;
		size_t _Minor;
	};
}

#endif      