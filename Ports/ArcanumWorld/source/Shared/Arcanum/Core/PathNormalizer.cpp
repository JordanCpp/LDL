// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Core/PathNormalizer.hpp>

using namespace Arcanum::Core;

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