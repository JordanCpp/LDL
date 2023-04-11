#include "ShaderLoader.hpp"

using namespace LDL::Graphics;

ShaderLoader::ShaderLoader()
{
}

ShaderLoader::~ShaderLoader()
{
}

bool ShaderLoader::Load(const std::string& path)
{
	_File.open(path);

	if (_File.is_open())
	{
		_Result.clear();

		while (std::getline(_File, _Line))
		{
			_Result += _Line;
			_Result += '\n';
		}

		_File.close();

		return true;
	}

	return false;
}

const std::string& ShaderLoader::Result()
{
	return _Result;
}