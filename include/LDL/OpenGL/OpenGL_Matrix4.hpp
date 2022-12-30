#ifndef LDL_OpenGL_OpenGL_Matrix4_hpp
#define LDL_OpenGL_OpenGL_Matrix4_hpp

#include <LDL/OpenGL/OpenGLTypes.hpp>

namespace LDL
{
	class Matrix4
	{
	public:
		enum
		{
			Max = 16
		};
		Matrix4();
		GLdouble* Values();
		void Perspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
	private:
		GLdouble _Values[Max];
	};
}

#endif      