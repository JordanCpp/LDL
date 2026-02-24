// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_TestEqual_hpp
#define LDL_Core_TestEqual_hpp

#include <string>
#include <LDL/Core/Types.hpp>

namespace LDL
{
	void LDL_LIBRARY TestEqual(bool condition, const std::string& description, const std::string& function, const std::string& file, size_t line);
}

#define LDL_TEST_EQUAL(x) LDL::TestEqual(x, #x, "__FUNCTION__", __FILE__, __LINE__)

#endif    
