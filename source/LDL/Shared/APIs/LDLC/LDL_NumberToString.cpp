// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDLC/LDL_Convert.h>
#include <LDL/Core/Convert.hpp>

using namespace LDL;

struct LDL_Convert
{
	Convert _numberToString;
};

LDL_Convert* LDL_ConvertNew()
{
	LDL_Convert* p = new LDL_Convert();

	return p;
}

void LDL_ConvertFree(LDL_Convert* numberToString)
{
	delete numberToString;
}

const char* LDL_ConvertToString(LDL_Convert* numberToString, intmax_t num)
{
	return numberToString->_numberToString.ToString(num);
}
