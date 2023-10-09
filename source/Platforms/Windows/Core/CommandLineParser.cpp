#include <LDL/Core/CommandLineParser.hpp>

using namespace LDL::Core;

CommandLineParser::CommandLineParser(size_t argc, char* argv[])
{
	for (size_t i = 0; i < argc; i++)
	{
		_Lines.push_back(argv[i]);
	}
}

const std::vector<std::string>& CommandLineParser::Lines()
{
	return _Lines;
}
