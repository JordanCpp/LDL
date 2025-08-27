// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Core/CommandLineParser.hpp>

using namespace Arcanum;

CommandLineParser::CommandLineParser(size_t argc, char* argv[])
{
	for (size_t i = 0; i < argc; i++)
	{
		_lines.push_back(argv[i]);
	}
}

const std::vector<std::string>& CommandLineParser::Lines()
{
	return _lines;
}
