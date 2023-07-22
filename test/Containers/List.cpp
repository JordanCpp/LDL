#include <LDL/Core/TestEqual.hpp>
#include <LDL/Containers/List.hpp>

using namespace LDL::Containers;

void Node()
{
	ListNode<size_t> listNode;

	LDL_TEST_EQUAL(listNode.Next == NULL);
	LDL_TEST_EQUAL(listNode.Prev == NULL);
}

void Init()
{
	List<size_t> list;

	LDL_TEST_EQUAL(list.Head == NULL);
	LDL_TEST_EQUAL(list.Tail == NULL);
}

void Append()
{
	const size_t limit = 128;

	List<size_t> list;

	for (size_t i = 0; i < limit; i++)
	{
		ListNode<size_t>* element = new ListNode<size_t>;

		element->Content = i;

		list.Append(element);
	}

	size_t j = 0;

	for (ListNode<size_t> * i = list.Head; i != NULL; i = i->Next)
	{
		LDL_TEST_EQUAL(i->Content == j);

		j++;
	}
}

void Remove()
{
	const size_t limit = 128;

	List<size_t> list;

	ListNode<size_t>* element = new ListNode<size_t>;

	list.Append(element);

	list.Remove(element);

	LDL_TEST_EQUAL(list.Head == NULL);
	LDL_TEST_EQUAL(list.Tail == NULL);
}

int main()
{
	Node();
	Init();
	Append();
	Remove();

	return 0;
}