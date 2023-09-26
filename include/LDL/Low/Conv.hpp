#ifndef LDL_Low_Conv_hpp
#define LDL_Low_Conv_hpp

#include <LDL/Low/Config.hpp>
#include <LDL/Low/Types.hpp>

class LDL_LIBRARY LDL_NumberToString
{
public:
	LDL_NumberToString();
	const char* Convert(intmax_t num, uint8_t base = 10);
private:
	void Swap(char& t1, char& t2);
	void Reverse(char* str, size_t length);
	char _Buffer[32];
	int _Result;
};

#endif    
