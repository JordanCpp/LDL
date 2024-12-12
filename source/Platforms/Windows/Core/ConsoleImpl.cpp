#include "ConsoleImpl.hpp"

using namespace LDL::Core;

ConsoleImpl::ConsoleImpl()
{
	_output = GetStdHandle(STD_OUTPUT_HANDLE);
}

void ConsoleImpl::Write(const std::string& text)
{
	DWORD count = 0;

	WriteConsole(_output, text.c_str(), text.size(), &count, NULL);
}
