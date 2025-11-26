// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Context_hpp
#define LDL_Context_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>
#include <LDL/Enums.hpp>

class LDL_LIBRARY LDL_RenderContext
{
public:
	LDL_RenderContext(size_t mode = LDL_RenderMode::OpenGL1);
	~LDL_RenderContext();
	size_t Mode();
private:
	size_t _mode;
};

#endif  
