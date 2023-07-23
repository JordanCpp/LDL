#include <LDL/Core/TestEqual.hpp>
#include <iostream>

void LDL::Core::TestEqual(bool condition, const char* description, const char* function, const char* file, size_t line)
{
	if (!condition)
	{
		std::cout << "\n"
		<< "Test failed: "
		<< description
		<< ", function "
		<< function
		<< ", file "
		<< file
		<< ", line "
		<< line
		<< '\n';
	}
}
