#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <string.h>

using namespace LDL::Core;

int main()
{
	NumberToString convert;

	LDL_TEST_EQUAL(strcmp(convert.Convert(100500), "100500") == 0);

	return 0;
}
