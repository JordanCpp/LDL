// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Funcs_hpp
#define LDL_Funcs_hpp

#include <math.h>
#include <LDL/Mat4.hpp>
#include <LDL/Vec3.hpp>

template<class T>
LDL_Mat4<T> LDL_Translate(LDL_Mat4<T>& m, const LDL_Vec3<T>& s)
{
	LDL_Mat4<T> result;

	result._values[12] = s.x;
	result._values[13] = s.y;
	result._values[14] = s.z;

	return result * m;
}

template<class T>
LDL_Mat4<T> LDL_Rotate(LDL_Mat4<T>& m, T angle, const LDL_Vec3<T>& axis)
{
	T x = axis.x;
	T y = axis.y;
	T z = axis.z;

	T len = (T)sqrt(x * x + y * y + z * z);

	T s, c, t,
		a00, a01, a02, a03,
		a10, a11, a12, a13,
		a20, a21, a22, a23,
		b00, b01, b02,
		b10, b11, b12,
		b20, b21, b22;

	//if (!len) { return NULL; }

	if (len != 1) {
		len = 1 / len;
		x *= len;
		y *= len;
		z *= len;
	}

	s = (T)sin(angle);
	c = (T)cos(angle);
	t = 1 - c;

	a00 = m._values[0]; a01 = m._values[1]; a02 = m._values[2];  a03 = m._values[3];
	a10 = m._values[4]; a11 = m._values[5]; a12 = m._values[6];  a13 = m._values[7];
	a20 = m._values[8]; a21 = m._values[9]; a22 = m._values[10]; a23 = m._values[11];

	// Construct the elements of the rotation matrix
	b00 = x * x * t + c;     b01 = y * x * t + z * s; b02 = z * x * t - y * s;
	b10 = x * y * t - z * s; b11 = y * y * t + c;     b12 = z * y * t + x * s;
	b20 = x * z * t + y * s; b21 = y * z * t - x * s; b22 = z * z * t + c;

	LDL_Mat4<T> result;

	result._values[12] = m._values[12];
	result._values[13] = m._values[13];
	result._values[14] = m._values[14];
	result._values[15] = m._values[15];

	// Perform rotation-specific matrix multiplication
	result._values[0] = a00 * b00 + a10 * b01 + a20 * b02;
	result._values[1] = a01 * b00 + a11 * b01 + a21 * b02;
	result._values[2] = a02 * b00 + a12 * b01 + a22 * b02;
	result._values[3] = a03 * b00 + a13 * b01 + a23 * b02;

	result._values[4] = a00 * b10 + a10 * b11 + a20 * b12;
	result._values[5] = a01 * b10 + a11 * b11 + a21 * b12;
	result._values[6] = a02 * b10 + a12 * b11 + a22 * b12;
	result._values[7] = a03 * b10 + a13 * b11 + a23 * b12;

	result._values[8] = a00 * b20 + a10 * b21 + a20 * b22;
	result._values[9] = a01 * b20 + a11 * b21 + a21 * b22;
	result._values[10] = a02 * b20 + a12 * b21 + a22 * b22;
	result._values[11] = a03 * b20 + a13 * b21 + a23 * b22;

	return result;
}

template<class T>
LDL_Mat4<T> LDL_Scale(LDL_Mat4<T>& m, const LDL_Vec3<T>& s)
{
	/**
	 * Matrix Translation
	 * | sx      |
	 * |   sy    |
	 * |     sz  |
	 * |       1 |
	 */

	LDL_Mat4<T> result;

	result._values[0] = s.x;
	result._values[5] = s.y;
	result._values[10] = s.z;

	return result * m;
}

template<class T>
LDL_Mat4<T> LDL_Perspective(T fovy, T aspect, T zNear, T zFar)
{
	T f = 1 / (T)tan(fovy * (3.14159265358979323846 / 360.0f));

	LDL_Mat4<T> result;

	result._values[0] = f / aspect;
	result._values[1] = 0;
	result._values[2] = 0;
	result._values[3] = 0;

	result._values[4] = 0;
	result._values[5] = f;
	result._values[6] = 0;
	result._values[7] = 0;

	result._values[8] = 0;
	result._values[9] = 0;
	result._values[10] = (zFar + zNear) / (zNear - zFar);
	result._values[11] = -1;

	result._values[12] = 0;
	result._values[13] = 0;
	result._values[14] = 2 * zFar * zNear / (zNear - zFar);
	result._values[15] = 0;

	return result;
}

template<class T>
LDL_Mat4<T> LDL_Ortho(T left, T right, T bottom, T top, T farv, T nearv)
{
	LDL_Mat4<T> result;

	result._values[0] = (2.0f / (right - left));
	result._values[5] = (2.0f / (top - bottom));
	result._values[10] = (-1.0);
	result._values[12] = (-(right + left) / (right - left));
	result._values[13] = (-(top + bottom) / (top - bottom));
	result._values[14] = (-(farv + nearv) / (farv - nearv));

	return result;
}

template<class T>
LDL_Mat4<T> LDL_LookAt(const LDL_Vec3<T>& eye, const LDL_Vec3<T>& center, const LDL_Vec3<T>& up)
{
	T x0, x1, x2, y0, y1, y2, z0, z1, z2, len,
		eyex = eye.x,
		eyey = eye.y,
		eyez = eye.z,
		upx = up.x,
		upy = up.y,
		upz = up.z,
		centerx = center.x,
		centery = center.y,
		centerz = center.z;

	//if (eyex == centerx && eyey == centery && eyez == centerz) {
	//	return mat4_identity(dest);
	//}

	//vec3.direction(eye, center, z);
	z0 = eyex - centerx;
	z1 = eyey - centery;
	z2 = eyez - centerz;

	// normalize (no check needed for 0 because of early return)
	len = 1 / (T)sqrt(z0 * z0 + z1 * z1 + z2 * z2);
	z0 *= len;
	z1 *= len;
	z2 *= len;

	//vec3.normalize(vec3.cross(up, z, x));
	x0 = upy * z2 - upz * z1;
	x1 = upz * z0 - upx * z2;
	x2 = upx * z1 - upy * z0;
	len = (T)sqrt(x0 * x0 + x1 * x1 + x2 * x2);
	if (!len) {
		x0 = 0;
		x1 = 0;
		x2 = 0;
	}
	else {
		len = 1 / len;
		x0 *= len;
		x1 *= len;
		x2 *= len;
	}

	//vec3.normalize(vec3.cross(z, x, y));
	y0 = z1 * x2 - z2 * x1;
	y1 = z2 * x0 - z0 * x2;
	y2 = z0 * x1 - z1 * x0;

	len = (T)sqrt(y0 * y0 + y1 * y1 + y2 * y2);
	if (!len) {
		y0 = 0;
		y1 = 0;
		y2 = 0;
	}
	else {
		len = 1 / len;
		y0 *= len;
		y1 *= len;
		y2 *= len;
	}

	LDL_Mat4<T> result;

	result._values[0] = x0;
	result._values[1] = y0;
	result._values[2] = z0;
	result._values[3] = 0;
	result._values[4] = x1;
	result._values[5] = y1;
	result._values[6] = z1;
	result._values[7] = 0;
	result._values[8] = x2;
	result._values[9] = y2;
	result._values[10] = z2;
	result._values[11] = 0;
	result._values[12] = -(x0 * eyex + x1 * eyey + x2 * eyez);
	result._values[13] = -(y0 * eyex + y1 * eyey + y2 * eyez);
	result._values[14] = -(z0 * eyex + z1 * eyey + z2 * eyez);
	result._values[15] = 1;

	return result;
}

template<class T>
LDL_Mat4<T> LDL_Frustum(T left, T right, T bottom, T top, T zNear, T zFar)
{
	T rl = (right - left),
		tb = (top - bottom),
		fn = (zFar - zNear);

	LDL_Mat4<T> result;

	result._values[0] = (zNear * 2) / rl;
	result._values[1] = 0;
	result._values[2] = 0;
	result._values[3] = 0;
	result._values[4] = 0;
	result._values[5] = (zNear * 2) / tb;
	result._values[6] = 0;
	result._values[7] = 0;
	result._values[8] = (right + left) / rl;
	result._values[9] = (top + bottom) / tb;
	result._values[10] = -(zFar + zNear) / fn;
	result._values[11] = -1;
	result._values[12] = 0;
	result._values[13] = 0;
	result._values[14] = -(zFar * zNear * 2) / fn;
	result._values[15] = 0;

	return result;
}

template<class T>
LDL_Vec3<T> LDL_Normalize(const LDL_Vec3<T>& v)
{
	T length = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

	LDL_Vec3<T> result;

	result.x = v.x / length;
	result.y = v.y / length;
	result.z = v.z / length;

	return result;
}

template<class T>
LDL_Vec3<T> LDL_Cross(const LDL_Vec3<T>& v1, const LDL_Vec3<T>& v2)
{
	LDL_Vec3<T> result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;

	return result;
}

#endif
