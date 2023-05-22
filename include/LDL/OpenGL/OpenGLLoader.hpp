#ifndef LDL_OpenGL_OpenGLLoader_hpp
#define LDL_OpenGL_OpenGLLoader_hpp

#include <LDL/OpenGL/OpenGL_Functions.hpp>

namespace LDL
{
	class LDL_EXPORT OpenGLLoader
	{
	public:
		OpenGLLoader();
		OpenGLLoader(size_t major, size_t minor);
		~OpenGLLoader();
		void Init(size_t major, size_t minor);
		bool Equal(size_t major, size_t minor);
		size_t Major();
		size_t Minor();
		void Init_1_0();
		void Init_1_1();
		void Init_1_2();
		void Init_1_3();
		void Init_1_4();
		void Init_1_5();
		void Init_2_0();
		void Init_2_1();
		void Init_3_0();
		void Init_3_1();
		void Init_3_2();
		void Init_3_3();
		void Init_4_0();
		void Init_4_1();
		void Init_4_2();
		void Init_4_3();
		void Init_4_4();
		void Init_4_5();
		void Init_4_6();
	private:
		LDL::Graphics::OpenGLFunctions _Functions;
		size_t _Major;
		size_t _Minor;
	};
}

#endif      