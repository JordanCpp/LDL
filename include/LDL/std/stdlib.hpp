#ifndef LDL_std_stdlib_hpp
#define LDL_std_stdlib_hpp

#include <LDL/Core/Config.hpp>
#include <LDL/std/stddef.hpp>

namespace LDL
{
	LDL_LIBRARY void* malloc(size_t bytes);
	LDL_LIBRARY void free(void* ptr);
}

#endif    
