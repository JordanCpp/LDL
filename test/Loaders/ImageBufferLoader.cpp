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
	LDL_TEST_EQUAL(imageBufferLoader.Pixels()        == nullptr);
}

void Load()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageBufferLoader imageBufferLoader(&allocator);

	LDL_TEST_EXCEPTION(imageBufferLoader.Load("TestFiles/359500_600.jpg"));

	LDL_TEST_EQUAL(imageBufferLoader.BytesPerPixel() == 3);
	LDL_TEST_EQUAL(imageBufferLoader.Size().PosX()   == 600);
	LDL_TEST_EQUAL(imageBufferLoader.Size().PosY()   == 438);
	LDL_TEST_EQUAL(imageBufferLoader.Pixels()        != nullptr);
	LDL_TEST_EQUAL(allocator.UsedBytes()             >= 600 * 438 * 3);
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
	LDL_TEST_EQUAL(imageBufferLoader.Pixels()        == nullptr);
	LDL_TEST_EQUAL(allocator.UsedBytes()             == 0);
}

int main()
{
	Init();
	Load();
	Clear();

	return 0;
}