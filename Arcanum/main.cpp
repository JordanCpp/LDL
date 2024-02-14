#include "Structs.hpp"
#include <stdio.h>

int main()
{
	HashTable table;

	printf("%d\n", table.Contains("hello") != NULL);

	HashItem* item = new HashItem;

	table.Add(item, "hello");

	printf("%d\n", table.Contains("hello") != NULL);

	return 0;
}