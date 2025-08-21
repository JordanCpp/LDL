#include <LDL/Core/Assert.hpp>
#include <LDL/Core/Console.hpp>
#include <LDL/Core/Terminate.hpp>
#include <LDL/Core/NumberToString.hpp>

using namespace LDL::Core;

void LDL::Core::Assert(bool condition, const std::string& description, const std::string& detail, const char* file, size_t line)
{
	if (!condition)
	{
		NumberToString conv;

		std::string message = '\n' + "Assert: " + description + ", detail " + detail + ", file " + file + ", line " + conv.Convert(line) + '\n';

		Console console;
		console.Write(message);

		Terminate();
	}
}
