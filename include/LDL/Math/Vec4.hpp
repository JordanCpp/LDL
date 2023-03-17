#ifndef LDL_Math_Vec4_hpp
#define LDL_Math_Vec4_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Math
	{
		template<typename T>
		class Vec4
		{
		public:
			Vec4()
			{
				_Values[0] = 0;
				_Values[1] = 0;
				_Values[2] = 0;
				_Values[3] = 0;
			}

			Vec4(T v1, T v2, T v3, T v4)
			{
				_Values[0] = v1;
				_Values[1] = v2;
				_Values[2] = v3;
				_Values[3] = v4;
			}

			T _Values[4];
		};
	}
}

#endif     