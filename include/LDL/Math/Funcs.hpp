#ifndef LDL_Math_Funcs_hpp
#define LDL_Math_Funcs_hpp

#include <LDL/Math/Mat4.hpp>
#include <LDL/Math/Vec3.hpp>
#include <math.h>

namespace LDL
{
	namespace Math
	{
		template<typename T>
		Mat4<T> Translate(Mat4<T>& m, const Vec3<T>& s)
		{
			Mat4<T> result;

			result._Values[12] = s.x;
			result._Values[13] = s.y;
			result._Values[14] = s.z;

			return result * m;
		}

		//mat4_t mat4_rotate(mat4_t mat, double angle, vec3_t axis, mat4_t dest) {

		template<typename T>
		Mat4<T> Rotate(Mat4<T>& m, T angle, const Vec3<T>& axis)
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

			a00 = m._Values[0]; a01 = m._Values[1]; a02 = m._Values[2];  a03 = m._Values[3];
			a10 = m._Values[4]; a11 = m._Values[5]; a12 = m._Values[6];  a13 = m._Values[7];
			a20 = m._Values[8]; a21 = m._Values[9]; a22 = m._Values[10]; a23 = m._Values[11];

			// Construct the elements of the rotation matrix
			b00 = x * x * t + c;     b01 = y * x * t + z * s; b02 = z * x * t - y * s;
			b10 = x * y * t - z * s; b11 = y * y * t + c;     b12 = z * y * t + x * s;
			b20 = x * z * t + y * s; b21 = y * z * t - x * s; b22 = z * z * t + c;

			Mat4<T> result;

			result._Values[12] = m._Values[12];
			result._Values[13] = m._Values[13];
			result._Values[14] = m._Values[14];
			result._Values[15] = m._Values[15];

			// Perform rotation-specific matrix multiplication
			result._Values[0] = a00 * b00 + a10 * b01 + a20 * b02;
			result._Values[1] = a01 * b00 + a11 * b01 + a21 * b02;
			result._Values[2] = a02 * b00 + a12 * b01 + a22 * b02;
			result._Values[3] = a03 * b00 + a13 * b01 + a23 * b02;

			result._Values[4] = a00 * b10 + a10 * b11 + a20 * b12;
			result._Values[5] = a01 * b10 + a11 * b11 + a21 * b12;
			result._Values[6] = a02 * b10 + a12 * b11 + a22 * b12;
			result._Values[7] = a03 * b10 + a13 * b11 + a23 * b12;

			result._Values[8] = a00 * b20 + a10 * b21 + a20 * b22;
			result._Values[9] = a01 * b20 + a11 * b21 + a21 * b22;
			result._Values[10] = a02 * b20 + a12 * b21 + a22 * b22;
			result._Values[11] = a03 * b20 + a13 * b21 + a23 * b22;

			return result;
		}

		template<typename T>
		Mat4<T> Scale(Mat4<T>& m, const Vec3<T>& s)
		{
			/**
			 * Matrix Translation
			 * | sx      |
			 * |   sy    |
			 * |     sz  |
			 * |       1 |
			 */

			Mat4<T> result;

			result._Values[0]  = s.x;
			result._Values[5]  = s.y;
			result._Values[10] = s.z;

			return result * m;
		}

		template<typename T>
		Mat4<T> Perspective(T fovy, T aspect, T zNear, T zFar)
		{
			T f = 1 / (T)tan(fovy * (3.14159265358979323846 / 360.0f));

			Mat4<T> result;

			result._Values[0] = f / aspect;
			result._Values[1] = 0;
			result._Values[2] = 0;
			result._Values[3] = 0;

			result._Values[4] = 0;
			result._Values[5] = f;
			result._Values[6] = 0;
			result._Values[7] = 0;

			result._Values[8] = 0;
			result._Values[9] = 0;
			result._Values[10] = (zFar + zNear) / (zNear - zFar);
			result._Values[11] = -1;

			result._Values[12] = 0;
			result._Values[13] = 0;
			result._Values[14] = 2 * zFar * zNear / (zNear - zFar);
			result._Values[15] = 0;

			return result;
		}

		template<typename T>
		Mat4<T> Ortho(T left, T right, T bottom, T top, T farv, T nearv)
		{
			Mat4<T> result;

			result._Values[0] = (2.0f / (right - left));
			result._Values[5] = (2.0f / (top - bottom));
			result._Values[10] = (-1.0);
			result._Values[12] = (-(right + left) / (right - left));
			result._Values[13] = (-(top + bottom) / (top - bottom));
			result._Values[14] = (-(farv + nearv) / (farv - nearv));

			return result;
		}

		template<typename T>
		Mat4<T> LookAt(const Vec3<T>& eye, const Vec3<T>& center, const Vec3<T>& up)
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

			Mat4<T> result;

			result._Values[0] = x0;
			result._Values[1] = y0;
			result._Values[2] = z0;
			result._Values[3] = 0;
			result._Values[4] = x1;
			result._Values[5] = y1;
			result._Values[6] = z1;
			result._Values[7] = 0;
			result._Values[8] = x2;
			result._Values[9] = y2;
			result._Values[10] = z2;
			result._Values[11] = 0;
			result._Values[12] = -(x0 * eyex + x1 * eyey + x2 * eyez);
			result._Values[13] = -(y0 * eyex + y1 * eyey + y2 * eyez);
			result._Values[14] = -(z0 * eyex + z1 * eyey + z2 * eyez);
			result._Values[15] = 1;

			return result;
		}

		template<typename T>
		Mat4<T> Frustum(T left, T right, T bottom, T top, T zNear, T zFar)
		{
			T rl = (right - left),
				tb = (top - bottom),
				fn = (zFar - zNear);

			Mat4<T> result;

			result._Values[0] = (zNear * 2) / rl;
			result._Values[1] = 0;
			result._Values[2] = 0;
			result._Values[3] = 0;
			result._Values[4] = 0;
			result._Values[5] = (zNear * 2) / tb;
			result._Values[6] = 0;
			result._Values[7] = 0;
			result._Values[8] = (right + left) / rl;
			result._Values[9] = (top + bottom) / tb;
			result._Values[10] = -(zFar + zNear) / fn;
			result._Values[11] = -1;
			result._Values[12] = 0;
			result._Values[13] = 0;
			result._Values[14] = -(zFar * zNear * 2) / fn;
			result._Values[15] = 0;

			return result;
		}

		template<typename T>
		Vec3<T> Normalize(const Vec3<T>& v)
		{
			T length = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

			Vec3<T> result;

			result.x = v.x / length;
			result.y = v.y / length;
			result.z = v.z / length;

			return result;
		}

		template<typename T>
		Vec3<T> Cross(const Vec3<T>& v1, const Vec3<T>& v2)
		{
			Vec3<T> result;

			result.x = v1.y * v2.z - v1.z * v2.y;
			result.y = v1.z * v2.x - v1.x * v2.z;
			result.z = v1.x * v2.y - v1.y * v2.x;

			return result;
		}
	}
}

#endif  