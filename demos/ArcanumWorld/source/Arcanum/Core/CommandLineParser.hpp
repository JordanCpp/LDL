// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Core_CommandLineParser_hpp
#define Arcanum_Core_CommandLineParser_hpp

#include <vector>
#include <string>

namespace Arcanum
{
	class CommandLineParser
	{
	public:
		CommandLineParser(size_t argc, char* argv[]);
		const std::vector<std::string>& Lines();
	private:
		std::vector<std::string> _lines;
	};
}

#endif
