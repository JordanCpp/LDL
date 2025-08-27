
#include <LDL/std/stdlib.hpp>
#include <LDL/Core/MemoryManager.hpp>

void* LDL::Malloc(size_t bytes)
{
	return LDL::MemoryManager::Instance().GetMalloc()(bytes);
}

void LDL::Free(void* ptr)
{
	LDL::MemoryManager::Instance().GetFree()(ptr);
}
