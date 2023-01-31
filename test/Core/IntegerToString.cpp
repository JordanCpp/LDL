#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/IntegerToString.hpp>

using namespace LDL::Core;

int main()
{
	IntegerToString convert;

	LDL_TEST_EQUAL(strcmp(convert.Convert(100500), "100500") == 0);

	return 0;
}