#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/IntegerToString.hpp>

int main()
{
	LDL::Core::IntegerToString convert;

	LDL_TEST_EQUAL(strcmp(convert.Convert(100500), "100500") == 0);

	return 0;
}