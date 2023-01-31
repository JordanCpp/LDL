#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Base/BaseRender.hpp>

using namespace LDL::Graphics;

void Init()
{
	BaseRender baseRender(Point2u(800, 600));

	LDL_TEST_EQUAL(baseRender.Size().PosX() == 800);
	LDL_TEST_EQUAL(baseRender.Size().PosY() == 600);

	LDL_TEST_EQUAL(baseRender.Color().Red() == 0);
	LDL_TEST_EQUAL(baseRender.Color().Green() == 0);
	LDL_TEST_EQUAL(baseRender.Color().Blue() == 0);
	LDL_TEST_EQUAL(baseRender.Color().Alpha() == 255);
}

void ColorCheck()
{
	BaseRender baseRender(Point2u(800, 600));

	baseRender.Color(Color(125, 175, 235));

	LDL_TEST_EQUAL(baseRender.Size().PosX() == 800);
	LDL_TEST_EQUAL(baseRender.Size().PosY() == 600);

	LDL_TEST_EQUAL(baseRender.Color().Red() == 125);
	LDL_TEST_EQUAL(baseRender.Color().Green() == 175);
	LDL_TEST_EQUAL(baseRender.Color().Blue() == 235);
	LDL_TEST_EQUAL(baseRender.Color().Alpha() == 255);
}

int main()
{
	Init();
	ColorCheck();

	return 0;
}