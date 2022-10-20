#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Rect2i.hpp>
#include <LDL/Graphics/Point2i.hpp>

void DefaultInit()
{
	LDL::Graphics::Rect2i rect;

	LDL_TEST_EQUAL(rect.Pos().PosX() == 0);
	LDL_TEST_EQUAL(rect.Pos().PosY() == 0);
	LDL_TEST_EQUAL(rect.Size().PosX() == 0);
	LDL_TEST_EQUAL(rect.Size().PosY() == 0);
}

void ValueInit()
{
	LDL::Graphics::Rect2i rect2(15, 25, 35, 45);

	LDL_TEST_EQUAL(rect2.Pos().PosX() == 15);
	LDL_TEST_EQUAL(rect2.Pos().PosY() == 25);
	LDL_TEST_EQUAL(rect2.Size().PosX() == 35);
	LDL_TEST_EQUAL(rect2.Size().PosY() == 45);
}

void Point2Init()
{
	LDL::Graphics::Rect2i rect3(LDL::Graphics::Point2i(115, 125), LDL::Graphics::Point2i(135, 145));

	LDL_TEST_EQUAL(rect3.Pos().PosX() == 115);
	LDL_TEST_EQUAL(rect3.Pos().PosY() == 125);
	LDL_TEST_EQUAL(rect3.Size().PosX() == 135);
	LDL_TEST_EQUAL(rect3.Size().PosY() == 145);
}

int main()
{
	DefaultInit();
	ValueInit();
	Point2Init();

	return 0;
}