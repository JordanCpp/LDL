#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Isometric.hpp>

using namespace LDL::Graphics;

int main()
{
	Isometric isometric;

	Point2u iso = isometric.CartesianToIsometric(Point2u(350, 150));

	LDL_TEST_EQUAL(iso.PosX() == 200);
	LDL_TEST_EQUAL(iso.PosY() == 250);

	Point2u cart = isometric.IsometricToCartesian(iso);

	LDL_TEST_EQUAL(cart.PosX() == 350);
	LDL_TEST_EQUAL(cart.PosY() == 150);

	return 0;
}