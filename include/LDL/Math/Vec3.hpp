#ifndef LDL_Math_Vec3_hpp
#define LDL_Math_Vec3_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Math
	{
		template<typename T>
		class Vec3
		{
		public:
			Vec3()
			{
				_Values[0] = 0;
				_Values[1] = 0;
				_Values[2] = 0;
			}

			Vec3(T v1, T v2, T v3)
			{
				_Values[0] = v1;
				_Values[1] = v2;
				_Values[2] = v3;
			}

			T _Values[3];
		};
	}
}

#endif     