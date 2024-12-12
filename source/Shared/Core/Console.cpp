#include <LDL/Core/Console.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Core/ConsoleImpl.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Core/ConsoleImpl.hpp"
#endif

using namespace LDL::Core;

Console::Console() :
	_impl(new ConsoleImpl())
{
}

Console::~Console()
{
	delete _impl;
}

void Console::Write(const std::string& text)
{
	_impl->Write(text);
}
