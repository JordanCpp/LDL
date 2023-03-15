#ifndef LDL_Math_Mat4_hpp
#define LDL_Math_Mat4_hpp

#include <LDL/Core/Types.hpp>

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

			Mat4<T>& operator * (const Mat4<T>& m) const {
				Mat4<T> result;

				result._Values[0] = ((_Values[0] * m._Values[0]) + (_Values[1] * m._Values[4]) + (_Values[2] * m._Values[8]) + (_Values[3] * m._Values[12]));
				result._Values[1] = ((_Values[0] * m._Values[1]) + (_Values[1] * m._Values[5]) + (_Values[2] * m._Values[9]) + (_Values[3] * m._Values[13]));
				result._Values[2] = ((_Values[0] * m._Values[2]) + (_Values[1] * m._Values[6]) + (_Values[2] * m._Values[10]) + (_Values[3] * m._Values[14]));
				result._Values[3] = ((_Values[0] * m._Values[3]) + (_Values[1] * m._Values[7]) + (_Values[2] * m._Values[11]) + (_Values[3] * m._Values[15]));

				result._Values[4] = ((_Values[4] * m._Values[0]) + (_Values[5] * m._Values[4]) + (_Values[6] * m._Values[8]) + (_Values[7] * m._Values[12]));
				result._Values[5] = ((_Values[4] * m._Values[1]) + (_Values[5] * m._Values[5]) + (_Values[6] * m._Values[9]) + (_Values[7] * m._Values[13]));
				result._Values[6] = ((_Values[4] * m._Values[2]) + (_Values[5] * m._Values[6]) + (_Values[6] * m._Values[10]) + (_Values[7] * m._Values[14]));
				result._Values[7] = ((_Values[4] * m._Values[3]) + (_Values[5] * m._Values[7]) + (_Values[6] * m._Values[11]) + (_Values[7] * m._Values[15]));

				result._Values[8] = ((_Values[8] * m._Values[0]) + (_Values[9] * m._Values[4]) + (_Values[10] * m._Values[8]) + (_Values[11] * m._Values[12]));
				result._Values[9] = ((_Values[8] * m._Values[1]) + (_Values[9] * m._Values[5]) + (_Values[10] * m._Values[9]) + (_Values[11] * m._Values[13]));
				result._Values[10] = ((_Values[8] * m._Values[2]) + (_Values[9] * m._Values[6]) + (_Values[10] * m._Values[10]) + (_Values[11] * m._Values[14]));
				result._Values[11] = ((_Values[8] * m._Values[3]) + (_Values[9] * m._Values[7]) + (_Values[10] * m._Values[11]) + (_Values[11] * m._Values[15]));

				result._Values[12] = ((_Values[12] * m._Values[0]) + (_Values[13] * m._Values[4]) + (_Values[14] * m._Values[8]) + (_Values[15] * m._Values[12]));
				result._Values[13] = ((_Values[12] * m._Values[1]) + (_Values[13] * m._Values[5]) + (_Values[14] * m._Values[9]) + (_Values[15] * m._Values[13]));
				result._Values[14] = ((_Values[12] * m._Values[2]) + (_Values[13] * m._Values[6]) + (_Values[14] * m._Values[10]) + (_Values[15] * m._Values[14]));
				result._Values[15] = ((_Values[12] * m._Values[3]) + (_Values[13] * m._Values[7]) + (_Values[14] * m._Values[11]) + (_Values[15] * m._Values[15]));

				return result;
			}

			T _Values[16];
		};
	}
}

#endif     