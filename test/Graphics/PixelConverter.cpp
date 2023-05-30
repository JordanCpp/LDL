#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/PixelConverter.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

void Fill()
{
	Vec2u size(800, 600);
	uint8_t bytesPerPixel = 4;

	Color* pixels = new Color[size.x * size.y];

	PixelConverter pixelConverter;

	pixelConverter.Fill((uint8_t*)pixels, size, bytesPerPixel, Color(1, 2, 3, 4));

	for (size_t i = 0; i < size.x * size.y; i++)
	{
		LDL_TEST_EQUAL(pixels[i].r == 1);
		LDL_TEST_EQUAL(pixels[i].g == 2);
		LDL_TEST_EQUAL(pixels[i].b == 3);
		LDL_TEST_EQUAL(pixels[i].a == 4);
	}

	delete[] pixels;
}

void BgrToRgb()
{
	Vec2u size(800, 600);
	uint8_t bytesPerPixel = 4;

	Color* pixels = new Color[size.x * size.y];

	PixelConverter pixelConverter;

	pixelConverter.Fill((uint8_t*)pixels, size, bytesPerPixel, Color(1, 2, 3, 4));

	pixelConverter.BgrToRgb((uint8_t*)pixels, size, bytesPerPixel);

	for (size_t i = 0; i < size.x * size.y; i++)
	{
		LDL_TEST_EQUAL(pixels[i].r == 3);
		LDL_TEST_EQUAL(pixels[i].g == 2);
		LDL_TEST_EQUAL(pixels[i].b == 1);
		LDL_TEST_EQUAL(pixels[i].a == 4);
	}

	delete[] pixels;
}

void RgbToBgr()
{
	Vec2u size(800, 600);
	uint8_t bytesPerPixel = 4;

	Color* pixels = new Color[size.x * size.y];

	PixelConverter pixelConverter;

	pixelConverter.Fill((uint8_t*)pixels, size, bytesPerPixel, Color(1, 2, 3, 4));

	pixelConverter.BgrToRgb((uint8_t*)pixels, size, bytesPerPixel);

	for (size_t i = 0; i < size.x * size.y; i++)
	{
		LDL_TEST_EQUAL(pixels[i].r == 3);
		LDL_TEST_EQUAL(pixels[i].g == 2);
		LDL_TEST_EQUAL(pixels[i].b == 1);
		LDL_TEST_EQUAL(pixels[i].a == 4);
	}

	delete[] pixels;
}

int main()
{
	Fill();
	BgrToRgb();
	RgbToBgr();

	return 0;
}