#ifndef LDL_Math_Mat4_hpp
#define LDL_Math_Mat4_hpp

#include <LDL/OpenGL/OpenGLTypes.hpp>
#include <math.h>
#include <string.h>

namespace LDL
{
	namespace Math
	{
		template<typename T>
		class Mat4
		{
		public:
			Mat4()
			{
				Identity();
			}

			Mat4<T>& operator=(const Mat4<T>& source)
			{
				if (this == &source)
					return *this;

				memcpy(&_Values, source._Values, sizeof(_Values));

				return *this;
			}

			T* Values()
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

			Mat4 operator * (const Mat4& m) const {
				Mat4 ret;

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

		//private:
			T _Values[16];
		};
	}
}

#endif      