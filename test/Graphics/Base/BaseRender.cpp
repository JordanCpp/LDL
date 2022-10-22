#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Base/BaseRender.hpp>

void Init()
{
	LDL::Graphics::BaseRender baseRender(LDL::Graphics::Point2u(800, 600));

	LDL_TEST_EQUAL(baseRender.Size().PosX() == 800);
	LDL_TEST_EQUAL(baseRender.Size().PosY() == 600);

	LDL_TEST_EQUAL(baseRender.Color().Red() == 0);
	LDL_TEST_EQUAL(baseRender.Color().Green() == 0);
	LDL_TEST_EQUAL(baseRender.Color().Blue() == 0);
	LDL_TEST_EQUAL(baseRender.Color().Alpha() == 255);
}

void Color()
{
	LDL::Graphics::BaseRender baseRender(LDL::Graphics::Point2u(800, 600));

	baseRender.Color(LDL::Graphics::Color(125, 175, 235));

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
	Color();

	return 0;
}