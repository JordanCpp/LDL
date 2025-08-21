#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/Convert.hpp>
#include <string.h>

using namespace LDL::Core;

int main()
{
	Convert convert;

	LDL_TEST_EQUAL(strcmp(convert.ToString(100500), "100500") == 0);

	return 0;
}
