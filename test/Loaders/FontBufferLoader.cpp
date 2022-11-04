#include <LDL/Core/TestEqual.hpp>
#include <LDL/Loaders/FontBufferLoader.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <iostream>

const size_t bytes = LDL::Allocators::Allocator::Mb * 1;

void Init()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::FontBufferLoader fontBufferLoader(&allocator);

	LDL_TEST_EQUAL(fontBufferLoader.Font() == nullptr);
	LDL_TEST_EQUAL(fontBufferLoader.Size() == 0);
}

void Load()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::FontBufferLoader fontBufferLoader(&allocator);

	LDL_TEST_EXCEPTION(fontBufferLoader.Load("TestFiles/cmunrm.ttf"));

	LDL_TEST_EQUAL(fontBufferLoader.Font() != nullptr);
	LDL_TEST_EQUAL(fontBufferLoader.Size() == 235656);
}

void Clear()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::FontBufferLoader fontBufferLoader(&allocator);

	LDL_TEST_EXCEPTION(fontBufferLoader.Load("TestFiles/cmunrm.ttf"));

	fontBufferLoader.Clear();

	LDL_TEST_EQUAL(fontBufferLoader.Font() == nullptr);
	LDL_TEST_EQUAL(fontBufferLoader.Size() == 0);
}

int main()
{
	Init();
	Load();
	Clear();

	return 0;
}