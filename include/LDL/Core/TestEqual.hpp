#ifndef LDL_Core_TestEqual_hpp
#define LDL_Core_TestEqual_hpp

#include <cstdint>

namespace LDL
{
	namespace Core
	{
		void TestEqual(bool condition, const char* description, const char* function, const char * file, size_t line);
	}
}

#define LDL_TEST_EQUAL(x) LDL::Core::TestEqual(x, #x, __FUNCTION__, __FILE__, __LINE__)

#endif    