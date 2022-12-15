#include <LDL/Core/FastPimpl.hpp>

using namespace LDL::Core;

void* FastPimpl::operator new(size_t bytes)
{
	return ::operator new(bytes);
}

void FastPimpl::operator delete(void* ptr)
{
	delete ptr;
}