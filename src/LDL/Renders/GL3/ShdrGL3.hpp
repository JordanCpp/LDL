// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Renders_GL3_ShdrGL3_hpp
#define LDL_Renders_GL3_ShdrGL3_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>

class LDL_ShaderLoaderOpenGL3
{
public:
	LDL_ShaderLoaderOpenGL3();
	~LDL_ShaderLoaderOpenGL3();
	bool Load(const char* path);
	const char* LDL_Result();
private:
};

#endif    
