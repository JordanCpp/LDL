#include <LDL/Core/TestEqual.hpp>
#include <LDL/Loaders/FontLoader.hpp>
#include <LDL/Allocators/FixedLinear.hpp>

using namespace LDL::Allocators;
using namespace LDL::Loaders;

const size_t bytes = Allocator::Mb * 1;

void Init()
{
	FixedLinear allocator(bytes);
	FontLoader fontLoader(&allocator);

	LDL_TEST_EQUAL(fontLoader.Font() == NULL);
	LDL_TEST_EQUAL(fontLoader.Size() == 0);
}

void Load()
{
	FixedLinear allocator(bytes);
	FontLoader fontLoader(&allocator);

	//LDL_TEST_EXCEPTION(fontLoader.Load("TestFiles/cmunrm.ttf"));

	LDL_TEST_EQUAL(fontLoader.Font() != NULL);
	LDL_TEST_EQUAL(fontLoader.Size() == 235656);
}

void Clear()
{
	FixedLinear allocator(bytes);
	FontLoader fontLoader(&allocator);

	//LDL_TEST_EXCEPTION(fontLoader.Load("TestFiles/cmunrm.ttf"));

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
