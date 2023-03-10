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
		Matrix4& operator= (const Matrix4& source);
		GLdouble* Values();
		void Identity();
		void Perspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
		Matrix4 operator * (const Matrix4& m) const;
		void Translate(GLdouble x, GLdouble y, GLdouble z);
		void RotateX(GLdouble radians);
		void RotateY(GLdouble radians);
		void RotateZ(GLdouble radians);
		void Scale(GLdouble sx, GLdouble sy, GLdouble sz);
		void Ortho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble farv, GLdouble nearv);
	private:
		GLdouble _Values[Max];
	};
}

#endif      