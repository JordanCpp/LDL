#ifndef LDL_Low_Assert_hpp
#define LDL_Low_Assert_hpp

#include <LDL/Low/Types.hpp>
#include <LDL/Low/Config.hpp>

LDL_LIBRARY void LDL_Assert(bool condition, const char* description, const char* file, size_t line);

#define LDL_ASSERT(x) LDL_Assert(x, #x, __FILE__, __LINE__)

#endif