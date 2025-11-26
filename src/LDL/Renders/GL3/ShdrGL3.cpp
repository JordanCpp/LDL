// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Renders/GL3/ShdrGL3.hpp>

LDL_ShaderLoaderOpenGL3::LDL_ShaderLoaderOpenGL3()
{
}

LDL_ShaderLoaderOpenGL3::~LDL_ShaderLoaderOpenGL3()
{
}

bool LDL_ShaderLoaderOpenGL3::Load(const char* path)
{
	LDL_UNUSED(path);

	/*
	_file.open(path);

	if (_file.is_open())
	{
		_result = "";;

		while (std::getline(_file, _line))
		{
			_result += _line;
			_result += '\n';
		}

		_file.close();

		return true;
	}
	*/

	return false;
}

const char* LDL_ShaderLoaderOpenGL3::LDL_Result()
{
	return NULL;
}
