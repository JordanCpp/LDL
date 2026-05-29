/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <math.h>
#include <LDL/Mat4f.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

float* LDL_Mat4fGetValues(LDL_Mat4f* mat)
{
	return mat->Values;
}

void LDL_Mat4fIdentity(LDL_Mat4f* mat)
{
	if (mat)
	{
		mat->Values[0]  = 1;
		mat->Values[1]  = 0;
		mat->Values[2]  = 0;
		mat->Values[3]  = 0;
		mat->Values[4]  = 0;
		mat->Values[5]  = 1;
		mat->Values[6]  = 0;
		mat->Values[7]  = 0;
		mat->Values[8]  = 0;
		mat->Values[9]  = 0;
		mat->Values[10] = 1;
		mat->Values[11] = 0;
		mat->Values[12] = 0;
		mat->Values[13] = 0;
		mat->Values[14] = 0;
		mat->Values[15] = 1;
	}
}

void LDL_Mat4fOrtho(LDL_Mat4f* mat, float left, float right, float bottom, float top, float farv, float nearv)
{
	if (mat)
	{
		mat->Values[0]  = (2.0f / (right - left));
		mat->Values[5]  = (2.0f / (top - bottom));
		mat->Values[10] = (-1.0);
		mat->Values[12] = (-(right + left) / (right - left));
		mat->Values[13] = (-(top + bottom) / (top - bottom));
		mat->Values[14] = (-(farv + nearv) / (farv - nearv));
	}
}

void LDL_Mat4fTranslate(LDL_Mat4f* mat, float x, float y, float z)
{
	if (mat)
	{
		mat->Values[12] = x;
		mat->Values[13] = y;
		mat->Values[14] = z;
	}
}
void LDL_Mat4fMultiply(LDL_Mat4f* result, const LDL_Mat4f* a, const LDL_Mat4f* b) 
{
	size_t i;
	size_t j;
	size_t k;

	for (i = 0; i < 4; ++i) 
	{
		for (j = 0; j < 4; ++j)
		{
			result->Values[i * 4 + j] = 0.0f;

			for (k = 0; k < 4; ++k)
			{
				result->Values[i * 4 + j] += a->Values[i * 4 + k] * b->Values[k * 4 + j];
			}
		}
	}
}

void LDL_Mat4fRotate(LDL_Mat4f* mat, float angle, float x, float y, float z) 
{
	float radians = angle * (float)(M_PI / 180.0f);
	float c = (float)cos(radians);
	float s = (float)sin(radians);
	LDL_Mat4f temp;

	LDL_Mat4fIdentity(&temp);

	if (x) 
	{
		temp.Values[5] = c;  temp.Values[6] = -s;
		temp.Values[9] = s;  temp.Values[10] = c;
	}
	else if (y) 
	{
		temp.Values[0] = c;  temp.Values[2] = s;
		temp.Values[8] = -s; temp.Values[10] = c;
	}
	else if (z) 
	{
		temp.Values[0] = c;  temp.Values[1] = -s;
		temp.Values[4] = s;  temp.Values[5] = c;
	}

	LDL_Mat4fMultiply(mat, mat, &temp);
}

void LDL_Mat4fCross(LDL_Mat4f* result, const LDL_Mat4f* a, const LDL_Mat4f* b) 
{
	result->Values[0] = a->Values[1] * b->Values[2] - a->Values[2] * b->Values[1];
	result->Values[1] = a->Values[2] * b->Values[0] - a->Values[0] * b->Values[2];
	result->Values[2] = a->Values[0] * b->Values[1] - a->Values[1] * b->Values[0];
}

void LDL_Mat4fLookAt(LDL_Mat4f* mat, float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ)
{
	float forwardX = centerX - eyeX;
	float forwardY = centerY - eyeY;
	float forwardZ = centerZ - eyeZ;
	float len;
	float sideX;
	float sideY;
	float sideZ;
	float upX2;
	float upY2;
	float upZ2;
	float transX;
	float transY;
	float transZ;

	len = (float)sqrt(forwardX * forwardX + forwardY * forwardY + forwardZ * forwardZ);
	if (len <= 0.0f) 
	{
		len = 1.0f;
	}

	forwardX /= len;
	forwardY /= len;
	forwardZ /= len;

	sideX = upY * forwardZ - upZ * forwardY;
	sideY = upZ * forwardX - upX * forwardZ;
	sideZ = upX * forwardY - upY * forwardX;

	len = (float)sqrt(sideX * sideX + sideY * sideY + sideZ * sideZ);
	if (len <= 0.0f)
	{
		len = 1.0f;
	}

	sideX /= len;
	sideY /= len;
	sideZ /= len;

	upX2 = forwardY * sideZ - forwardZ * sideY;
	upY2 = forwardZ * sideX - forwardX * sideZ;
	upZ2 = forwardX * sideY - forwardY * sideX;

	mat->Values[0]  = sideX;
	mat->Values[1]  = sideY;
	mat->Values[2]  = sideZ;
	mat->Values[3]  = 0.0f;

	mat->Values[4]  = upX;
	mat->Values[5]  = upY;
	mat->Values[6]  = upZ;
	mat->Values[7]  = 0.0f;

	mat->Values[8]  = -forwardX;
	mat->Values[9]  = -forwardY;
	mat->Values[10] = -forwardZ;
	mat->Values[11] = 0.0f;

	mat->Values[12] = 0.0f;
	mat->Values[13] = 0.0f;
	mat->Values[14] = 0.0f;
	mat->Values[15] = 1.0f;

	transX = -eyeX;
	transY = -eyeY;
	transZ = -eyeZ;

	mat->Values[12] += transX * mat->Values[0] + transY * mat->Values[4] + transZ * mat->Values[8];
	mat->Values[13] += transX * mat->Values[1] + transY * mat->Values[5] + transZ * mat->Values[9];
	mat->Values[14] += transX * mat->Values[2] + transY * mat->Values[6] + transZ * mat->Values[10];
}

void LDL_Mat4fPerspective(LDL_Mat4f* mat, float fovy, float aspect, float nearv, float farv)
{
	float top;
	float right;

	if (mat)
	{
		top   = nearv * (float)tan(fovy * M_PI / 360.0f);
		right = top * aspect;

		mat->Values[0] = nearv / (right - (-right));
		mat->Values[5] = nearv / (top - (-top));
		mat->Values[10] = -(farv + nearv) / (farv - nearv);
		mat->Values[11] = -1;
		mat->Values[14] = -(2 * farv * nearv) / (farv - nearv);
	}
}
