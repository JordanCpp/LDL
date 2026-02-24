#include <Arcanum/Core/PathNormalizer.hpp>

using namespace Arcanum;

void PathNormalizer::Normalize(char* path)
{
	size_t i = 0;

	while (path[i] != '\0')
	{
		if (path[i] == '\\')
			path[i] = '/';

		i++;
	}
}

void PathNormalizer::Normalize(std::string& path)
{
	Normalize((char*)path.c_str());
}