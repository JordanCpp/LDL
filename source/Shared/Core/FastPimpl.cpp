#include <LDL/Core/FastPimpl.hpp>
#include <stdlib.h>

using namespace LDL::Core;

void* FastPimpl::operator new(size_t bytes)
{
	return malloc(bytes);
}

void FastPimpl::operator delete(void* ptr)
{
	free(ptr);
}
