
#include <LDL/std/stdlib.hpp>
#include <LDL/Core/MemoryManager.hpp>

void* LDL::malloc(size_t bytes)
{
	return LDL::Core::MemoryManager::Instance().GetMalloc()(bytes);
}

void LDL::free(void* ptr)
{
	LDL::Core::MemoryManager::Instance().GetFree()(ptr);
}
