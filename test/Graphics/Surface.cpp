#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Surface.hpp>

using namespace LDL::Graphics;

const Point2u Size     = Point2u(320, 240);
const Point2u Capacity = Point2u(640, 480);

void Init()
{
	Surface surface(Size, 4);

	LDL_TEST_EQUAL(surface.Pixels() != nullptr);

	LDL_TEST_EQUAL(surface.Capacity().PosX() == Size.PosX());
	LDL_TEST_EQUAL(surface.Capacity().PosY() == Size.PosY());

	LDL_TEST_EQUAL(surface.Size().PosX() == Size.PosX());
	LDL_TEST_EQUAL(surface.Size().PosY() == Size.PosY());

	LDL_TEST_EQUAL(surface.Bytes() == Size.PosX() * Size.PosY() * 4);

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);

	LDL_TEST_EQUAL(surface.Empty() == false);
}

void InitCapacity()
{
	Surface surface(Size, 4, Capacity);

	LDL_TEST_EQUAL(surface.Pixels() != nullptr);

	LDL_TEST_EQUAL(surface.Capacity().PosX() == Capacity.PosX());
	LDL_TEST_EQUAL(surface.Capacity().PosY() == Capacity.PosY());

	LDL_TEST_EQUAL(surface.Size().PosX() == Size.PosX());
	LDL_TEST_EQUAL(surface.Size().PosY() == Size.PosY());

	LDL_TEST_EQUAL(surface.Bytes() == Capacity.PosX() * Capacity.PosY() * 4);

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);

	LDL_TEST_EQUAL(surface.Empty() == false);
}

void Clear()
{
	Surface surface(Size, 4);

	surface.Clear();

	LDL_TEST_EQUAL(surface.Pixels() != nullptr);

	LDL_TEST_EQUAL(surface.Capacity().PosX() == Size.PosX());
	LDL_TEST_EQUAL(surface.Capacity().PosY() == Size.PosY());

	LDL_TEST_EQUAL(surface.Size().PosX() == 0);
	LDL_TEST_EQUAL(surface.Size().PosY() == 0);

	LDL_TEST_EQUAL(surface.Bytes() == Size.PosX() * Size.PosY() * 4);

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);

	LDL_TEST_EQUAL(surface.Empty() == true);
}

void ClearCapacity()
{
	Surface surface(Size, 4, Capacity);

	surface.Clear();

	LDL_TEST_EQUAL(surface.Pixels() != nullptr);

	LDL_TEST_EQUAL(surface.Capacity().PosX() == Capacity.PosX());
	LDL_TEST_EQUAL(surface.Capacity().PosY() == Capacity.PosY());

	LDL_TEST_EQUAL(surface.Size().PosX() == 0);
	LDL_TEST_EQUAL(surface.Size().PosY() == 0);

	LDL_TEST_EQUAL(surface.Bytes() == Capacity.PosX() * Capacity.PosY() * 4);

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);

	LDL_TEST_EQUAL(surface.Empty() == true);
}

void ClearColor()
{
	Surface surface(Size, 4);

	surface.Clear(Color(1, 2, 3, 4));

	LDL_TEST_EQUAL(surface.Pixels() != nullptr);

	LDL_TEST_EQUAL(surface.Capacity().PosX() == Size.PosX());
	LDL_TEST_EQUAL(surface.Capacity().PosY() == Size.PosY());

	LDL_TEST_EQUAL(surface.Size().PosX() == Size.PosX());
	LDL_TEST_EQUAL(surface.Size().PosY() == Size.PosY());

	LDL_TEST_EQUAL(surface.Bytes() == Size.PosX() * Size.PosY() * 4);

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);

	LDL_TEST_EQUAL(surface.Empty() == false);

	Color* pixels = (Color*)surface.Pixels();

	for (size_t i = 0; i < surface.Size().PosX() * surface.Size().PosY(); i++)
	{
		LDL_TEST_EQUAL(pixels[i].Red()   == 1);
		LDL_TEST_EQUAL(pixels[i].Green() == 2);
		LDL_TEST_EQUAL(pixels[i].Blue()  == 3);
		LDL_TEST_EQUAL(pixels[i].Alpha() == 4);
	}
}

void ClearColorCapacity()
{
	Surface surface(Size, 4, Capacity);

	surface.Clear(Color(1, 2, 3, 4));

	LDL_TEST_EQUAL(surface.Pixels() != nullptr);

	LDL_TEST_EQUAL(surface.Capacity().PosX() == Capacity.PosX());
	LDL_TEST_EQUAL(surface.Capacity().PosY() == Capacity.PosY());

	LDL_TEST_EQUAL(surface.Size().PosX() == Size.PosX());
	LDL_TEST_EQUAL(surface.Size().PosY() == Size.PosY());

	LDL_TEST_EQUAL(surface.Bytes() == Capacity.PosX() * Capacity.PosY() * 4);

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);

	LDL_TEST_EQUAL(surface.Empty() == false);

	Color* pixels = (Color*)surface.Pixels();

	for (size_t i = 0; i < surface.Size().PosX() * surface.Size().PosY(); i++)
	{
		LDL_TEST_EQUAL(pixels[i].Red() == 1);
		LDL_TEST_EQUAL(pixels[i].Green() == 2);
		LDL_TEST_EQUAL(pixels[i].Blue() == 3);
		LDL_TEST_EQUAL(pixels[i].Alpha() == 4);
	}
}

int main()
{
	Init();
	InitCapacity();
	Clear();
	ClearCapacity();
	ClearColor();
	ClearColorCapacity();

	return 0;
}