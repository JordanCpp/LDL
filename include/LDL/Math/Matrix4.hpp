#ifndef LDL_Math_Matrix4_hpp
#define LDL_Math_Matrix4_hpp

#include <LDL/OpenGL/OpenGLTypes.hpp>
#include <math.h>
#include <string.h>

namespace LDL
{
	namespace Math
	{
		template<typename TYPE>
		class Matrix4
		{
		public:
			enum
			{
				Max = 16
			};

			Matrix4()
			{
				Identity();
			}

			Matrix4<TYPE>& operator=(const Matrix4<TYPE>& source)
			{
				if (this == &source)
					return *this;

				memcpy(&_Values, source._Values, sizeof(_Values));

				return *this;
			}

			TYPE* Values()
			{
				return _Values;
			}

			void Identity()
			{
				_Values[0] = 1;
				_Values[1] = 0;
				_Values[2] = 0;
				_Values[3] = 0;
				_Values[4] = 0;
				_Values[5] = 1;
				_Values[6] = 0;
				_Values[7] = 0;
				_Values[8] = 0;
				_Values[9] = 0;
				_Values[10] = 1;
				_Values[11] = 0;
				_Values[12] = 0;
				_Values[13] = 0;
				_Values[14] = 0;
				_Values[15] = 1;
			}

			void Perspective(TYPE fovy, TYPE aspect, TYPE zNear, TYPE zFar)
			{
				TYPE f = 1 / tan(fovy * (3.14159265358979323846 / 360.0f));

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

			Matrix4 operator * (const Matrix4& m) const {
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

			void Translate(TYPE x, TYPE y, TYPE z)
			{
				Matrix4<TYPE> t;
				t = (*this);

				Identity();
				_Values[12] = x;
				_Values[13] = y;
				_Values[14] = z;

				(*this) = (*this) * t;
			}

			void RotateX(TYPE radians)
			{
				/**
				 * Matrix Rotation X
				 * | 1       |
				 * |   c s   |
				 * |  -s c   |
				 * |       1 |
				 */

				TYPE c = cosf(radians);
				TYPE s = sinf(radians);

				Matrix4<TYPE> t;
				t = (*this);

				Identity();
				_Values[5] = c;
				_Values[6] = s;
				_Values[9] = -s;
				_Values[10] = c;

				(*this) = (*this) * t;
			}

			void RotateY(TYPE radians)
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

				Matrix4<TYPE> t;
				t = (*this);

				Identity();
				_Values[0] = c;
				_Values[2] = -s;
				_Values[8] = s;
				_Values[10] = c;

				(*this) = (*this) * t;
			}

			void RotateZ(TYPE radians)
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

				Matrix4<TYPE> t;
				t = (*this);

				Identity();
				_Values[0] = c;
				_Values[1] = s;
				_Values[4] = -s;
				_Values[5] = c;

				(*this) = (*this) * t;
			}

			void Scale(TYPE sx, TYPE sy, TYPE sz)
			{
				/**
				 * Matrix Translation
				 * | sx      |
				 * |   sy    |
				 * |     sz  |
				 * |       1 |
				 */

				Matrix4<TYPE> t;
				t = (*this);

				Identity();
				_Values[0] = sx;
				_Values[5] = sy;
				_Values[10] = sz;

				(*this) = (*this) * t;
			}

			void Ortho(TYPE left, TYPE right, TYPE bottom, TYPE top, TYPE farv, TYPE nearv)
			{
				_Values[0] = (2.0f / (right - left));
				_Values[5] = (2.0f / (top - bottom));
				_Values[10] = (-1.0);
				_Values[12] = (-(right + left) / (right - left));
				_Values[13] = (-(top + bottom) / (top - bottom));
				_Values[14] = (-(farv + nearv) / (farv - nearv));
			}
		private:
			TYPE _Values[Max];
		};
	}
}

#endif      