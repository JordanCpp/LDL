#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/VideoMode.hpp>

void Limit()
{
	LDL_TEST_EQUAL(LDL::Graphics::VideoMode::Limit > 0);
}

void Default()
{
	LDL::Graphics::VideoMode videoMode;

	LDL_TEST_EQUAL(videoMode.Size().PosX()  == 0);
	LDL_TEST_EQUAL(videoMode.Size().PosY()  == 0);
	LDL_TEST_EQUAL(videoMode.BitsPerPixel() == 0);
}

void Init()
{
	LDL_TEST_EQUAL(LDL::Graphics::VideoMode::Limit > 0);

	LDL::Graphics::VideoMode videoMode(LDL::Graphics::Point2u(800, 600), 32);

	LDL_TEST_EQUAL(videoMode.Size().PosX()  == 800);
	LDL_TEST_EQUAL(videoMode.Size().PosY()  == 600);
	LDL_TEST_EQUAL(videoMode.BitsPerPixel() == 32);
}

int main()
{
	Limit();
	Default();
	Init();

	return 0;
}