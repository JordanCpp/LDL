#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Base/BaseRender.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

void Init()
{
	BaseRender baseRender(Vec2u(800, 600));

	LDL_TEST_EQUAL(baseRender.Size().x == 800);
	LDL_TEST_EQUAL(baseRender.Size().y == 600);

	LDL_TEST_EQUAL(baseRender.Color().Red() == 0);
	LDL_TEST_EQUAL(baseRender.Color().Green() == 0);
	LDL_TEST_EQUAL(baseRender.Color().Blue() == 0);
	LDL_TEST_EQUAL(baseRender.Color().Alpha() == 255);
}

void ColorCheck()
{
	BaseRender baseRender(Vec2u(800, 600));

	baseRender.Color(Color(125, 175, 235));

	LDL_TEST_EQUAL(baseRender.Size().x == 800);
	LDL_TEST_EQUAL(baseRender.Size().y == 600);

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