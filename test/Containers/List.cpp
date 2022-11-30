#include <LDL/Core/TestEqual.hpp>
#include <LDL/Containers/List.hpp>

void Node()
{
	LDL::Containers::ListNode<size_t> listNode;

	LDL_TEST_EQUAL(listNode.Next == NULL);
	LDL_TEST_EQUAL(listNode.Prev == NULL);
}

void Init()
{
	LDL::Containers::List<size_t> list;

	LDL_TEST_EQUAL(list.Head == NULL);
	LDL_TEST_EQUAL(list.Tail == NULL);
}

void Append()
{
	const size_t limit = 128;

	LDL::Containers::List<size_t> list;

	for (size_t i = 0; i < limit; i++)
	{
		LDL::Containers::ListNode<size_t>* element = new LDL::Containers::ListNode<size_t>;

		element->Content = i;

		list.Append(element);
	}

	size_t j = 0;

	for (LDL::Containers::ListNode<size_t> * i = list.Head; i != nullptr; i = i->Next)
	{
		LDL_TEST_EQUAL(i->Content == j);

		j++;
	}
}

void Remove()
{
	const size_t limit = 128;

	LDL::Containers::List<size_t> list;

	LDL::Containers::ListNode<size_t>* element = new LDL::Containers::ListNode<size_t>;

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