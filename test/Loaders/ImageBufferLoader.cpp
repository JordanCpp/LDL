#include <LDL/Core/TestEqual.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <iostream>

const size_t bytes = LDL::Allocators::Allocator::Mb * 4;

void Init()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageLoader imageLoader(&allocator);

	LDL_TEST_EQUAL(imageLoader.BytesPerPixel() == 0);
	LDL_TEST_EQUAL(imageLoader.Size().PosX()   == 0);
	LDL_TEST_EQUAL(imageLoader.Size().PosY()   == 0);
	LDL_TEST_EQUAL(imageLoader.Pixels()        == NULL);
}

void LoadJpg()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageLoader imageLoader(&allocator);

	LDL_TEST_EXCEPTION(imageLoader.Load("TestFiles/359500_600.jpg"));

	LDL_TEST_EQUAL(imageLoader.BytesPerPixel() == 3);
	LDL_TEST_EQUAL(imageLoader.Size().PosX()   == 600);
	LDL_TEST_EQUAL(imageLoader.Size().PosY()   == 438);
	LDL_TEST_EQUAL(imageLoader.Pixels()        != NULL);
}

void LoadPng()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageLoader imageLoader(&allocator);

	LDL_TEST_EXCEPTION(imageLoader.Load("TestFiles/Gorgosaurus_BW_transparent.png"));

	LDL_TEST_EQUAL(imageLoader.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(imageLoader.Size().PosX() == 700);
	LDL_TEST_EQUAL(imageLoader.Size().PosY() == 476);
	LDL_TEST_EQUAL(imageLoader.Pixels() != NULL);
}

void Clear()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageLoader imageLoader(&allocator);
	
	LDL_TEST_EXCEPTION(imageLoader.Load("TestFiles/359500_600.jpg"));

	imageLoader.Clear();

	LDL_TEST_EQUAL(imageLoader.BytesPerPixel() == 0);
	LDL_TEST_EQUAL(imageLoader.Size().PosX()   == 0);
	LDL_TEST_EQUAL(imageLoader.Size().PosY()   == 0);
	LDL_TEST_EQUAL(imageLoader.Pixels()        == NULL);
}

int main()
{
	Init();
	LoadJpg();
	LoadPng();
	Clear();

	return 0;
}