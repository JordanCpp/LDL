#ifndef LDL_Core_IntegerToString_hpp
#define LDL_Core_IntegerToString_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Core
	{
		class IntegerToString
		{
		public:
			IntegerToString();
			bool Convert(intmax_t num, uint8_t base = 10);
			const char* Result();
		private:
			void Swap(char& t1, char& t2);
			void Reverse(char * str, size_t length);
			char _Buffer[32];
			int _Result;
		};
	}
}

#endif    