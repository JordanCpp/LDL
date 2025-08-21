#ifndef LDL_Core_Convert_hpp
#define LDL_Core_Convert_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Core
	{
		class LDL_LIBRARY Convert
		{
		public:
			Convert();
			const char* ToString(intmax_t num, uint8_t base = 10);
		private:
			void Swap(char& t1, char& t2);
			void Reverse(char * str, size_t length);
			char _buffer[32];
			int  _result;
		};
	}
}

#endif    
