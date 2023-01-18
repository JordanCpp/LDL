#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/PixelPainter.hpp>

using namespace LDL::Graphics;

void InitDefault()
{
	Surface surface(Point2u(640, 480), 4);

	PixelPainter painter;

	LDL_TEST_EQUAL(painter.Target()        == NULL);
	LDL_TEST_EQUAL(painter.Size().PosX()   == 0);
	LDL_TEST_EQUAL(painter.Size().PosY()   == 0);
	LDL_TEST_EQUAL(painter.BytesPerPixel() == 0);
	LDL_TEST_EQUAL(painter.Pixels()        == NULL);
	LDL_TEST_EQUAL(painter.Color().Red()   == 0);
	LDL_TEST_EQUAL(painter.Color().Green() == 0);
	LDL_TEST_EQUAL(painter.Color().Blue()  == 0);
}

void InitValue()
{
	Surface surface(Point2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	LDL_TEST_EQUAL(painter.Target()        == &surface);
	LDL_TEST_EQUAL(painter.Size().PosX()   == 640);
	LDL_TEST_EQUAL(painter.Size().PosY()   == 480);
	LDL_TEST_EQUAL(painter.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(painter.Pixels()        != NULL);
	LDL_TEST_EQUAL(painter.Color().Red()   == 0);
	LDL_TEST_EQUAL(painter.Color().Green() == 0);
	LDL_TEST_EQUAL(painter.Color().Blue()  == 0);
}

void InitColor()
{
	Surface surface(Point2u(640, 480), 4);

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
	Surface surface(Point2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	painter.Color(LDL::Graphics::Color(1, 2, 3, 4));
	painter.Clear();

	for (size_t i = 0; i < painter.Size().PosX(); i++)
	{
		for (size_t j = 0; j < painter.Size().PosY(); j++)
		{
			LDL_TEST_EQUAL(painter.GetPixel(Point2u(i, j)).Red()   == 1);
			LDL_TEST_EQUAL(painter.GetPixel(Point2u(i, j)).Green() == 2);
			LDL_TEST_EQUAL(painter.GetPixel(Point2u(i, j)).Blue()  == 3);
			LDL_TEST_EQUAL(painter.GetPixel(Point2u(i, j)).Alpha() == 4);
		}
	}
}

void Pixel()
{
	Surface surface(Point2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	painter.Color(LDL::Graphics::Color(1, 2, 3, 4));
	painter.Clear();

	painter.Color(LDL::Graphics::Color(5, 6, 7, 8));
	painter.Pixel(Point2u(150, 300));

	LDL_TEST_EQUAL(painter.GetPixel(Point2u(150, 300)).Red()   == 5);
	LDL_TEST_EQUAL(painter.GetPixel(Point2u(150, 300)).Green() == 6);
	LDL_TEST_EQUAL(painter.GetPixel(Point2u(150, 300)).Blue()  == 7);
	LDL_TEST_EQUAL(painter.GetPixel(Point2u(150, 300)).Alpha() == 8);
}

int main()
{
	InitDefault();
	InitValue();
	InitColor();
	Clear();
	Pixel();

	return 0;
}