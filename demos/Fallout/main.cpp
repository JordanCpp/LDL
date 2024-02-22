/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "Engine.hpp"
#include "Loaders.hpp"
#include "Frm.hpp"

void HashTableTest()
{
	class Item : HashItem
	{
	public:
		Item(size_t value) :
			Value(value)
		{
		}

		size_t Value;
	};

	HashTable table(HashTable::Small);
	LDL_NumberToString conv;

	for (size_t i = 0; i < 100; i++)
	{
		LDL_TEST_EQUAL(table.Contains(conv.Convert(i)) == NULL);
	}

	for (size_t j = 0; j < 100; j++)
	{
		Item* item = new Item(j);

		table.Add((HashItem*)item, conv.Convert(j));
    }

	for (size_t k = 0; k < 100; k++)
	{
		Item* item = (Item*)table.Contains(conv.Convert(k));

		LDL_TEST_EQUAL(item != NULL);
		LDL_TEST_EQUAL(item->Value == k);
	}
}

#if defined(__MSDOS__)
LDL_Vec2i windowSize(320, 200);
#else
LDL_Vec2i windowSize(800, 600);
#endif

int main()
{
	//HashTableTest();

	Engine engine(windowSize);
	engine.Run();

	return 0;
}