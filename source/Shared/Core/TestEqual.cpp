#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Core/Console.hpp>

void LDL::Core::TestEqual(bool condition, const std::string& description, const std::string& function, const std::string& file, size_t line)
{
	if (!condition)
	{
		NumberToString conv;

		std::string message = '\n' + "Test failed: " + description + ", function " + function + ", file " + file + ", line " + conv.Convert(line) + '\n';

		Console console;
		console.Write(message);
	}
}
