#include <LDL/Core/TestEqual.hpp>
#include <LDL/Loaders/FontLoader.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Core/RuntimeError.hpp>

const size_t bytes = LDL::Allocators::Allocator::Mb * 1;

void Init()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::FontLoader fontLoader(&allocator);

	LDL_TEST_EQUAL(fontLoader.Font() == NULL);
	LDL_TEST_EQUAL(fontLoader.Size() == 0);
}

void Load()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::FontLoader fontLoader(&allocator);

	LDL_TEST_EXCEPTION(fontLoader.Load("TestFiles/cmunrm.ttf"));

	LDL_TEST_EQUAL(fontLoader.Font() != NULL);
	LDL_TEST_EQUAL(fontLoader.Size() == 235656);
}

void Clear()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::FontLoader fontLoader(&allocator);

	LDL_TEST_EXCEPTION(fontLoader.Load("TestFiles/cmunrm.ttf"));

	fontLoader.Clear();

	LDL_TEST_EQUAL(fontLoader.Font() == NULL);
	LDL_TEST_EQUAL(fontLoader.Size() == 0);
}

int main()
{
	Init();
	Load();
	Clear();

	return 0;
}