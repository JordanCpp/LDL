#include <LDLC/LDL_NumberToString.h>
#include <LDL/Core/NumberToString.hpp>

using namespace LDL::Core;

struct LDL_NumberToString
{
	NumberToString _numberToString;
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
	return numberToString->_numberToString.Convert(num);
}
