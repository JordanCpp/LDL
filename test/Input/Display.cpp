#include <LDL/Core/TestEqual.hpp>
#include <LDL/Input/Display.hpp>

using namespace LDL::Input;
using namespace LDL::Graphics;

void Modes()
{
	Display display;
	
	std::vector<VideoMode> modes = display.Modes();

	LDL_TEST_EQUAL(modes.size() > 0);

	for (size_t i = 0; i < modes.size(); i++)
	{
		LDL_TEST_EQUAL(modes[i].Size().x > 0);
		LDL_TEST_EQUAL(modes[i].Size().y > 0);
		LDL_TEST_EQUAL(modes[i].BitsPerPixel() > 0);
	}
}

void Current()
{
	Display display;

	VideoMode current = display.Current();

	LDL_TEST_EQUAL(current.Size().x > 0);
	LDL_TEST_EQUAL(current.Size().y > 0);
	LDL_TEST_EQUAL(current.BitsPerPixel() > 0);
}

int main()
{
	Modes();
	Current();

	return 0;
}
