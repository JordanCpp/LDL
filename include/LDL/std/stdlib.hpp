#ifndef LDL_std_stdlib_hpp
#define LDL_std_stdlib_hpp

#include <LDL/Config.hpp>
#include <LDL/std/stddef.hpp>

namespace LDL
{
	LDL_LIBRARY void* LDL_malloc(size_t bytes);
	LDL_LIBRARY void LDL_free(void* ptr);
}

#endif    
