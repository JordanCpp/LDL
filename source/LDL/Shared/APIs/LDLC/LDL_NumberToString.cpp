#include <LDLC/LDL_NumberToString.h>
#include <LDL/Core/Convert.hpp>

using namespace LDL::Core;

struct LDL_NumberToString
{
	Convert _numberToString;
};

LDL_NumberToString* LDL_NumberToStringNew()
{
	LDL_NumberToString* p = new LDL_NumberToString();

	return p;
}

void LDL_NumberToStringFree(LDL_NumberToString* numberToString)
{
	delete numberToString;
}

const char* LDL_NumberToStringConvertInt(LDL_NumberToString* numberToString, intmax_t num)
{
	return numberToString->_numberToString.ToString(num);
}
