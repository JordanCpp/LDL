#include "ShaderLoaderOpenGL3.hpp"

using namespace LDL::Graphics;

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

		while (std::getline(_file, _line))
		{
			_result += _line;
			_result += '\n';
		}

		_file.close();

		return true;
	}

	return false;
}

const std::string& ShaderLoader::Result()
{
	return _result;
}
