#ifndef LDL_Low_TestEqual_hpp
#define LDL_Low_TestEqual_hpp

#include <LDL/Low/Types.hpp>

void LDL_TestEqual(bool condition, const char* description, const char * file, size_t line);

#define LDL_TEST_EQUAL(x) LDL_TestEqual(x, #x, __FILE__, __LINE__)

#endif    
