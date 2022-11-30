#ifndef LDL_Containers_List_hpp
#define LDL_Containers_List_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Containers
	{
		template<typename TYPE>
		class ListNode
		{
		public:
			ListNode()
			{
				Next = NULL;
				Prev = NULL;
				Content = TYPE();
			}

			ListNode<TYPE>* Next;
			ListNode<TYPE>* Prev;
			TYPE Content;
		};

		template<typename TYPE>
		class List
		{
		public:
			ListNode<TYPE> * Head;
			ListNode<TYPE> * Tail;

			List()
			{
				Head = NULL;
				Tail = NULL;
			}

			~List()
			{
				ListNode<TYPE>* i = Head;
				ListNode<TYPE>* next = NULL;

				while (i) 
				{
					next = i->Next;
					i = next;
				}

				Head = NULL;
				Tail = NULL;
			}

			void Append(ListNode<TYPE>& element)
			{
				Append(element);
			}

			void Append(ListNode<TYPE>* element)
			{
				element->Next = NULL;
				element->Prev = Tail;

				if (Tail)
				{
					Tail->Next = element;
				}

				Tail = element;

				if (Head == NULL)
				{
					Head = element;
				}
			}

			void Remove(ListNode<TYPE>* element)
			{
				if (element->Prev) 
				{
					element->Prev->Next = element->Next;
				}

				if (element->Next)
				{
					element->Next->Prev = element->Prev;
				}

				if (!element->Prev)
				{
					Head = element->Next;
				}

				if (!element->Next) 
				{
					Tail = element->Prev;
				}
			}
		};
	}
}

#endif   