#include <LDL/Core/TestEqual.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <iostream>
#include <fstream>

uint8_t* FileSize(const std::string& path, size_t* bytes)
{
	std::fstream file(path, std::ios_base::in | std::ios::binary);

	file.seekg(0, std::ios::end);
	size_t size = static_cast<size_t>(file.tellg());
	*bytes = size;
	file.seekg(0, file.beg);

	uint8_t* buffer = new uint8_t[size];
	file.read((char*)buffer, size);

	file.close();

	return buffer;
}

using namespace LDL::Allocators;
using namespace LDL::Loaders;

const size_t bytes = Allocator::Mb * 4;

void Init()
{
	FixedLinear allocator(bytes);
	ImageLoader imageLoader(&allocator);

	LDL_TEST_EQUAL(imageLoader.BytesPerPixel() == 0);
	LDL_TEST_EQUAL(imageLoader.Size().PosX()   == 0);
	LDL_TEST_EQUAL(imageLoader.Size().PosY()   == 0);
	LDL_TEST_EQUAL(imageLoader.Pixels()        == NULL);
}

void LoadJpg()
{
	FixedLinear allocator(bytes);
	ImageLoader imageLoader(&allocator);

	LDL_TEST_EXCEPTION(imageLoader.Load("TestFiles/359500_600.jpg"));

	LDL_TEST_EQUAL(imageLoader.BytesPerPixel() == 3);
	LDL_TEST_EQUAL(imageLoader.Size().PosX()   == 600);
	LDL_TEST_EQUAL(imageLoader.Size().PosY()   == 438);
	LDL_TEST_EQUAL(imageLoader.Pixels()        != NULL);
}

void LoadJpgFromMemory()
{
	FixedLinear allocator(bytes);
	ImageLoader imageLoader(&allocator);

	size_t size = 0;
	uint8_t* memory = FileSize("TestFiles/359500_600.jpg", &size);

	LDL_TEST_EQUAL(size   == 61491);
	LDL_TEST_EQUAL(memory != NULL);

	LDL_TEST_EXCEPTION(imageLoader.Load(memory, size));

	LDL_TEST_EQUAL(imageLoader.BytesPerPixel() == 3);
	LDL_TEST_EQUAL(imageLoader.Size().PosX()   == 600);
	LDL_TEST_EQUAL(imageLoader.Size().PosY()   == 438);
	LDL_TEST_EQUAL(imageLoader.Pixels()        != NULL);
}

void LoadPng()
{
	FixedLinear allocator(bytes);
	ImageLoader imageLoader(&allocator);

	LDL_TEST_EXCEPTION(imageLoader.Load("TestFiles/Gorgosaurus_BW_transparent.png"));

	LDL_TEST_EQUAL(imageLoader.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(imageLoader.Size().PosX()   == 700);
	LDL_TEST_EQUAL(imageLoader.Size().PosY()   == 476);
	LDL_TEST_EQUAL(imageLoader.Pixels()        != NULL);
}

void LoadPngFromMemory()
{
	FixedLinear allocator(bytes);
	ImageLoader imageLoader(&allocator);

	size_t size = 0;
	uint8_t* memory = FileSize("TestFiles/Gorgosaurus_BW_transparent.png", &size);

	LDL_TEST_EQUAL(size   == 198959);
	LDL_TEST_EQUAL(memory != NULL);

	LDL_TEST_EXCEPTION(imageLoader.Load(memory, size));

	LDL_TEST_EQUAL(imageLoader.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(imageLoader.Size().PosX()   == 700);
	LDL_TEST_EQUAL(imageLoader.Size().PosY()   == 476);
	LDL_TEST_EQUAL(imageLoader.Pixels()        != NULL);
}

void Clear()
{
	FixedLinear allocator(bytes);
	ImageLoader imageLoader(&allocator);
	
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
	LoadJpgFromMemory();
	LoadPng();
	LoadPngFromMemory();
	Clear();

	return 0;
}