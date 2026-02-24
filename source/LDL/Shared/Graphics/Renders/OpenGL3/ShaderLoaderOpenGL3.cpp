// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "ShaderLoaderOpenGL3.hpp"

using namespace LDL;

ShaderLoader::ShaderLoader()
{
}

ShaderLoader::~ShaderLoader()
{
}

bool ShaderLoader::Load(const std::string& path)
{
	_file.open(path.c_str());

	if (_file.is_open())
	{
		_result = "";;

		//while (std::getline(_file, _line))
		//{
		//	_result += _line;
		//	_result += '\n';
		//}

		_file.close();

		return true;
	}

	return false;
}

const std::string& ShaderLoader::Result()
{
	return _result;
}
