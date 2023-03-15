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
		Mat4<T>& Translate(Mat4<T>& m, Vec3<T>& v)
		{
			Mat4<T>& result(m);

			result._Values[12] = v._Values[0];
			result._Values[13] = v._Values[1];
			result._Values[14] = v._Values[2];

			return result;
		}

		template<typename T>
		Mat4<T>& Ortho(T left, T right, T bottom, T top, T farv, T nearv)
		{
			Mat4<T> result;

			result._Values[0] = (2 / (right - left));
			result._Values[5] = (2 / (top - bottom));
			result._Values[10] = (-1);
			result._Values[12] = (-(right + left) / (right - left));
			result._Values[13] = (-(top + bottom) / (top - bottom));
			result._Values[14] = (-(farv + nearv) / (farv - nearv));

			return result;
		}

		template<typename T>
		Mat4<T>& Perspective(T fovy, T aspect, T zNear, T zFar)
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
	}
}

#endif  