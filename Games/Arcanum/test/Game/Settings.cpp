#include <LDL/Core/TestEqual.hpp>
#include <Arcanum/Game/Settings.hpp>

using namespace Arcanum::Game;

void Default()
{
	Settings settings;

	LDL_TEST_EQUAL(settings.Title() == "");
	LDL_TEST_EQUAL(settings.Size().PosX() == 0);
	LDL_TEST_EQUAL(settings.Size().PosY() == 0);
	LDL_TEST_EQUAL(settings.Fps() == 0);
}

void Init()
{
	Settings settings;

	settings.Title("Disciples project");
	settings.Size(LDL::Graphics::Point2u(800, 600));
	settings.Fps(60);

	LDL_TEST_EQUAL(settings.Title() == "Disciples project");
	LDL_TEST_EQUAL(settings.Size().PosX() == 800);
	LDL_TEST_EQUAL(settings.Size().PosY() == 600);
	LDL_TEST_EQUAL(settings.Fps() == 60);
}

int main()
{
	Default();
	Init();

	return 0;
}