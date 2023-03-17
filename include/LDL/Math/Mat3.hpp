#ifndef LDL_Math_Mat3_hpp
#define LDL_Math_Mat3_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Math
	{
		template<typename T>
		class Mat3
		{
		public:
			Mat3()
			{
			}

			T* Values()
			{
				return _Values;
			}

		//private:
			T _Values[9];
		};
	}
}

#endif      