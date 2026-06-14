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

#ifndef LDL_Mat4f_H
#define LDL_Mat4f_H

#include <LDL/Types.h>
#include <LDL/Config.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Mat4f
{
	float Values[16];
} LDL_Mat4f;

LDL_LIBRARY float* LDL_Mat4fGetValues(LDL_Mat4f* mat);
LDL_LIBRARY void LDL_Mat4fIdentity(LDL_Mat4f* mat);
LDL_LIBRARY void LDL_Mat4fOrtho(LDL_Mat4f* mat, float left, float right, float bottom, float top, float farv, float nearv);
LDL_LIBRARY void LDL_Mat4fTranslate(LDL_Mat4f* mat, float x, float y, float z);
LDL_LIBRARY void LDL_Mat4fMultiply(LDL_Mat4f* result, const LDL_Mat4f* a, const LDL_Mat4f* b);
LDL_LIBRARY void LDL_Mat4fRotate(LDL_Mat4f* mat, float angle, float x, float y, float z);
LDL_LIBRARY void LDL_Mat4fCross(LDL_Mat4f* result, const LDL_Mat4f* a, const LDL_Mat4f* b);
LDL_LIBRARY void LDL_Mat4fLookAt(LDL_Mat4f* mat, float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
LDL_LIBRARY void LDL_Mat4fPerspective(LDL_Mat4f* mat, float fovy, float aspect, float nearv, float farv);

#ifdef __cplusplus
}
#endif 

#endif
