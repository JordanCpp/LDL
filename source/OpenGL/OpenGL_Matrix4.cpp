#include <LDL/OpenGL/OpenGL_Matrix4.hpp>
#include <math.h>

const GLdouble NumberPi = 3.14159265358979323846;

LDL::Matrix4::Matrix4()
{
	for (size_t i = 0; i < Max; i++)
	{
		_Values[i] = 0;
	}
}

GLdouble* LDL::Matrix4::Values()
{
	return _Values;
}

void LDL::Matrix4::Identity()
{
	_Values[0]  = 1;
	_Values[1]  = 0;
	_Values[2]  = 0;
	_Values[3]  = 0;
	_Values[4]  = 0;
	_Values[5]  = 1;
	_Values[6]  = 0;
	_Values[7]  = 0;
	_Values[8]  = 0;
	_Values[9]  = 0;
	_Values[10] = 1;
	_Values[11] = 0;
	_Values[12] = 0;
	_Values[13] = 0;
	_Values[14] = 0;
	_Values[15] = 1;
}

void LDL::Matrix4::Perspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)
{
	GLdouble f = 1 / tan(fovy * (NumberPi / 360.0f));

	_Values[0] = f / aspect;
	_Values[1] = 0;
	_Values[2] = 0;
	_Values[3] = 0;

	_Values[4] = 0;
	_Values[5] = f;
	_Values[6] = 0;
	_Values[7] = 0;

	_Values[8] = 0;
	_Values[9] = 0;
	_Values[10] = (zFar + zNear) / (zNear - zFar);
	_Values[11] = -1;

	_Values[12] = 0;
	_Values[13] = 0;
	_Values[14] = 2 * zFar * zNear / (zNear - zFar);
	_Values[15] = 0;
}

