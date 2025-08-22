// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3Lite_RingBuffer_hpp
#define SDL3Lite_RingBuffer_hpp

#include <string.h>
#include <LDL/Core/Types.hpp>

namespace LDL
{
	template<class T, size_t COUNT>
	class RingBuffer
	{
	public:
		RingBuffer() :
			_head(-1),
			_tail(0),
			_length(0),
			_capacity(COUNT)
		{
			memset(&_content, 0, sizeof(T) * COUNT);
		}

		bool empty()
		{
			return _length == 0;
		}

		bool full()
		{
			return _length == _capacity;
		}

		int next(int position)
		{
			return (position + 1) % _capacity;
		}

		bool dequeue(T& element)
		{
			if (!empty())
			{
				element = _content[_tail];
				_tail = next(_tail);
				_length--;

				return true;
			}

			return false;
		}

		void enqueue(const T& element)
		{
			_head = next(_head);

			_content[_head] = element;

			if (full())
			{
				_tail = next(_tail);
			}
			else
			{
				_length++;
			}
		}
	private:
		T   _content[COUNT];
		int _head;
		int _tail;
		int _length;
		int _capacity;
	};
}

#endif
