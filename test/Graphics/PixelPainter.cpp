#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/PixelPainter.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

void InitDefault()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	LDL_TEST_EQUAL(painter.Target()        == NULL);
	LDL_TEST_EQUAL(painter.Size().x   == 0);
	LDL_TEST_EQUAL(painter.Size().y   == 0);
	LDL_TEST_EQUAL(painter.BytesPerPixel() == 0);
	LDL_TEST_EQUAL(painter.Pixels()        == NULL);
	LDL_TEST_EQUAL(painter.Color().Red()   == 0);
	LDL_TEST_EQUAL(painter.Color().Green() == 0);
	LDL_TEST_EQUAL(painter.Color().Blue()  == 0);
}

void InitValue()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	LDL_TEST_EQUAL(painter.Target()        == &surface);
	LDL_TEST_EQUAL(painter.Size().x   == 640);
	LDL_TEST_EQUAL(painter.Size().y   == 480);
	LDL_TEST_EQUAL(painter.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(painter.Pixels()        != NULL);
	LDL_TEST_EQUAL(painter.Color().Red()   == 0);
	LDL_TEST_EQUAL(painter.Color().Green() == 0);
	LDL_TEST_EQUAL(painter.Color().Blue()  == 0);
}

void InitColor()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	painter.Color(LDL::Graphics::Color(1, 2, 3, 4));

	LDL_TEST_EQUAL(painter.Color().Red()   == 1);
	LDL_TEST_EQUAL(painter.Color().Green() == 2);
	LDL_TEST_EQUAL(painter.Color().Blue()  == 3);
	LDL_TEST_EQUAL(painter.Color().Alpha() == 4);
}

void Clear()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	painter.Color(LDL::Graphics::Color(1, 2, 3, 4));
	painter.Clear();

	for (size_t i = 0; i < painter.Size().x; i++)
	{
		for (size_t j = 0; j < painter.Size().y; j++)
		{
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).Red()   == 1);
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).Green() == 2);
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).Blue()  == 3);
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).Alpha() == 4);
		}
	}
}

void Fill()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	painter.Color(LDL::Graphics::Color(0, 0, 0, 0));
	painter.Clear();

	painter.Color(LDL::Graphics::Color(1, 2, 3, 4));
	painter.Fill(Vec2u(50, 50), Vec2u(320, 240));

	for (size_t i = 50; i < 320; i++)
	{
		for (size_t j = 50; j < 240; j++)
		{
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).Red()   == 1);
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).Green() == 2);
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).Blue()  == 3);
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).Alpha() == 4);
		}
	}
}

void Line()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	painter.Color(LDL::Graphics::Color(0, 0, 0, 0));
	painter.Clear();

	painter.Color(LDL::Graphics::Color(1, 2, 3, 4));
	painter.Line(Vec2u(0, 0), Vec2u(320, 0));

	for (size_t i = 0; i < 320; i++)
	{
		LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, 0)).Red()   == 1);
		LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, 0)).Green() == 2);
		LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, 0)).Blue()  == 3);
		LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, 0)).Alpha() == 4);
	}
}

void Pixel()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	painter.Color(LDL::Graphics::Color(1, 2, 3, 4));
	painter.Clear();

	painter.Color(LDL::Graphics::Color(5, 6, 7, 8));
	painter.Pixel(Vec2u(150, 300));

	LDL_TEST_EQUAL(painter.GetPixel(Vec2u(150, 300)).Red()   == 5);
	LDL_TEST_EQUAL(painter.GetPixel(Vec2u(150, 300)).Green() == 6);
	LDL_TEST_EQUAL(painter.GetPixel(Vec2u(150, 300)).Blue()  == 7);
	LDL_TEST_EQUAL(painter.GetPixel(Vec2u(150, 300)).Alpha() == 8);
}

int main()
{
	InitDefault();
	InitValue();
	InitColor();
	Clear();
	Pixel();
	Fill();
	Line();

	return 0;
}