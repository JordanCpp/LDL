#ifndef LDL_Math_Mat2_hpp
#define LDL_Math_Mat2_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Math
	{
		template<typename T>
		class Mat2
		{
		public:
			Mat2()
			{
			}

			T* Values()
			{
				return _Values;
			}

		//private:
			T _Values[4];
		};
	}
}

#endif      