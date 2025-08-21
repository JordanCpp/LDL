#include <LDL/Core/TestEqual.hpp>
#include <LDL/Math/Isometric.hpp>

using namespace LDL::Math;

void CartesianToIsometric()
{
	Isometric isometric;

	Vec2u iso = isometric.CartesianToIsometric(Vec2u(350, 150));

	LDL_TEST_EQUAL(iso.x == 200);
	LDL_TEST_EQUAL(iso.y == 250);
}

void IsometricToCartesian()
{
	Isometric isometric;

	Vec2u cart = isometric.IsometricToCartesian(Vec2u(200, 250));

	LDL_TEST_EQUAL(cart.x == 350);
	LDL_TEST_EQUAL(cart.y == 150);
}

int main()
{
	CartesianToIsometric();
	IsometricToCartesian();

	return 0;
}
