#ifndef LDL_Core_TestEqual_hpp
#define LDL_Core_TestEqual_hpp

#include <string>
#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Core
	{
		void LDL_LIBRARY TestEqual(bool condition, const std::string& description, const std::string& function, const std::string& file, size_t line);
	}
}

#define LDL_TEST_EQUAL(x) LDL::Core::TestEqual(x, #x, "__FUNCTION__", __FILE__, __LINE__)

#endif    
