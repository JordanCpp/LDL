#include <LDL/Low/Mat4f.hpp>

LDL_Mat4f LDL_Orthof(float left, float right, float bottom, float top, float farv, float nearv)
{
	LDL_Mat4f result;

	result._Values[0] = (2.0f / (right - left));
	result._Values[5] = (2.0f / (top - bottom));
	result._Values[10] = (-1.0);
	result._Values[12] = (-(right + left) / (right - left));
	result._Values[13] = (-(top + bottom) / (top - bottom));
	result._Values[14] = (-(farv + nearv) / (farv - nearv));

	return result;
}