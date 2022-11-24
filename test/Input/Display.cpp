#include <LDL/Core/TestEqual.hpp>
#include <LDL/Input/Display.hpp>

void Init()
{
	LDL::Input::Display display;
	
	std::vector<LDL::Graphics::VideoMode> modes = display.Modes();

	LDL_TEST_EQUAL(modes.size() > 0);

	for (size_t i = 0; i < modes.size(); i++)
	{
		LDL_TEST_EQUAL(modes[i].Size().PosX() > 0);
		LDL_TEST_EQUAL(modes[i].Size().PosY() > 0);
		LDL_TEST_EQUAL(modes[i].BitsPerPixel() > 0);
	}
}

int main()
{
	Init();

	return 0;
}