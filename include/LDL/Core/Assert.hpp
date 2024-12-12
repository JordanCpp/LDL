#ifndef LDL_Core_Assert_hpp
#define LDL_Core_Assert_hpp

#include <LDL/Core/Types.hpp>
#include <string>

namespace LDL
{
    namespace Core
    {
        LDL_LIBRARY void Assert(bool condition, const std::string& description, const std::string& detail, const char* file, size_t line);
    }
}

#define LDL_ASSERT(x)            LDL::Core::Assert(x, #x, "", __FILE__, __LINE__)
#define LDL_ASSERT_DETAIL(x, y)  LDL::Core::Assert(x, #x,  y, __FILE__, __LINE__)

#endif    
