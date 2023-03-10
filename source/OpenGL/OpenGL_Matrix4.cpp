#include <LDL/OpenGL/OpenGL_Matrix4.hpp>
#include <math.h>
#include <string.h>

using namespace LDL;

const GLdouble NumberPi = 3.14159265358979323846;

Matrix4::Matrix4()
{
	Identity();
}

Matrix4& Matrix4::operator=(const Matrix4& source)
{
	if (this == &source)
		return *this;

	memcpy(&_Values, source._Values, sizeof(_Values));

	return *this;
}

GLdouble* Matrix4::Values()
{
	return _Values;
}

void Matrix4::Identity()
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

void Matrix4::Perspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)
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

Matrix4 Matrix4::operator * (const Matrix4& m) const {
	Matrix4 ret;

	ret._Values[0] = ((_Values[0] * m._Values[0]) + (_Values[1] * m._Values[4]) + (_Values[2] * m._Values[8]) + (_Values[3] * m._Values[12]));
	ret._Values[1] = ((_Values[0] * m._Values[1]) + (_Values[1] * m._Values[5]) + (_Values[2] * m._Values[9]) + (_Values[3] * m._Values[13]));
	ret._Values[2] = ((_Values[0] * m._Values[2]) + (_Values[1] * m._Values[6]) + (_Values[2] * m._Values[10]) + (_Values[3] * m._Values[14]));
	ret._Values[3] = ((_Values[0] * m._Values[3]) + (_Values[1] * m._Values[7]) + (_Values[2] * m._Values[11]) + (_Values[3] * m._Values[15]));

	ret._Values[4] = ((_Values[4] * m._Values[0]) + (_Values[5] * m._Values[4]) + (_Values[6] * m._Values[8]) + (_Values[7] * m._Values[12]));
	ret._Values[5] = ((_Values[4] * m._Values[1]) + (_Values[5] * m._Values[5]) + (_Values[6] * m._Values[9]) + (_Values[7] * m._Values[13]));
	ret._Values[6] = ((_Values[4] * m._Values[2]) + (_Values[5] * m._Values[6]) + (_Values[6] * m._Values[10]) + (_Values[7] * m._Values[14]));
	ret._Values[7] = ((_Values[4] * m._Values[3]) + (_Values[5] * m._Values[7]) + (_Values[6] * m._Values[11]) + (_Values[7] * m._Values[15]));

	ret._Values[8] = ((_Values[8] * m._Values[0]) + (_Values[9] * m._Values[4]) + (_Values[10] * m._Values[8]) + (_Values[11] * m._Values[12]));
	ret._Values[9] = ((_Values[8] * m._Values[1]) + (_Values[9] * m._Values[5]) + (_Values[10] * m._Values[9]) + (_Values[11] * m._Values[13]));
	ret._Values[10] = ((_Values[8] * m._Values[2]) + (_Values[9] * m._Values[6]) + (_Values[10] * m._Values[10]) + (_Values[11] * m._Values[14]));
	ret._Values[11] = ((_Values[8] * m._Values[3]) + (_Values[9] * m._Values[7]) + (_Values[10] * m._Values[11]) + (_Values[11] * m._Values[15]));

	ret._Values[12] = ((_Values[12] * m._Values[0]) + (_Values[13] * m._Values[4]) + (_Values[14] * m._Values[8]) + (_Values[15] * m._Values[12]));
	ret._Values[13] = ((_Values[12] * m._Values[1]) + (_Values[13] * m._Values[5]) + (_Values[14] * m._Values[9]) + (_Values[15] * m._Values[13]));
	ret._Values[14] = ((_Values[12] * m._Values[2]) + (_Values[13] * m._Values[6]) + (_Values[14] * m._Values[10]) + (_Values[15] * m._Values[14]));
	ret._Values[15] = ((_Values[12] * m._Values[3]) + (_Values[13] * m._Values[7]) + (_Values[14] * m._Values[11]) + (_Values[15] * m._Values[15]));

	return ret;
}

void Matrix4::Translate(GLdouble x, GLdouble y, GLdouble z) 
{
	Matrix4 t;
	t = (*this);

	Identity();
	_Values[12] = x;
	_Values[13] = y;
	_Values[14] = z;

	(*this) = (*this) * t;
}

void Matrix4::RotateX(GLdouble radians) 
{
	/**
	 * Matrix Rotation X
	 * | 1       |
	 * |   c s   |
	 * |  -s c   |
	 * |       1 |
	 */

	GLdouble c = cosf(radians);
	GLdouble s = sinf(radians);

	Matrix4 t;
	t = (*this);

	Identity();
	_Values[5] = c;
	_Values[6] = s;
	_Values[9] = -s;
	_Values[10] = c;

	(*this) = (*this) * t;
}

void Matrix4::RotateY(GLdouble radians) 
{
	/**
	 * Matrix Rotation X
	 * | c  -s   |
	 * |   1     |
	 * | s   c   |
	 * |       1 |
	 */

	float c = cosf(radians);
	float s = sinf(radians);

	Matrix4 t;
	t = (*this);

	Identity();
	_Values[0] = c;
	_Values[2] = -s;
	_Values[8] = s;
	_Values[10] = c;

	(*this) = (*this) * t;
}

void Matrix4::RotateZ(GLdouble radians) 
{
	/**
	 * Matrix Rotation X
	 * | c s     |
	 * |-s c     |
	 * |         |
	 * |       1 |
	 */

	float c = cosf(radians);
	float s = sinf(radians);

	Matrix4 t;
	t = (*this);

	Identity();
	_Values[0] = c;
	_Values[1] = s;
	_Values[4] = -s;
	_Values[5] = c;

	(*this) = (*this) * t;
}

void Matrix4::Scale(GLdouble sx, GLdouble sy, GLdouble sz)
{
	/**
	 * Matrix Translation
	 * | sx      |
	 * |   sy    |
	 * |     sz  |
	 * |       1 |
	 */

	Matrix4 t;
	t = (*this);

	Identity();
	_Values[0] = sx;
	_Values[5] = sy;
	_Values[10] = sz;

	(*this) = (*this) * t;
}

void Matrix4::Ortho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble farv, GLdouble nearv) 
{
	_Values[0] = (2.0f / (right - left));
	_Values[5] = (2.0f / (top - bottom));
	_Values[10] = (-1.0);
	_Values[12] = (-(right + left) / (right - left));
	_Values[13] = (-(top + bottom) / (top - bottom));
	_Values[14] = (-(farv + nearv) / (farv - nearv));
}