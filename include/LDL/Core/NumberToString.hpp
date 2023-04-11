#ifndef LDL_Core_NumberToString_hpp
#define LDL_Core_NumberToString_hpp

#include <LDL/Config.hpp>
#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Core
	{
		class LDL_EXPORT NumberToString
		{
		public:
			NumberToString();
			const char* Convert(intmax_t num, uint8_t base = 10);
		private:
			void Swap(char& t1, char& t2);
			void Reverse(char * str, size_t length);
			char _Buffer[32];
			int _Result;
		};
	}
}

#endif    