#ifndef LDL_Core_TestEqual_hpp
#define LDL_Core_TestEqual_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <iostream>

namespace LDL
{
	namespace Core
	{
		void LDL_EXPORT TestEqual(bool condition, const char* description, const char* function, const char * file, size_t line);
	}
}

#define LDL_TEST_EQUAL(x) LDL::Core::TestEqual(x, #x, "__FUNCTION__", __FILE__, __LINE__)

#define LDL_TEST_EXCEPTION( expression)              \
  try                                                \
  {                                                  \
    (expression);                                    \
  }                                                  \
  catch( LDL::Core::RuntimeError& error )            \
  {                                                  \
    std::cout << error.what()                        \
              << std::string( __FILE__ )             \
              << std::string( ":" )                  \
              << std::to_string( __LINE__ )          \
              << std::string( " in " )               \
              << std::string( "__FUNCTION__" )       \
              << '\n';                               \
  }                                                  \


#endif    