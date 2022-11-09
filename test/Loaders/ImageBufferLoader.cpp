#include <LDL/Core/TestEqual.hpp>
#include <LDL/Loaders/ImageBufferLoader.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <iostream>

const size_t bytes = LDL::Allocators::Allocator::Mb * 4;

void Init()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageBufferLoader imageBufferLoader(&allocator);

	LDL_TEST_EQUAL(imageBufferLoader.BytesPerPixel() == 0);
	LDL_TEST_EQUAL(imageBufferLoader.Size().PosX()   == 0);
	LDL_TEST_EQUAL(imageBufferLoader.Size().PosY()   == 0);
	LDL_TEST_EQUAL(imageBufferLoader.Pixels()        == NULL);
}

void LoadJpg()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageBufferLoader imageBufferLoader(&allocator);

	LDL_TEST_EXCEPTION(imageBufferLoader.Load("TestFiles/359500_600.jpg"));

	LDL_TEST_EQUAL(imageBufferLoader.BytesPerPixel() == 3);
	LDL_TEST_EQUAL(imageBufferLoader.Size().PosX()   == 600);
	LDL_TEST_EQUAL(imageBufferLoader.Size().PosY()   == 438);
	LDL_TEST_EQUAL(imageBufferLoader.Pixels()        != NULL);
	LDL_TEST_EQUAL(allocator.UsedBytes()             >= 600 * 438 * 3);
}

void LoadPng()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageBufferLoader imageBufferLoader(&allocator);

	LDL_TEST_EXCEPTION(imageBufferLoader.Load("TestFiles/Gorgosaurus_BW_transparent.png"));

	LDL_TEST_EQUAL(imageBufferLoader.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(imageBufferLoader.Size().PosX() == 700);
	LDL_TEST_EQUAL(imageBufferLoader.Size().PosY() == 476);
	LDL_TEST_EQUAL(imageBufferLoader.Pixels() != NULL);
	LDL_TEST_EQUAL(allocator.UsedBytes() >= 700 * 476 * 4);
}

void Clear()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageBufferLoader imageBufferLoader(&allocator);
	
	LDL_TEST_EXCEPTION(imageBufferLoader.Load("TestFiles/359500_600.jpg"));

	imageBufferLoader.Clear();

	LDL_TEST_EQUAL(imageBufferLoader.BytesPerPixel() == 0);
	LDL_TEST_EQUAL(imageBufferLoader.Size().PosX()   == 0);
	LDL_TEST_EQUAL(imageBufferLoader.Size().PosY()   == 0);
	LDL_TEST_EQUAL(imageBufferLoader.Pixels()        == NULL);
	LDL_TEST_EQUAL(allocator.UsedBytes()             == 0);
}

int main()
{
	Init();
	LoadJpg();
	LoadPng();
	Clear();

	return 0;
}