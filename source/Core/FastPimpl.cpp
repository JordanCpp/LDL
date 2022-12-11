#include <LDL/Core/FastPimpl.hpp>

void* LDL::Core::FastPimpl::operator new(size_t bytes)
{
	return ::operator new(bytes);
}

void LDL::Core::FastPimpl::operator delete(void* ptr)
{
	delete ptr;
}